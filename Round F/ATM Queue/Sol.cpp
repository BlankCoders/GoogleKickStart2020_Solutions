////   Author: ABHINASH GIRI
#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI (2*acos(0.0))
#define sz(x)           ( (ll) (x).size())
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pos_rt_stbt(x)   (__builtin_ffsll(x))   // return position of rightmost set bit ( 1 indexing ) pos_rt_stbt(10) = 2 ( 1010 )
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            int t; cin>>t; while(t--)
#define nl "\n"
#define all(v) (v).begin(),(v).end()
#define clr(v) memset(v,0,sizeof(v));
#define sqr(x) ((x) * (x))
typedef long long ll;
typedef vector<long long int> vll;
typedef pair<ll, ll> pll;
int main()
{
	fast;
	ll t;
	cin >> t;
	for (auto z = 1; z <= t; z++)
	{
		ll n, x;
		cin >> n >> x;
		vll v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		multiset<pll>s;
		for (int i = 0; i < n; ++i)
		{
			ll d = ceil(1.0 * v[i] / x);
			s.insert(pll{d, i + 1});
		}
		cout << "Case #" << z << ": ";
		for (auto &i : s)
		{
			cout << i.second << " ";
		}
		cout << endl;
	}




	return 0;
}


