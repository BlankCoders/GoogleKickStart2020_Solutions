// Inspired by Ashish Gupta

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, tnum=1;
	cin >> t;

	while(t--) {
	    int n, k, a[100000];
		cin >> n >> k;
	    
	    for(int i = 0; i < n; ++i) {
		    cin >> a[i];
	    }

	    int l = 1, r = a[n - 1] - a[0];
	    
	    while( l < r ) {
		    
		    int m = ( l + r ) / 2;
		    int _k = 0;
		    
		    for(int i = 1; i < n; ++i) {
			    int d = a[i] - a[ i - 1 ] ;
			    _k += ( d + m - 1 ) / m - 1;
		    }
		    
		    if(_k <= k){
			    r = m;
		    }
		    else{
			    l = m + 1;
		    }
	    }
	    cout << "Case #" << tnum << ": " << l << endl;
        tnum++;
	}
	return 0;
}
