#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1-i; j++)
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
}

void selectionSort(int a[], int n){
	int minIndex;
	for(int i=0; i<n-1; i++){
		minIndex = i;
		for(int j=i+1; j<n; j++)
			if(a[minIndex] > a[j])
				minIndex = j;
		swap(a[i], a[minIndex]);
	}
}

void insertionSort(int a[], int n){
	int e, j;
	for(int i=1; i<n; i++){
		e=a[i]; j=i-1;
		while(a[j]>e & j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = e;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	bubbleSort(a, n);
	for(auto x:a)
		cout<<x<<" ";
    selectionSort(a, n);
	for(auto x:a)
		cout<<x<<" ";
    insertionSort(a, n);
	for(auto x:a)
		cout<<x<<" ";

	return 0;
}
