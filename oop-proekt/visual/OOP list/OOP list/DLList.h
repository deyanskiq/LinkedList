#pragma once
#include "Node.h"
template <typename T>
class List
{
public:
	List();//default-ен констуктор
	List(const List&);
	~List(); //деструтор
	void push_front(const T& val); //добавя елемент в началото на списъка
	void push_back(const T& val); //добавя елемент в края на списъка
	void pop_front();//премахва елемент в началото на списъка
	void pop_back();//премахва елемент в края на списъка
	T front();//връща стойността на елемента в началото на списъка
	T back(); //връща стойността на елемента в края на списъка
	int get_size();//връща броя елементи в списъка
	void clear();//изтрива всички елементи в списъка
	bool empty();//проверява дали списъка е празен 
	void print(); 
	class iterator{  // за лесно обхождане на двусвързания списък
	public:
		iterator(Node<T>*); // констуктор с параметър указател към Node
		//предефиниране на операторите *, ++(), ++(int), !=
		T operator*();
		iterator operator++();
		iterator operator++(int);
		bool operator!=(iterator);
		//get и set методи за работа с текущия Node
		Node<T>* getCurrent();
		void setCurrent(Node<T>*);
	private:
		Node<T>* current;
	};
	iterator begin(); // връща Interator-a към началото на списъка
	iterator end() const ;// връща Interator-a към края на списъка
	void insert(iterator&, const T&);// вмъква елемент на позиция Interator
	void erase(iterator&); //изтрива елемент на позиция Interator
private:
	Node<T>* pFront;
	Node<T>* pBack;
	int size;
};
//List* - като указател, за да се пести памет
//свързваме итератора с конкретен лист
template <typename T>
List<T>::iterator::iterator(Node<T>* node)
{
	this->current = node;
}
template <typename T>
T List<T>::iterator::operator*()
{
	return this->current->getVal();
}
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++()
{
	this->current = this->current->getNext();
	return *this;
}
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int value)
{
	this->current = this->current->getNext();
	return *this;
}
template <typename T>
bool typename List<T>::iterator::operator!=(typename List<T>::iterator other)
{
	return (this->current->getNext() != other.getCurrent()->getNext() && this->current->getPrevious() != other.getCurrent()->getPrevious());
}
template <typename T>
Node<T>* List<T>::iterator::getCurrent()
{
	return this->current;
}
template <typename T>
void List<T>::iterator::setCurrent(Node<T>* node){
	this->current = node;
}
template <typename T>
List<T>::List()
{
	this->pBack = NULL;
	this->pFront = NULL;
}

template <typename T>
List<T>::List(const List<T>& other)
{
	this->pFront = other.begin().getCurrent();
	this->pBack = other.end().getCurrent()->getPrevious();
	this->size = other.get_size();
	List<T>::iterator iter(other.begin().getCurrent());
	while (iter != other.end())
	{
		iter++;
		this->push_back(iter.getCurrent()->getVal());
	}
}
template <typename T>
List<T>::~List() 
{
	// докато първия елемент е различен от последния  изтрива елементите последователно
	//и когато pFront съвпадне с pBack изтрива pFront
	List <T>::iterator iter = this->begin();
	while (iter != this->end())
	{
		delete iter.getCurrent();

	}
	delete iter.getCurrent();

}

template <typename T>
void List<T>::push_front(const T& value) 
{
	if (size == 0) //проверяваме дали списъка е празен 
	{
		this->pBack = new Node<T>(value, NULL, NULL); 
		this->pFront = this->pBack;
	}
	else{
		Node<T>* temp = new Node<T>(value, NULL, this->pFront); //създава нов Node , който сочи към pFront, a pPrevious = NULL
		this->pFront->SetPrevious(temp); // свързваме pPrevious на pFront с новосъздадения Node
		this->pFront = temp; // правим новосъздадения Node pFront(първи)
	}
	size++; // увеличаваме размера на листа
}

template <typename T>
void List<T>::push_back(const T& value) 
{
	if (size == 0)
	{
		this->pBack = new Node <T> (value, NULL, NULL);
		this->pFront = this->pBack;
	}
	else{
		Node<T>* temp = new Node<T>(value, this->pBack, NULL); //създава нов Node , който сочи към pBack, a pNext = NULL
		this->pBack->SetNext(temp); // свързваме pNext на pBack с новосъздадения Node
		this->pBack = temp; // правим новосъздадения Node pBack(последен)
	}
	size++; // увеличаваме размера на листа
}

