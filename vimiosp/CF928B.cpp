#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=15;
char s[N][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int t=read();
  while(t--){
    int n=read();
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    bool f=0;
    for(int i=1;i<n-1;i++)
      for(int j=1;j<n-1;j++)
        if(s[i][j]=='1'&&s[i][j-1]=='0')f|=(s[i+1][j-1]=='1'||s[i-1][j-1]=='1');
        else if(s[i][j]=='1'&&s[i][j+1]=='0')f|=(s[i+1][j+1]=='1'||s[i-1][j+1]=='1');
    puts(f?"TRIANGLE":"SQUARE");
  }  
  return 0;
}