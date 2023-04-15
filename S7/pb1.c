#include <stdio.h>
#include <stdlib.h>

typedef char Data;

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    int height;
}Node;


Node *newNode(Data data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

void preorder(Node *root) {
    if (root) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

Node *rightRotation(Node *z) {
    Node *y = z->left;
    Node *T3 = y->right;
    y->right = z;
    z->left = T3;
    return y;
}

Node *leftRotation(Node *z) {
    Node *y = z->right;
    Node *T2 = y->left;
    y->left = z;
    z->right = T2;
    return y;
}

Node *LRRotation(Node *Z) {
    Z->left = leftRotation(Z->left);
    return rightRotation(Z);
}

Node *RLRotation(Node *Z) {
    Z->right = rightRotation(Z->right);
    return leftRotation(Z);
}
Node *search(Node *root, int key) {
    if (root == NULL || root->val == key)
        return root;
    if (root->val < key)
        return search(root->right, key);
    return search(root->left, key);

    return 0;
}


void inorder(Node *root, int *nrOfRequest, int *sum){
	if(root) {
		inorder(root->right, nrOfRequest, sum);
		if (*sum < 140) {
			(*nrOfRequest)++;
			*sum += root->val;
		}
		else
			return;
		inorder(root->left, nrOfRequest, sum);
	}
}


    int main() {
        int cereri[] = {12, 10, 32, 27, 16, 25, 19, 26};
        
        Node *root = NULL;
        for (int i = 0; i < sizeof(cereri) / sizeof(int); i++)
        	root = insert(root, cereri[i]);

		//echilibrare
		Node *p = NULL;
		Node *c = NULL;
		
		p = search(root, 27);
		c = search(root, 16);
		p->left = leftRotation(c);


		p = search(root, 32);
		c = search(root, 27);
		p->left = rightRotation(c);

	
		p = search(root, 12);
		c = search(root, 32);
		p->right = rightRotation(c);


		p = search(root, 25);
		c = search(root, 32);
		p->right = rightRotation(c);


		c = search(root, 12);
		root = leftRotation(c);

		preorder(root);
		printf("\n");

		int sum = 0;
		int nrOfRequest = 0;
	    inorder(root, &nrOfRequest, &sum);
	//	printf("%d\n", nrOfRequest);
		int allRequests = sizeof(cereri)/sizeof(int) ;
		printf("Randament = %0.f\n", (float)nrOfRequest / allRequests * 100);
	

        return 0;
    }