#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e6+5;
int t[35],ans;
char s[N];

signed main(){
  scanf("%s",s+1);int n=strlen(s+1);
  ans=n*(n-1)/2;
  for(int i=1;s[i];i++)t[s[i]-'a']++;
  for(int i=0;i<26;i++)ans-=t[i]*(t[i]-1)/2;
  for(int i=0;i<26;i++)if(t[i]>1){ans++;break;}
  cout<<ans;
  return 0;
}