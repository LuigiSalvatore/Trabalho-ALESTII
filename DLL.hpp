#ifndef _DLL
#define _DLL
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

#ifndef _DLLNode
#define _DLLNode
// classe nodo para navegar a lista
class Node
{
public:
    Node *next; // Pointer to the next node in the list
    Node *prev; // Pointer to the previous node in the list
    char data;  // The data stored in the node

    Node(char data); // Constructor
    ~Node();         // Destructor
};
#endif // _DLLNode

class DLL
{
private:
    Node *head; // Pointer to the first node in the list
    Node *tail; // Pointer to the last node in the list
    int size;   // The number of nodes in the list
    int isSame; // Counter for the doStuff function

public:
    DLL();
    ~DLL();
    void add(char data);
    char remove();
    char remove(Node *node);
    string str();
    int listSize();
    Node *getHead();
    Node *getTail();
    void doStuff();
};
#endif //_DLL
