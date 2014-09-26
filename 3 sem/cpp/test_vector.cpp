#include <vector>
#include <iostream>
#include <cstdlib>
using	namespace std;
int main(int argc, char const *argv[])
{
	vector<int> v1;
	vector<int>::iterator it1;
	it1 = v1.end();
	v1.insert(it1, 55);
	it1 = v1.end();
	v1.insert(it1, 66);
	cout << v1[0] << " , " << v1[1];
	return 0;
}

