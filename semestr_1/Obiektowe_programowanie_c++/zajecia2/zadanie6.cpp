#include <iostream>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

string to_string(char *a)
{
	string b(a);
	return b;
}

char *to_char(string a)
{
	int n = a.length();
	char *b = new char[n+1];
	strcpy(b, a.c_str());
	return b;
}

void odwroc_char(char *a)
{
	int n = strlen(a);
	char *temp = new char[n];
	int j=n-1;
	for(int i=0;i<n/2;i++)
	{
		char temp=a[i];
		a[i]=a[j-i];
		a[j-i]=temp;
	}
}

void odwroc_string(string &a)
{
	reverse(a.begin(), a.end());	
}

int main()
{
	const char *tekst = "tekst";
	int n = strlen(tekst);
	char *cha = new char[n];
	strncpy(cha, tekst, n);	
	string strin(to_string(cha));
	cout << strin << endl;
	char *chara = to_char(strin);
	cout << chara << endl;
	odwroc_char(cha);
	cout << cha << endl;
	odwroc_string(strin);
	cout << strin <<endl;
	return 0;
}
