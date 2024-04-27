#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int N=1e5+5;
int n,m,a[N],t1[N],t2[N];
void upd(int x,int v){for(int r=x;x<=n;x+=x&-x)t1[x]+=v,t2[x]+=r*v;}
int qry(int x){int r=x,c=0;for(;x;x-=x&-x)c+=(r+1)*t1[x]-t2[x];return c;}

signed main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=1,p,l,r,d,k;i<=m;i++){
    scanf("%lld%lld",&p,&l);
    if(p==1){
      scanf("%lld%lld%lld",&r,&k,&d);int o=r-l+1;
      upd(l,k),upd(l+1,d-k),upd(r+1,-(r-l+1)*d-k),upd(r+2,(r-l)*d+k);
    }
    else printf("%lld\n",qry(l)+a[l]);
  }
  return 0;
}
