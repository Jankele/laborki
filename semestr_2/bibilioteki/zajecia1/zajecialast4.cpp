template<class T>
std::ostream& operator <<(std::ostream& os, const std::list<T>& l) {
    os << "[";
	for (std::list<T>::const_iterator iterator = intList.begin(); iterator != intList.end(); ++iterator)
	{
    	os << " " << *iterator;
	}
    os << " ]";
    return os;
}