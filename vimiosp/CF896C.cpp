#include<iostream>
#include<set>

using namespace std;
const int p=1e9+7,N=1e5+5;
int n,m,seed,vmax,a[N];
struct nd{
  int l,r;mutable int v;
  nd(int l,int r=0,int v=0):l(l),r(r),v(v){}
  bool operator<(const nd &a)const{return l<a.l;}
};
set<nd>s;
set<nd>::iterator split(int x){
  set<nd>::iterator it=s.lower_bound(nd(x));
  if(it!=s.end()&&it->l==pos)return it;
  it--;
  if(it->r<x)return s.end();
  int l=it->l,r=it->r,v=it->v;
  s.erase(it);s.insert(nd(l,x-1,v));
  return s.insert(nd(x,r,v)).first;
}
void add(int l,int r,int x){
  set<nd>::iterator itr=split(r+1),itl=split(l);
  for(set<nd>::iterator it=itl;it!=itr;it++)it->v+=x;
}
void assign(int l,int r,int x){
  set<nd>::iterator itr=split(r+1),itl=split(l);
  s.erase(itl,itr);s.insert(nd(l,r,x));
}


signed main(){
  scanf("%lld%lld%lld%lld",&n,&m,&seed,&vmax);
  return 0;
}
