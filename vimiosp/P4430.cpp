#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N=1e6+5,p=9999991;
int n;
int pow(int x,int k){
  int c=1;x%=p;
  while(k){
    if(k&1)c=c*x%p;
    x=x*x%p,k/=2;
  }return c%p;
}

signed main(){
  scanf("%lld",&n);int a=1;
  for(int i=1;i<n;i++)a=a*i%p;
  printf("%d",a*pow(n,n-2)%p);
  return 0;
}
