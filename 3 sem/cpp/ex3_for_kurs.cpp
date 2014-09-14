#include <iostream>
#include <fstream>
using namespace std;

class tunnelSort{
private:
	int *array;
	int *resultArray;
	int size;
public:
	setSize(){
		cout << "Enter the number of elements: ";
		cin >> size;
		int *array = new int [size];
	}
	arrFill(){
		int menu;
		cout << "How do u want to fill an array?\n" <<
		"(1 - Enter from keyboard, 2 - Read from file, 3 - Fill by a random numbers)\n";
		cin >> menu;
		switch (menu){
			case 1: 

		}
	}
	arrSort(){

	}

};


int main(){
	tunnelSort.setSize();
}