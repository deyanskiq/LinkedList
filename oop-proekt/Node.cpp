#include "Node.h"

Node::Node(int val=0, Node* prev = NULL, Node* next= NULL) {
this->val =val;
this->pNext = NULL;
this ->pPrev = NULL;
}
Node:: ~Node()
{
       delete this->pNext;
       delete this->pPrevious;
       }
int Node::getVal()
{
    return this->val;
}
Node* Node::getNext()
{
     return this->pNext;
     }
Node* Node::getPrev() {
return this->pPrev;
}

 
