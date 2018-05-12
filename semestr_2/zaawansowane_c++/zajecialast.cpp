class C {
public:
    C(const char* text) {
        table = new char[strlen(text) + 1];
        strcpy(table, text);
    }
    ~C() {
        delete [] table;

    }

    char* getStr() {
        return table;
    }

    C& operator=(const C& other)
    {
        delete[] table;
        table = new char[strlen(other.table) + 1];
        for(int i=0;i<strlen(table);i++)
            table[i] = other.table[i];
        return *this;
    }

    c& operator=(C&& other)
    {
        table = other.table;
        other.table = nullptr;
        return *this;
    }
    
private:
    char* table;
};