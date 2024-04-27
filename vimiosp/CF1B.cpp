#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int t,p[105];
char s[105];
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*a;
    a=a*a,k/=2;
  }
  return r;
}
int gt(int a){
  int ans=0;
  for(int i=0;i<a;i++)
    ans=ans*26+s[i]-'A'+1;
  return ans;
}
void out(int x){
  int i=0;
  for(;x;x=x/26-!(x%26)){
    if(x%26)p[++i]=x%26;
    else p[++i]=26;
  }
  for(;i;i--)printf("%c",char(p[i]+'A'-1));
}

int main (int argc, char *argv[]) {
  cin>>t;
  while(t--){
    cin>>s;int i=0,a=0,b=0,d=0;
    while(s[i]>='A'&&s[i]<='Z')a++,i++;
    while(s[i]>='0'&&s[i]<='9')b=b*10+s[i]-48,i++;
    if(s[i]=='C'){
      i++;
      while(s[i]>='0'&&s[i]<='9')d=d*10+s[i]-48,i++;
      out(d);printf("%d\n",b);
    }
    else printf("R%dC%d\n",b,gt(a));
  }
  return 0;
}
