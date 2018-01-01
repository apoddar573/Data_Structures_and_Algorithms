#include<iostream>
#include<stdlib.h>
#include<limits.h>

using namespace std;

void merge(int *num, int p, int r, int q);

void printList(int *num, int n){
	for(int i = 0; i<n; i++) {
		cout<<*(num+i)<<" ";
	}
	cout<<endl;
}

void mergeSort(int *num, int p, int q) {
	if (p<q) {
		int r = (p+q)/2;
		mergeSort(num, p, r);
		mergeSort(num, r+1, q);
		merge(num, p, r, q);
	}
}

void merge(int *num, int p, int r, int q) {
	int L1[r-p+2];
	int L2[q-r+1];
	int i = 0, j = 0;
	
	for(int k = p; k<=q; k++)  {
		if(k<=r) {
			L1[k-p] = num[k];
		} else {
			L2[k-r-1] = num[k];
		}
	}
	L1[r-p+1] = INT_MAX;
	L2[q-r] = INT_MAX;

	for(int k = p; k<=q; k++) {
		if(L1[i]<=L2[j]) {
			num[k] = L1[i];
			i = i+1;
		} else {
			num[k] = L2[j];
			j += 1;
		}
	}
}

int main()
{
	int n = 100;
	int num[n];

	for(int i = 0; i<n; i++) {
		num[i] = rand()%1000;
	}
	printList(num, n);
	mergeSort(num, 0, n-1);
	printList(num, n);

	return 0;
}


