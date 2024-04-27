#include<iostream>
#include<algorithm>

using namespace std;
long long n,a[4];

int main (int argc, char *argv[]) {
  scanf("%lld",&n);
  a[0]=n,a[1]=n-1,a[2]=n-2,a[3]=n-3;
  for(int i=0;i<4;i++)
    if(a[i]%4==0){a[i]/=4;break;}
  for(int i=0;i<4;i++)
    if(a[i]%3==0){a[i]/=3;break;}
  for(int i=0;i<4;i++)
    if(a[i]%2==0){a[i]/=2;break;}
  printf("%lld",a[0]*a[1]*a[2]*a[3]);
  return 0;
}
