#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *num, int i, int j) {
	int t = num[i];
	num[i] = num[j];
	num[j] = t;
}

void printList(int *num, int n){
	for(int i = 0; i<n; i++) {
		cout<<*(num+i)<<" ";
	}
	cout<<endl;
}

int partition(int *num, int p, int q) {
	int i = p-1;

	for(int k = p; k<q; k++) {
		if (num[k]<num[q]) {
			swap(num, ++i, k);
		}
	}
	swap(num, ++i, q);

	return i;

}

void quickSort(int *num, int p, int q) {
	if(p<q) {
		int r = partition(num, p, q);
		quickSort(num, p, r-1);
		quickSort(num, r+1, q);
	}
}


int main() {
	
	int n = 100;
	int num[n];

	for(int i = 0; i<n; i++) {
		num[i] = rand()%1000;
	}
	
	//int num[] = {77, 11, 5, 7, 9, 3, 7, 8, 6, 4};
	printList(num, n);
	quickSort(num, 0, n-1);
	printList(num, n);
}





