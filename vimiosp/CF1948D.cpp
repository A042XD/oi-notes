#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e3+5;
int q,pi[N];
char s[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  q=read();
  while(q--){
    scanf("%s",s);int ans=0,m=strlen(s);
    for(int l=0;l<m;l++){
      for(int i=l+1,j=0;s[i];i++){
        while(j&&((s[i]!='?'&&s[j+l]!='?'&&s[i]!=s[j+l])||j*2>i-l))j=pi[j-1+l];
        j+=(s[i]=='?'||s[j+l]=='?'||s[i]==s[j+l]),pi[i]=j;
      }
      for(int i=l+1;s[i];i++)
        if(pi[i]*2==i-l+1)ans=max(ans,i-l+1);
      for(int i=0;s[i];i++)printf("%d ",pi[i]),pi[i]=0;
      puts("");
    }
    printf("%d\n",ans);
  }
  return 0;
}