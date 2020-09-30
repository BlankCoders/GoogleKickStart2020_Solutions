//Bus Routes

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll D;
ll X[1010];

bool works (ll K)
{
    for (int i = 0; i < N; i++)
    {
        if (K % X[i] != 0)
            K += (X[i] - K % X[i]);
    }
    return K <= D;
}

void gogo()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++)
        cin >> X[i];

    ll lo = 0, hi = D;
    while (lo < hi)
    {
        ll mid = (lo + hi + 1) / 2;
        if (works (mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << "\n";
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