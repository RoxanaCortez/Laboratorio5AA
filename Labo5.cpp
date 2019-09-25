#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};
// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//Funcion para recorrido postOrden TAREA! ********
void postorder(struct node *root){
	if(root==NULL){
		return;
	}
	else{
		postorder(root->left);
		postorder(root->right);
		printf("\t");
		printf("%d  -  ", root->key);
		
	}
}
//*********************


//funcion recorrido inOrder
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("\t");
		printf("%d  -  ", root->key);
		inorder(root->right);
	}
}

//funcion recorrido preOrden
void preorder(struct node *root){
	if(root==NULL){
		return;
	}
	else{
		printf("\t");
		printf("%d  -  ", root->key);
		preorder(root->left);
		preorder(root->right);
		
	}
}


/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);
	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
/* return the (unchanged) node pointer */
	return node;
}
// Driver Program to test above functions
int main()
{
/* Let us create following BST
50
/ \
30 70
/ \ / \
20 40 60 80 */
struct node *root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);

printf("\n\t       ARBOL\n");
printf("\n\t\t50");
printf("\n\t     .       .");
printf("\n\t     30      70");
printf("\n\t   .    .   .    .");
printf("\n\t  20   40  60   80");
printf("\n\n");

//imprimiendo arbol en postOrder, inOrder y preOrder  
printf("\n\nRecorrido postOrder (Tarea) \n\n"); //Tarea
postorder(root);
printf("\n\nRecorrido inOrder\n\n");
inorder(root);
printf("\n\nRecorrido preOrder\n\n");
preorder(root);
printf("\n\n");

return 0;
}
