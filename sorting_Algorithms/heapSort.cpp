#include <iostream>
#include <algorithm>

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

void heapify(int *num, int i, int n) {
	int largest = i;
	int l = 2*i+1;
	int r  =2*i+2;

	if (l<n && num[largest] < num[l])
		largest = l;
	if (r<n && num[largest] < num[r])
		largest = r;
	if (largest != i) {
		swap(num, i, largest);
		heapify(num, largest, n);
	}
}

void build_max_heap(int *num, int n)
{
	for(int i = n/2-1; i>=0; i--) {
		heapify(num, i, n);
	}
}

void heapSort(int *num, int n) {
	build_max_heap(num, n);
	printList(num, n);

	for(int i = n-1; i>=0; i--) {
		swap(num, 0, i);

		heapify(num, 0, i);

	}
}


int main()
{
    int num[] = {77, 11, 5, 7, 9, 3, 7, 8, 6, 4};
    printList(num, 10);
    heapSort(num, 10);
    printList(num, 10);

    return 0;
}
