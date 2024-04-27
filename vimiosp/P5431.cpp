#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e6 + 6;
int n, p, k;
int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}

int main(){
  n = read(), p = read(), k = read();
  
  return 0;
}
