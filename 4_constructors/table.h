#ifndef TABLE_H
#define TABLE_H

#include <cstdio>
#include <string>

class Table
{
public:
    Table(int sz);
    Table(std::string n, int sz); // Constructor
    // TODO-5: create copy constructor which doing deep copy and add prefix 'copy-' to name if name exist
    // Table(const Table& other);
    ~Table();                  // Destructor

    void write(int row, int data);
    int read(int row) const;
    int size() const { return m_size; }

    void display();

    // TODO-2: Add function to set name to table

private:
    const int id;
    std::string name;
    int* m_mem;    // pointer to dynamically allocated memory
    int m_size;
};

#endif