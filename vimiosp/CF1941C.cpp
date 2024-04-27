#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e6+5;
int t,n;
string a;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();
    cin>>a;int ans=0;
    for(int i=0;i<n;i++){
      if(i<=n-3){
        string b=a.substr(i,3);
        if(b=="map"||b=="pie")ans++,i+=2;
      }
      if(i<=n-5){
        string b=a.substr(i,5);
        if(b=="mapie")ans++,i+=4;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}