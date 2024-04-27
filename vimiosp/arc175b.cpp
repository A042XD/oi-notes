#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=2e6+5;
int n,a,b;
char s[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),a=read(),b=read();
  scanf("%s",s+1);
  int lm=0,d1=0,d2=0;
  for(int i=1;s[i];i++){
    if(s[i]=='('){
      lm++;
    }
    else{
      lm--;
      if(lm<0)lm=1,d1++;
    }
  }
  d2=lm/2;
  
  int ans=min(d1,d2)*min(a,2*b);
  ans+=(d1-min(d1,d2))*b;
  ans+=(d2-min(d1,d2))*b;
  printf("%lld",ans);
  return 0;
}