#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N=1005;
int n,tot,c[105*26][26],fl[105*26],rl[105],id[105*26];
char s[105],a[N][N];
void ins(char a[],int x,int p=0){
  for(int i=0;a[i];i++){
    int t=a[i]-'a';
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  if(id[p])rl[x]=id[p];
  else id[p]=x;
}
void fail(){
  queue<int>q;
  for(int i=0;i<26;i++)if(c[0][i])q.push(c[0][i]);
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=0;i<26;i++)
      if(c[u][i])fl[c[u][i]]=c[fl[u]][i],q.push(fl[c[u][i]]);
      else c[u][i]=c[fl[u]][i];
  }
}
void qry(char s[],int p=0){
  for(int i=0;s[i];i++)
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%s",a[i]);
  scanf("%d%d",&x,&y);
  for(int i=1;i<=x;i++)scanf("%s",s),rl[i]=i,ins(s,i);
  fail();
  return 0;
}
