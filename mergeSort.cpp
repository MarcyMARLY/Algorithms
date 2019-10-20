#include <iostream>
using namespace std;
int n;
int a[1000];
int b[1000];

void mergesort(int l, int r){
	if(l == r)
		return;

	int mid = (r + l)/2;
	
	mergesort(l, mid);
	mergesort(mid + 1, r);

	int i = l, j = mid + 1, m = 0;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			
			b[m++] = a[i];
			i++;
		}else{
			b[m++] = a[j];
			j++;
		}
	}
	while(i <= mid){
		b[m++] = a[i];
		i++;
	}
	while(j <= r){ 
		b[m++] = a[j];
		j++;
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	for(int i = l, j = 0; i <=r; i++, j++){
		a[i] = b[j];
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	mergesort(0, n-1);
	for(int i = 0; i < n; i++)
		cout<< a[i] << " ";
	cout << endl;
	return 0;
}