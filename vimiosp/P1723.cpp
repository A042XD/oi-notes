#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=2e7+5;
int q,p[N],m;
char s[N],t[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  q=read();
  while(q--){
    scanf("%s",s),t[0]='!',t[m=1]='#';int ans=0;
    for(int i=0;s[i];i++)t[++m]=s[i],t[++m]='#';t[++m]='@';
    for(int i=1,r=0,d=0;t[i];i++){
      if(i>r)p[i]=1;
      else p[i]=min(r-i+1,p[2*d-i]);
      while(t[i+p[i]]==t[i-p[i]])p[i]++;
      if(i+p[i]-1>r)r=i+p[i]-1,d=i;
      ans=max(ans,p[i]-1);
    }
    printf("%d\n",ans);
    for(int i=0;i<=m+1;i++)t[i]=p[i]=0;
  }
  return 0;
}