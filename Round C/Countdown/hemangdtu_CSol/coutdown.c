#include <iostream>
int main()
{
    int T, ctr = 0;
    scanf("%d", &T);
    while(T--)
    {
        int N, K;
        scanf("%d%d", &N, &K);
        int A[N], ans = 0;
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        for (int j = 0; j < N; j++)
            if (A[j] == K)
            {
                int x = K;
                for (int a = j; a < j + K; a++)
                    if (A[a] == x)
                        x--;
                    else
                        break;
                if (x == 0)
                    ans++;
            }
        printf("Case #%d: %d\n", ctr+1, ans);
        ctr+=1;
    }
}