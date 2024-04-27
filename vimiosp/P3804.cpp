#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e6+5,S=1e6+5,M=3e6+5;
int n,c[N][26],lst=1,tot=1,lk[N],ln[N],ct[N];
char s[S];long long ans;
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void ins(int x){
  int r=++tot,p=lst;ln[r]=ln[p]+1,ct[r]=1;
  while(p&&!c[p][x])c[p][x]=r,p=lk[p];
  if(!p)return lk[lst=r]=1,void();int q=c[p][x];
  if(ln[p]+1==ln[q])return lk[lst=r]=q,void();
  int nw=++tot;ln[nw]=ln[p]+1,lk[nw]=lk[q];
  for(int i=0;i<26;i++)c[nw][i]=c[q][i];
  while(p&&c[p][x]==q)c[p][x]=nw,p=lk[p];
  lk[lst=r]=lk[q]=nw;
}
void bld(){for(int i=2;i<=tot;i++)g.add(lk[i],i);}
void dfs(int x){
  for(int i=g.hd[x];i;i=g.nx[i])dfs(g.to[i]),ct[x]+=ct[g.to[i]];
  if(ct[x]>1)ans=max(ans,(long long)ct[x]*ln[x]);
}

signed main(){
  scanf("%s",s+1);
  for(int i=1;s[i];i++)ins(s[i]-'a');
  bld(),dfs(1);printf("%lld",ans);
  return 0;
}