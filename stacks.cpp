#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
	int val;
	struct node *next;
} ;

class stack {
	int len = 0;
	struct node *start;
public:
	int top();
	stack(int *num, int n);
	void pop();
	void push(int k);
	int isEmpty();
} ;

int stack :: top() {
	if (len > 0)
		return start->val;
	else
		return -1;
}

void stack :: pop() {
	start = start->next;
	len = len - 1;
}

void stack :: push(int k) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->val = k;
	temp->next = start;
	start = temp;
	len += 1;
}

int stack :: isEmpty() {
	if (len)
		return 0;
	else 
		return 1;
}

stack :: stack(int *num, int n) {
	for(int i = 0; i<n; i++) {
		push(num[i]);
	}
	len = n;
}

int main() {
	int num[] = {5, 6, 7, 1, 3, 4, 5};
	stack s(num, 7);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.isEmpty()<<endl;

}





