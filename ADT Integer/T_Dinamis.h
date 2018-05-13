#define MAX_SIZE 15
#define IndexRoot 1
#define Nil 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int Infotype;
typedef struct Tree *Address;
typedef struct Tree{
	Infotype Info;
	Address Parent;
	Address FirstSon;
	Address Brother;
}TreeNode;

bool IsEmpty(Address Node);
Address Search(Address Root,Infotype Data);

/*--------- About Create / Delete A Node/Tree -----------*/
Address CreateRoot(Infotype Data);
Address CreateNode(Infotype Data);
void InsertNode(Address *Root,Address Parent,Infotype Data);
void DeleteNode(Address *Root,Address NodeDeleted);
void SubTreeDelete(Address Node);

/*--------- Info About The Tree -----------*/
int Depth(Address Node);
Infotype Min(Address Node);
Infotype Max(Address Node);
void Leaf(Address Node);
int Height(Address Node);
int Size(Address Node);
int MaxDegree(Address Node);

/*--------- Info About The Node -----------*/
int Degree(Address Node);
int Level(Address Node); //
void Ancestor(Address Node);
void Descendant(Address Node);
void SubTree(Address Node);

/*--------- Get About The Node -----------*/
Infotype GetRoot(Address Node);
Infotype GetParent(Address Node);
Infotype GetSon(Address Node);
Infotype GetBrother(Address Node);

///*--------- Traversing -----------*/
void PreOrder(Address Node);
void PostOrder(Address Node);
void InOrder(Address Node);
