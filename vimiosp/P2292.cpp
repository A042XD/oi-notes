#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e2+1,M=2e6+1;
int n,m,son[N][26],fail[N],idx,len[N],now,sz,ans,q[N],last,u,max_len,tmp;
bool e[N],f[M];
char a[M];
inline void insert(char* s){
	now=0,sz=strlen(s);
	for(int i=0;i<sz;i++){
		if(!son[now][s[i]-'a'])
			son[now][s[i]-'a']=++idx,len[idx]=len[now]+1;
		now=son[now][s[i]-'a'];
	}
	e[now]=1;
}
void get_fail(){
	last=0,now=0;
	for(int i=0;i<26;i++)
		if(son[0][i])
			q[++last]=son[0][i];
	while(now<last){
		u=q[++now];
		for(int i=0;i<26;i++){
			if(son[u][i])
				fail[son[u][i]]=son[fail[u]][i],q[++last]=son[u][i];
			else
				son[u][i]=son[fail[u]][i];
		}
	}
}
int query(char* s)
{
	now=0,ans=0,f[0]=1,sz=strlen(s);
	for(int i=1;i<=sz;i++)
	{
		now=son[now][s[i-1]-'a'];
		if(ans+max_len<i)
			return ans;
		for(int j=now;j;j=fail[j])
			if(e[j]){ //e[now] 改成 e[j]
				f[i]|=f[i-len[j]]; // f[i-len[now]] 改成 f[i-len[j]]
				if(f[i])
					break;
			}
		if(f[i])
			ans=i;
	}
	return ans;
}
signed main(){
	scanf("%lld%lld",&n,&m);
   	for(int i=1;i<=n;i++)
    	scanf("%s",a),insert(a),tmp=strlen(a),max_len=max(max_len,tmp);
    get_fail();
    for(int i=1;i<=m;i++)
    	scanf("%s",a),memset(f,0,sizeof(f)),printf("%lld\n",query(a));
    return 0;
}
