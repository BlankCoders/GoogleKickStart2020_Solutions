#include <bits/stdc++.h>

template <typename T> inline void tense(T &a,const T &b){if (a>b) a=b;}
const double INF=1e100;

int n,m,q;

int a[105];

std::map<std::pair<int,std::string>,double> dp;

std::string get(const std::vector<int> &a){
    std::string ans;
    for (auto i:a) ans+=std::to_string(i),ans+='-';
    return ans;
}

double dfs(int i,const std::vector<int> &current){
    if (current.size()>q) return INF;
    for (int i=0;i<current.size();i++) if (current[i]>a[i+q-current.size()+1]) return INF;
    if (i==n){
        return 0;
    }
    std::string str=get(current);
    auto pii=std::make_pair(i,str);
    if (dp.find(pii)!=dp.end()) return dp[pii];
    
    double ans=INF;
    
    std::vector<std::pair<double,int>> tmp;
    
    for (int j=0;j<m;j++){
        std::vector<int> then=current;
        if (j<(int)current.size()) then[j]++; else then.push_back(1);
        std::sort(then.begin(),then.end());
        tmp.push_back(std::make_pair(dfs(i+1,then),j));
    }
    std::sort(tmp.begin(),tmp.end());
    double sum=0;
    for (int j=0;j<m;j++){
        double p=1.*(j+1)/m;
        sum+=tmp[j].first;
        tense(ans,((1-p)+p*(sum/(j+1)+1))/p);
    }
    dp[pii]=ans;
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);
    for (int tx=1;tx<=t;tx++){
        printf("Case #%d: ",tx);
        scanf("%d%d%d",&n,&m,&q);
        dp.clear();
        for (int i=1;i<=q;i++) scanf("%d",&a[i]);
        std::sort(a+1,a+q+1);
        printf("%.6f\n",dfs(0,std::vector<int>({})));
    }
    return 0;
}
