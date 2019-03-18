#include <iostream>
#include <conio.h>
#include <exception>

using namespace std;

struct Node{
	char data;
	Node* left; //Указатель на левую вершину
	Node* right; //Указатель на правую вершину
};

class Tree{
public:
	Node* list; //Вершина дерева

	//Конструктор, создающий пустое дерево
	Tree(){
		list = new Node();
		list->left = NULL;
		list->right = NULL;
	}

	//Конструктор, создающий вершину дерева (символ на вход)
	Tree(char _ch){
		list = new Node();
		list->data = _ch;
		list->left = NULL;
		list->right = NULL;
	}


	
	//Функция добавления вершины (лист и символ на вход)
	void AddItem(Node* _list, char _ch){
		if (_list->data == NULL) {
			_list->data = _ch;
			_list->left = NULL;
			_list->right = NULL;
		} 
		else
		{
			if ((int)_ch < (int)_list->data){ //Проверка символов в ASCII коде
				if (_list->left == NULL){
					_list->left = new Node();
				}
				AddItem(_list->left, _ch); 
			}
			if ((int)_ch > (int)_list->data){ //Проверка символов в ASCII коде
				if (_list->right == NULL){
					_list->right = new Node();
				}
				AddItem(_list->right, _ch);
			}
		}
	}

	//Функция вывода дерева на экран (вершина на вход)
	void PrintTree(Node* _list){
		if (!_list->data){
			cout << "Empty tree!" << endl;
		} 
		else
		{
			cout << _list->data << endl;
			if (_list->left){			
			PrintTree(_list->left);
			}
			if (_list->right){			
			PrintTree(_list->right);
			}
		}
	}

	void ClearTree(Node* _list){  //Функция очистки дерева
		if (!_list->data){
			cout << "Empty tree!" << endl;
		} 
		else
		{
			if (_list->left){			
			ClearTree(_list->left);			
			}
			if (_list->right){			
			ClearTree(_list->right);
			}
			_list->data = NULL;
			_list->right = _list->left = NULL;
		}
		if (_list != list){
			delete _list;
		}
	}

	 static Tree* DeleteLit(Tree* _Tr,char* _str){     //Функция удаления согласных букв из дерева, объект класса на выход
		char* buff = new char[100];
		char* dia = new char[30];
		int counter = 0;
		int cnt = 0;
		dia = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";

		//Построение новой строки для генерации дерева с исключением согласных букв
		for (int i = 0; _str[i]; i++){
			counter = 0;
			for (int j = 0; dia[j]; j++){
				if ((int)_str[i] == (int)dia[j]){
					counter = 0;
					break;
				} 
				else
				{
					counter = 1;
				}
			}
			if (counter == 1){
				buff[cnt] = _str[i];
				cnt++;
			}
			
		}
		_Tr->ClearTree(_Tr->list);
		Tree* _Bin = new Tree();
		for (int i = 0; i < cnt; i++){
			_Bin->AddItem(_Bin->list, buff[i]);
		}
		return _Bin;
	}
	
	 ~Tree(){
		 ClearTree(this->list);
	 }
};

void main(){
	int menu = 1;
	char* str = new char[100];	
	Tree* BinTree;
	BinTree = new Tree();
	while (menu){
		cout << endl;
		cout << "1>Create binary tree by your string" << endl;
		cout << "2>Add new element" << endl;
		cout << "3>Clear tree" << endl;
		cout << "4>Delete literal by tree" << endl;
		cout << "5>Print tree" << endl;
		cout << "0>Exit" << endl;
		cin >> menu;
	switch(menu){
		case 1:
			cout << endl;
			BinTree->ClearTree(BinTree->list);
			cout << "Please, enter the string: ";
			cin >> str;			
			for (int i = 0; str[i]; i++)
			{
				BinTree->AddItem(BinTree->list, str[i]);
			}
			cout << "Completed!" << endl;
			break;
		case 2:			
			cout << endl;
			BinTree->list->data = BinTree->list->data;
			cout << "Please, enter the symbol: ";
			cin >> str;
			BinTree->AddItem(BinTree->list, str[0]);
			cout << "Completed!" << endl;
			break;
		case 3:
			cout << endl;
			BinTree->ClearTree(BinTree->list);
			cout << "Completed!" << endl;
			break;
		case 4:
			cout << endl;
			BinTree = BinTree->DeleteLit(BinTree,str);
			cout << "Completed!" << endl;
			break;
		case 5:
			cout << endl;
			try{
				BinTree->PrintTree(BinTree->list);
			}
			catch(...){
				cout << "Error! Empty tree!" << endl;
			}
			break;
		case 0:
			delete BinTree;
			exit;
			break;
		default: 
			menu = 1;
			break;
	}
	}
	system("pause");
}