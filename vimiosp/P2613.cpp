#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int p=19260817;
int a,b;
void exgcd(int a,int b,int&x,int&y,int&d){
  if(!b)x=1,y=0,d=a;
  else exgcd(b,a%b,y,x,d),y=y-a/b*x;
}
int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x*10+c-48)%p;c=getchar();}
  return x*f;
}

signed main(){
  int x,y,d;
  a=read(),b=read();
  if(b%p==0&&a%p!=0)return puts("Angry!");
  if(a%p==0)return puts("0");
  exgcd(b,p,x,y,d);
  printf("%lld",(x%p+p)%p);
  return 0;
}
