#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

signed main(){
  struct _timeb T;
  _ftime(&T);
  srand(T.millitm);
  
  freopen("in.txt","w",stdout);
  int a=rand()%20+1,b=rand()%a+1;
  printf("1\n%d %d\n",a,b);
  for(int i=1;i<=a;i++)printf("%d",rand()%2);
  puts("");
  return 0;
}