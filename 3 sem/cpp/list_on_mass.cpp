#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct onewayList {
	int number;
	int next;
};

class newList {
private:
	onewayList list[100];
public:

	void delAtPos() { //удаление элемента
		cout << "Enter the number of position(0<=pos<100):";
		int pos = 0, count = 0, check = 0, checkPrev = 0;
		cin >> pos;
		do{
			check=list[check].next;
			count++;
		}while(count<pos); //проход до позиции элемента
		do{
			checkPrev = check; 
			check=list[check].next;
			list[checkPrev].number=list[check].number;
			count++;
		}while(count<99); //сдвиг списка (при сдвиге искомый элемент удаляется)
		list[check].number='\0';
	}

	void listFill() { //заполнение списка
		long long x;
		asm("rdtsc" : "=A"(x));
		srand(x);
		bool mass[100], menu;
		cout << "Do u want to enter the numbers from keyboard or read it from file? (0 for keyboard, 1 for file)";
		cin >> menu;
		ifstream input;
		for (int i = 0; i < 100; ++i) mass[i]=false;
		if(menu)	input.open("random.txt");
		mass[0] = true;
		int count = 0, countLast;
		for (int i=0; i<99; i++){
			if(menu) input >> list[count].number;
			else cin >> list[count].number;
			countLast = count; //запись позиции текущего элемента
			while (mass[count])	count=rand()%100; //выдача случайного, не повторяющегося номера
			list[countLast].next = count; //запись в структуру позиции следующего элемента
			mass[count]=true;
		}
		if(menu) input >> list[count].number;
		else cin >> list[count].number;
		list[count].next = -1; //последний элемент

	}

	void printList() { //вывод списка
		cout << "POS" << '\t' << '\t' << "NUMBER\n";
		int check=0, count=0;
		do{
			cout << count << '\t' << "|" << '\t' << list[check].number << '\n';
			check = list[check].next;
			count++;
		}while(check!=-1);
	}

};


int main (){
	newList test;
	test.listFill();
	test.printList();
	test.delAtPos();
	test.printList();
}