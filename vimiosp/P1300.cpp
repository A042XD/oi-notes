#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;
const int N = 35;
int n, m, sx, sy, sd, ex, ey;
char mp[N][N];
int bfs(int x, int y, int d){
  priority_queue<pii>
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++){
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= m; j++)
      if (mp[i][j] == 'E') sx = j, sy = i, sd = 1;
      else if (mp[i][j] == 'W') sx = j, sy = i, sd = 2;
      else if (mp[i][j] == 'N') sx = j, sy = i, sd = 3;
      else if (mp[i][j] == 'S') sx = j, sy = i, sd = 4;
      else if (mp[i][j] == 'F') ex = j, ey = i;
  }
  
  return 0;
}
