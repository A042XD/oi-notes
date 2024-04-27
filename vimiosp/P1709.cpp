#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e6+5;
int n,ans;
char s[N];
int ms(){
  int i=0,j=1,k=0;
  while(i<=n&&j<=n&&k<=n)
    if(s[(i+k)%n]==s[(j+k)%n])k++;
    else{
      if(s[(i+k)%n]<s[(j+k)%n])j+=k+1;
      else i+=k+1;
      if(i==j)i++;
      k=0;
    }
  return min(i,j);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=0;i<n;i++)cin>>s[i];
  int ans=ms();
  printf("%d",ans);
  return 0;
}