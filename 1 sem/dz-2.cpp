#include <iostream>
using namespace std;
int main () 
{
int n, j=2, i=0; // вводим переменные
cout << "enter the number:" << endl;
cin >> n; // ввод N
cout << endl;
for (i=2; i<=n; i++){ // перебор всех чисел от 2 до N
	while (j<=i){
		if (i%j == 0) break; // если остаток равен 0, то цикл останавливается
		else j++;
	}
	if (j==i) cout << j << endl; // вывод числа, если оно простое
	j=2;
}
system("pause"); // чтобы консоль не закрывалась
return 0;
}