#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int t,n,m;
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
    n=read(),m=read();scanf("%s",s);
    int q=0;
    while(s[q]&&s[q]!='1')q++;
    if(q==m&&m<n){
      puts("Yes");
      continue;
    }
    int j=-1,f=0,p=0;
    for(int i=q+1;s[i];i++){
      if(s[i]=='0')p++;
      if(s[i]=='1'){
        if(j==-1)j=p;
        else if(j!=p)f=1;
        p=0;
      }
    }
    if(q>=n||p>=n)puts("No");
    else if(j!=-1&&j<n&&q<=j&&p<=j)puts("Yes");
    else if(j==-1&&q<n&&p<n)puts("Yes");
    else puts("No");
  }
  return 0;
}