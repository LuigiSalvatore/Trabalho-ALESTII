#include "DLL.hpp"

#pragma region Nodes 
void Node::Node(char data)
{
    this->data = data;
    #ifdef DEBUG
    cout << "+ Node with " << data <<" created." << endl;
    #endif
}
void Node::~Node()
{
    #ifdef DEBUG
    cout << "- Node with " << data <<" destroyed." << endl;
    #endif
}
#pragma endregion

#pragma region List

DLL::DLL()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    this->dumbCounter = false;
    #ifdef DEBUG
    cout << "+ List created." << endl;
    #endif
}
DLL::~DLL()
{
    Node *aux = this->head;
    do
    {
        Node *next = aux->next;
        delete aux;
        aux = next;
    } while (aux != nullptr);
    #ifdef DEBUG
    cout << "- List destroyed." << endl;
    #endif
}
void DLL::add(char data)
{
    Node *newNode = new Node(data);
    if (this->head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        newNode->next = this->head;
    }
    this->size++;
}
char DLL::remove(char data)
{
    Node *aux = this->head;
    do
    {
        if (aux->data == data)
        {
            if (aux == this->head)
            {
                this->head = aux->next;
                this->head->prev = this->tail;
            }
            else if (aux == this->tail)
            {
                this->tail = aux->prev;
                this->tail->next = head;
            }
            else
            {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }
            char data = aux->data;
            delete aux;
            this->size--;
            return data;
        }
        aux = aux->next;
    } while (aux != this->head);
    
    return nullptr;
    printf("Element not found.\n");
}
char DLL::remove(Node *node)
{
    char data = node->data;
    if (node == this->head)
    {
        this->head = node->next;
        this->head->prev = this->tail;
    }
    else if (node == this->tail)
    {
        this->tail = node->prev;
        this->tail->next = head;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    delete node;
    return data;
}
string DLL::str()
{
    Node *aux = this->head;
    sringstream ss;
    do 
    {
        ss << aux->data;
        aux = aux->next;
    } while (aux != this->head);
    ss << endl;
    return ss.str();
}
int DLL::size()
{
    return this->size;
}
Node *DLL::getHead()
{
    return this->head;
}
Node *DLL::getTail()
{
    return this->tail;
}
bool DLL::isEmpty()
{
    return this->size == 0;
}
bool DLL::isAllSame()
{
    Node *aux = this->head;
    do
    {
        if (aux->data != this->head->data)
        {
            return false;
        }
        aux = aux->next;
    } while (aux != this->head);
    return true;
}
void DLL::doStuff()
{
    /*
        DN = A
        DA = N
        NA = D
    */
    while(!this->isAllSame())
    {        
        if(this->size > 1){
            Node *first = this->head;
            Node *second = this->head->next;
            if(first->data == second->data){
                this->add(remove(first  ->data));
                this->add(remove(second ->data));
            }
            else if(first == 'D' && second == 'N'){
                this->remove(first);
                this->remove(second);
                this->add('A');
            }
            else if(first == 'D' && second == 'A'){
                this->remove(first);
                this->remove(second);
                this->add('N');
            }
            else if(first == 'N' && second == 'A'){
                this->remove(first);
                this->remove(second);
                this->add('D');
            }
        }
        else{
            #ifdef DEBUG
                cout << "List is empty or has a size of '1'" << endl;
            #endif
            return;
            }
    }
}

#pragma endregion