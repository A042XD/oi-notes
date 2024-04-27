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
const int N=1e5+5,K=30;
int t,n,k,c[K][K],a[K],b[K];
char s[5];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();int ans=0;
    
    scanf("%s",s+1);
    c[s[1]-'a'][s[2]-'a']++;
    a[s[1]-'a']++,b[s[2]-'a']++;
    for(int i=2;i<=n;i++){
      scanf("%s",s+1);
      //printf("    %d %d %d\n",a[s[1]-'a'],b[s[2]-'a'],c[s[1]-'a'][s[2]-'a']);
      ans+=a[s[1]-'a']+b[s[2]-'a']-2*c[s[1]-'a'][s[2]-'a'];
      c[s[1]-'a'][s[2]-'a']++;
      a[s[1]-'a']++,b[s[2]-'a']++;
    }
    printf("%lld\n",ans);

    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
  }
  return 0;
}