#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 4674;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
void solve(int tc = 0) {
	cout << "Case #" << tc + 1 << ": ";
		
	bool adj[26][26];
	cin >> n >> q;
	memset(adj, 0, sizeof(adj));
	string ss[n];
	bool has[n][26];
	memset(has, 0, sizeof(has));
	
	for (ll i = 0; i < n; i++) {
		cin >> s;
		ss[i] = s;
		for (char c: s) has[i][c - 'A'] = 1;
		
		for (ll j = 0; j < 26; j++) {
			for (ll k = 0; k < 26; k++) {
				if (has[i][j] && has[i][k]) {
					adj[j][k] = 1;
				}
			}
		}
	}
	
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		
		queue<pair<ll, ll>> q;
		bool vis[26];
		memset(vis, 0, sizeof(vis));
		
		for (ll j = 0; j < 26; j++) {
			if (has[a][j]) {
				q.push(make_pair(j, 0));
				vis[j] = 1;
			}
		}
		
		ll ans = -1;
		while (!q.empty()) {
			pair<ll, ll> x = q.front();
			q.pop();
			
			// cout << (char)(x.f + 'A') << " " << x.s << endl;
			
			if (has[b][x.f]) {
				ans = x.s + 2;
				break;
			}
			
			for (ll j = 0; j < 26; j++) {
				if (adj[x.f][j] && !vis[j]) {
					vis[j] = 1;
					q.push(make_pair(j, x.s + 1));
				}
			}
		}
		
		cout << ans << " ";
	}
	
	cout << '\n';
}

int main() {
    
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
}