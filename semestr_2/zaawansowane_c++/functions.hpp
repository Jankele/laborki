#include <iostream>
#include <vector>

template<typename T>
class String
{
	public:
	String() {}
	void create(T const&);	
	void add(T const&, T const&);

	private:
		std::vector<T> wektor;
		std::vector<T> wektor2;
};

template<class T>
void String<T>::create(T const& w)
{
	wektor.push_back(w);
}

template<class T>
void String<T>::add(T const& w, T const& y)
{
	w.insert( w.end(), y.begin(), w.end() );
}
