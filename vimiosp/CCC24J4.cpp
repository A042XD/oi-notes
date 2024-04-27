#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>

using namespace std;
string a,b;
bool c[144],d[144];

signed main(){
  cin>>a>>b;
  for(int i=0;a[i];i++)c[a[i]]=1;
  for(int i=0;b[i];i++)d[b[i]]=1;
  if(a.size()!=b.size()){
    for(int x='a';x<26+'a';x++)
      for(int y='a';y<26+'a';y++)
        if(x!=y&&c[x]&&c[y]&&!d[y]){
          //printf(" %c %c\n",x,y);
          bool k=0;
          for(int i=1;a[i];i++)
            if(a[i]==x&&a[i-1]==y||a[i]==y&&a[i-1]==x)k=1;
          if(k)continue;

          int cx=0,f=0;char dx=0;
          for(int i=0;a[i];i++){
            if(a[i]==y){cx++;continue;}
            if(i>=cx&&a[i]==x){
              if(dx==0)dx=b[i-cx];
              if(b[i-cx]!=dx){f=1;break;}
            }
            else if(a[i]!=b[i-cx]){f=1;break;}
          }
          if(a.size()-b.size()!=cx)f=1;
          if(f==0){
            printf("%c %c\n%c",x,dx,y);
            exit(0);
          }
        }
  }
  else{
    char x,y;
    for(int i=0;a[i];i++)
      if(a[i]!=b[i]){
        x=a[i],y=b[i];
        break;
      }
    printf("%c %c\n-",x,y);
  }
  return 0;
}