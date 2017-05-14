
/* c program for heap sorting method*/

#include<stdio.h>
#include<conio.h>
void manage(int *, int);
void heapsort(int *, int, int);
int main()
{
 int arr[20]; 
 int i,j,size,tmp,k;
 printf("\n\t------- Heap sorting method -------\n\n");
 printf("Enter the number of elements to sort : ");
 scanf("%d",&size);
 for(i=1; i<=size; i++)
 {
   printf("Enter %d element : ",i);
   scanf("%d",&arr[i]);
   manage(arr,i);
 }
 j=size;
 for(i=1; i<=j; i++)
 {
   tmp=arr[1];
   arr[1]=arr[size];
   arr[size]=tmp;
   size--;
   heapsort(arr,1,size);
 }
 printf("\n\t------- Heap sorted elements -------\n\n");
 size=j;
 for(i=1; i<=size; i++)
     printf("%d ",arr[i]);
 getch();
 return 0;
}


void manage(int *arr, int i)
{
 int tmp; 
 tmp=arr[i];
 while((i>1)&&(arr[i/2]<tmp))
 {
   arr[i]=arr[i/2];
   i=i/2;
 }
 arr[i]=tmp;
}


void heapsort(int *arr, int i, int size)
{
 int tmp,j;
 tmp=arr[i];
 j=i*2;
 while(j<=size)
 {
   if((j<size)&&(arr[j]<arr[j+1]))
      j++;
   if(arr[j]<arr[j/2]) 
      break;
   arr[j/2]=arr[j];
   j=j*2;
 }
 arr[j/2]=tmp;
}

# include <conio.h>
# include <stdlib.h>
 
typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
 
void main() {
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;
   clrscr();
 
   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
 
      switch (choice) {
      case 1:
         do {
            new_node = get_node();
            printf("\nEnter The Element ");
            scanf("%d", &new_node->data);
 
            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);
 
            printf("\nWant To enter More Elements?(y/n)");
            ans = getch();
         } while (ans == 'y');
         break;
 
      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);
 
         tmp = search(root, key, &parent);
         printf("\nParent of node %d is %d", tmp->data, parent->data);
         break;
 
      case 3:
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nThe Inorder display : ");
            inorder(root);
            printf("\nThe Preorder display : ");
            preorder(root);
            printf("\nThe Postorder display : ");
            postorder(root);
         }
         break;
      }
   } while (choice != 4);
}
/*
 Get new Node
 */
node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
/*
 This function is for creating a binary search tree
 */
void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }
 
   if (new_node->data > root->data) {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}
/*
 This function is for searching the node from
 binary Search Tree
 */
node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\nThe %d Element is Present", temp->data);
         return temp;
      }
      *parent = temp;
 
      if (temp->data > key)
         temp = temp->lchild;
      else
         temp = temp->rchild;
   }
   return NULL;
}
/*
 This function displays the tree in inorder fashion
 */
void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d", temp->data);
      inorder(temp->rchild);
   }
}
/*
 This function displays the tree in preorder fashion
 */
void preorder(node *temp) {
   if (temp != NULL) {
      printf("%d", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
 
/*
 This function displays the tree in postorder fashion
 */
void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d", temp->data);
   }
}
