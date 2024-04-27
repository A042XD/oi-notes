#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
int a,b,x,y,d;
void exgcd(int a,int b,int&x,int&y,int&d){
  if(!b)x=1,y=0,d=a;
  else exgcd(b,a%b,y,x,d),y=y-a/b*x;
}

signed main(){
  scanf("%lld%lld",&a,&b);
  exgcd(a,b,x,y,d);
  printf("%lld",(x%b+b)%b);
  return 0;
}
