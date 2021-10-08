#include <stdio.h>
#include <stdlib.h>


long long min(long long num1, long long num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

void solve(int i)
{
    printf("Case #%d: ", i);
    long long N, K, S;
    scanf("%ld", &N);
    scanf("%ld", &K);
    scanf("%ld", &S);

    int minimum = min(N + 1, K - S + N - S + 1);

    printf("%d\n", (K - 1 + minimum));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    return 0;
}