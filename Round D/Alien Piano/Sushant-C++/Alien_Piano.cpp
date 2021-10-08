#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pair<int, int> range = {1, 4};
    int count = 0;

    for (int j = 1; j < n; j++)
    {
        if (v[j] > v[j - 1])
        {
            range.first += 1;
            range.second = 4;
        }
        else if (v[j] < v[j - 1])
        {
            range.first = 1;
            range.second -= 1;
        }
        else
        {
            continue;
        }

        if (range.first > range.second)
        {
            count++;
            range = {1, 4};
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int answer = solve();
        cout << "Case #" << i + 1 << ": " << answer << endl;
    }

    return 0;
}