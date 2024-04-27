#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
int a,b;

signed main(){
  scanf("%lld%lld",&a,&b);
  printf("%lld",a*b-a-b);
  return 0;
}