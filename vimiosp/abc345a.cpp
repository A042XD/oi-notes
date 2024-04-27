#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>

using namespace std;
string a;

signed main(){
  cin>>a;
  bool f=0;
  f|=(a[0]!='<');
  int i;
  for(i=1;a[i+1];i++)
    f|=(a[i]!='=');
  f|=(a[i]!='>');
  puts(f?"No":"Yes");
  return 0;
}