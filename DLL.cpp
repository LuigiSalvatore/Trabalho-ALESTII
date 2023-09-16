#include "DLL.hpp"
// #define DEBUG
// #define MESSAGES
#pragma region Nodes
Node::Node(char data)
{
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
#ifdef DEBUG
    cout << "+ Node with " << data << " created." << endl;
#endif
}
Node::~Node()
{
#ifdef DEBUG
    cout << "- Node with " << data << " destroyed." << endl;
#endif
}
#pragma endregion

#pragma region List

DLL::DLL()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    this->isSame = false;
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
    Node *temp = new Node(data);

    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}
char DLL::remove()
{
    if (size != 0)
    {
        Node *temp = head;
        if (head == tail)
        {
            tail = NULL;
        }
        char delValue = temp->data;
        head = head->next;

        delete temp;

        size--;

        return delValue;
    }
    return 0;
}
char DLL::remove(Node *node)
{
    char data = node->data;
    if (this->size == 0)
    {
        return '\0';
    }
    else if (this->size == 1)
    {
        this->head = nullptr;
    }
    else if (node == this->tail)
    {
        this->tail->prev->next = nullptr;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
#ifdef DEBUG
    cout << "- Node with data=" << data << "deleted" << endl;
#endif
    delete node;
    return data;
}
string DLL::str()
{
    Node *aux = this->head;
    stringstream ss;
    while (aux != nullptr)
    {
        ss << aux->data;
        aux = aux->next;
    }
    ss << endl;
    return ss.str();
}
int DLL::listSize()
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
void DLL::doStuff()
{
    /*
        AD || DA = N
        DN || ND = A
        AN || NA = D
    */
    while ((this->size > 1) && (isSame <= this->size))
    {
        Node *one = this->head;
        Node *two = this->head->next;
#ifdef MESSAGES
        cout << "one: " << one->data
             << endl
             << "two: " << two->data
             << endl;
#endif
        if ((one->data == 'D' && two->data == 'N') || (one->data == 'N' && two->data == 'D')) // se for DN, remove DN e coloca A no final, e diz que a lista não é igual;
        {
            this->remove();
            this->remove();
            this->add('A');
            this->isSame = 0;
#ifdef MESSAGES
            cout << "removed DN"
                 << endl
                 << "list: " << str()
                 << endl;
#endif
        }                                                                                          // endif de DN
        else if ((one->data == 'D' && two->data == 'A') || (one->data == 'A' && two->data == 'D')) // se for DA, remove DA e coloca N no final, e diz que a lista não é igual;
        {
            this->remove();
            this->remove();
            this->add('N');
            this->isSame = 0;
#ifdef MESSAGES
            cout << "removed DA"
                 << endl
                 << "list: " << str()
                 << endl;
#endif
        }                                                                                          // endif de DA
        else if ((one->data == 'N' && two->data == 'A') || (one->data == 'A' && two->data == 'N')) // se for NA, remove NA e coloca D no final, e diz que a lista não é igual;
        {
            this->remove();
            this->remove();
            this->add('D');
            this->isSame = 0;
#ifdef MESSAGES
            if (one->data == 'N' && two->data == 'A')
                cout << "NA" << endl;
            if (one->data == 'A' && two->data == 'N')
                cout << "AN" << endl;
            cout << "removed NA"
                 << endl
                 << "list: " << str()
                 << endl;
#endif
        }                                                // endif de NA
        else if ((one->data == 'A' && two->data == 'A')) // se for AA, diz que a lista é igual
        {
            this->remove();
            this->remove();
            this->add('A');
            this->add('A');
            this->isSame++;
#ifdef MESSAGES
            cout << "removed AA"
                 << endl
                 << "list: " << str()
                 << endl;
#endif
        }                                                // endif de AA
        else if ((one->data == 'D' && two->data == 'D')) // se for DD, diz que a lista é igual
        {
            this->remove();
            this->remove();
            this->add('D');
            this->add('D');
            this->isSame++;
#ifdef MESSAGES
            cout << "removed DD"
                 << endl
                 << "list: " << str()
                 << endl;
#endif
        }                                                // endif de DD
        else if ((one->data == 'N' && two->data == 'N')) // se for NN, diz que a lista é igual
        {
            this->remove();
            this->remove();
            this->add('N');
            this->add('N');
            this->isSame++;
#ifdef MESSAGES
            cout << "removed NN"
                 << endl
                 << "list: "
                 << str()
                 << endl;
#endif
        } // endif de NN
    }     // end of while (this->size > 1 && (!isSame))
}
#pragma endregion