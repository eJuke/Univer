#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(){
	ofstream random;
	cout << "How much numbers do u want?\n";
	int weight, module;
	string name;
	cin >> weight;
	cout << "Enter the max of rand\n";
	cin >> module;
	long long x;
	asm("rdtsc" : "=A"(x));
	srand(x);
	cout << "Enter the name of file\n";
	cin >> name;
	name +=".txt";
	random.open(name.c_str());
	for (int i=0; i<weight; i++){
		random << rand()%module << " ";
	}
	random.close();
}