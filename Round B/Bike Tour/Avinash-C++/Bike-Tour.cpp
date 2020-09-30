#include <iostream>
#include <algorithm>
using namespace std;

#define intt long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);



int main() {
    fast
    intt t;
    cin>>t;
    int tc=0;
    while(t--){
       
      int n;
      cin>>n;

      
       intt a[n];
       for(intt i=0;i<n;i++){
           cin>>a[i];
          
       } 
       intt count=0;
        for(intt i=1;i<n;i++){
            if(a[i-1]<a[i] and a[i]>a[i+1]){
                  count++  ;

            }      
         if(a[i]==a[i+1]){
             continue;
         }
          
        }
        tc++;
          cout<<"Case #"<<tc<<": "<<count<<endl;

    }
    
	return 0;
}