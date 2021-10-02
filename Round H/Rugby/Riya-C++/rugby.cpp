#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 4674;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll best(vector<ll> v) {
	ll pos = v[v.size() / 2];
	ll s = 0;
	for (ll x: v) s += abs(x - pos);
	return s;
}
void solve(int tc = 0) {
	cout << "Case #" << tc + 1 << ": ";
	cin >> n;
	vector<ll> x, y;
	for (ll i = 0; i < n; i++) {
		cin >> l >> r;
		x.push_back(l);
		y.push_back(r);
	}
	ll ans = 0;
	sort(y.begin(), y.end());
	ans += best(y);
	sort(x.begin(), x.end());
	for (ll i = 0; i < n; i++) x[i] -= i;
	sort(x.begin(), x.end());
	ans += best(x);
	cout << ans << '\n';
}
int main() {
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
} 