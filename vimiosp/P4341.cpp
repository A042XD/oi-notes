#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e3+5,D=9e6+5;
int n,tot,c[D][2],r[D];
char s[N];
void ins(int x,int p=0){
  for(int i=x;s[i];i++){
    int t=s[i]-'0';
    if(!c[p][t])c[p][t]=++tot;
    r[p=c[p][t]]++;
  }
}
void dfs(int p){
  if(r[p]>1)printf("%d\n",r[p]);
  if(c[p][0])dfs(c[p][0]);
  if(c[p][1])dfs(c[p][1]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),scanf("%s",s+1);
  for(int i=1;i<=n;i++)ins(i);
  dfs(0);
  return 0;
}