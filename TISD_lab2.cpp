#include <iostream>
#include <conio.h>
#include <exception>

using namespace std;

struct Node{
	char data;
	Node* left; //��������� �� ����� �������
	Node* right; //��������� �� ������ �������
};

class Tree{
public:
	Node* list; //������� ������
	int height; //������ ������ (���������� ����)

	//�����������, ��������� ������� ������ (������ �� ����)
	Tree(char _ch){
		height = 0;
		list = new Node();
		list->data = _ch;
		list->left = NULL;
		list->right = NULL;
		height++;
	}
	
	//������� ���������� ������� (���� � ������ �� ����)
	void AddItem(Node* _list, char _ch){
		if (_list->data == NULL) {
			_list->data = _ch;
			_list->left = NULL;
			_list->right = NULL;
			height++;
		} 
		else
		{
			if ((int)_ch < (int)_list->data){ //�������� �������� � ASCII ����
				if (_list->left == NULL){
					_list->left = new Node();
				}
				AddItem(_list->left, _ch); 
			}
			if ((int)_ch > (int)_list->data){ //�������� �������� � ASCII ����
				if (_list->right == NULL){
					_list->right = new Node();
				}
				AddItem(_list->right, _ch);
			}
		}
	}

	//������� ������ ������ �� ����� (������� �� ����)
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
	Tree* BinTree = new Tree('C');	//�������� ������� '�'
	BinTree->AddItem(BinTree->list, 'B');  //�������� ����� 'B' ������
	BinTree->AddItem(BinTree->list, 'D');  //�������� ����� 'D' �������
	BinTree->AddItem(BinTree->list, 'A');  //�������� ����� 'A' � ������ ���� ������
	BinTree->PrintTree(BinTree->list);
	system("pause");
}