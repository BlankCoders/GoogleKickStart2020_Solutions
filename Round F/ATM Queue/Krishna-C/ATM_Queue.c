#include<stdio.h>

struct str
{
    int value;
    int index;
};

int cmp(const void *a, const void *b)
{
    struct str *a1 = (struct str *)a;
    struct str *a2 = (struct str *)b;
    if ((*a1).value <= (*a2).value)
        return -1;
    else
        return 1;
}


void printOrderOfLeaving(int n, int limit, int money[]){
    struct str objects[n];
    for (int i = 0; i < n; i++){
        objects[i].value = (money[i]+limit-1)/limit;
        objects[i].index = i;
    }
    qsort(objects, n, sizeof(objects[0]), cmp);
    for (int i = 0; i < n; i++)
        printf("%d ", objects[i].index+1);
        
    printf("\n");
    
}

int main(){
    int TC=1;
    scanf("%d", &TC);
    int test_num=1;
    while(TC--){
        printf("Case #%d: ", test_num);
        int n, m;
        scanf("%d %d", &n, &m);
        
        int money[n];
        for(int i=0;i<n;i++){
            scanf("%d", &money[i]);
        }
        printOrderOfLeaving(n, m, money);
        test_num++;
    }
    return 0;
}