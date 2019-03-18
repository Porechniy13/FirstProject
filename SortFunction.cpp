#include <iostream>

using namespace std;

struct Node{
	char data;
	Node* next;
	Node* prev;
};

class List{
public:
	Node* top;
	int size;

	List(){						//Конструктор для создания объекта класса 
		top = new Node();
		top->next = NULL;
		top->prev = NULL;
		size = 0;
	}

	void CreatByStr(Node* _top, char* str){		//Создание списка по строке
		Node* buff = _top;
		for (int i = 0; str[i]; i++){
			_top->data = str[i];
			_top->next = new Node();
			if (i == 0){
				_top->prev = NULL;
				_top = _top->next;
			}
			else {
				_top->prev = buff;
				buff = _top;
				_top = _top->next;
			}
			size++;
		}
	}

	char* SortList(Node* _top){			//Сортировка списка, на выход - массив символов
		char* str = new char[100];
		Node* buff = _top;
		_top = buff->next;
		int counter = 0;
		int cnt = 0;
		while(buff->next){		
			counter = 0;
			while(_top->data){
				if (_top == buff){
					_top = _top->next;
					continue;
				}
				if ((int)buff->data == (int)_top->data){
					counter = 0;
					break;
				}
				else {
					counter = 1;
					_top = _top->next;
				}
			}
			if (counter == 1){
				str[cnt] = buff->data;
				cnt++;
			}
			_top = buff->next;
			buff = _top;
			_top = this->top;
		}
		return str;
	}

	void PrintList(Node* _top){   //Вывод списка на экран
		cout << endl;
		while (_top->data){
			cout << _top->data << endl;
			_top = _top->next;
		}
		cout << endl;
	}
};

int main(){
	List* obj = new List();			//Создание пустого списка
	char* str = new char();			//Создание массива символов и его
	str = "DANYAPIDOR";				//инициализация.
	
	obj->CreatByStr(obj->top, str); //Инициализация списка по заданному массиву
	obj->PrintList(obj->top);		//Вывод на экран

	str = obj->SortList(obj->top);	//Массив символов сортируется при помощи списка (нахуя - не знаю)

	for (int i = 0; str[i] != NULL; i++){  //Вывод этой хуйни на экран
		cout << str[i];
	}
	system("pause");  //Конец ёпта
}