template <typename T>
void List<T>::pop_front()
{
	Node<T>* temp = this->pFront; //създаваме временен Node , който е равен на pFront
	this->pFront = this->pFront->getNext(); // правим pFront равен на следващия
	delete temp;//изтриваме временния Node
}

template <typename T>
void List<T>::pop_back()
{
	Node<T>* temp = this->pBack;
	this->pBack = this->pBack->getPrevious();
	delete temp;
}

template <typename T>
void List<T>::print() {
	typename List<T>::iterator iter = this->begin();
	while (iter != this->end()) {
		std::cout << iter.getCurrent()->getVal() << " ";
		iter++;
	}
	std::cout << iter.getCurrent()->getVal() << std::endl;
}

template <typename T>
T List<T>::front() // връща стойността на pFront
{
	return this->pFront->getVal();
}

template <typename T>
T List<T>::back()  //връща стойността на pBack
{
	return this->pBack->getVal();
}

template <typename T>
void List<T>::clear()
{
	delete this;
}

template <typename T>
int List<T>::get_size()
{
	return this->size;
}

template <typename T>
bool List<T>::empty()
{
	return this->size == 0;
}

template <typename T>
typename List<T>::iterator List<T>::begin()
{
	return iterator(this->pFront);
}

template <typename T>
typename List<T>::iterator List<T>::end() const
{
	T val;
	Node<T>* endNode = new Node<T>(val, this->pBack, NULL);
	this->pBack->SetNext(endNode);
	return iterator(endNode);
}

template <typename T>
void List<T>::insert(typename List<T>::iterator& iter, const T& val) { 
	Node<T>* insertionNode = new Node<T>(val, NULL, NULL); // създаваме нов несвързан Node
	if (iter.getCurrent()->getPrevious() == NULL) { // проверяваме дали сме в началото на списъка
		// поставяме новия несвързан Node в началото на списъка
		iter.getCurrent()->SetPrevious(insertionNode);  //променям pPrevious
		insertionNode->SetNext(iter.getCurrent()); //променям pNext
		this->pFront = insertionNode; //новосъздадения Node вече е pFront
	}

	else if (iter.getCurrent()->getNext() == NULL) { //проверяваме дали сме с края на списъка
		iter.getCurrent()->SetNext(insertionNode); //променям pNext
		insertionNode->SetPrevious(iter.getCurrent()); //променям pPrevious
		this->pBack = insertionNode; //  новосъздадения Node вече е pBack
	}
	else {
		Node<T>* prev = iter.getCurrent()->getPrevious();
		iter.getCurrent()->SetPrevious(insertionNode); //свързвамe pPrevious на итератора с insertionNode
		prev->SetNext(insertionNode);
		//свързвамe новия Node с предишния и следващия Node
		insertionNode->SetNext(iter.getCurrent()); 
		insertionNode->SetPrevious(prev);
	}
	iter.setCurrent(insertionNode);//правим InsertionNode Iterator
	this->size++; 
}

template<typename T>
void List<T>::erase(typename List<T>::iterator& iter){
	if (iter.getCurrent()->getPrevious() == NULL){ // проверяваме дали сме в началото  на списъка
		iter.setCurrent(iter.getCurrent()->getNext());
		iter.getCurrent()->SetPrevious(NULL);
		this->pFront = iter.getCurrent();
	}
	else if (iter.getCurrent()->getNext() == NULL){ // проверяваме дали сме в края  на списъка
		iter.setCurrent(iter.getCurrent()->getPrevious());
		iter.getCurrent()->SetNext(NULL);
		this->pBack = iter.getCurrent();
	}
	else{
		iter.getCurrent()->getPrevious()->SetNext(iter.getCurrent()->getNext());
		iter.getCurrent()->getNext()->SetPrevious(iter.getCurrent()->getPrevious());
		//за да премести Iterator-a да не е на елемента, който сме изтрили създаваме нов Node
		Node<T>* temp = iter.getCurrent()->getNext(); 
		delete iter.getCurrent();
		iter.setCurrent(temp);
	}
	this->size--;
}