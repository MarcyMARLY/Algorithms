
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
void insertion_sort(int arr[],int n){
		for(int i=2;i<=n;i++){
			int val = arr[i];
			int j = i-1;
			while(j>0 && arr[j]<val){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1]=val;
		}
}
// freopen("firesafe.in", "r", stdin);
// freopen("firesafe.out", "w", stdout);
ll dp[33][33];
//map<ll,ll>mmap;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	insertion_sort(a,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}

}