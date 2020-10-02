////   Author: ABHINASH GIRI
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target ("sse4")
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
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
#define ptvs(v) for(auto &item :v) cout<<item<<" ";cout<<"\n";
#define pt(x) cout<<((x))<<"\n";
#define pt2(x,y) cout<<(x)<<" "<<(y)<<"\n";
#define cinvll(v,start,end) vll v(end+1);for(auto i=start;i<=end;i++) {cin>>v[i];}
//***********************************************************************************************

int main()
{
	fast;
	vll v;
	for (int i = 0; i * i <= 10000000 ; ++i)
	{
		v.emplace_back(i * i);
	}
	ll q;
	cin >> q;
	for (int l = 1; l <= q ; ++l)
	{
		ll n;
		cin >> n;
		cinvll(a, 0, n - 1);
		ll ns = 0, ps = 0;
		for (auto &i : a)
		{
			if (i > 0)ps += i;
			if (i < 0)ns += i;
		}
		vll pre(n + 1, 0);
		pre[0] = a[0];
		vll pre_cnt(ps - ns + 2, 0);
		pre_cnt[0 - ns] = 1;
		ll ans = 0LL;
		for (int i = 0; i < n ; ++i)
		{
			if (i == 0)pre[i] = a[0];
			else pre[i] = pre[i - 1] + a[i];
			for (int j = 0; j < sz(v); ++j)
			{
				if (v[j] > pre[i] - ns)
				{
					break;
				}
				ll comp = pre[i] - v[j];
				ans += pre_cnt[comp - ns];
			}
			pre_cnt[pre[i] - ns]++;
		}

		cout << "Case #" << l << ": " << ans << nl;


	}

	return 0;
}
