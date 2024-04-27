#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int t,n;
char a[N],b[N];
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
    scanf("%s%s",a,b);
    int ca=0,cb=0;
    for(int i=0;a[i];i++){
      if(a[i]=='0'&&b[i]=='1')ca++;
      if(a[i]=='1'&&b[i]=='0')cb++;
    }
    printf("%d\n",max(ca,cb));
  }  
  return 0;
}