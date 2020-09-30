#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int n, k;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		int ans = 0;
		int arr[n];

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == k)
			{
				int x = k;
				for (int a = j; a < j + k; a++)
				{
					if (arr[a] == x)
					{
						x--;
					}

					else
					{
						break;
					}
					
				}
				if (x == 0)
				{
					ans++;
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
}