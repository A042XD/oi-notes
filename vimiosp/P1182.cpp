#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int N=1e5+5;
int n,m,a[N],p;
bool c(int x){
  int ans=1,t=0;
  for(int i=1;i<=n;i++){
    if(a[i]>x)return 0;
    if(t+a[i]>x)ans++,t=a[i];
    else t+=a[i];
  }
  return ans<=m;
}

signed main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]),p+=a[i];
  int l=1,r=1e9;
  while(l<r){
    int mid=(l+r)/2;
    if(c(mid))r=mid;
    else l=mid+1;
  }
  printf("%lld",l);
  return 0;
}
