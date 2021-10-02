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
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

void solve(int tc = 0) {
	cout << "Case #" << tc + 1 << ": ";
	ll s;
	cin >> n >> k >> s;
	cout << k + min(n, abs(k - s) + n - s) << '\n';
}

int main() {
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
} 