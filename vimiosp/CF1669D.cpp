#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5;
int t,n;
char s[N];
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
    scanf("%s",s+1);
    bool f=1;
    for(int i=1;i<=n;i++){
      while(s[i]=='W')i++;
      if(!s[i])break;
      char c=s[i];
      bool k=1;
      while(s[i]&&s[i]!='W'){
        if(s[i]!=c)k=0;
        i++;
      } 
      if(k)f=0;
    }
    puts(f?"YES":"NO");
  }
  return 0;
}