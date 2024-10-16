#include<stdexcept>

struct Node{
	Node* next;
	Node* prev;
	int data;

	Node(){
		next = nullptr;
		prev = nullptr;
	}
	Node(int value){
		next = nullptr;
		prev = nullptr;
		data = value;	
	}
};

class DoublyLinkedList{
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList(){
		head = nullptr;
		tail = nullptr;
	}
	int front();
	int back();
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	void insert(int, int);
	int operator[](int);
	bool empty();
	int size();
	void clear();
	void reverse();
	void showElements();
};

int DoublyLinkedList::front(){
	if(head == nullptr){
		throw("Doesn't exist head");
	}
	return head->data;
}

int DoublyLinkedList::back(){
	if(tail == nullptr){
		throw("Doesn't exist tail");
	}
	return tail->data;	
}

void DoublyLinkedList::push_front(int data){
	if(head == nullptr){
		head = new Node(data);
		tail = head;
		return;
	}

	Node* node = new Node(data);
	
	node->next = head;
	head->prev = node;
	head = node;	
}

void DoublyLinkedList::push_back(int data){
	if(head == nullptr){
		head = new Node(data);
		tail = head;
		return;
	}
	Node* node = new Node(data);
	tail->next = node;
	node->prev = tail;
	tail = node;

}

void DoublyLinkedList::pop_front(){
	if(head == nullptr){
		return;
	}
	Node* temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
}

void DoublyLinkedList::pop_back(){
	if(tail == nullptr){
		return;
	}
	Node* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;	
}

int DoublyLinkedList::operator[](int index){
	Node* current = head;
	while(index > 0 && current != nullptr){
		index--;
		current = current->next;
	}
	if(current == nullptr){
		throw invalid_argument("Doesn't exist value");
	}
	return current->data;
}

/*
A -> B -> C
		  !
		  t
*/
void DoublyLinkedList::showElements(){
	Node* current = head;
	if(head == nullptr){
		cout<<endl;
		cout<<endl;
		return;
	}
	while(current != nullptr){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
	current = tail;
	while(current != nullptr){
		cout<<current->data<<" ";
		current = current->prev;
	}
	cout<<endl;

}

bool DoublyLinkedList::empty(){
	return head == nullptr;
}

void DoublyLinkedList::clear(){
	while(head != nullptr){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int DoublyLinkedList::size(){
	int res = 0;
	while(head!= nullptr){
		res++;
		head = head->next;
	}
	return res;
}

void DoublyLinkedList::reverse(){
	Node* cur = head;
	while(cur != nullptr){
		Node* temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;
		cur = temp;
	}
	Node* temp = head;
	head = tail;
	tail = temp;
}
/*
=A=B=C=
 |   |
 h   t

*/

void DoublyLinkedList::insert(int value, int index){
	Node* cur = head;
	if(index < 0){
		throw("Doesn't exist index");
	}
	Node* node = new Node(value);
	if(head == nullptr){
		head = new Node(value);
		tail = head;
		return;
	}
	if(index == 0){
		node->next = head;
		head->prev = node;
		head = node;
		return;
	}
	while(--index && cur != nullptr){
		cur = cur->next;
	}
	if(cur == nullptr){
		throw("Doesn't exist index");
	}
	node->next = cur->next;
	node->prev = cur;
	cur->next = node;
	if(node->next != nullptr){
		node->next->prev = node;
	}
	else{
		tail = node;
	}
}