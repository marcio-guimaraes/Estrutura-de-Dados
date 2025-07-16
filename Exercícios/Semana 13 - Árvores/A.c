#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int chave;
    struct Node *esq;
    struct Node *dir;
} Node;

Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->chave = key;
    node->esq = node->dir = NULL;
    return node;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->chave)
        root->esq = insert(root->esq, key);
    else
        root->dir = insert(root->dir, key);
    return root;
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->esq);
    postOrder(root->dir);
    printf("%d ", root->chave);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->esq);
    freeTree(root->dir);
    free(root);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *pre = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &pre[i]);

    Node *root = NULL;
    for (int i = 0; i < n; ++i)
        root = insert(root, pre[i]);

    postOrder(root);
    printf("\n");

    freeTree(root);
    free(pre);
    return 0;
}
