#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=8005;
int q,n,a[N],b[N],t[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  q=read();
  while(q--){
    n=read();
    for(int i=1;i<=n;i++)b[a[i]=read()]++;
    for(int i=2;i<=n;i++){
      int sum=0;
      for(int j=1;j<i;j++)sum+=a[j];
      for(int j=1;j<=n-i+1;j++){
        sum-=a[j-1],sum+=a[j+i-1];
        if(sum<=8000)t[sum]=1;
      }
    }
    int ans=0;
    for(int i=1;i<=8000;i++)if(t[i])ans+=b[i];
    printf("%d\n",ans);
    for(int i=1;i<=8000;i++)t[i]=b[i]=a[i]=0;
  }
  return 0;
}