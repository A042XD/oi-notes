#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e6+5;
string a,b;
int n,m,pi[N];

signed main(){
  cin>>a>>b;m=b.size();
  string c=b+'#'+a;
  for(int i=1,j=0;c[i];i++){
    while(j&&c[i]!=c[j])j=pi[j-1];
    j+=(c[i]==c[j]);pi[i]=j;
    if(pi[i]==m)printf("%d\n",i-2*m+1);
  }
  printf("0 ");
  for(int i=1,j=0;b[i];i++){
    while(j&&b[i]!=b[j])j=pi[j-1];
    j+=(b[i]==b[j]);pi[i]=j;
    printf("%d ",pi[i]);
  }
  return 0;
}