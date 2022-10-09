// Inspired or took help from https://www.youtube.com/watch?v=Wb0tE1Tw9SM
#include<stdio.h>

int MAX = 1e9; 

int min(int a, int b){
    return a<b ? a : b;
}

int findMinNumberOfRuleBreaks(int notes[], int n){
    int dp[n][4];
    for(int i=0;i<n;i++){
        for(int val=0;val<4;val++){
            if(i==0){
                dp[i][val]=0;
            } else{
            int ans=MAX;
            for(int j=0;j<4;j++){
                if((notes[i-1]<notes[i] && j<val) || (notes[i-1]>notes[i] && j>val) || (notes[i-1]==notes[i] && j==val))
                    ans=min(ans, dp[i-1][j]);
                else
                    ans=min(ans, 1+dp[i-1][j]);
            }
            dp[i][val]=ans;
            }
        }
    }

    int ans=MAX;
    for(int val=0;val<4;val++){
        ans=min(ans, dp[n-1][val]);
    }
    return ans;
}

int main(){
    int TC=1;
    scanf("%d", &TC);
    int test_num=1;
    while(TC--){
        int n;
        scanf("%d", &n);
        int notes[n];
        for(int i=0;i<n;i++)
            scanf("%d", &notes[i]);
        int ruleBreaks=findMinNumberOfRuleBreaks(notes, n);
        printf("Case #%d: %d\n", test_num, ruleBreaks);
        test_num++;
    }
    return 0;
}