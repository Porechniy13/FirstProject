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
	int height; //Высота дерева (количество слоёв)

	//Конструктор, создающий вершину дерева (символ на вход)
	Tree(char _ch){
		height = 0;
		list = new Node();
		list->data = _ch;
		list->left = NULL;
		list->right = NULL;
		height++;
	}
	
	//Функция добавления вершины (лист и символ на вход)
	void AddItem(Node* _list, char _ch){
		if (_list->data == NULL) {
			_list->data = _ch;
			_list->left = NULL;
			_list->right = NULL;
			height++;
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
};

void main(){
	Tree* BinTree = new Tree('C');	//Создание вершины 'С'
	BinTree->AddItem(BinTree->list, 'B');  //Создание листа 'B' налево
	BinTree->AddItem(BinTree->list, 'D');  //Создание листа 'D' направо
	BinTree->AddItem(BinTree->list, 'A');  //Создание листа 'A' в третий слой налево
	BinTree->PrintTree(BinTree->list);
	system("pause");
}