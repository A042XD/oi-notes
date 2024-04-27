#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=105;
int n,m,ans,dx[15]={1,0,-1,0,1,1,-1,-1},dy[15]={0,1,0,-1,1,-1,-1,1},
tr[2][15]={{1,0,1,0,5,4,5,4},{3,2,3,2,7,6,7,6}};
char s[N],p[N][N];
bool c(int y,int x,int d,int t){
  bool f=1;
  for(int i=d;s[i];i++){
    if(x>m||y>n||x<1||y<1)f=0;
    if(!f||p[y][x]!=s[i]){
      f=0;
      break;
    }
    x+=dx[t],y+=dy[t];
  }
  return f;
}
int chk(int y,int x,int t){
  int f=1,ans=0;
  for(int i=0;s[i];i++){
    if(x>m||y>n||x<1||y<1)f=0;
    if(!f||p[y][x]!=s[i]){
      f=0;
      break;
    }
    if(i>0&&s[i+1])ans+=c(y,x,i,tr[0][t])+c(y,x,i,tr[1][t]);
    x+=dx[t],y+=dy[t];
  }
  return f+ans;
}

signed main(){
  scanf("%s%d%d",s,&n,&m);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>p[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      for(int k=0;k<8;k++)ans+=chk(i,j,k);
  printf("%d",ans);
  return 0;
}