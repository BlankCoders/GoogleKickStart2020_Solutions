#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,q,t,s[100],beg,en;
    int temp,sy=1;
    char ope[100];
    int cmd[100][2];
    std::vector<int> a;
    cin>>t;
    for(int cases=1;cases<=t;cases++)
    {
        cin>>n>>q;
        //takes the array input
        for(int i=0;i<n;i++){
            cin>>temp;
            a.push_back(temp);
        }
        //takes input as 'U' or 'Q'
        for(int i=0;i<q;i++){
            cin>>ope[i];
            for(int j=0;j<2;j++){
                cin>>cmd[i][j];
            }
        }
        //processing
        s[cases]=0;
        for(int r=0;r<q;r++){
            if(ope[r]=='U')
                a[cmd[r][0]-1]=cmd[r][1];
            else{
                beg=cmd[r][0]-1;
                en=cmd[r][1]-1;
                int fac=1;
                for(int i=beg;i<=en;i++)
                {
                    if(fac%2==0)
                        sy=-1;
                    else
                        sy=1;
                    int h=a[i]*fac*sy;
                    s[cases]+=h;
                    fac++;
                }

            }
        }
        //clears the array for the next test cases
        a.clear();
    }

    for(int i=1;i<=t;i++)
        printf("Case #%d: %d\n",i,s[i]);
}
