#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+20;
int n,pi[N];
char s[N];
int main(){
  scanf("%d",&n);
  for(int b=1;b<=n;b++){
    scanf("%s",s);int l=0;
    for(int i=1,j=0;s[i];i++,l++){
      while(j&&s[i]!=s[j])j=pi[j-1];
      j+=(s[i]==s[j]),pi[i]=j;
    }
    if(!pi[l]){printf("Case %d: 0\n",b);continue;}
    int j=pi[l],ans=1;
    while(pi[j-1])ans++,j=pi[j-1];
    printf("Case %d: %d\n",b,ans);
  }
  return 0;
}
