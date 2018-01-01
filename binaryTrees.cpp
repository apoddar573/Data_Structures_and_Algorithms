#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
	struct node *parent;
} ;

struct node *createNode() {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->parent = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node *root, int k) {
	if (root == NULL) {
		root->val = k;
	}
	else {
		struct node *x = root;
		struct node *p = x;
		struct node *temp = createNode();
		temp->val = k;
		while(x != NULL) {
			if(x->val > k) {
				p = x;
				x = x->left;
			} else {
				p = x;
				x = x->right;
			}
		}
		if (p->val > k) {
			p->left = temp;
		} else {
			p->right = temp;
		}
		temp->parent = p;
	}
}

void inorder(struct node *root) {
	if(root->left != NULL)
		inorder(root->left);
	cout<<root->val<<" ";
	if (root->right != NULL)
		inorder(root->right);
}

struct node *search(struct node *root, int k) {
	struct node *x = root;
	if (root->val == k) {
		return root;
	} else {
		while(x->val != k) {
			if(x->val > k)
				x = x->left;
			else
				x = x->right;
		}
		return x;
	}
}

struct node *minimum(struct node *temp) {
	struct node *x = temp;
	while(x->left != NULL) {
		x = x->left;
	}
	return x;
}

struct node *maximum(struct node *temp) {
	struct node *x = temp;
	while(x->right != NULL) {
		x = x->right;
	}
	return x;
}

struct node *successor(struct node *root, int k) {
	struct node *temp = search(root, k);
	if (temp->right != NULL) {
		return minimum(temp->right);
	} else {
		while(temp != temp->parent->left) {
			temp = temp->parent;
		}
		return temp->parent;
	}
}

struct node *predecessor(struct node *root, int k) {
	struct node *temp = search(root, k);
	if(temp->left != NULL) {
		return maximum(temp->left);
	} else {
		while(temp != temp->parent->right) {
			temp = temp->parent;
		}
		return temp->parent;
	}
}

