//#include "DLList.h"
//
//DLList::DLList(int val) {
//	this->pFront = new Node(val, nullptr, nullptr);
//	this->pEnd = this->pFront;	
//	this->size = 1;
//}
//
//DLList::~DLList() {
//	while (this->pEnd != this->pFront) {
//		this->pEnd = this->pEnd->getNext();
//		delete this->pEnd->getPrev();
//	}
//	delete this->pEnd;
//}
//
//void DLList::push_front(int val) {
//	Node* temp = new Node(val, this->pFront, nullptr);
//	this->pFront->setNext(temp);
//	this->pFront = temp;
//	size++;
//}
//
//void DLList::push_back(int val) {
//	Node* temp = new Node(val, nullptr, this->pEnd);
//	this->pEnd->setPrev(temp);
//	this->pEnd = temp;
//	size++;
//}
//
//void DLList::print() {
//	DLList::Iterator iter = this->begin();
//	while (iter != this->end()) {
//		std::cout << iter.get_current()->getVal() << " ";
//		iter++;
//	}
//	std::cout << iter.get_current()->getVal() << std::endl;
//}
//
//void DLList::pop_front() {
//	Node* temp = this->pFront;
//	this->pFront = this->pFront->getPrev();
//	delete temp;
//}
//
//void DLList::pop_back() {
//	Node* temp = this->pEnd;
//	this->pEnd = this->pEnd->getNext();
//	delete temp;
//}
//
//Node* DLList::front() {
//	return this->pFront;
//}
//
//Node* DLList::back() {
//	return this->pEnd;
//}
//
//void DLList::clear() {
//	delete this;
//}
//
//int DLList::get_size() {
//	return this->size;
//}
//
//bool DLList::empty() {
//	return size == 0;
//}
//
//DLList::Iterator DLList::begin() {
//	return Iterator(this->pEnd);
//}
//
//DLList::Iterator DLList::end() {
//	return Iterator(this->pFront);
//}
//
//void DLList::insert(DLList::Iterator iter, int val) {
//	Node* insertionNode = new Node(val, nullptr, nullptr);
//
//	if (iter.get_current()->getPrev() == nullptr) {
//		iter.get_current()->setPrev(insertionNode);
//		insertionNode->setNext(iter.get_current());
//		this->pEnd = insertionNode;
//	}
//
//	else if (iter.get_current()->getNext() == nullptr) {
//		iter.get_current()->setNext(insertionNode);
//		insertionNode->setPrev(iter.get_current());
//		this->pFront = insertionNode;
//	}
//	else {
//		Node* prev = iter.get_current()->getPrev();
//		iter.get_current()->setPrev(insertionNode);
//		prev->setNext(insertionNode);
//
//		insertionNode->setNext(iter.get_current());
//		insertionNode->setPrev(prev);
//	}
//}