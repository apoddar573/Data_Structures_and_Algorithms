#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int parent(int a, int *par) {
	if(par[a] == a)
		return a;
	else 
		par[a] = parent(par[a], par);
		return par[a];
}

void unions(int a, int b, int *rank, int *par) {
	int l = parent(a, par);
	int r = parent(b, par);
	if(l == r)
		return;
	if(rank[l] > rank[r]) {
		par[r] = l;
		rank[l] = max(rank[l], rank[r] + 1);
	} else {
		par[l] = r;
		rank[r] = max(rank[r], rank[l] + 1);
	}
}

void printList(int *a, int n) {
	for(int i = 0; i<n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int rank[10];
	int par[10];
	for (int i = 0; i < 10; ++i)
	{
		par[i] = i;
		rank[i] = 0;
	}
	unions(2, 3, rank, par);
	unions(1, 4, rank, par);
	unions(2, 1, rank, par);
	unions(5, 6, rank, par);
	unions(7, 6, rank, par);
	printList(par, 10);
	printList(rank, 10);
	unions(1, 6, rank, par);
	printList(par, 10);
	printList(rank, 10);

}