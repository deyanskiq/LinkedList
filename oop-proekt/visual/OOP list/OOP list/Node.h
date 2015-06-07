#pragma once
#include<iostream>
template <typename T>
class Node {
public:
	Node(const T&, Node<T>*, Node<T>*);//констуктор с 3 параметъра: стойност и два указателя съответно към предишния и следващия Node
	//get и set методи за улеснение на достъпа до данните на отделните Node-ве
	T getVal();
	Node<T>* getPrevious();
	Node<T>* getNext();
	void SetPrevious(Node<T>*);
	void SetNext(Node<T>*);
	Node<T> operator=(const Node<T>&);
private:
	T value;
	Node<T>* pPrevious;
	Node<T>* pNext;
};
template <typename T>
Node<T>::Node(const T& value, Node<T>* previous = NULL, Node<T>* next = NULL)
{
	this->value = value;
	this->pPrevious = previous;
	this->pNext = next;
}
template <typename T>
T Node<T>::getVal()
{
	return this->value;
}
template <typename T>
Node<T>* Node<T>::getPrevious()
{
	return this->pPrevious;
}
template <typename T>
Node<T>* Node<T>::getNext()
{
	return this->pNext;
}
template <typename T>
void Node<T>::SetPrevious(Node<T>* previous)
{
	this->pPrevious = previous;
}
template <typename T>
void Node<T>::SetNext(Node<T>* next)
{
	this->pNext = next;
}
