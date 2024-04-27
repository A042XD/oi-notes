#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long

using namespace std;
const int N=1e6+5,p=1e9+7;
int n,pi[N],r[N],v[N];
char a[N];

signed main(){
  scanf("%lld",&n);
  while(n--){
    scanf("%s",a);int ans=1;
    for(int i=1,j=0;a[i];i++){
      while(j&&(a[i]!=a[j]))j=r[j-1];
      j+=(a[i]==a[j]),r[i]=j;
    }
    for(int i=1,j=0;a[i];i++){
      while(j&&(a[i]!=a[j]||j>=(i+1)/2))j=r[j-1];
      j+=(a[i]==a[j]),pi[i]=j;
    } 
    v[0]=1;
    for(int i=1;a[i];i++)v[i]=1+v[r[i]-1];
    for(int i=1;a[i];i++)ans=ans*(1+v[pi[i]-1])%p;
    printf("%lld\n",ans);
  }
  return 0;
}
