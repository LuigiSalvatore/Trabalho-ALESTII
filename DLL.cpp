#include "DLL.hpp"

#pragma region Nodes 
Node::Node(char data)
{
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
    #ifdef DEBUG
    cout << "+ Node with " << data <<" created." << endl;
    #endif
}
Node::~Node()
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
    this->isAllSame = false;
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
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        newNode->next = nullptr;
        this->tail = newNode;
    }
    this->size++;
}
char DLL::remove(char data)
{
    Node *aux = this->head;
    char auxChar = '\0'
    while(aux != this->tail;){
        if(aux->data == data){
            auxChar = aux->data;
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            delete aux;
        }
        else
        aux = aux->next;   
    }
    if (auxChar != '\0')
        return auxChar
    else
    cout << "No character to remove"<< endl;
}
char DLL::remove(Node *node)
{
    char data = node->data;
    if (this->size == 0) {
        return '\0';
    }
    else if (this->size == 1){
        this->head = nullptr
    }
    else if (node == this->tail){
        this->tail->prev->next = nullptr;
    }
    else {
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
    while (aux != nullptr){
        ss << aux->data;
        aux = aux->next;
    } 
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
void DLL::doStuff()
{
    /*
        DN = A
        DA = N
        NA = D
    */
    while(this->size > 1 && (!isAllSame))
    {
        Node *one = this->head;
        Node *two = this->head->next;
        if (one->data == two->data) // se for AA ou DD ou NN, coloca no final da lista e diz que tudo é igual;
        {
            this->add(remove(one));
            this->add(remove(two));
            this->isAllSame = true;
            /*=========================*/ 
            one = this->head;
            two = this->head->next;
        } //endif de AA || DD || NN
        else if (one->data == 'D')
        {
            if (two->data == 'N') // se for DN, remove DN e coloca A no final, e diz que a lista não é igual;
            {
                this->remove(one);
                this->remove(two);
                this->add('A');
                this->isAllSame = false;
            } //endif de N
            if (two->data == 'A') // se for DA, remove DA e coloca N no final, e diz que a lista não é igual;
            {
                this->remove(one);
                this->remove(two);
                this->add('N');
                this->isAllSame = false;
            } //endif de A
        } //endif de DN and DA
        else if (one->data == 'N')
        {
            if (two->data == 'A') // se for NA, remove NA e coloca D no final, e diz que a lista não é igual;
            {
                this->remove(one);
                this->remove(two);
                this->add('D');
                this->isAllSame = false;
            }  //endif de A
        } //endif de NA

    } //end of while (this->size > 1 && (!isAllSame))
}
#pragma endregion