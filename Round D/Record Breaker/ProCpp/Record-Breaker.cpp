
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define dopamine ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007

int main()
{
//	serotonin();
	dopamine
	int t = 1; cin >> t;
	for (int j = 1; j <= t; j++)
	{	int a; cin >> a; int arr[a];
		for (int i = 0; i < a; i++)
			cin >> arr[i];

		int c = 0;
		ll maxi = -100;
		for (int i = 0; i < a ; i++)
		{
			if (arr[i] > maxi)
			{	maxi = arr[i];
				if (i == a - 1 ) {c++; break;}
				if (arr[i] > arr[i + 1])
					c++;


			}
		}

		cout << "Case #" << j << ": " << c << "\n";
	}
	return 0;
}
