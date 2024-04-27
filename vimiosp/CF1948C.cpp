#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=2e5+5;
int n,t,dp[2][N];
bool m[2][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();
    for(int i=0;i<2;i++)
      for(int j=1;j<=n;j++){
        char c;
        cin>>c;
        if(c=='>')m[i][j]=1;
        else m[i][j]=0;
        dp[i][j]=0;
      }
    dp[0][1]=1;
    for(int i=1;i<=n;i++){
      if(i<n-1){
        dp[0][i+2]|=m[0][i+1]&&dp[0][i];
        dp[1][i+2]|=m[1][i+1]&&dp[1][i];
      } 
      if(i<n){
        dp[1][i+1]|=m[1][i]&&dp[0][i];
        dp[0][i+1]|=m[0][i]&&dp[1][i];
      }
    }
    puts(dp[1][n]?"YES":"NO");
  }  
  return 0;
}