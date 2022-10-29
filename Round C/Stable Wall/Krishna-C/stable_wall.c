#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define S 30

int queue[S];
int frontId = 0;
int rear = -1;
int queue_size = 0;

int front() {
   return queue[frontId];
}

bool isEmpty() {
   return queue_size == 0;
}

bool isFull() {
   return queue_size == S;
}

int size() {
   return queue_size;
}  

void push(int data) {
   if(!isFull()) {
      if(rear == S-1) {
         rear = -1;            
      }       
      queue[++rear] = data;
      queue_size++;
   }
}

int pop() {
   int data = queue[frontId++];
   if(frontId == S) {
      frontId = 0;
   }
   queue_size--;
   return data;  
}
int main() {
    int T, R, C, DP[26][26], wall[30][30], freq[26], height[26];
    char ans[30];
    int ansIndex=0;
    scanf("%d",&T);
    for (int Case = 1; Case <= T; Case++){
        scanf("%d %d",&R,&C);
        memset(wall, 0, sizeof(wall));
        memset(freq, 0, sizeof(freq));
        memset(height, 0, sizeof(height));
        memset(DP, 0, sizeof(DP));
        for (int i = 0; i < R; i++){
                char row[C];
                scanf("%s",&row);
            for (int j = 0; j < C; j++){
                wall[i][j] = row[j]-'A';
                height[row[j]-'A'] = 1;
            }
        }
        for (int j = 0; j < C; j++){
            for (int i = 1; i < R; i++){
                if (wall[i][j] != wall[i-1][j] && DP[wall[i-1][j]][wall[i][j]] == 0){
                    DP[wall[i-1][j]][wall[i][j]] = 1;
                    freq[wall[i-1][j]]++;
                }
            }
        }
        for (int i = 0; i < 26; i++){
            if (freq[i] == 0) push(i);
        }
        ansIndex = 0;
        while (!isEmpty()){
            int now = front();
            pop();
            for (int i = 0; i < 26; i++){
                if (DP[i][now] == 1){
                    freq[i]--;
                    DP[i][now] = 0;
                    if (freq[i] == 0) push(i);
                }
            }
            ans[ansIndex++] = (char)('A'+now);
        }
        printf("Case #");
        printf("%d",Case);
        printf(": ");
        if (ansIndex != 26){
            printf("-1\n");
            continue;
        }
        for (int i=0;i<ansIndex;i++){
            if (height[ans[i]-'A']) printf("%C", ans[i]);
        }
        printf("\n");
    }
}