#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int t,n;
char c[55];
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
    scanf("%s",c);
    int ans=0;
    for(int i=0;c[i];i++){
      if(c[i]=='@')ans++;
      if(c[i]=='*')break;
      if(c[i+1]=='*')i++;
    }
    printf("%d\n",ans);
  }  
  return 0;
}