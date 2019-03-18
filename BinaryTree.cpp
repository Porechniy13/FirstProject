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
		delete _list;
	}

	 static Tree* DeleteLit(char* _str){     //Функция удаления согласных букв из дерева, объект класса на выход
		char* buff = new char[100];
		char* dia = new char[30];
		int counter = 0;
		int cnt = 0;
		dia = "BCDFGHJKLMNPQRSTVWXZ";

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
		Tree* _Bin = new Tree(buff[0]);
		for (int i = 1; i < cnt; i++){
			_Bin->AddItem(_Bin->list, buff[i]);
		}
		return _Bin;
	}
	
};

void main(){
	char* str = new char[100];	
	str = "STRINGGULP";
	Tree* BinTree = new Tree(str[0]);
	for (int i = 1; str[i]; i++)
	{
		BinTree->AddItem(BinTree->list, str[i]);
	}
	BinTree->PrintTree(BinTree->list);
	cout << endl;
	BinTree->ClearTree(BinTree->list);
	BinTree = BinTree->DeleteLit(str);
	BinTree->PrintTree(BinTree->list);
	system("pause");
}