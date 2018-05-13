#include "T_Dinamis.h"

bool IsEmpty(Address Node){
	if(Node != NULL) return false;
	else return true;	
}

Address CreateNode(Infotype Data){
	Address Node;
	Node = (Address) malloc(sizeof(TreeNode));
	Node->Parent = NULL;
	Node->Brother = NULL;
	Node->FirstSon = NULL;
	Node->Info = Data;
	return Node;
}

Address CreateRoot(Infotype Data){
	Address Root;
	Root = CreateNode(Data);
	return Root;
}

Address Search(Address Root,Infotype Data){
	Address NodeCurrent;
	bool Resmi,Found;
	NodeCurrent=Root;
	Found = false;
	if(NodeCurrent->Info == Data) Found=true;
	else {
		Resmi = true;
		do{
			if(!IsEmpty(NodeCurrent->FirstSon) && Resmi){		
				NodeCurrent = NodeCurrent->FirstSon;
				if(NodeCurrent->Info == Data) Found=true;
			}
			else {
				if(!IsEmpty(NodeCurrent->Brother)){
					NodeCurrent = NodeCurrent->Brother;
					if(NodeCurrent->Info == Data) Found=true;
					Resmi = true;
				}
				else {
					NodeCurrent = NodeCurrent->Parent;
					Resmi = false;
				}
			}
		}while(NodeCurrent->Parent != NULL && !Found);	
	}
	if(Found) return NodeCurrent;
	else return NULL;
}

void InsertNode(Address *Root,Address Parent,Infotype Data){
	
	Address NodeCurrent;
	Address NewNode;
	NewNode = CreateNode(Data);
	
	if(!IsEmpty(Parent->FirstSon)){
		NodeCurrent = Parent->FirstSon;
		while(!IsEmpty(NodeCurrent->Brother)){
			NodeCurrent = NodeCurrent->Brother;
		}
		NodeCurrent->Brother = NewNode;
	}
	
	else Parent->FirstSon = NewNode;
	NewNode->Parent = Parent;	
	
}

void PreOrder(Address Node){
	bool Resmi;
	printf("{ ");
	printf("%c ",Node->Info);
	Resmi = true;
	if(!IsEmpty(Node->FirstSon)){
		
		do{
			if(!IsEmpty(Node->FirstSon) && Resmi){		
				Node = Node->FirstSon;
				printf("%c ",Node->Info);
			}
			else {
				if(!IsEmpty(Node->Brother)){
					Node = Node->Brother;
					printf("%c ",Node->Info);
					Resmi = true;
				}
				else {
					Node = Node->Parent;
					Resmi = false;
				}
			}
		}while(Node->Parent != NULL);
	}
	printf("}\n");	
}

void PostOrder(Address Node){
	bool Resmi;
	Resmi = true;
	printf("{ ");
	while(!IsEmpty(Node)){
		if (!IsEmpty(Node->FirstSon) && Resmi) Node=Node->FirstSon;
		else {
			printf("%c ",Node->Info);
			if (!IsEmpty(Node->Brother)){
				Node = Node->Brother;
				Resmi = true;
			}
			else {
				Node = Node->Parent;
				Resmi = false;
			}
		}
	}
	printf("}\n");
}

void InOrder(Address Node){
	
	printf("{ ");
	if(IsEmpty(Node)) printf("");
	
	else if(!IsEmpty(Node->FirstSon)){
		
		Node = Node->FirstSon;
		bool Resmi = true;
		while (!IsEmpty(Node->Parent)){
			if (!IsEmpty(Node->FirstSon) && Resmi){
				Node = Node->FirstSon;	
			}
			else{
				if (Resmi){
					printf ("%c ",Node->Info);
				}
				if (Node == Node->Parent->FirstSon){
					printf ("%c ",Node->Parent->Info);
				}
				if(!IsEmpty(Node->Brother)){
					Node = Node->Brother;
					Resmi = true;
				}
				else {
					Node = Node->Parent;
					Resmi = false;
				}
			}
		}
	}
	else printf("%c ",Node->Info);
	printf("}\n");
}

