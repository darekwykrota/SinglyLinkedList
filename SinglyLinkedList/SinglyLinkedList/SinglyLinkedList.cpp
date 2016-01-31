#include <iostream>

template<typename T>
class Node {
	T _value;
	Node<T>* _next;
public:
	explicit Node<T>(const T&);
	explicit Node<T>(const T&, Node<T>*);

	T getValue() const;
	Node<T>* getNext() const;
	void setNext(Node<T>*);

};

template<typename T>
Node<T>::Node(const T& value) : _value(value), _next(nullptr){}

template<typename T>
Node<T>::Node(const T& value, Node<T>* next) : _value(value), _next(next){}

template<typename T>
T Node<T>::getValue() const { return _value; }

template<typename T>
Node<T>* Node<T>::getNext() const { return _next; }

template<typename T>
void Node<T>::setNext(Node<T>* next) { _next = next; }





template<typename T>
class SinglyLinkedList {
	Node<T>* _head;
	void removeFirst();
public:
	explicit SinglyLinkedList();
	void pushFront(const T&);
	void pushBack(const T&);
	void remove(const T&);
	bool isEmpty() const;
	int size() const;
	void printContents() const;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : _head(nullptr){}

template<typename T>
void SinglyLinkedList<T>::pushFront(const T& value){
	auto newNode = new Node<T>(value, _head);
	_head = newNode;
}

template<typename T>
void SinglyLinkedList<T>::pushBack(const T& value){
	if (isEmpty()) pushFront(value);
	else{
		auto temporary = _head;
		while (temporary->getNext()){
			temporary = temporary->getNext();
		}
		auto newNode = new Node<T>(value);
		temporary->setNext(newNode);
	}
}

template<typename T>
void SinglyLinkedList<T>::removeFirst(){
	auto temporary = _head;
	_head = _head->getNext();
	delete temporary;
}

template<typename T>
void SinglyLinkedList<T>::remove(const T& value){
	Node<T>* fast = _head;
	Node<T>* slow = nullptr;

	while (fast && fast->getValue() != value){
		slow = fast;
		fast = fast->getNext();
	}

	if (fast){
		if (!slow){
			removeFirst();
		}
		else{
			slow->setNext(fast->getNext());
			delete fast;
		}
	}
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() const { return !_head; }

template<typename T>
int SinglyLinkedList<T>::size() const {
	auto temporary = _head;
	int counter = 0;
	while (temporary){
		++counter;
		temporary = temporary->getNext();
	}
	return temporary;
}

template<typename T>
void SinglyLinkedList<T>::printContents() const {
	auto temporary = _head;
	while (temporary){
		std::cout << temporary->getValue() << std::endl;
		temporary = temporary->getNext();
	}
}

void testSinglyLinkedList(){
	SinglyLinkedList<int> sll;

	for (int i = 0; i < 5; ++i) sll.pushBack(i);

	sll.printContents();

	std::cout << "\n\n";
	sll.remove(0);
	sll.printContents();
}



int main(){

	return 0;
}
