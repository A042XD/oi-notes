#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int C=1e5+5;
int t,n,m,q;
struct _p{int x,y;}p1[C],p2[C];
bool cmp1(_p a,_p b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp2(_p a,_p b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int gt(int y,int x){
  int rt=(x==1)+(x==m)+(y==1)+(y==n),l,r;

  // 同列
  l=1,r=q;
  while(l<r){
    int mid=(l+r+1)/2;
    if(p1[mid].x<=x)l=mid;
    else r=mid-1;
  }
  if(p1[l].x==x){
    if(p1[l].y>y)rt+=p1[l].y==y+1;
    else{
      r=q;
      while(l<r){
        int mid=(l+r+1)/2;
        if(p1[mid].x!=x)r=mid-1;
        else if(p1[mid].y>y)r=mid-1;
        else l=mid;
      } 
      rt+=(p1[l+1].x==x&&p1[l+1].y==y+1);
      if(p1[l].x==x&&p1[l].y==y)rt+=(p1[l-1].x==x&&p1[l-1].y==y-1);
      else rt+=(p1[l].x==x&&p1[l].y==y-1);
    }
  }

  // 同行


  return rt;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read(),q=read();
    for(int i=1;i<=q;i++)p1[i].x=p2[i].x=read(),p1[i].y=p2[i].y=read();
    sort(p1+1,p1+q+1,cmp1);
    sort(p2+1,p2+q+1,cmp2);
    int ans=4;
    
    /*puts("DEBUG");
    for(int i=1;i<=n;i++,puts(""))
      for(int j=1;j<=m;j++)
        printf("%d ",gt(i,j));
    puts("");*/

    for(int i=1;i<=q;i++){
      if(p1[i].y>1)ans=min(ans,4-gt(p1[i].y-1,p1[i].x));
      if(p1[i].y<n)ans=min(ans,4-gt(p1[i].y+1,p1[i].x));
      if(p1[i].x>1)ans=min(ans,4-gt(p1[i].y,p1[i].x-1));
      if(p1[i].x<m)ans=min(ans,4-gt(p1[i].y,p1[i].x+1));
    }
    printf("%d\n",ans);
  }
  return 0;
}