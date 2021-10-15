#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void test_case()
{
    int n;
    scanf("%d", &n);
    long long map[2000005];
    for (int i = 0; i < 2000005; ++i)
    {
        map[i] = 0;
    }
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            int x;
            scanf("%d", &x);
            
            int F = 0;
            if(row < col) F = 1000000;
            map[row - col + F] += x;
        }
    }
    long long answer = 0;
    for (int i = 0; i < 2000005; ++i)
    {
        answer = MAX(answer, map[i]);
    }
    printf("%lld\n", answer);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int nr = 1; nr <= T; ++nr)
    {
        printf("Case #%d: ", nr);
        test_case();
    }
}