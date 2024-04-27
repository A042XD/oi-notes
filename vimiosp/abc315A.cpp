#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
char s[N];

int main(){
  scanf("%s", s);
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
      printf("%c", s[i]);
  return 0;
}
