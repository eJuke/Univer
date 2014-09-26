// countHelp - к-во эл-тов, доступных для сравнения, за текущий проход
// 
// 
// 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

class Sort{
public:
	void startTest(const char *typeOfEx, const char *typeOfInput){
		cout << "Enter the number of elements: ";
		cin >> size;
		setSize(size);
		if (*typeOfEx == 'c') compare();
		else{
			arrFill(typeOfInput);
			if (*typeOfEx == 't') tSort();
			if (*typeOfEx == 'r') rSort(typeOfInput);
			arrPrint();
		}
	}

private:
	int size;
	int *array, *resultArray;
	bool *help, *helpMem;
	vector<int> helpRadix[10];
	vector<int>::iterator itRadix;

	void compare(){
		unsigned long long cmp, cmp2;
		cout << "size" << "\t|\t" << "radix" << "\t|\t" << "tournament" << endl;
		arrFill("r");
		asm("rdtsc" : "=A"(cmp2));
		rSort("r");
		asm("rdtsc" : "=A"(cmp));
		cout << size << "\t|\t" << cmp-cmp2;
		asm("rdtsc" : "=A"(cmp2));
		tSort();
		asm("rdtsc" : "=A"(cmp));
		cout << "\t|\t" << cmp-cmp2;
	}

	void setSize(int size){
		array = new int[size];
		resultArray = new int [size];
		help = new bool [size];
		helpMem = new bool [size];
	}

	void arrPrint(){
		cout << "INPUT" << '\t' << "SORTED" << endl; 
		for (int i = 0; i < size; ++i)
		{
			cout << array[i] << '\t' << resultArray[i] << endl;
		}
	}

	void arrFill(const char *typeOfInput){
		long long set_rand;
		asm("rdtsc" : "=A"(set_rand));
		srand(set_rand);
		int now;
		ifstream input;
		do{
			if (*typeOfInput == 'k'){ 
				cout << "Enter the values:\n";
				for (int i = 0; i < size; ++i){
					cin >> now;
					array[i] = now;
					help[i] = true;
					helpMem[i] = true;
				}
			}
			if (*typeOfInput == 'f'){
				input.open("array.txt");
				for (int i = 0; i < size; ++i){
					input >> now;
					array[i] = now;
					help[i] = true;
					helpMem[i] = true;
				}
				input.close();
			}
			if (*typeOfInput == 'r'){
				for (int i = 0; i < size; ++i){
					array[i] = (rand()%(size*2)+1);
					help[i] = true;
					helpMem[i] = true;
				}
			}
			break;
		}while(true);
	}

	void tSort(){
		int countHelp = 10, countMem, arrMem;
		bool memCheck = false;
		for (int i = 0; i < size; ++i){
			countHelp = 0;
			countMem = 0;
			while(true){
				memCheck = false;
				countHelp = 0;
				for (int j = 0; j < size; ++j)	if (help[j] == true) countHelp++;
				if (countHelp == 1) break;
				for (int it = 0; it < size; ++it){
					if(help[it]){
						if(memCheck){
							if(array[arrMem] > array[it]) help[arrMem] = false;
							else if (array[arrMem] < array[it]) help[it] = false;
							else if (array[arrMem] == array[it]) help[it] = false;
							memCheck = false;
						}
						else{
							arrMem = it;
							memCheck = true;
						}
					}
				}
			}
			countMem = 0;
			while (!help[countMem]) countMem++;
			resultArray[i] = array[countMem];
			helpMem[countMem] = false;
			for (int b = 0; b < size; b++) help[b] = helpMem[b];
		}
	}

	void rSort(const char *typeOfInput){
		int length;
		if ((*typeOfInput == 'k') || (*typeOfInput == 'f')) {
			cout << "Pls enter the max length of number" << endl;
			cin >> length;
		}
		else {
			length = 1;
			int maxNumber = size*2+1;
			while (maxNumber/10 != 0){
				maxNumber /= 10;
				length++;
			}
		}
		for (int i = 0; i < size; ++i) resultArray[i] = array[i];
		int mem, helpRMem;
		for (int count = 0; count < length; ++count){
			for (int i = 0; i < size; ++i){
				mem = (resultArray[i] % newPow(10, count+1)) / newPow(10 , count);
				helpRadix[mem].push_back(resultArray[i]);
			}
			helpRMem = 0;
			for (int i = 0; i < 10; ++i){
				for (int j = 0; j < helpRadix[i].size(); ++j) resultArray[helpRMem++] = helpRadix[i][j];
				helpRadix[i].clear();
			}
		}
	}

	int newPow(int base, int exp){
		int pow = 1;
		for (int i = 0; i < exp; ++i) pow *= base;
		return pow;
	}
};


int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cout << "Error. Enter the \"" << argv[0] << " h\" for help";
		return 0;
	}
	if ((argv[1][0] == 'h') || (argv[1][0] == 't') || (argv[1][0] == 'r') || (argv[1][0] == 'c')){
		if (argv[1][0] == 'h') {
			cout << endl << "Use a command " << argv[0] << " <arg1> <arg2>" << endl << "Arguments:" << endl 
			<< "[arg1]:" << endl << '\t' << "h - help" << endl << '\t' << "t - turnir(tournament) sort"
			 << endl << '\t' << "r - radix sort" << endl << '\t' << "c - compare between 2 methods" 
			 << endl << "[arg2]:" << endl << '\t' << "k - enter the values from the keyboard" << endl 
			 << '\t' << "f - read values from the file" << endl << '\t' << "r - use a random values" << endl;
		}
		else if (argv[1][0] == 'c'){
				Sort example;
				example.startTest(argv[1], argv[2]);
			}
		else {
			if (argc < 3) cout << "use a second argument";
			else if ((argv[2][0] == 'k') || (argv[2][0] == 'f') || (argv[2][0] == 'r')){
				Sort example;
				example.startTest(argv[1], argv[2]);
			}
			else cout << "use a right second argument";
		}
	}
	return 0;
}