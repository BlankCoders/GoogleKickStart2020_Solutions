#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, j, k) for (int i = j; i < k; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200005;
ll mi[305][305];
vector<int> g[305];
vector<vector<int>> re;
int n, m, s, r;
bool relax()
{
    ll nm[n + 1][s + 1];
    f1(n)
    {
        fr(j, 1, s + 1)
        {
            nm[i][j] = mi[i][j];
        }
    }
    for (int i = 1; i <= s; i++)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        fr(j, 1, n + 1)
        {
            if (nm[j][i] <= 1000000000000)
                pq.push({nm[j][i], j});
        }
        while (pq.size())
        {
            auto now = pq.top();
            pq.pop();
            if (nm[now.S][i] != now.F)
            {
                continue;
            }
            for (auto &j : g[now.S])
            {
                if (nm[j][i] > now.F + 1)
                {
                    nm[j][i] = now.F + 1;
                    pq.push({nm[j][i], j});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto &j : re)
        {
            ll sum = 0;
            for (int k = 0; k < j.size() - 1; k++)
            {
                sum += nm[i][j[k]];
                if (sum > 1000000000000)
                {
                    break;
                }
            }
            if (sum < nm[i][j.back()])
            {
                nm[i][j.back()] = sum;
            }
        }
    }
    int f = 0;
    ;
    f1(n)
    {
        fr(j, 1, s + 1)
        {
            if (mi[i][j] ^ nm[i][j])
            {
                f = 1;
            }
            mi[i][j] = nm[i][j];
            //cout << mi[i][j] <<' ';
        }
        //cout << '\n';
    }
    return f;
}
void go()
{
    cin >> n >> m >> s >> r;
    re.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        for (int j = 1; j <= s; j++)
        {
            mi[i][j] = 1000000000000;
        }
    }
    f(m)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    f1(n)
    {
        int k;
        cin >> k;
        fr(j, 0, k)
        {
            int x;
            cin >> x;
            mi[i][x] = 0;
        }
    }
    f(r)
    {
        int k;
        cin >> k;
        vector<int> add;
        fr(j, 0, k + 1)
        {
            int x;
            cin >> x;
            add.pb(x);
        }
        re.pb(add);
    }
    while (relax())
        ;
    ll ans = 1e18;
    f1(n)
    {
        ans = min(ans, mi[i][1]);
    }
    if (ans >= 1000000000000)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 1;
    int t;
    if (!c)
    {
        t = 1;
    }
    else
    {
        cin >> t;
    }
    while (t--)
    {
        cout << "Case #" << (c++) << ": ";
        go();
    }
}