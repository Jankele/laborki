template <typename T>
class C {
public:
    C(T* data, size_t size) {
        table = new T[size];
        _size = size;
    }
    ~C() {
        delete [] table;
    }

    T* getTable() {
        return table;

        }
    C<T>& operator=(const C& other)
    {
        _size = other._size;
        delete[] table;
        table = new T[_size];
        for(size_t i=0;i<_size;i++)
            table[i] = other.table[i];
        return *this;
    }

    /*C& operator=(C&& other)
    {
        table = other.table;
        other.table = nullptr;
        return *this;
    }*/

    C<T>& operator=(C&& other)
    {
        delete[] table;
        table = std::exchange(other.table, nullptr);
        size = std::exchange(other.size, 0);
    }
private:
    T* table;
    size_t _size;
};