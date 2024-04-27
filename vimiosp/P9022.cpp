#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int x;
  bool f=1;
  while(cin>>x&&x!=99999){
    int t=x/10000+x%10000/1000;
    if(t==0)printf(f?"left":"right");
    else if(t&1)printf("left"),f=1;
    else printf("right"),f=0;
    printf(" %d\n",x%1000);
  }  
  return 0;
}