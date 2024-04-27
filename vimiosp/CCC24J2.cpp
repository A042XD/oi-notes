#include<iostream>
#include<algorithm>

using namespace std;
int d,x;

int main(){
  scanf("%d",&d);
  bool f=1;
  while(cin>>x){
    if(x<d&&f)d+=x;
    if(x>=d)f=0;
  }
  printf("%d",d);
  return 0;
}