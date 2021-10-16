#include <stdio.h>

void solve()
{
    long long d, n;
    scanf("%lld%lld", &n, &d);
    long long M[1000005];
    for (int i = 1; i <= n; i++) scanf("%lld", &M[i]);
    for (int i = n; i > 0; i--) d -= d % M[i];
    printf("%lld\n", d);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}