#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=55;
int t,n,m;
char c[N][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read();
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++){
      for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
          if(c[i][j]=='*'){
            if(i<n&&c[i+1][j]=='.')swap(c[i][j],c[i+1][j]);
          }
    }
    for(int i=1;i<=n;i++,puts(""))
      for(int j=1;j<=m;j++)
        printf("%c",c[i][j]);
    puts("");
  }
  return 0;
}