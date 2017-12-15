#include <iostream>
#include <vector>

using namespace std;

void wypisztab(int *a, int n)
{
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;	
}

void polacztab(int *a, int *b, int *c,int n)
{
	for(int i=0;i<n;i++)
	{
		c[i] = a[i];
		c[i+n] = b[i];
	}
}

void wypiszwektor(vector <int> a, int n)
{
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}

void polaczwektor(vector <int> a, vector <int> b, vector <int> ab)
{

	ab.reserve(a.size() + b.size());
	ab.insert(ab.end(), a.begin(), a.end());
	ab.insert(ab.end(), b.begin(), b.end());
}

int main()
{
//tablice
	int n = 9;
	int tab3[2*n];
	int tab1[] = {1,2,3,4,5,6,7,8,9};
	wypisztab(tab1, n);
	int tab2[] = {9,8,7,6,5,4,3,2,1};
	wypisztab(tab2, n);
	polacztab(tab1, tab2, tab3, n);
	wypisztab(tab3, 2*n);
//vectory
	vector <int> wektor;
	vector <int> wektor2;
	vector <int> wektor3;
	for(int i=0;i<n;i++)
	{
		wektor.push_back(i);
		wektor2.push_back(i+10);
	}
	wypiszwektor(wektor, n);	
	wypiszwektor(wektor2, n);
	polaczwektor(wektor, wektor2, wektor3);
	wypiszwektor(wektor, 18);	
	return 0;
}

