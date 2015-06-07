#ifdef NODE
#define NODE

#include <iostream>
struct Node(
public:
      Node(int,Node*,Node*);
      ~Node();
      int getVal(); 
      Node* getNext();
      Node* getPrev();
      private:
 int val;
 Node* pNext;
 Node* pPrevious;              
              };
#endif 
