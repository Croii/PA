
Node* newNode(Data data) {  
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = data;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node* node, int key) {  
	if (node == NULL) return newNode(key);
	
	if (key < node->val)  		
		node->left  = insert(node->left, key);
	else if (key > node->val)  	
		node->right = insert(node->right, key);  
	node->height = height(node); 
	return node; 
} 

void preorder(Node*root) {
	if (root){
		printf("%d ",root->val);
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

Node* LRRotation(Node*Z) { 
	Z->left = leftRotation(Z->left);
	return rightRotation(Z);
}

Node* RLRotation(Node*Z) { 
	Z->right = rightRotation(Z->right);
	return leftRotation(Z);
}
Node* search(Node* root, int key) {
	if (root == NULL || root->val == key)
		return root;
	if (root->val < key)  
		return search(root->right, key);	
	return search(root->left, key);

	return 0;
}


