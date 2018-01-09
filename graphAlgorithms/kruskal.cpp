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

struct Edge {
	int src, des, wt;
} ;

struct Graph {
	int E, V;
	int pt;
	struct Edge* edge;
} ;

struct Graph* createGraph(int V, int E) {
	struct Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->pt = 0;
	graph->edge = new Edge[E];
	return graph;
}

void insertEdge(Graph *graph, int src, int des, int wt) {
	graph->edge[graph->pt].src = src;
	graph->edge[graph->pt].des = des;
	graph->edge[graph->pt].wt = wt;
	graph->pt = graph->pt + 1;
}

int edgeComp(Edge *a, Edge *b) {
	return (a->wt<b->wt);
}


//not my function 
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->wt > b1->wt;
}

void kruskal(Graph *g) {

	//sorting line not mine
	qsort(g->edge, g->E, sizeof(g->edge[0]), myComp);
	
	int rank[g->V], par[g->V];
	for (int i = 0; i < 10; ++i)
	{
		par[i] = i;
		rank[i] = 0;
	}

	int n = 0, i = 0;
	while(n < g->V-1) {
		int src = g->edge[i].src;
		int des = g->edge[i].des;
		int wt = g->edge[i].wt;
		if (par[src] != par[des]) {
			unions(src, des, rank, par);
			n++;
			cout<<src<<"----"<<des<<"->"<<wt<<endl;
		}
		i++;
	}
}


int main() {
	Graph *g = createGraph(5, 7);
	insertEdge(g, 0, 2, 6);
	insertEdge(g, 1, 4, 2);
	insertEdge(g, 0, 3, 7);
	insertEdge(g, 1, 3, 4);
	insertEdge(g, 2, 3, 1);
	insertEdge(g, 0, 1, 3);
	insertEdge(g, 0, 4, 6);
	kruskal(g);
}