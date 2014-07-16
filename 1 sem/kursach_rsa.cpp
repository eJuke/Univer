#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//функция для нахождения простых чисел(взята из 1 лабораторной)
int pr(int e){
	int k, z;
	for (int i=e-20; i<e; i++){
		k=0;
		for (int j=1; j<=i; j++){
			if (i%j==0) k++;}
		if (k==2) z=i;}
	return z;
}
//Алгоритм Евклида
int e_gcd(int a, int b){
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}

int main()
{
//создание ключа
	int s_key, o_key, module;
	long long x;
	cout << "Key generation process..." << endl;	
	for(;;){
		asm("rdtsc" : "=A"(x));
		srand(x);
		int prime1=pr(rand()%100), prime2;
		while(prime2==prime1)	prime2=pr(rand()%100);
		cout << prime1 << "\t" << prime2 << endl;
		module=prime2*prime1;	
		int d2=0;
		while (d2!=1){
			s_key=rand()%100;
			d2=e_gcd(s_key, ((prime1-1)*(prime2-1)));}
		int e2=0;
		o_key=0;
		while (e2!=1){
			o_key = ++o_key;
			e2=(o_key*s_key)%((prime1-1)*(prime2-1));}
		if (o_key&s_key!=1 && o_key!=s_key && o_key&s_key<10000 && o_key&s_key>30) break;  
	}
	cout << '{' << o_key << ',' << "\t" << module << '}' << " - Open key" << endl;
	cout << '{' << s_key << ',' << "\t" << module << '}' << " - Secret key" << endl << endl;
//ввод текста
	string s1;
	getline(cin, s1);
	int count = s1.size();
	char *text_mass = new char [count];
	strcpy(text_mass, s1.c_str());
	int *Crypt_text = new int [count];
	int *DeCrypt_text = new int [count];
	int c, b=301;
//шифрование
	for (int i=0; i<count; i++){
		c=1;
		unsigned int j=0;
		int symbol_code = (static_cast<int>(text_mass[i]))+b;
		while (j<o_key){
			c=c*symbol_code;
			c=c%module;
			j++;}
		Crypt_text[i]=c;
	}
//дешифрование
	int m;
	for (int i=0; i<count; i++){
		m=1;
		unsigned int j=0;
		while(j<s_key){
			m=m*Crypt_text[i];
			m=m%module;
			j++;}
		m=m-b;
		DeCrypt_text[i]=m;
	}		
//вывод данных на экран
	cout << endl << setw(5) << "Text" << setw(6) << "ASCII"
	<< setw(20) <<"Crypt_Text/Block#" << setw(14)
	<< "ASCIIdecrypt" << setw(14) << "Text decrypt" << endl
	<< "------------------------------------------------------------" << endl;
	for (int j = 0; j < count; j++)
	{
		cout << setw(5) << text_mass[j] << setw(6) << static_cast<int>(text_mass[j]) << setw(20)
		<< Crypt_text[j] << setw(14) << DeCrypt_text[j] << setw(14) << static_cast<char>(DeCrypt_text[j]) << endl;
	}
}