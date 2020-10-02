#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++){
        int n,x,temp,temp2;
        cin>>n>>x;
        long long sum=0;
        vector<pair<long long,long long>> A;
        for(int i = 0;i<n;i++){
            cin>>temp>>temp2;
            A.push_back(make_pair(temp,temp2));
        }
        sort(A.begin(),A.end());
        long long cur = A[0].first+x;
        sum++;
        for(int i = 0;i<A.size();i++){
            if(A[i].first >= cur){
                cur = A[i].first + x;
                sum++;
            }
            if(A[i].second>cur){
                while(A[i].second>cur){
                    sum++;
                    cur += x;
                }
            }
        }
        cout<<"Case #"<<k<<":"<<" "<<sum<<endl;
    }
    return 0;
}
