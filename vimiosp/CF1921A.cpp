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
  int n;
  n=read();
  while(n--){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    if(x1!=x2)swap(x2,x3),swap(y2,y3);
    if(x1!=x2)swap(x2,x4),swap(y2,y4);
    printf("%d\n",abs(y2-y1)*abs(x3-x2));
  }
  return 0;
}