#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct oneway_list {
	int number;
	int next;
};

class new_list {
private:
	oneway_list list[100];
public:

	void del_atpos() {
		cout << "Enter the number of position(0<=pos<100):";
		int pos = 0, count = 0, check = 0, check_prev = 0;
		cin >> pos;
		do{
			check=list[check].next;
			count++;
		}while(count<pos);
		do{
			check_prev = check;
			check=list[check].next;
			list[check_prev].number=list[check].number;
			count++;
		}while(count<99);
		list[check].number='\0';
	}

	void list_fill() {
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
		int count = 0, count_last;
		for (int i=0; i<99; i++){
			if(menu) input >> list[count].number;
			else cin >> list[count].number;
			count_last = count;
			while (mass[count])	{count=rand()%100;
								cout << count << "lalala\n";}
			list[count_last].next = count;
			mass[count]=true;
		}
		if(menu) input >> list[count].number;
		else cin >> list[count].number;
		list[count].next = -1;

	}

	void print_list() {
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
	new_list test;
	test.list_fill();
	test.print_list();
	test.del_atpos();
	test.print_list();
}