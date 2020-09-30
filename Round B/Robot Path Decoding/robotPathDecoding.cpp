//Robot Path Decoding
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const ll MOD = 1e9;

int N;
string S;
pair <ll, ll> dp[MAXN][MAXN];

string xf = "NSEW";
int xc[4] = {0, 0, 1, -1};
int yc[4] = {-1, 1, 0, 0};

void figure (int lo, int hi)
{
    //cout << lo << " " << hi << endl;
    ll xres = 0, yres = 0;
    for (int i = lo; i <= hi; i++)
    {
        //cout << i << endl;
        if (S[i] >= '0' && S[i] <= '9')
        {
            int ntot = 1, cloc = i + 2;
            while (ntot)
            {
                if (S[cloc] == '(') ntot++;
                else if (S[cloc] == ')') ntot--;
                cloc++;
            }
            int nv = S[i] - '0';
            figure (i + 2, cloc - 2);
            pair <ll, ll> pv = dp[i + 2][cloc - 2];
            pv.first *= nv;
            pv.second *= nv;
            xres = (xres + pv.first) % MOD;
            yres = (yres + pv.second) % MOD;
            i = cloc - 1;
            continue;
        }
        
        for (int j = 0; j < 4; j++)
            if (xf[j] == S[i])
            {
                xres = (xres + MOD + xc[j]) % MOD;
                yres = (yres + MOD + yc[j]) % MOD;
            }
    }
    dp[lo][hi] = make_pair (xres, yres);
}

void gogo()
{
    cin >> S;
    N = S.length();
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = make_pair (-1, -1);

    figure (0, N - 1);

    ll x = dp[0][N-1].first % MOD + 1;
    ll y = dp[0][N-1].second % MOD + 1;
    cout << x << " " << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        gogo();
    }
}