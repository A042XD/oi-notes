#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int t,n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();int ans=read();
    for(int i=2,x;i<=n;i++){
      x=read();
      if(x>ans)ans=x;
      else ans=x*(ans/x+1);
    }
    printf("%d\n",ans);
  }  
  return 0;
}