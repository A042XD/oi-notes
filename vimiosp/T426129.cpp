#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

signed main(){
  int a,b,c,ans=0;
  scanf("%d%d%d",&a,&b,&c);
  if(a>b+c)ans++;
  if(b>a+c)ans++;
  if(c>a+b)ans++;
  printf("%d",ans);
  return 0;
}