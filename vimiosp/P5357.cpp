#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e5+5,S=2e6+5;
int n,c[N][26],tot,fl[N],r[N],ct[N],in[N];
char s[S];
void ins(char s[],int x,int p=0){
  for(int i=0;s[i];i++){
    int t=s[i]-'a';
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  r[x]=p;
}
void fail(){
  queue<int>q;
  for(int i=0;i<26;i++)if(c[0][i])q.push(c[0][i]);
  while(q.size()){
    int p=q.front();q.pop();
    for(int i=0;i<26;i++)
      if(c[p][i])fl[c[p][i]]=c[fl[p]][i],++in[fl[c[p][i]]],q.push(c[p][i]);
      else c[p][i]=c[fl[p]][i];
  }
}
void qry(char s[],int p=0){for(int i=0;s[i];i++)++ct[p=c[p][s[i]-'a']];}
void topo(){
  queue<int>q;
  for(int i=1;i<=tot;i++)if(!in[i])q.push(i);
  while(q.size()){
    int u=q.front();q.pop();
    ct[fl[u]]+=ct[u];
    if(!--in[fl[u]])q.push(fl[u]);
  }
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
    scanf("%s",s);
    ins(s,i);
  }
  fail();
  scanf("%s",s);
  qry(s);
  topo();
  for(int i=1;i<=n;i++)printf("%d\n",ct[r[i]]);
  return 0;
}