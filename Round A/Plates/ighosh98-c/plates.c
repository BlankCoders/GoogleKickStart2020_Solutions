#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b )
{
	return a > b ? a : b;
}
int main()
{
	int n, m, p, t;
	scanf("%d", &t);
	for (int theta = 1; theta <= t; theta++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		scanf("%d", &p);
		int a[n][m];
		int dp[n + 1][p + 1];
		memset(dp, 0, sizeof(dp));
		int mark[n];
		memset(mark, 0, sizeof(mark));


		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				scanf("%d", &a[j][k]);
				if (k > 0)
					a[j][k] += a[j][k - 1];
			}

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k + j + 1 <= p; k++)
				{
					dp[i + 1][k + j + 1] = max(dp[i][k + j + 1], dp[i + 1][k + j + 1]);
					dp[i + 1][k + j + 1] = max(dp[i][k] + a[i][j], dp[i + 1][k + j + 1]);
				}
			}
		}
		printf("Case #%d: %d\n", theta, dp[n][p]);
	}
}