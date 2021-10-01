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
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
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
	#ifdef Rk1091_sol
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef Rk1091_sol
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 	
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef Rk1091_sol
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
} 