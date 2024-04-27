#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int n,q,mc,c[N],mm[N],cg[N],lim[N];
bool mut[N],tr[N];
struct nd{
  int a,h;
  friend bool operator<(nd a,nd b){
    if(a.h!=b.h)return a.h<b.h;
    return a.a>b.a;
  }
}r[N];

signed main(){
  int t;
  cin>>t;
  while(t--){
    scanf("%d%d%d",&n,&q,&mc);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),mut[i]=(c[i]==0);
    for(int i=1;i<=q;i++)scanf("%d%d",&r[i].a,&r[i].h);
    sort(r+1,r+q+1);
    //for(int i=1;i<=q;i++,puts(""))printf("   %d %d",r[i].a,r[i].h);
    int p=1,mx=c[1];mm[1]=c[1];bool flag=0;
    int tl=0;
    for(int i=1;i<=q;i++){
      if(r[i].h==r[i-1].h)continue;
      if(r[i].a<tl){
        flag=1;
        break;
      }
      tr[r[i].a]=1;
      tl=max(tl,r[i].a);
    }
    
    p=1;
    for(int i=1;i<=n;i++)mm[i]=max(c[i],mm[i-1]);
    for(int i=1;i<=n;i++){
      if(r[p].h==i){
        int t=p+1;
        while(r[t].h==r[t-1].h)t++;
        if(c[i]==0){
          if(t<=q)c[i]=max(mm[r[t].a],mm[r[p].a]+1);
          else c[i]=mm[r[p].a]+1;
        }
        else{
          if(mm[i-1]>mm[r[p].a])flag=1;
        }
        p++; 
        while(r[p].h==r[p-1].h)p++;
      }
      else if(c[i]==0){
        if(r[p].a>=i)c[i]=max(1,mm[r[p].h-1]);
        else c[i]=1;
      }
      mm[i]=max(mm[i-1],c[i]);
    }

    int chk=0;
    for(int i=1;i<=n;i++)chk=max(chk,c[i]);
    if(flag||chk>mc)puts("-1");
    else{
      for(int i=1;i<=n;i++)printf("%d%c",c[i],(i==n?'\n':' '));
    }
    for(int i=1;i<=n;i++)c[i]=mm[i]=tr[i]=mut[i]=cg[i]=lim[i]=0;
    for(int i=1;i<=q;i++)r[i].a=r[i].h=0;
  }
  return 0;
}