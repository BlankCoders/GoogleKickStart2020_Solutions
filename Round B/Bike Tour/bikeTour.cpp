
//Bike Tour
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int arr[110];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 1; i < N - 1; i++)
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
            ans++;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    // loop for test cases
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        gogo();
    }
}