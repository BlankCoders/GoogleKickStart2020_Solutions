#include <bits/stdc++.h>
using namespace std;
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
ll a[template_array_size]; ll b[template_array_size]; ll c[template_array_size];
string s, t;
ll ans = 0;

ll f(ll x) {
	if (x == 0) return 0;
	string s = to_string(x);
	ll less = 0, cur = 1;
	for (ll i = 1; i < s.length(); i++) {
		cur *= 5;
		less += cur;
	}
	ll ok = 0, eq = 1;
	for (ll i = 0; i < s.length(); i++) {
		ll c = s[i] - '0';
		ll v;
		if ((i + 1) % 2 == 0) v = c / 2 + 1;
		else v = (c + 1) / 2;
		ll nok = 0, neq = 0;
		nok += ok * 5;
		if (c % 2 == (i + 1) % 2) {
			--v;
			neq = eq;
			nok += eq * v;
		} else {
			nok += eq * v;
		}
		ok = nok;
		eq = neq;
	}
	return less + ok + eq;
}

void solve(int tc = 0) {
	cout << "Case #" << tc + 1 << ": ";
		
	cin >> l >> r;
	cout << f(r) - f(l - 1) << '\n';
}
int main() {

	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
} 