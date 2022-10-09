#include <bits/stdc++.h>
#define int long long
using namespace std;

long double F(int n, int t)
{
    if (t < 0 or t > n)
        return 0;
    bool f = (t > n - t);
    if (f)
        t = n - t - 1;
    long double ret = 1;
    long double sum = 1;
    int rem = n;
    for (int i = 1; i <= t; ++i)
    {
        ret *= (n + 1 - i);
        ret /= i;
        sum += ret;
        while (sum > 1 and rem > 0)
        {
            rem--;
            sum /= 2;
            ret /= 2;
        }
    }

    while (rem--)
    {
        sum /= 2;
    }

    if (f)
        return 1 - sum;
    else
        return sum;
}

void Seeyouagain()
{
    int W, H, L, U, R, D;
    cin >> W >> H >> L >> U >> R >> D;
    long double r1 = F(L + D - 2, L - 2), r2 = F(R + U - 2, U - 2);
    if (D == H)
        r1 = 0;
    if (R == W)
        r2 = 0;
    cout << r1 + r2 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(!cin.tie(nullptr));
    int testc = 1;
    cin >> testc;
    cout << fixed << setprecision(15);
    for (int i = 1; i <= testc; ++i)
    {
        cout << "Case #" << i << ": ";
        Seeyouagain();
    }
    return 0;
}