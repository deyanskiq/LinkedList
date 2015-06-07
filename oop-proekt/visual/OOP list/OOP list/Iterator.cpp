//#include "DLList.h"
//
//DLList::Iterator::Iterator(Node* node) {
//	this->current = node;
//}
//
//int DLList::Iterator::operator*() {
//	return this->current->getVal();
//}
//
//DLList::Iterator DLList::Iterator::operator++() {
//	this->current = this->current->getNext();
//	return *this;
//}
//
//DLList::Iterator DLList::Iterator::operator++(int val) {
//	this->current = this->current->getNext();
//	return *this;
//}
//
//bool DLList::Iterator::operator!=(DLList::Iterator other) {
//	return this->current != other.get_current();
//}
//
//Node* DLList::Iterator::get_current() {
//	return this->current;
//}