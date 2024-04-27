#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>

using namespace std;
const int N=2e6+5;
int t,n,k,ml,mr,p[N],q[N],c[N],r[N],ans;
char s[N];
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
    scanf("%s",s+1),ml=mr=0,ans=2147483647;
    for(int i=1;s[i];i++)
      if(s[i]=='1'){
        mr=i;
        if(!ml)ml=i;
      }
    if(ml==mr&&ml==0){puts("0");continue;}
    for(int i=ml;i<=mr;i++)q[i]=q[i-1]+(s[i]=='1');
    for(int i=mr;i>=ml;i--)p[i]=p[i+1]+(s[i]=='1');
    for(int i=mr;i>=ml;i--){
      if(c[i+k])r[i]=r[i+k];
      else if(s[i]=='1')r[i]=i;
      c[i]=c[i+k]+(s[i]=='1');
    }
    for(int i=ml;i<=mr;i++)ans=min(ans,(r[i]-i)/k+1-2*c[i]+q[i-1]+p[i]);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)p[i]=q[i]=c[i]=r[i]=0;
  }  
  return 0;
}