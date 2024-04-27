#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e5+5;
int lst=1,tot=1,c[N][26],ans[N],fl[N],ln[N];
char s[N];

signed main(){
  scanf("%s",s+1);
  s[0]='#',ln[1]=-1,fl[0]=1;
  for(int i=1;s[i];i++){
    if(i>1)s[i]=char((s[i]-97+ans[lst])%26+97);
    while(s[i]!=s[i-ln[lst]-1])lst=fl[lst];
    if(!c[lst][s[i]-'a']){
      int j=fl[lst];ln[++tot]=ln[lst]+2;
      while(s[i]!=s[i-ln[j]-1])j=fl[j];
      fl[tot]=c[j][s[i]-'a'],c[lst][s[i]-'a']=tot;
      ans[tot]=ans[fl[tot]]+1;
    }
    lst=c[lst][s[i]-'a'];
    printf("%d ",ans[lst]);
  }
  return 0;
}