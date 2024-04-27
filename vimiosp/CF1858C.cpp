#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e5+5;
int t,n,a[N];
bool v[N];

int main(){
  scanf("%d",&t);
  while(t--){ 
    for(int i=1;i<=n;i++)v[i]=0;
    scanf("%d",&n);a[1]=1;int cnt=1;
    for(int i=2;i<=n;i++){
      int k=i;
      if(!v[k])
        while(k<=n)a[++cnt]=k,v[k]=1,k+=k;
    }
    for(int i=1;i<=cnt;i++)printf("%d ",a[i]);
    puts("");
  }
  return 0;
}
