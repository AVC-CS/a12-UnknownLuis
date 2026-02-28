#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// ==============================
// DATA SEGMENT (Initialized globals)
// ==============================
int globalInit1 = 100;
int globalInit2 = 200;

// ==============================
// BSS SEGMENT (Uninitialized globals)
// ==============================
int globalUninit1;
int globalUninit2;

// Stack check function
void checkStack(int* parentAddr) {
    int childVar = 0;

    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;

    cout << "Address from main (parent frame): " << parentAddr << endl;
    cout << "Address of parameter (child frame): " << &parentAddr << endl;
    cout << "Address of childVar (child frame): " << &childVar << endl;

    if (parentAddr > &childVar)
        cout << "Stack grows: DOWN" << endl;
    else
        cout << "Stack grows: UP" << endl;

    cout << endl;
}

int main() {

    // STACK variable
    int mainLocalVar = 50;

    // HEAP allocations (larger size for clarity)
    void* heap1 = malloc(1024);
    void* heap2 = malloc(1024);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // ==============================
    // TEXT SEGMENT
    // ==============================
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "Address of main(): " << (void*)&main << endl;
    cout << "Address of checkStack(): " << (void*)&checkStack << endl;
    cout << endl;

    // ==============================
    // DATA SEGMENT
    // ==============================
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "globalInit1 address: " << &globalInit1 
         << " value: " << globalInit1 << endl;
    cout << "globalInit2 address: " << &globalInit2 
         << " value: " << globalInit2 << endl;
    cout << endl;

    // ==============================
    // BSS SEGMENT
    // ==============================
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "globalUninit1 address: " << &globalUninit1 
         << " value: " << globalUninit1 << endl;
    cout << "globalUninit2 address: " << &globalUninit2 
         << " value: " << globalUninit2 << endl;
    cout << endl;

    // ==============================
    // STACK CHECK
    // ==============================
    checkStack(&mainLocalVar);

    // ==============================
    // HEAP SEGMENT
    // ==============================
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "heap1 address: " << heap1 << endl;
    cout << "heap2 address: " << heap2 << endl;

    if (heap2 > heap1)
        cout << "Heap grows: UP" << endl;
    else
        cout << "Heap grows: DOWN" << endl;

    cout << endl;

    // ==============================
    // RELATIVE POSITION SUMMARY
    // ==============================
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    cout << "Text (code) typically lowest" << endl;
    cout << "Then Data and BSS" << endl;
    cout << "Heap grows upward toward higher addresses" << endl;
    cout << "Stack grows downward toward lower addresses" << endl;
    cout << endl;

    // Free heap memory
    free(heap1);
    free(heap2);

    return 0;
}