#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define ll long long
#define ld long double
#define str string

// freopen("firesafe.in", "r", stdin);
// freopen("firesafe.out", "w", stdout);
//ll dp[33][33];
//map<ll,ll>mmap;
int n,q;
long long t[4*100000+1];
void build(long a[],int v, int l, int r){
  if(l==r){
    t[v] = a[l];
  }else{
    int mid = (l+r)>>1;
    build(a, v+v,l,mid);
    build(a, v+v+1, mid+1, r);
    t[v] = t[v+v]+t[v+v+1];
  }
}
long long sum(int v,int l, int r, int L, int R){
//  printf("%d %d %d %d %d \n", v, l, r, L, R);
  if(L>R) return 0;
  if(l==L && r==R) return t[v];
  int mid = (l+r)>>1;
  return sum(v+v,l,mid,L,min(mid,R)) + sum(v+v+1, mid+1, r , max(mid+1,L), R );
}
void update(int v, int l, int r, int pos, long val){

  if(l==r) {t[v] = val;}
  else{
    int mid = (l+r)>>1;
    if(pos<=mid){
      update(v+v,l,mid, pos,val);
    }else{
      update(v+v+1,mid+1, r, pos, val);
    }
    t[v] = t[v+v]+t[v+v+1];
  }

}

int main(){
   freopen("sum.in", "r", stdin);
   freopen("sum.out", "w", stdout);
  cin>>n>>q;
  long a[100000+1];
  rep(i,n){
    a[i]=0;
  }

  build(a,1,0, n-1);

  rep(i,q){
    string s;
    long b,c;

    cin>>s>>b>>c;

    if(s=="A"){
      b--;
      update(1, 0, n-1, b,c);
    }else{
      b--;c--;
      cout<<sum(1, 0,n-1,b,c)<<endl;
    }

  }


}