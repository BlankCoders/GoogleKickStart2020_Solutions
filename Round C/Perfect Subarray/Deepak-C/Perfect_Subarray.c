#include <stdio.h>

void solve()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum += abs(a[i]);
    }
    int cnt[2 * sum + 1];
    for (size_t i = 0; i < 2 * sum + 1; i++)
    {
        cnt[i] = 0;
    }

    cnt[sum]++;
    int pref = 0;
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        pref += a[i];
        for (int j = 0; j * j <= sum + pref; j++)
        {
            answer += cnt[sum + pref - j * j];
        }
        cnt[sum + pref]++;
    }
    printf("%lld\n", answer);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
}