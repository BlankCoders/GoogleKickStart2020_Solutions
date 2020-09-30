//Wandering Robot

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int W, H, L, U, R, D;
double lfac[MAXN];
double p2[MAXN];

double choose (int N, int K)
{
    if (K < 0 || K > N) return 0;
    return exp (lfac[N] - lfac[K] - lfac[N-K] - p2[N]);
}

void gogo()
{
    cin >> W >> H >> L >> U >> R >> D;
    W--, H--, L--, U--, R--, D--;

    double ans = 0.0;

    int ly = U, lx = R;
    if (R < W)
    {
        double mult = 1.0;
        while (ly > 0)
        {
            ly--;
            lx++;

            if (lx >= W)
            {
                lx = W - 1;
                mult = 0.5;
            }
            //cout << mult << lx << ly << "\n";
            ans += mult * choose (lx + ly, lx);
        }
    }

    swap (U, L);
    swap (D, R);
    swap (H, W);
    ly = U, lx = R;
    if (R < W)
    {
        double mult = 1.0;
        while (ly > 0)
        {
            ly--;
            lx++;

            if (lx >= W)
            {
                lx = W - 1;
                mult = 0.5;
            }
            ans += mult * choose (lx + ly, lx);
        }
    }
    cout << fixed << setprecision(9);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    lfac[0] = 0.0;
    for (int i = 1; i < MAXN; i++)
        lfac[i] = lfac[i-1] + log(i);
    p2[1] = log(2);
    for (int i = 2; i < MAXN; i++)
        p2[i] = p2[i-1] + p2[1];

    //cout << choose (1, 0) << "\n";

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        gogo();
    }
}