#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=0;
int t,n,k;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),k=read();
    if(n&1){
      if(k%2==0){
        puts("NO");
        continue;
      }
      if(n<k){
        puts("NO");
        continue;
      }
      puts("YES");
      for(int i=1;i<k;i++)printf("1 ");
      printf("%lld\n",n-k+1);
    }
    else{
      if(k&1){
        if(k*2>n){
          puts("NO");
          continue;
        }
        puts("YES");
        for(int i=1;i<k;i++)printf("2 ");
        printf("%lld\n",n-(k-1)*2);
      }
      else{
        if(k>n){
          puts("NO");
          continue;
        }
        puts("YES");
        for(int i=1;i<k;i++)printf("1 ");
        printf("%lld\n",n-k+1);
      }
    }
  }
  return 0;
}