int Depth(Address Node){
	bool Resmi = true;
	Address Current = Node;
	int y,z;
	y=0;z=0;
	if(!IsEmpty(Current->FirstSon)){
		do{
			if(Current->FirstSon != Nil && Resmi){
				y++;		
				Current = Current->FirstSon;
			}
			else {
				if(Current->Brother != Nil){
					Current = Current->Brother;
					Resmi = true;
				}
				else {
					if(y>z) z=y;
					y--;
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);	
	}
	return z;
}

void DeleteNode(Address *Root,Address NodeDeleted){
	
	//Save Information Node Delete
	Address TempParent 		= NodeDeleted->Parent;
	Address TempBrother 	= NodeDeleted->Brother;
	Address TempFirstSon 	= NodeDeleted->FirstSon;
	Infotype TempInfo		= NodeDeleted->Info;
	
	if(NodeDeleted != (*Root)){
		
		//Check If This Node Is FirstSon / Not
		if(TempParent->FirstSon == NodeDeleted){
			//If FirstSon But Have Brother
			//Move The FirstSon To Brother
			if(!IsEmpty(TempBrother)){
				TempParent->FirstSon = TempBrother;
				if(!IsEmpty(NodeDeleted->FirstSon)) {
					SubTreeDelete(NodeDeleted->FirstSon);	
				}
				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
				free(NodeDeleted);
			}
			//If FirstSon But NotHave Brother
			else {
				TempParent->FirstSon = NULL;
				if(!IsEmpty(NodeDeleted->FirstSon)) {
					SubTreeDelete(NodeDeleted->FirstSon);	
				}
				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
				free(NodeDeleted);
			}
		}
		else {
			
			Address Before;
			//Try To Search Position Before Node
			Before = TempParent->FirstSon;
			while(Before->Brother != NodeDeleted){
				Before = Before->Brother;
			}
			//If Not FirstSon (Brother) And Have Other Brother
			if(!IsEmpty(TempBrother)) {
				Before->Brother = TempBrother;
				if(!IsEmpty(NodeDeleted->FirstSon)) {
					SubTreeDelete(NodeDeleted->FirstSon);	
				}
				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
				free(NodeDeleted);
			}
			
			//If Not FirstSon (Brother) And Not Have Other Brother
			else {
				Before->Brother = NULL;
				if(!IsEmpty(NodeDeleted->FirstSon)) {
					SubTreeDelete(NodeDeleted->FirstSon);	
				}
				NodeDeleted->Parent = NodeDeleted->FirstSon  = NodeDeleted->Brother = NULL;
				free(NodeDeleted);	
			}
		}	
	}
	else SubTreeDelete(NodeDeleted);
	
}

void SubTreeDelete(Address Node){

    if (IsEmpty(Node)) return; 
    //Delete SubTree
    SubTreeDelete(Node->FirstSon);
    SubTreeDelete(Node->Brother);
 
    //Then Delete The Node
    Node->Parent = NULL;
    Node->FirstSon = NULL;
    Node->Brother = NULL;
    free(Node);
}

Infotype Min(Address Node){
	bool Resmi;
	Address Current = Node;
	Resmi = true;
	Infotype Min,TempMin;
	Min=Current->Info;
	
	if(!IsEmpty(Current->FirstSon)){
		do{
			if(Current->FirstSon != NULL && Resmi){
				Current = Current->FirstSon;
				TempMin = Current->Info;
				if(TempMin < Min) Min = TempMin;
			}
			else {
				if(Current->Brother != NULL){
					Current = Current->Brother;
					TempMin = Current->Info;
					if(TempMin < Min) Min = TempMin;
					Resmi = true;
				}
				else {
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
		
	return Min;
	
}

Infotype Max(Address Node){
	bool Resmi;
	Resmi = true;
	Infotype Max,TempMax;
	Address Current = Node;
	Max=Current->Info;
	
	if(!IsEmpty(Current->FirstSon)){
			
		do{
			if(Current->FirstSon != NULL && Resmi){
				Current = Current->FirstSon;
				TempMax = Current->Info;
				if(TempMax > Max) Max = TempMax;
			}
			else {
				if(Current->Brother != NULL){
					Current = Current->Brother;
					TempMax = Current->Info;
					if(TempMax > Max) Max = TempMax;
					Resmi = true;
				}
				else {
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
	
	return Max;
}

int Degree(Address Node){
	Address Current = Node;
	bool Resmi;
	Resmi = true;
	int _Degree=0;
	if(!IsEmpty(Current->FirstSon)){
		Current = Current->FirstSon;
		_Degree++;
		printf("%c ",Current->Info);
		while(!IsEmpty(Current->Brother)){
			Current=Current->Brother;
			_Degree++;
		}
	}
	
	return _Degree;
}

int Height(Address Node){
	return (Depth(Node) + 1);
}

void Leaf(Address Node){
	
	bool Resmi;
	Address Current = Node;
	int _Leaf=0;
	Resmi = true;
	printf("{ ");
	
	if(!IsEmpty(Current->FirstSon)){
			
		do{
			if(!IsEmpty(Current->FirstSon) && Resmi){		
				Current = Current->FirstSon;
			}
			else {
				if(!IsEmpty(Current->Brother)){
					if(IsEmpty(Current->FirstSon)){
						printf("%c ",Current->Info);
						_Leaf++;	
					}
					Current = Current->Brother;
					Resmi = true;
				}
				else {
					if(IsEmpty(Current->FirstSon)){
						printf("%c ",Current->Info);
						_Leaf++;	
					}
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
	printf("} [%d]\n",_Leaf);	

}

int Size(Address Node){
	
	Address Current=Node;
	bool Resmi;
	Resmi = true;
	int _Size=0;
	_Size++;
	if(!IsEmpty(Current->FirstSon)){
		
		do{
			if(!IsEmpty(Current->FirstSon) && Resmi){		
				Current = Current->FirstSon;
				_Size++;
			}
			else {
				if(!IsEmpty(Current->Brother)){
					_Size++;
					Current = Current->Brother;
					Resmi = true;
				}
				else {
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
	
	return _Size;
}

void Ancestor(Address Node){
	int _Ancestor=0;
	Node=Node->Parent;
	printf("{ ");
	if(!IsEmpty(Node)){
		do {
			_Ancestor++;
			printf("%c ",Node->Info);
			Node = Node->Parent;
		}while(!IsEmpty(Node));	
	}
	printf("} [%d]\n",_Ancestor);
	
}

void Descendant (Address Node){
	Address Current=Node;
	bool Resmi;
	int _Descendant=0;
	Current=Current->FirstSon;
	printf("{ ");
	if(!IsEmpty(Current)){
		_Descendant++;
		printf("%c ",Current->Info);
		Resmi = true;
		do{
			if(!IsEmpty(Current->FirstSon) && Resmi){	
				_Descendant++;	
				Current = Current->FirstSon;
				printf("%c ",Current->Info);
			}
			else {
				if(!IsEmpty(Current->Brother)){
					_Descendant++;
					Current = Current->Brother;
					printf("%c ",Current->Info);
					Resmi = true;
				}
				else {
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
	printf("} [%d]\n",_Descendant);
}

Infotype GetRoot(Address Node){

	if(!IsEmpty(Node->Parent)){
		do{
			Node = Node->Parent;
		}while(!IsEmpty(Node->Parent));	
	}
	
	return Node->Info;
}

Infotype GetParent(Address Node){
	return Node->Parent->Info;
}

Infotype GetSon(Address Node){
	return Node->FirstSon->Info;
}

Infotype GetBrother(Address Node){
	return Node->Brother->Info;
}

void SubTree(Address Node){
	Address Current;
	Address Child;
	bool Resmi;
	Child=Node->FirstSon;
	int NumberOfSubTree = 0;
	while(!IsEmpty(Child)){
		if(!IsEmpty(Child->FirstSon)){
			NumberOfSubTree++;
			Current = Child;
			printf("{ ");
			printf("%c ",Current->Info);
			Resmi = true;
			do{
				if(!IsEmpty(Current->FirstSon) && Resmi){	
					Current = Current->FirstSon;
					printf("%c ",Current->Info);
				}
				else {
					if(!IsEmpty(Current->Brother)){
						Current = Current->Brother;
						printf("%c ",Current->Info);
						Resmi = true;
					}
					else {
						Current = Current->Parent;
						Resmi = false;
					}
				}
			}while(Current != Child);
			printf("}, ");
		}
		Child = Child->Brother;
	}
	printf("[%d]\n",NumberOfSubTree);
}

int MaxDegree(Address Node){
	Address Current=Node;
	int MaxDegree;
	int TempMaxDegree;
	bool Resmi;
	Resmi = true;
	TempMaxDegree = 0;
	MaxDegree = 0;
	if(!IsEmpty(Node->FirstSon)){
			
		do{
			if(!IsEmpty(Current->FirstSon) && Resmi){		
				Current = Current->FirstSon;
				TempMaxDegree=1;
			}
			else {
				if(!IsEmpty(Current->Brother)){
					TempMaxDegree+=1;
					Current = Current->Brother;
					Resmi = true;
				}
				else {
					if(TempMaxDegree>=MaxDegree) MaxDegree = TempMaxDegree;
					Current = Current->Parent;
					Resmi = false;
				}
			}
		}while(Current != Node);
	}
	return MaxDegree;
}
