#include "table.h"

int main()
{
    Table t1("table1", 5);

    for (int i = 0; i < t1.size(); ++i)
        t1.write(i, i * 10);

    
    Table t2 = t1;

    t1.display();
    t2.display();

    // TODO-3: Rename t2 to 'table2' then display again

    // Modify original
    t1.write(0, 999);

    // TODO-4: Check output from t1 and t2???
    t1.display();
    t2.display();

    printf("End program!\n");
    return 0;
}