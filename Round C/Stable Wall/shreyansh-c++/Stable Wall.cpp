#include<bits/stdc++.h>

using namespace std;

#define int long long

const unsigned int M = 1e9 + 7;

signed main(){
	int t; cin>>t;
	for(int tc = 1; tc <= t; tc++){
		cout<<"Case #"<<tc<<": ";
		
		int r, c; cin>>r>>c;
		vector<vector<char> > a(r, vector<char>(c));
		int distinct = 0;
		vector<int> f('Z' + 1);
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				char temp; cin>>temp;
				a[i][j] = temp;
				f[a[i][j]]++;
				if(f[a[i][j]] == 1) distinct++;
			}
		}
		string ans = "";
		vector<int> done('Z' + 1);
		for(int i = 0; i < distinct; i++){
			bool found = false;
			for(int j = 0; j < 26; j++){
				if(done[j + 'A'] || f[j + 'A'] == 0) continue;
				bool pos = true;
				for(int x = 0; x < r; x++){
					for(int y = 0; y < c; y++){
						if(a[x][y] == (j + 'A')){
							if(x == r-1 || (a[x+1][y] == (j + 'A')) || done[a[x+1][y]]){
							}else{
								pos = false;
								break;
							}
						}
					}
				}
				
				if(pos){
					ans += (j + 'A');
					done[j + 'A'] = 1;
					found = true;
					break;
				}
			}
			if(!found){
				ans = "-1";
				break;
			}
		}
		cout<<ans<<endl;
		
	}
}
