#include<stdio.h>


//<global declaration>
float pro[9];


struct tree_el {
   int val;
   struct tree_el * right, * left;
};typedef struct tree_el node;

//</global declaration>


//<functions>
//<insert_tree>
void insert(node ** tree, node * item) 
{
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}
//</insert_tree>

//<print>
void printout(node * tree)
{
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}

//</print>

//<sort>
void sort()
{
		
}
//</sort>

//</functions>


main()
{
	printf(" . . . .HUFFMANS ALGORITHM . . . ");
	printf("\n");
	printf("Enter probability for instructions (10):");
	int i=0;
	node * curr,* root;
	printf("\n");
	for(i=0;i<=9;i++)
	{printf("\t\t");;scanf("%f",&pro[i]);}
	printf("probability is as folllows :");
	i=0;	
	for(i=0;i<=9;i++)	
	{printf("%d : %f",i,pro[i]);printf("\n");}
	sort();
//insertion into tree
	for(i=1;i<=10;i++) 
	{
      	curr = (node *)malloc(sizeof(node));
      	curr->left = curr->right = NULL;
     	curr->val = rand();
      	insert(&root, curr);
   	}
//insertion into tree*/
	


		
}
