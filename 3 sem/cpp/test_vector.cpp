#include <vector>
#include <iostream>
#include <cstdlib>
using	namespace std;
int main(int argc, char const *argv[])
{
	vector<int> v1;
	vector<bool> v2;
	vector<int>::iterator it1, it11;
	vector<bool>::iterator it2, it22;
	int now;
		for (int i = 0; i < 3; ++i)
		{
			cin >> now;
			v1.push_back(now);
			v2.push_back(true);
		}
		it1 = v1.begin();
		it2 = v2.begin();
		while(it1 != v1.end() && it2 != v2.end()){
			cout << *it1 << '\t' << *it2 <<'\n';
			it1++; it2++;
		}
		cout << endl;
		it1 = v1.begin();
		it2 = v2.begin();
		v1.erase(it1);
		v2.erase(it2);
		while(it11 != v1.end() && it22 != v2.end()){
			cout << *it11 << '\t' << *it22 <<'\n';
			it1++; it2++;
		}
		cout << endl;
		v1.erase(it1);
		v2.erase(it2);
		while(it1 != v1.end() && it2 != v2.end()){
			cout << *it1 << '\t' << *it2 <<'\n';
			it1++; it2++;
		}

		if(v1.empty()) cout << "\n v is empty\n";
	return 0;
}
/*private:
	int size;
	int *arr = (int*) malloc (1 * sizeof(int));
	int *resultArray = (int*) malloc (1 * sizeof(int));
	bool *help = (bool*) malloc (1 * sizeof(bool));
	bool *helpMem = (bool*) malloc (1 * sizeof(bool));
	void setSize(){
		cout << "Enter the number of elements: ";
		cin >> size;
		array = (int*) realloc(array, sizeof(int)*size);
		resultArray = (int*) realloc(resultArray, sizeof(int)*size);
	}
*/

	private:
	int size;
	int *array, *resultArray;
	bool *help, *helpMem;
	void setSize(){
		cout << "Enter the number of elements: ";
		cin >> size;
		array = new int[size];
		resultArray = new int [size];
	}
protected: