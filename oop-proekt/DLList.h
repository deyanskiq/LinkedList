#ifdef DLLIST
#define DLLIST

#include "Node.h"
class DLList
{
      public:
             DLList(int);
             ~DLList();
             
             void push_front(int);
             void pop_front(int);
             void push_back(int);
             void pop_back(int);
             
             int front();
             int back();
             
             int size();
             void clear();
             bool empty();
             
             
             private:
             Node* pOriginal;
             int size;
             
                     
      };
#endif
