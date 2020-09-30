#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    int i = 0;
    
    // input number of testcases
    cin >> t;
    
    // Repeat until all testcases are executed
    while(t--){
        int n,b;
        
        // Input number of houses and budget
        cin >> n >> b;
        
        // Create an array of size "n" to store list of house costs
        int a[n];
        
        // input list of house costs
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        
        // sort the list of house costs to implement the algorithm
        sort(a,a + n);
        
        int ans = 0;
        
        // traverse through the sorted list
        for(int j = 0; j < n; j++){
        
            // Check if the budget is greater than cost of house
            // IF YES then buy that house
            if(b >= a[j]){
                
                // House bought so increase the number of ans
                ans++;
                
                // Since House is bought so decrease the cost of house from budget
                b -= a[j];
            }
        }
        
        // Print the answer for present test-case
        cout << "Case #" << ++i << ": " << ans << endl;
    }
}
