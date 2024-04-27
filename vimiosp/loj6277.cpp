#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e4+5,B=305;
int a[N],b[N],len,n,s[B];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
void add(int x,int y,int v){
  if(b[x]==b[y]){
    for(int i=x;i<=y;i++)a[i]+=v;
    return;
  }
  for(int i=x;b[i]==b[x];i++)a[i]+=v;
  for(int i=y;b[i]==b[y];i--)a[i]+=v;
  for(int i=b[x]+1;i<b[y];i++)s[i]+=v;
}
int qry(int x){return a[x]+s[b[x]];}

signed main(){
  n=read(),len=sqrt(n);
  for(int i=1;i<=n;i++)a[i]=read(),b[i]=(i-1)/len+1;
  for(int i=1;i<=n;i++){
    int op=read(),x=read(),y=read(),z=read();
    if(!op)add(x,y,z);
    else printf("%d\n",qry(y));
  }
  return 0;
}