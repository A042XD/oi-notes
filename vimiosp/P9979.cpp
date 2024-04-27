#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e5+5,d=1e5+5;
int n,m,pos,res,ans,Cnt[N],*cnt=Cnt+d,X[N],*x=X+d;
char c[N];

void gt(){
  pos=res=0;
  memset(Cnt,0,sizeof(Cnt));
  for(int i=1;i<=m;i++)
    if(c[i]=='L')pos--;
    else if(c[i]=='R')pos++;
    else if(++cnt[pos]==1&&x[pos])res++;
  ans=max(ans,res);
}
void ltor(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++,ans=max(ans,res);
    else if(c[i]=='R')pos--;
    else{
      if(!--cnt[pos]&&x[pos])res--;
      if(++cnt[pos+2]==1&&x[pos+2])res++;
    }
}
void ltof(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++,ans=max(ans,res+(!cnt[pos]&&x[pos]));
    else if(c[i]=='R')pos--;
    else{
      if(!--cnt[pos]&&x[pos])res--;
      if(++cnt[pos+1]==1&&x[pos+1])res++;
    }
}
void rtol(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++;
    else if(c[i]=='R')pos--,ans=max(ans,res);
    else{
      if(!--cnt[pos]&&x[pos])res--;
      if(++cnt[pos-2]==1&&x[pos-2])res++;
    }
}
void rtof(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++;
    else if(c[i]=='R')pos--,ans=max(ans,res+(!cnt[pos]&&x[pos]));
    else{
      if(!--cnt[pos]&&x[pos])res--;
      if(++cnt[pos-1]==1&&x[pos-1])res++;
    }
}
void ftol(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++;
    else if(c[i]=='R')pos--;
    else{
      if(!--cnt[pos]&&x[pos])res--;
      ans=max(ans,res);
      if(++cnt[pos-1]==1&&x[pos-1])res++;
    }
}
void ftor(){
  gt();
  for(int i=m;i;i--)
    if(c[i]=='L')pos++;
    else if(c[i]=='R')pos--;
    else{
      if(!--cnt[pos]&&x[pos])res--;
      ans=max(ans,res);
      if(++cnt[pos+1]==1&&x[pos+1])res++;
    }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,a;i<=m;i++)scanf("%d",&a),x[a]=1;
  scanf("%s",c+1);
  gt();
  ltor();
  ltof();
  rtol();
  rtof();
  ftol();
  ftor();
  printf("%d",ans);
  return 0;
}