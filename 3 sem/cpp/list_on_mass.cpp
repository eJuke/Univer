#include <iostream>
#include <cstdlib>

using namespace std;

class new_list {
private:
	int mass [100];

public:

	void del_atpos() {
		cout << "Enter the number of position(0<=pos<100):";
		int pos = 0;
		cin >> pos;
		for (; pos<99; pos++){
			mass[pos]=mass[pos+1];
		}
		mass[99] = '\0';
	}

	void list_fill() {
		long long x;
		asm("rdtsc" : "=A"(x));
		srand(x);
		for (int i=0; i<100; i++){
			mass[i]=rand()%100;
		}
	}

	void print_list() {
		cout << "POS" << '\t' << '\t' << "NUMBER\n";
		for (int i=0; i<100; i++){
			cout << i << '\t' << "|" << '\t' << mass[i] << '\n';
		}
	}
};


int main (){
	new_list test;
	test.list_fill();
	test.print_list();
	test.del_atpos();
	test.print_list();
}