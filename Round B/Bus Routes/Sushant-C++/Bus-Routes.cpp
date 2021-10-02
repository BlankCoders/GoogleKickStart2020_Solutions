#include <bits/stdc++.h>
using namespace std;

vector<long long int> a(1001);

int main()
{
    // counter will keep track of the number of test cases.
    int counter;
    cin >> counter;

    for (int i = 1; i <= counter; i++)
    {
        // n is the number of bus-routes and d is the finishing day.
        long long int n, d;
        cin >> n >> d;

        // getting the input of the day for each of the bus.
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }

        // finalBucket denotes the last possible day to take the last bus.
        long long int finalBucket = d;

        // For the previous bus i.e. (n-1)th the last possible date to ride is finalBucket - (finalBucket % (n-1)).
        // In this way, we will iterate from last possible bus to the first one and that will be our answer.
        for (int j = n - 1; j >= 0; j--)
        {
            finalBucket = min(finalBucket, finalBucket - (finalBucket % a[j]));
        }
        cout << "Case #" << i << ": " << finalBucket << endl;
    }

    return 0;
}