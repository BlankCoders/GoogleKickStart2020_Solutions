#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar_unlocked(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread_unlocked(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar_unlocked(c[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int TEST;
int S;
int C;
int mp[6][12];
int X1;
int Y1;
int X2;
int Y2;
int X;
int Y;
int go(int &x, int &y, int d){
  if(d==0){
    if(y%2==1){
      x--;
      y--;
      return 1 - mp[x][y];
    }
    return 0;
  }
  if(d==1){
    if(x+1 < S && y%2==0){
      x++;
      y++;
      return 1 - mp[x][y];
    }
    return 0;
  }
  if(d==2){
    if(y != 0){
      y--;
      return 1 - mp[x][y];
    }
    return 0;
  }
  if(d==3){
    if(y != 2*x){
      y++;
      return 1 - mp[x][y];
    }
    return 0;
  }
  return 0;
}
int solve(int X1, int Y1, int X2, int Y2){
  int d;
  int res = -1073709056;
  int x;
  int y;
  for(d=(0);d<(4);d++){
    x = X1;
    y = Y1;
    if(go(x,y,d)==0){
      continue;
    }
    mp[x][y] = 1;
    chmax(res, 1 - solve(X2, Y2, x, y));
    mp[x][y] = 0;
  }
  if(res==-1073709056){
    for(d=(0);d<(4);d++){
      x = X2;
      y = Y2;
      if(go(x,y,d)){
        break;
      }
    }
    if(d==4){
      return 0;
    }
    chmax(res, -solve(X2, Y2, X1, Y1));
  }
  return res;
}
int main(){
  int cTE1_r3A = rd_int();
  for(TEST=(0);TEST<(cTE1_r3A);TEST++){
    int ao_dF3pO, i;
    int res;
    wt_L("Case #");
    wt_L(TEST+1);
    wt_L(": ");
    rd(S);
    rd(X1);X1 += (-1);
    rd(Y1);Y1 += (-1);
    rd(X2);X2 += (-1);
    rd(Y2);Y2 += (-1);
    rd(C);
    for(i=(0);i<(S);i++){
      int j;
      for(j=(0);j<(2*S);j++){
        mp[i][j] = 0;
      }
    }
    for(ao_dF3pO=(0);ao_dF3pO<(C);ao_dF3pO++){
      rd(X);X += (-1);
      rd(Y);Y += (-1);
      mp[X][Y] = 1;
    }
    mp[X1][Y1] = mp[X2][Y2] = 1;
    res = solve(X1, Y1, X2, Y2);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// int TEST;
// 
// int S, C, mp[6][12];
// int X1, Y1, X2, Y2, X, Y;
// 
// int go(int &x, int &y, int d){
//   if(d==0){
//     if(y%2==1) x--, y--, return 1 - mp[x][y];
//     return 0;
//   }
//   if(d==1){
//     if(x+1 < S && y%2==0) x++, y++, return 1 - mp[x][y];
//     return 0;
//   }
//   if(d==2){
//     if(y != 0) y--, return 1 - mp[x][y];
//     return 0;
//   }
//   if(d==3){
//     if(y != 2*x) y++, return 1 - mp[x][y];
//     return 0;
//   }
//   return 0;
// }
// 
// 
// int solve(int X1, int Y1, int X2, int Y2){
//   int res = -int_inf;
//   int x, y;
// 
//   rep(d,4){
//     x = X1, y = Y1;
//     if(go(x,y,d)==0) continue;
//     mp[x][y] = 1;
//     res >?= 1 - solve(X2, Y2, x, y);
//     mp[x][y] = 0;
//   }
// 
//   if(res==-int_inf){
//     rep(d,4){
//       x = X2, y = Y2;
//       if(go(x,y,d)) break;
//     }
//     if(d==4) return 0;
//     res >?= -solve(X2, Y2, X1, Y1);
//   }
// 
//   return res;
// }
// 
// 
// {
//   REP(TEST,rd_int()){
//     int res;
//     wtF("Case #{TEST+1}: ");
//     rd(S, X1--, Y1--, X2--, Y2--, C);
//     rep(i,S) rep(j,2*S) mp[i][j] = 0;
//     rep(C){
//       rd(X--, Y--);
//       mp[X][Y] = 1;
//     }
//     mp[X1][Y1] = mp[X2][Y2] = 1;
//     res = solve(X1, Y1, X2, Y2);
//     wt(res);
//   }
// }