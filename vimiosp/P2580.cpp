#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e4+5;
int n,c[55*N][26],tot,lst[55*N];
char s[55];
void ins(char s[],int p=0){
  for(int i=0;s[i];i++){
    int t=s[i]-'a';
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  lst[p]=1;
}
int qry(char s[],int p=0){
  for(int i=0;s[i];i++){
    int t=s[i]-'a';
    if(!c[p][t])return 0;
    p=c[p][t];
  }
  return p;
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
    scanf("%s",s+1);
    ins(s+1);
  }
  int m=read();
  while(m--){
    scanf("%s",s+1);
    int ans=qry(s+1);
    if(!ans||!lst[ans])puts("WRONG");
    else if(lst[ans]==1)puts("OK"),lst[ans]++;
    else puts("REPEAT");
  }
  return 0;
}