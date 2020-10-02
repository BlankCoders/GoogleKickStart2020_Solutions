#include<stdio.h>
#include<stdlib.h>
// run a binary search
typedef long long int ll;

ll check(ll d, ll a[], ll n, ll k)
{
	ll x = 0;
	for (ll i = 0; i + 1 < n; i++)
	{
		x += (a[i + 1] - a[i] - 1) / d;
	}
	if (x <= k)
		return 1;
	return 0;
}
ll binsearch(ll lo, ll hi, ll a[], ll n, ll k)
{
	while (lo < hi)
	{
		ll mid  = (lo + hi) / 2;
		if (check(mid, a, n, k))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}
int main()
{
	ll t;
	scanf("%lld", &t);
	ll tc;
	for (ll tc = 1; tc <= t; tc++)
	{
		ll n, k;
		scanf("%lld", &n);
		scanf("%lld", &k);
		ll a[n + 10];
		for (ll i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
		}
		ll ans = binsearch(1, 1000000000, a, n, k);
		printf("Case #%lld: %lld\n", tc, ans);
	}
}