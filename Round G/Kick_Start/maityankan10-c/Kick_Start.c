#include <stdio.h>
#include <string.h>
int main()
{
    long long int k, t;
    char s[100000];
    scanf("%lld", &t);
    for(k = 0; k < t; k++){
        long long int i, j, count = 0;
        scanf("%s",s);
        for(i = 0; i < strlen(s); i++){
            if(s[i + 0] == 'K' && s[i + 1] == 'I' && s[i + 2] == 'C' && s[i + 3] == 'K'){
                for(j = i + 4; j < strlen(s); j++){
                    if(s[j + 0] == 'S' && s[j + 1] == 'T' && s[j + 2] == 'A' && s[j + 3] == 'R' && s[j + 4] == 'T'){
                        count++;
                        j = j + 3; 
                    }
                }
                i = i + 2;
            }
        }
        printf("Case #%lld: %lld\n", k + 1, count);
    }

}