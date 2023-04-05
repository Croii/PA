#include <stdio.h>
#include <stdlib.h>

struct N
{
    int num;
    char type;
    struct N *left, *right;
};

typedef struct N Node;

Node *createNode(char type, int num)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->num  = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *createTree(Node *root)
{
    root = createNode('Q', 1);
    root->left  = createNode('Q', 2);
    root->right = createNode('Q', 3);
    root->left->left   = createNode('Q', 4);
    root->left->right  = createNode('Q', 5);
    root->right->left  = createNode('Q', 6);
    root->right->right = createNode('C', 2);
    root->left->left->left   = createNode('Q', 7);
    root->left->left->right  = createNode('Q', 8);
    root->left->right->left  = createNode('Q', 9);
    root->left->right->right = createNode('C', 3);
    root->right->left->left  = createNode('C', 4);
    root->right->left->right = createNode('Q', 10);
    root->left->left->left->left    = createNode('C', 1);
    root->left->left->left->right   = createNode('C', 2);
    root->left->left->right->left   = createNode('C', 2);
    root->left->left->right->right  = createNode('C', 4);
    root->left->right->left->left   = createNode('C', 2);
    root->left->right->left->right  = createNode('C', 1);
    root->right->left->right->left  = createNode('C', 1);
    root->right->left->right->right = createNode('C', 4);

    return root;
}

void printPath(char *path, int pathLen) {
    for (int i = 0; i < pathLen; i++)
        printf("%c " , path[i]);
    printf("\n");

}

void pathToLeaf(Node *root, char *path, int *pathLen) {
    if (root == NULL) {
        return;
    }
    //stanga
    if (root->left != NULL) {
        path[(*pathLen)++] = 'd';
        pathToLeaf(root->left, path, pathLen);
        (*pathLen)--;
    }
    //dreapta
    if (root->right != NULL) {
        path[(*pathLen)++] = 'n';
        pathToLeaf(root->right, path, pathLen);
        (*pathLen)--;
    }

    //radacina
    if (root->left == NULL && root->right == NULL){
        printf("%c%d : ", root->type, root->num);
        printPath(path, *pathLen);
    }

}

void pathToLeafConditional(Node *root, char *path, int *pathLen, int keyNum) {
    if (root == NULL) {
        return;
    }
    //stanga
    if (root->left != NULL) {
        path[(*pathLen)++] = 'd';
        pathToLeafConditional(root->left, path, pathLen, keyNum);
        (*pathLen)--;
    }
    //dreapta
    if (root->right != NULL) {
        path[(*pathLen)++] = 'n';
        pathToLeafConditional(root->right, path, pathLen, keyNum);
        (*pathLen)--;
    }

    //radacina
    if (root->left == NULL && root->right == NULL && root->type == 'C' && root->num == keyNum){
       // printf("%d %d", root->num, keyNum);
        printPath(path, *pathLen);

    }

}

void getLeaves(Node *root, int *leaves, int *numberOfLeaves, int *quantity) {
    if(root->left != NULL)
        getLeaves(root->left, leaves, numberOfLeaves, quantity);
    if (root->right != NULL)
        getLeaves(root->right, leaves, numberOfLeaves, quantity);
    
    if (root->left == NULL && root->right == NULL) {
        int exists = 0;
        for (int i = 0; i < *numberOfLeaves; i++)
            if (root->num == leaves[i]) {
                exists = 1;
                quantity[i]++;
            }
        if (!exists) {
            leaves[(*numberOfLeaves)++] = root->num;
            quantity[(*numberOfLeaves) - 1] = 1;
        } 
    }

}

void groupedLeaves(Node *root) {
    int leaves[50] = {0};
    int quantity[50] = {0};
    int numberOfLeaves = 0;
    getLeaves(root, leaves, &numberOfLeaves, quantity);
    for (int i = 0; i < numberOfLeaves; i++)
        printf("%d %d\n", leaves[i], quantity[i]);

    printf("\n");

    char path[50];
    int pathLen = 0;
    for (int i = 0; i < numberOfLeaves; i++) {
        printf("C%d: %d cai\n", leaves[i], quantity[i]);
        pathToLeafConditional(root, path, &pathLen, leaves[i]);
        printf("\n");
    }


}

void printLevel(Node *root, int level)
{   

    if (root == NULL)
        return;
    if (level == 1) {
        FILE *output = fopen("date.out", "at");
        fprintf(output, "%c%d ", root->type, root->num);
        fclose(output);

    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);

    }
}

int height(Node *root)
{
    int hs, hd;
    if (root == NULL)
        return -1;

    
    hs = height(root->left);
    hd = height(root->right);

    return 1 + ((hs > hd) ? hs : hd);
}

void levelOrderTraversal(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h + 1; i++)
    {
        printLevel(root, i);
        FILE *output = fopen("date.out", "at");
        fprintf(output, "%c", '\n');
        fclose(output);
        
    }
}


int main()
{
    FILE *output = fopen("date.out", "wt");
    fclose(output);
    Node *root = NULL;
    root = createTree(root);
//    levelOrderTraversal(root);
    int pathLen = 0;
    char path[50] = "";
    pathToLeaf(root, path, &pathLen);
    printf("\n");
    groupedLeaves(root);
}