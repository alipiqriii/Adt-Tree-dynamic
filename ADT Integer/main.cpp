#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "T_Dinamis.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Address Root=NULL;
	Address Parent;
	Root=CreateRoot('A');
	InsertNode(&Root,Search(Root,'A'),'B');
	InsertNode(&Root,Search(Root,'A'),'C');
	InsertNode(&Root,Search(Root,'A'),'D');
	InsertNode(&Root,Search(Root,'B'),'E');
	InsertNode(&Root,Search(Root,'B'),'F');
	InsertNode(&Root,Search(Root,'B'),'G');
	InsertNode(&Root,Search(Root,'E'),'H');
	InsertNode(&Root,Search(Root,'F'),'I');
	InsertNode(&Root,Search(Root,'F'),'J');
	InsertNode(&Root,Search(Root,'C'),'K');
	InsertNode(&Root,Search(Root,'C'),'L');
	InsertNode(&Root,Search(Root,'D'),'M');
	InsertNode(&Root,Search(Root,'M'),'N');
	InsertNode(&Root,Search(Root,'M'),'O');
//	DeleteNode(&Root,Search(Root,'D'));
//	DeleteNode(&Root,Search(Root,'C'));
//	DeleteNode(&Root,Search(Root,'B'));
	printf("PreOrder \t: "); PreOrder(Root);
	printf("PostOrder \t: "); PostOrder(Root);
	printf("InOrder \t: "); InOrder(Root);
	printf("Depth \t\t: %d\n",Depth(Root));
	printf("Min \t\t: %c\n",Min(Root));
	printf("Max \t\t: %c\n",Max(Root));
	printf("Leaf \t\t: ");Leaf(Root);
	printf("Size \t\t: %d\n",Size(Root));
	printf("Max Degree \t: %d\n",MaxDegree(Root));
	printf("Degree (F) \t: %d\n",Degree(Search(Root,'F')));
	printf("Ancestor (H) \t: ");Ancestor(Search(Root,'H'));
	printf("Descendant (B) \t: ");Descendant(Search(Root,'B'));
	printf("Subtree (A) \t: ");SubTree(Search(Root,'A'));
	printf("Root from (O)\t: %c\n",GetRoot(Search(Root,'O')));
	printf("Parent from (O)\t: %c\n",GetParent(Search(Root,'O')));
	printf("Brother from (N)\t: %c\n",GetBrother(Search(Root,'N')));
	printf("FirstSon from (M)\t: %c\n",GetSon(Search(Root,'M')));
	return 0;
}