void delet(struct node *root, int k) {
	struct node *x = search(root, k);
	if(x->left == NULL && x->right == NULL) {
		if(x == x->parent->left) {
			x->parent->left = NULL;
		} else {
			x->parent->right = NULL;
		}
	} else if (x->left == NULL) {
		if(x == x->parent->left) {
			x->parent->left = x->right;
			x->right->parent = x->parent;
		} else {
			x->parent->right = x->right;
			x->right->parent = x->parent;
		}
	} else if (x->right == NULL) {
		if(x == x->parent->left) {
			x->parent->left = x->left;
			x->left->parent = x->parent;
		} else {
			x->parent->right = x->left;
			x->left->parent = x->parent;
		}
	} else {
		struct node *y = x->left;
		struct node *z = x->right;
		if(x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->parent = x->parent;
		if(y->right == NULL) {
			y->right = z;
			z->parent = y;
		} else {
			struct node *b = maximum(y->right);
			b->right = z;
			z->parent = b;
		}
	}
}

int size(struct node *root) {
	struct node *x = root;
	if (x == NULL) {
		return 0;
	} else {
		return size(x->left) + size(x->right) + 1;
	}
}

int sameTree(struct node *root1, struct node *root2) {
	if (root1 == NULL && root2 == NULL) {
		return 1;
	} else if(root1 == NULL || root2 == NULL) {
		return 0;
	} else {
		if(root1->val == root2->val) {
			int l = sameTree(root1->left, root2->left);
			int r = sameTree(root1->right, root2->right);
			if(l != 0 && r != 0) {
				return 1;
			}
		} else {
			return 0;
		}
	}
}

int depth(struct node *root) {
	if(root == NULL) {
		return 0;
	} else {
		int l = depth(root->left);
		int r = depth(root->right);
		if (l>r) {
			return 1+l;
		} else {
			return 1+r;
		}
	}
}

void deleteTree(struct node *root) {
	if (root == NULL) {
		return ;
	} else {
		deleteTree(root->left);
		deleteTree(root->right);
		cout<<"Deleting Node: "<<root->val<<" ";
		free(root);
	}
}

void mirror(struct node *root) {
	if (root == NULL) {
		return;
	} else {
		mirror(root->left);
		mirror(root->right);
		struct node *temp = root->left;
		root->left = root->right;
		root->right = temp;
		return;
	}
}

void printArray(int num[], int pathLen) {
	for(int i = 0; i<pathLen; i++) {
		cout<<num[i]<<" ";
	}
	cout<<"\n";
}

void printPathRecur(struct node *root, int path[], int pathLen) {
	if(root == NULL) {
		return;
	}
	path[pathLen] = root->val;
	pathLen++;

	if(root->left == NULL && root->right == NULL) {
		printArray(path, pathLen);
	} else {
		printPathRecur(root->left, path, pathLen);
		printPathRecur(root->right, path, pathLen);
	}
}

void printPaths(struct node *root) {
	int path[1000];
	printPathRecur(root, path, 0);
}

struct node *lowestAncestor(struct node *root, int a, int b) {
	struct node *x = root;
	if(a>b) {
		swap(a, b);
	}
	bool flag = (a <= x->val && b >= x->val);
	while(!flag) {
		if(x->val > b) {
			x = x->left;
		} else {
			x = x->right;
		}
		flag =  (a <= x->val && b >= x->val);
	}
	return x;
}

int leafNodes(struct node *root) {
	if (root == NULL) {
		return 0;
	} else if (root->left == NULL && root->right == NULL) {
		return 1;
	} else {
		return leafNodes(root->left) + leafNodes(root->right);
	}
}

void printGivenLevel(struct node *root, int level) {
	if (root == NULL) {
		return;
	} else if (level == 1) {
		cout<<root->val<<" ";
	} else {
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

void levelOrder(struct node *root) {
	int n = depth(root);
	for(int i = 1; i<=n; i++) {
		cout<<"Level Order for "<<i<<": ";
		printGivenLevel(root, i);
		cout<<endl;
	}
}

void printGivenLevelSpiral(struct node *root, int level, int ltr) {
	if (root == NULL) {
		return;
	} else if (level == 1) {
		cout<<root->val<<" ";
	} else {
		if (ltr == 1) {
			printGivenLevelSpiral(root->left, level - 1, ltr);
			printGivenLevelSpiral(root->right, level - 1, ltr);
		} else {
			printGivenLevelSpiral(root->right, level - 1, ltr);
			printGivenLevelSpiral(root->left, level - 1, ltr);
		}
	}
}

void levelOrderSpiral(struct node *root) {
	bool ltr = 0;
	int n = depth(root);
	for(int i = 1; i<=n; i++) {
		cout<<"Level Order for "<<i<<": ";
		printGivenLevelSpiral(root, i, ltr);
		cout<<endl;
		ltr = !ltr;
	}
}


int checkBST(struct node *root) {
	if(root == NULL) {
		return 1;
	} else if (root->left != NULL && maximum(root->left)->val > root->val) {
		return 0;
	} else if (root->right != NULL && minimum(root->right)->val < root->val) {
		return 0;
	} else if(checkBST(root->left) && checkBST(root->right)) {
		return 1;
	}
}

int diameter(struct node *root) {
	if (root == NULL) 
		return 0;
	int ldepth = depth(root->left);
	int rdepth = depth(root->right);

	return max(ldepth + rdepth + 1, max(diameter(root->left), diameter(root->right)));
}

int isBalanced(struct node *root) {
	if(root == NULL)
		return 1;
	int a = depth(root->left);
	int b = depth(root->right);

	if(abs(a-b) <= 1) {
		return (isBalanced(root->left) && isBalanced(root->right));
	}
	return 0;
}

void rootToLeafSumUtil(struct node *root, int sum, int *path, int pathLen) {
	if(root == NULL) 
		return;
	sum = sum - root->val;
	path[pathLen] = root->val;
	pathLen++;
	if(sum == 0 && root->left == NULL && root->right == NULL) {
			printArray(path, pathLen);
	} else {
		rootToLeafSumUtil(root->left, sum, path, pathLen);
		rootToLeafSumUtil(root->right, sum, path, pathLen);
	}
}

void rootToLeafSum(node *root, int sum) {
	int path[1000];
	rootToLeafSumUtil(root, sum, path, 0);
}

int getLevelWidth(struct node *root, int k) {
	if(root == NULL)
		return 0;
	if(k == 1)
		return 1;
	else
		return getLevelWidth(root->left, k - 1) + getLevelWidth(root->right, k - 1);
}

int getMaxWidth(struct node *root) {
	int d = depth(root);
	int maxWidth = 0;
	for(int k = 1; k<=d; k++) {
		int width = getLevelWidth(root, k);
		if(maxWidth<width) 
			maxWidth = width;
	}
	return maxWidth;
}

int getLevel(struct node *root, int k) {
	if(root == NULL)
		return 0;
	if(k == root->val)
		return 1;
	else {
		int l = getLevel(root->left, k);
		int r = getLevel(root->right, k);
		if(l+r > 0)
			return 1+l+r;
		else
			return 0;
	}
}

int leftViewUtil(struct node *root, int k) {
	if(root == NULL) 
		return 0;
	if(k == 1) {
			cout<<root->val<<" ";
			return 1;}
	int l = leftViewUtil(root->left, k-1);
	if(l == 1)
		return 1;
	else {
		int r = leftViewUtil(root->right, k - 1);
		return r;
	}
}

void leftView(struct node *root) {
	int d = depth(root);
	for(int k = 1; k<=d; k++) {
		leftViewUtil(root, k);
	}
	cout<<endl;
}

int rightViewUtil(struct node *root, int k) {
	if(root == NULL) 
		return 0;
	if(k == 1) {
			cout<<root->val<<" ";
			return 1;}
	int r = rightViewUtil(root->right, k-1);
	if(r == 1)
		return 1;
	else {
		int l = rightViewUtil(root->left, k - 1);
		return l;
	}
}

void rightView(struct node *root) {
	int d = depth(root);
	for(int k = 1; k<=d; k++) {
		rightViewUtil(root, k);
	}
	cout<<endl;
}

int main() {
	struct node *root = createNode();
	root->val = 6;
	insert(root, 9);
	insert(root, 8);
	insert(root, -20);
	insert(root, 4);
	insert(root, 5);
	insert(root, 7);
	insert(root, -6);
	insert(root, -9);
	insert(root, -4);
	inorder(root);
	struct node *temp = search(root, 8);
	cout<<endl<<successor(root, 5)->val<<endl;
	cout<<successor(root, -9)->val<<endl;
	cout<<predecessor(root, 7)->val<<endl;
	cout<<endl;
	delet(root, 4);
	inorder(root);
	cout<<endl<<root->left->right->right->right->val;
	delet(root, 9);
	inorder(root);
	cout<<endl<<root->right->val<<endl;
	cout<<successor(root, -9)->val<<endl;
	cout<<predecessor(root, 7)->val<<endl;
	cout<<size(root)<<endl;
	struct node *root1 = createNode();
	root1->val = 6;
	insert(root1, 9);
	insert(root1, 8);
	insert(root1, -20);
	insert(root1, 4);
	insert(root1, 5);
	insert(root1, 7);
	insert(root1, -6);
	insert(root1, -9);
	insert(root1, -4);
	delet(root1, 4);
	delet(root1, 9);
	struct node *root2 = createNode();
	root2->val = 5;
	insert(root2, 7);
	cout<<sameTree(root, root1)<<endl;
	cout<<sameTree(root2, root1)<<endl;
	cout<<sameTree(root, root2)<<endl ;
	cout<<depth(root)<<endl;
	cout<<depth(root1)<<endl;
	cout<<depth(root2)<<endl;
	inorder(root2);
	cout<<endl;
	inorder(root1);
	cout<<endl<<"Root to leaf paths: "<<endl;
	printPaths(root);
	cout<<lowestAncestor(root, 5, -9)->val<<endl;
	cout<<leafNodes(root)<<endl;
	levelOrderSpiral(root);
	cout<<checkBST(root)<<endl;
	mirror(root1);
	cout<<checkBST(root1)<<endl;
	mirror(root1);
	cout<<checkBST(root1)<<endl;
	cout<<diameter(root)<<endl;
	delet(root1, 5);
	delet(root1, -20);
	insert(root, -5);
	//delet(root2, 7);
	cout<<isBalanced(root)<<endl;
	cout<<isBalanced(root1)<<endl;	
	rootToLeafSum(root, -29);
	cout<<getMaxWidth(root)<<" "<<getMaxWidth(root1)<<" "<<getMaxWidth(root2)<<endl;
	cout<<getLevel(root, -20)<<" "<<getLevel(root, -9)<<" "<<getLevel(root2, 5)<<endl;
	leftView(root);
	rightView(root);
}




