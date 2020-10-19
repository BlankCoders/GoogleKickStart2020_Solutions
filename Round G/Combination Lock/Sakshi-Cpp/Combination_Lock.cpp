#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long long int w,n;
	int t;
    cin >> t;
	long long int i,j;
     for(int m=1;m<=t;m++){
        cout << "Case #" << m << ": ";
        cin >> w >> n ;
        long long int arr[3*w],barr[3*w];
        
        for(i=0;i<w;i++)
            cin >> arr[i];
        sort(arr,arr+w);

        for(i=0;i<w;i++){
            arr[i+w]=arr[i];
            arr[i+w+w]=arr[i]+n;
            arr[i]-=n;
        }
        long long int ans = LLONG_MAX;
        barr[0]=arr[0];
        for(i=1;i<3*w;i++){
            barr[i]=barr[i-1]+arr[i];
        }
        for(i=w;i<2*w;i++){
            j=i-(w+1)/2;
            long long int tmp = (barr[j+w]-barr[i-1])-arr[i]*(j+w-(i-1));
            tmp += arr[i]*(i-1-j)-(barr[i-1]-barr[j]);
            ans = min(ans,tmp);
        }
        cout << ans << "\n";
    }
	return 0;
}
