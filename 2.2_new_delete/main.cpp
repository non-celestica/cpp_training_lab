#include <cstdio>
#include <vector>
#include <new>    // placement new
#include <cstdlib> // malloc, free

struct MyObject {
    int value;
};

void newAndDelete()
{
    MyObject* pObj = new MyObject; // dynamically allocate and construct
    pObj->value = 42;
    // TODO-1: Printout value of pObj
    // printf("Value via pointer: %d\n", ...);
    delete pObj; // destruct and free
}

void placementNew()
{
    // Size for 10 objects
    size_t poolSize = 10;
    MyObject *pool = static_cast<MyObject*>(std::malloc(poolSize * sizeof(MyObject)));
    if (!pool) {
        printf("Failed to allocate memory pool\n");
        return;
    }

    printf("Memory pool size: %zu\n", poolSize);
    for (size_t i=0; i<poolSize; ++i) {
        printf("\t#%zu address: %p\n", i, (void*)&pool[i]);
    }

    // Create 5 objects inside pool using placement new
    /**
     * So, this example of using placement new is not make much sense, since pool type is the same as objects type
     * just want to demonstrate that placement new() can construct objects in user-provide memory - rather than allocate new memory.
     *
     * In real use cases, this useful when we need to create a new object in memory that already exists, 
     * like mapping hw memory to C++ object in an embedded system.
     */
    printf("Use placement new() to create object, observe the pointer value of each entry and compare of each entry in pool above!\n");
    MyObject* objects[5];
    for (int i = 0; i < 5; ++i) {
        // Create call MyObject constructor with 
        objects[i] = new (&pool[i]) MyObject;
        objects[i]->value = (i*10);
        printf("\tObject %d at %p\n", i, (void*)objects[i]);
    }

    printf("Accessing object values:\n");
    // TODO-2: Print out value of each object created above

    // Free the whole pool memory
    std::free(pool);
}

void rawArray()
{
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void vector()
{
    std::vector<int> vec = {100, 200, 300};
    vec.push_back(400);  // dynamic resizing
    for (size_t i = 0; i < vec.size(); ++i) {
        printf("vec[%zu] = %d\n", i, vec[i]);
    }
}

int main() {
    // ----------- 1. new/delete -----------
    printf("---- new/delete example ----\n");
    newAndDelete();

    // ----------- 2. Placement new -----------
    printf("\n---- placement new example ----\n");
    placementNew();

    // ----------- 3. Raw arrays -----------
    printf("\n---- raw array example ----\n");
    rawArray();

    // ----------- 4. std::vector -----------
    printf("\n---- std::vector example ----\n");
    vector();

    return 0;
}