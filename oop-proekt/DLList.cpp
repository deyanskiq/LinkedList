#include "DLList.h"

DLList::DLList(int val)
{
 this->pOrigin = new Node(val,NULL,NULL);
 this->size = 1;
}
DLList:: ~DLList()
{
         Node* next = this->pOrigin->getNext();
         Node* prev = this->pOrigin ->getPrev();
         delete this->pOrigin;
         if (next !=NULL)
         {
                  
         while (next ->getNext() != NULL){
               next = next->getNext();
               delete next->getPrev();
               }
               }
               if (prev !=NULL){
         while(prev->getPrev() != NULL)
{
          prev = prev->getPrev();
               delete prev->getNext();
               }
               }
                delete prev;
                delete next;
                this->size=0;
                                   
               }
               
         
         

