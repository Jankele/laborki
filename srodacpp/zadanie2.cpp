#include <iostream>

using namespace std;

void porownaj(float a, float b)
{
    if(a==b)
        cout << "liczby " << a << " oraz " << b << " sa rowne." << endl;
    else
        cout << "liczby " << a << " oraz " << b << " nie sa rowne." << endl;
}

int main()
{
    float a = 123.4;
    float b = 123.4;
    float c = 124.4;
    porownaj(a,b);
    porownaj(a,c);
    return 0;
}
