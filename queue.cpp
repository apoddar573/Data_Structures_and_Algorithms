#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
	int val;
	struct node *next;
} ;

class queue {
	int len = 0;
	struct node *start;
	struct node *end;
public:
	queue(int *num, int n);
	void enqueue(int k);
	int dequeue();
	int isEmpty();
} ;

void queue :: enqueue(int k) {
	if (len > 0) {
 		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->val = k;
		temp->next = NULL;
		end->next = temp;
		end = temp;
		}
	else {
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->val = k;
		temp->next = NULL;
		start = temp;
		end = temp;
		}
	len += 1;
}

int queue :: dequeue() {
	int l = start->val;
	start = start->next;
	len = len - 1;
	return l;
}


int queue :: isEmpty() {
	if (len)
		return 0;
	else 
		return 1;
}

queue :: queue(int *num, int n) {
	for(int i = 0; i<n; i++) {
		enqueue(num[i]);
	}
	len = n;
}

int main() {
	int num[] = {5, 6, 7, 1, 3, 4, 5};
	queue q(num, 7);
	q.enqueue(91);
	q.enqueue(71);
	q.enqueue(19);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.isEmpty()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.isEmpty()<<endl;

}





