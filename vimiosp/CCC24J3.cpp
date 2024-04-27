#include<iostream>
#include<algorithm>

using namespace std;
const int N=2.5e5+5;
int n,a[N],b[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=b[i]=read();
  sort(a+1,a+n+1,greater<>());
  int m=unique(a+1,a+n+1)-a-1,ans=0;
  for(int i=1;i<=n;i++)ans+=(a[3]==b[i]);
  printf("%d %d",a[3],ans);
  return 0;
}