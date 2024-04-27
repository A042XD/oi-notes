#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;
const int N=2e5+5;
int n,tot=1,lst=1,lk[N],ln[N];
map<int,int>c[N];long long ans;
void ins(int x){
  int r=++tot,p=lst;ln[r]=ln[p]+1;
  while(p&&!c[p][x])c[p][x]=r,p=lk[p];
  if(!p)return lk[lst=r]=1,void();int q=c[p][x];
  if(ln[p]+1==ln[q])return lk[lst=r]=q,void();
  int nw=++tot;ln[nw]=ln[p]+1,lk[nw]=lk[q];
  c[nw]=c[q];
  while(p&&c[p][x]==q)c[p][x]=nw,p=lk[p];
  lk[lst=r]=lk[q]=nw;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    ins(read()),ans+=ln[lst]-ln[lk[lst]];
    printf("%lld\n",ans);
  }
  return 0;
}