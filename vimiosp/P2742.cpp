#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 5;
int n, tp, ans, s[N];
struct vc{double x, y;}p[N];
double sq(double a){return a * a;}
double dis(vc a, vc b){return sqrt(sq(b.x - a.x) + sq(b.y - a.y));}
double crs(vc a, vc b){return a.x * b.y - a.y * b.x;}
double gtrl(vc a, vc b, vc p){return crs({b.x - a.x, b.y - a.y}, {p.x - a.x, p.y - a.y});}

int adrw(int n){
  if (n < 3) return -1;
  sort(p + 1, p + n + 1, [](vc a, vc b){return a.x < b.x;}), s[++tp] = 1;
  for (int i = 2; i <= n; i++){
    while (tp > 2 && gtrl(p[s[tp - 1]], p[s[tp]], p[i]) <= 0) tp--;
    s[++tp] = i;
  }
  int tmp = tp; s[++tp] = n - 1;
  for (int i = n - 2; i >= 1; i--){
    while (tp > tmp && gtrl(p[s[tp - 1]], p[s[tp]], p[i]) <= 0) tp--;
    s[++tp] = i;
  }
  return tp;
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
  int sz = adrw(n);
  for (int i = 1; i < sz; i++) ans += dis(p[s[i]], p[s[i] + 1]);
  printf("%.2lf", ans + dis(p[s[sz]], p[s[1]]));
  return 0;
}
