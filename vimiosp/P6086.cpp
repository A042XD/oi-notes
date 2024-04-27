#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e6+6;
int n,m,f[N],p[N],d[N];long long ans;
void tp(){
  for(int i=1;i<n;i++)scanf("%d",&f[i]),++d[f[i]];
  for(int i=1,j=1;i<=n-2;i++,j++){
    while(d[j])j++;p[i]=f[j];
    while(i<=n-2&&!--d[p[i]]&&p[i]<j)p[i+1]=f[p[i]],i++;
  }
  for(int i=1;i<=n-2;i++)ans^=1ll*i*p[i];
}
void pt(){
  for(int i=1;i<=n-2;i++)scanf("%d",&p[i]),++d[p[i]];p[n-1]=n;
  for(int i=1,j=1;i<n;i++,j++){
    while(d[j])++j;f[j]=p[i];
    while(i<n&&!--d[p[i]]&&p[i]<j)f[p[i]]=p[i+1],i++;
  }
  for(int i=1;i<n;i++)ans^=1ll*i*f[i];
}

signed main(){
  scanf("%d%d",&n,&m);
  if(m==1)tp();
  else pt();
  printf("%lld",ans);
  return 0;
}