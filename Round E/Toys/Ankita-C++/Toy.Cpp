#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;
    ll cur_cycle=0;
    vector<ll> e, r ;
    for (int i = 0; i < N; i++) {
        /* code */
        ll E,R;
        cin>> E>> R;
        cur_cycle+=E;
        e.push_back(E);
        r.push_back(R);
    }
    priority_queue<pair<ll, int>> pq;
    
    ll max_enjoyment= cur_cycle;
    int min_rm_count=0;
    ll cur_enjoyment = cur_cycle;
    int rm_count=0;
    
    for (int i = 0; i < N; i++) {
        /* code */
        
        pq.push({e[i]+r[i], i});
        cur_enjoyment+=e[i];
        while(! pq.empty()){
            ll  longest_cooltime= pq.top().first;
            int longest_ct_toy_id= pq.top().second;
            if(longest_cooltime<= cur_cycle){
                break;
            }else{
                cur_enjoyment-=(2* e[longest_ct_toy_id]);
                cur_cycle-= e[longest_ct_toy_id];
                pq.pop();
                ++rm_count;
            }
        }
        if( max_enjoyment< cur_enjoyment){
            max_enjoyment= cur_enjoyment;
            min_rm_count=-(rm_count);
        }
        else if(max_enjoyment== cur_enjoyment){
            min_rm_count= max(min_rm_count, -(rm_count));
        }
        
        
    }
    
    if(!pq.empty()){
        max_enjoyment= INT_MAX;
        min_rm_count=- (rm_count);
    }
    if(max_enjoyment== INT_MAX){
        cout<< - min_rm_count<<" " << "INDEFINITELY";
    }
    else{
        cout<< - min_rm_count<<" " << max_enjoyment;
    }

}

int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);
    int C;
    cin>>C;
    int i=1;
    while(C--){
        cout<<" Case #"<<i<<": ";
        solve();
        cout<<endl;
        ++i;
    }
    return 0;
}