#include<iostream>
#include<algorithm>
#define pair<int,int> pii

using namespace std;
const int N=1e5+5;
int n,d,r=1,v[N];
pii a[N];

int main(){
  scanf("%d%d",&n,&d);
  for(int i=1;i<n;i++)scanf("%d",&v[i]);
  for(int i=1;i<=n;i++)scanf("%d",&a[i].first),a[i].second=i;
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    
  }
  return 0;
}
