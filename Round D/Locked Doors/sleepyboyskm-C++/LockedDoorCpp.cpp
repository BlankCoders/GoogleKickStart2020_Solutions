#include <bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 200005;
int st[maxn][20], fa[maxn][20], lo[maxn];
int a[maxn], T, n, Q, nc, rec[maxn];
int ans[maxn];

struct TreeNode
{
    int fat, l, r, mid;
    void init(int lg, int rg, int f) { fat = f; l = lg; r = rg; mid = 0; }
}tr[maxn << 1];

int find_max_id(int l, int r)
{
    if(r < l) return 0;
    int t = lo[r - l + 1];
    int x = st[l][t];
    int y = st[r - (1 << t) + 1][t];
    return a[x] > a[y] ? x : y;
}

void make_tree(int l, int r, int f)
{
    ++ nc; tr[nc].init(l, r, f);
    fa[nc][0] = f;
    for(int k = 1; (1 << k) <= n; ++ k)
        fa[nc][k] = fa[fa[nc][k - 1]][k - 1];
    if(l == r) { rec[l] = nc; return; }
    int m = find_max_id(l, r - 1);

    //printf("%d %d %d %d\n", nc, l, r, m);

    tr[nc].mid = m; int tnc = nc; 
    make_tree(l, m, tnc); make_tree(m + 1, r, tnc);
}

int find(int s, int k)
{
    if(k == 0) return s;
    int bg = rec[s];
    int p = 0; while( (1 << p) <= n) ++ p;
    -- p;
    while(p >= 0)
    {
        int tf = fa[bg][p];
        if(tr[tf].r - tr[tf].l <= k) bg = fa[bg][p];
        -- p;
    }
    if(tr[bg].r - tr[bg].l >= k)
    {
        int m = tr[bg].mid;
        if(s <= m) return tr[bg].r; else return tr[bg].l;
        return 0;
    }
    int f = fa[bg][0];
    int m = tr[f].mid;
    k -= (tr[bg].r - tr[bg].l);
    if(s <= m) return m + k; else return m - k + 1;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &Q);
        for(int i = 1; i < n; ++ i) scd(a[i]);
        a[n] = 0;
        for(int i = 1; i <= n; ++ i) st[i][0] = i;
        for(int k = 1; (1 << k) <= n; ++ k)
            for(int i = 1; i + (1 << k) - 1 <= n; ++ i)
                if( a[st[i][k - 1]] > a[st[i + (1 << (k - 1))][k - 1]] )
                    st[i][k] = st[i][k - 1];
                else
                    st[i][k] = st[i + (1 << (k - 1))][k - 1];
        lo[1] = 0; for(int i = 2; i <= n; ++ i) lo[i] = lo[i >> 1] + 1;
        nc = 0; make_tree(1, n, 1);
        
        // solve
        for(int i = 1; i <= Q; ++ i)
        {
            int s, k; scanf("%d%d", &s, &k);
            ans[i] = find(s, k - 1);
        }
        prcas; for(int i = 1; i <= Q; ++ i) printf("%d%c", ans[i], i == Q ? '\n' : ' ');
    }
    return 0;
}
