#include<stdio.h>
#include<stdlib.h>
int main()
{
    int c;

    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {   int r1=0;
        int n,k;

        scanf("%d %d",&n,&k);
        int *p;
        p=malloc(n*sizeof(int));
        for(int j=0;j<n;j++ )
        {
            scanf("%d",(p+j));
        }
        for(int x=0;x<n;x++)
        {
            if(*(p+x)==k)
            {int y=x+1;
                for(int  q=k-1;q>=0;q--){
                        if(q==0)
                        {
                            r1++;

                            break;
                        }
                    if(*(p+y)==q)
                    {
                       y++;
                        continue;
                    }

                    else
                        break;
                }
            }
            else
                continue;
        }
   printf("Case #%d: %d\n",i+1,r1   );
   free(p); }
return 0;}
