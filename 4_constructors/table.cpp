#include "table.h"
#include <cstring>  // for memcpy

static int table_cnt = 0;

// Constructor
// TODO-1: initial id using variable table_cnt then increase table_cnt by 1, so we have unique id
Table::Table(int sz): m_size(sz)
{
    printf("Construct Table(int sz)\n");
    m_mem = new int[m_size];
}

// TODO-1: initial id using variable table_cnt then increase table_cnt by 1, so we have unique id
Table::Table(std::string n, int sz): name(n), m_size(sz)
{
    printf("Construct Table(std::string n, int sz)\n");
    m_mem = new int[m_size];
}

// TODO-6: Copy constructor definition with deep copy (don't forget about id)

// Destructor
Table::~Table()
{
    printf("Destroy ~Table()\n");
    if (m_mem != nullptr)
        delete[] m_mem;
}

void Table::write(int row, int data)
{
    if (row >= 0 && row < m_size)
        m_mem[row] = data;
}

int Table::read(int row) const
{
    if (row >= 0 && row < m_size)
        return m_mem[row];
    return 0; // or some error value
}

void Table::display()
{
    printf("Table id: %d name: %s m_size: %d\n", id, name.c_str(), m_size);
    for (int i=0; i<m_size; i++)
    {
        printf("\t#%d (addr: %p): %d\n", i, &m_mem[i], m_mem[i]);
    }
}
