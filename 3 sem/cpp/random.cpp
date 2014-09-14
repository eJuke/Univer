#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	ofstream random;
	random.open("random.txt");
	cout << "How much numbers do u want?\n";
	int weight, module;
	cin >> weight;
	cout << "Enter the max of rand\n";
	cin >> module;
	long long x;
	asm("rdtsc" : "=A"(x));
	srand(x);
	for (int i=0; i<weight; i++){
		random << rand()%module << " ";
	}
	random.close();
}