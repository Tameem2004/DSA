#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
Node *insert(Node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
  return root;
}
Node *delete_node(Node *root, int data)
{
  if (root == NULL)
  {
    return root;
  }
  if (data < root->data)
  {
    root->left = delete_node(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = delete_node(root->right, data);
  }
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if (root->left != NULL && root->right == NULL)
    {
      Node *temp;
      temp = root;
      root = root->left;
      free(temp);
      return root;
    }
    if (root->left == NULL && root->right != NULL)
    {
      Node *temp;
      temp = root;
      root = root->right;
      free(temp);
      return root;
    }
    else
    {
      Node *temp;
      Node *min;
      root = root->left;
      root = temp;
      while (root->right != NULL)
      {
        min = temp;
        temp = root->right;
      }
      root->data = min->data;
      root->left = delete_node(root->left, root->data);
      return root;
    }
    return root;
  }
}
void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(Node *root)
{
  if (root != NULL)
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

int main()
{
    system("cls");
  Node *root = NULL;
  root = insert(root, 41);
  insert(root, 30);
  insert(root, 27);
  insert(root, 4);
  insert(root, 7);
  delete_node(root, 27);
  insert(root, 8);

  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorderTraversal(root);
  printf("\n");
  delete_node(root, 30);
  printf("Inorder traversal after deletion: ");
  inorderTraversal(root);
  printf("\n");
  return 0;
}