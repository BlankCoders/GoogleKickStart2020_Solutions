#include <stdio.h>
#include <sys/time.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

const int N = 2e5 + 87;

long long n, C, aa[N], S[N];

unsigned int X;
 
void srand_() {
	struct timeval tv;
 
	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec | 1;
}
 
int rand_() {
	return (X *= 3) >> 1;
}

void sort(long long *aa, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r;
		long long a = aa[l + rand_() % (r - l)], tmp;
 
		while (j < k)
			if (aa[j] == a)
				j++;
			else if (aa[j] < a) {
				tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = aa[j], aa[j] = aa[k], aa[k] = tmp;
			}
		sort(aa, l, i);
		l = k;
	}
}

void solve()
{
   scanf("%d%d", &n, &C);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &aa[i]);
    sort(aa, 1,n + 1);
    for (int i = n + 1; i <= 2 * n; ++i)
        aa[i] = aa[i - n] + C;
    for (int i = 1; i <= 2 * n; ++i)
        S[i] = S[i - 1] + aa[i];
    long long ans = (long long) 1e18;
    for (int r = n; r < 2 * n; ++r) {
        int l = r - n + 1;
        int m = (l + r) / 2;
        ans = MIN(ans, (m - l + 1) * aa[m] - (S[m] - S[l - 1]) + S[r] - S[m] - (r - m) * aa[m]);
    }
    printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		solve();
	}
}
