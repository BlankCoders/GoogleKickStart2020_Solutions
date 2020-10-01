#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[500001][2];
vector<int> tree[500001];

void whatsWithThisOPFormat(){
    static int tno = 1;
    cout << "Case #" <<tno++ <<": ";
}

void solve(int src, int par, vector<int>& ancestors, int& dis, bool aOrb){
    dp[src][aOrb] = 1;
    ancestors.push_back(src);
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ancestors, dis, aOrb);
    }
    ancestors.pop_back();
    int totalAncestors = ancestors.size();
    if(totalAncestors >= dis){
        dp[ancestors[totalAncestors - dis]][aOrb] += dp[src][aOrb];
    }
}

int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   cin >> t;
   //t = 1;
   while(t--)
   {
        int a,b;
        cin >> n >> a >> b;
        fr(1,n+1)tree[i].clear();

        fr(0,n-1)
        {
            cin >> x;
            tree[i+2].push_back(x);
            tree[x].push_back(i+2);
        }

        vector<int> dfsOfTree;

        solve(1,0,dfsOfTree, a, 0);
        solve(1,0,dfsOfTree, b, 1);

        double ans = 0;

        for(int i = 1; i <= n; i++){
            ans = (ans + 1ll*n*(dp[i][0] + dp[i][1]));
            ans = (ans - 1ll*dp[i][0]*dp[i][1]);
        }


        whatsWithThisOPFormat();
        prDouble (((double)ans/(double)(n*n)));
        cout << '\n';
   }
   return 0;
}
