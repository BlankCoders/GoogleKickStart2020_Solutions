#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, maxVal, maxCount, diff, nextDiff, tc = 0;
    cin >> t;
    while (t--)
    {
        tc++;
        maxCount = maxVal = diff = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0)
            {
                if (i == 1)
                {
                    diff = arr[i] - arr[i - 1];
                    maxVal = 2;
                }
                else
                {
                    nextDiff = arr[i] - arr[i - 1];
                    if (nextDiff == diff)
                    {
                        if (maxVal == 0)
                        {
                            maxVal += 2;
                        }
                        else
                        {
                            maxVal++;
                        }
                    }
                    else
                    {
                        maxVal = 2;
                    }
                    diff = nextDiff;
                }
                if (maxCount < maxVal)
                {
                    maxCount = maxVal;
                }
            }
        }
        cout << "Case #" << tc << ": " << maxCount << "\n";
    }
    return 0;
}
