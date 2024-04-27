#include<iostream>
#include<algorithm>

using namespace std;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
void exgcd(int a,int b,int &x,int &y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int inv(int a,int b){
  int x,y;
  exgcd(a,b,x,y);
  return (x%b+b)%b;
}

int main(){
  int a,b,c,d,i=0;
  cin>>a>>b>>c>>d;
  while(a+b+c+d!=-4){
    i++;
    int p=23*28*33;
    int a1=a*p/23*inv(p/23,23);
    int a2=b*p/28*inv(p/28,28);
    int a3=c*p/33*inv(p/33,33);
    int x=(a1+a2+a3-d+p)%p;
    if(x==0)x=21252;
    printf("Case %d: the next triple peak occurs in %d days.\n",i,x);
    cin>>a>>b>>c>>d;
  }
  return 0;
}
