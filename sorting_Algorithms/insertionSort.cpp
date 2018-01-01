#include<iostream>
#include<stdlib.h>

using namespace std;

void printList(int *num, int n){
	for(int i = 0; i<n; i++) {
		cout<<*(num+i)<<" ";
	}
	cout<<endl;
}

void swap(int *num, int i, int j) {
	int t = num[i];
	num[i] = num[j];
	num[j] = t;
}

void insertionSort(int *num, int n) {	
	int j = 0;
	int key = 0;
	for(int i = 1; i<n; i++) {
		j = i-1;
		key = num[i];
		while(j >= 0 && key<num[j]) {
			num[i] = num[j];
			i = i-1;
			j = i-1;
		}
		num[i] = key;
	}
}

int main() {
	int n;
	n = 100;
    int num[n];
    for(int i = 0; i<n; i++) {
    	num[i] = rand()%1000;
    }
    printList(num, n);
    insertionSort(num, n);
    printList(num, n);

    return 0;
}



