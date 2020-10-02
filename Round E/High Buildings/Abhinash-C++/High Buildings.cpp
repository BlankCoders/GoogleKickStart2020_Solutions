////   Author: ABHINASH GIRI
#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define nl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vll;

#define ptvs(v) for(auto &item :v) cout<<item<<" ";cout<<"\n";
#define pt(x) cout<<((x))<<"\n";
#define pt2(x,y) cout<<(x)<<" "<<(y)<<"\n";
#define cinvll(v,start,end) vll v(end+1);for(auto i=start;i<=end;i++) {cin>>v[i];}

int main()
{
	fast;
	ll q;
	cin >> q;
	for (int l = 1; l <= q ; ++l)
	{
		ll n, a, b, c;
		cout << "Case #" << l << ": ";
		cin >> n >> a >> b >> c;
		if (a + b - c > n)
		{
			pt("IMPOSSIBLE");
			continue;
		}
		if (n == 1)
		{
			if (a == 1 and b == 1 and c == 1)pt(1)
				else pt("IMPOSSIBLE");
			continue;
		}
		if (n == 2)
		{
			if (a == 2 and b == 2 and c == 2)
			{
				pt2(1, 1);
			}
			else if (a == 2 and b == 1 and c == 1)
			{
				pt2(1, 2);
			}
			else if (a == 1 and b == 2 and c == 1)
			{
				pt2(2, 1);
			}
			else pt("IMPOSSIBLE");
			continue;
		}
		ll sm = n - (a + b - c);
		if (sm < 0)pt("IMPOSSIBLE");
		if (a - c > 0)
		{
			for (int i = 0; i < a - c; ++i)
			{
				cout << 2 << " ";
			}
			for (int i = 0; i < sm; ++i)
			{
				cout << 1 << " ";
			}
			for (int i = 0; i < c; ++i)
			{
				cout << 3 << " ";
			}
			for (int i = 0; i < b - c; ++i)
			{
				cout << 2 << " ";
			}
			cout << nl;
		}
		else if (b - c > 0)
		{
			for (int i = 0; i < c; ++i)
			{
				cout << 3 << " ";
			}
			for (int i = 0; i < sm; ++i)
			{
				cout << 1 << " ";
			}
			for (int i = 0; i < b - c; ++i)
			{
				cout << 2 << " ";
			}
			cout << nl;
		}
		else if (c >= 2)
		{
			cout << 3 << " ";
			for (int i = 0; i < sm; ++i)
			{
				cout << 1 << " ";
			}
			for (int i = 1; i < c ; ++i)
			{
				cout << 3 << " ";
			}
			cout << nl;
		}
		else pt("IMPOSSIBLE");



	}

	return 0;
}
