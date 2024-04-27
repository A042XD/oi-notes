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
const int N=3e6+5;
int n,k,a[N],fa[N],w[N],s[N],tp;
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))fa[x]=y;}
priority_queue<pii,vector<pii>,greater<pii>>q1;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),k=read();
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=n;i++)a[i]=read();

  for(int i=1;i<=k;i++)w[i]=a[i],q1.push(make_pair(w[i],i));
  for(int i=k+1;i<=n;i++){
    s[tp=1]=q1.top().second;q1.pop();
    while(q1.size()&&q1.top().first==w[s[1]])
      s[++tp]=q1.top().second,q1.pop();
    for(int j=2;j<=tp;j++)mrg(s[j],s[j-1]);
    while(tp&&i<=n)
      q1.push(make_pair(w[s[tp]]=w[s[tp]]+a[i],s[tp])),i++,tp--;
    i--;
  }
  while(tp)q1.push(make_pair(w[s[tp]],s[tp])),tp--;

  int rt=q1.top().first,tmp=q1.top().second;
  printf("%lld\n",rt);
  for(int i=1;i<=k;i++)if(w[i]==rt)mrg(i,tmp);
  for(int i=1;i<=k;i++)
    if(fd(i)==fd(tmp))printf("1");
    else printf("0");
  return 0;
}