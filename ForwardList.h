template<typename T>
struct Node{
	T data;
	Node<T>* next;
	Node(){
		next = nullptr;
	}
	Node(T value){
		next = nullptr;
		data = value;
	}

};

template<typename T>
class ForwardList{
private:
	Node<T>* head;
public:
	ForwardList(){
		head = nullptr;
	}
	T front(); // Retorna el elemento al comienzo
	T back(); // Retorna el elemento al final
	void push_front(T); // Agrega un elemento al comienzo
	void push_back(T); // Agrega un elemento al final
	void pop_front(); // Remueve el elemento al comienzo
	void pop_back(); // Remueve el elemento al final
	T operator[ ](int); // Retorna el elemento en la posición indicada
	bool empty(); // Retorna si la lista está vacía o no
	int size(); // Retorna el tamaño de la lista
	void clear(); // Elimina todos los elementos de la lista
	void sort(); // Implemente un algoritmo de ordenacion con listas enlazadas)
	void reverse(); // Revierte la lista
	void removeElements(T);
	void showElements();
};

template<typename T>
T ForwardList<T>::front(){
	return head->data;
}

template<typename T>
T ForwardList<T>::back(){
	Node<T>* current = head;
	while(current->next != nullptr){
		current = current->next;
	}
	return current->data;
}

template<typename T>
void ForwardList<T>::push_front(T value){
	Node<T>* node = new Node<T>;
	node->data = value;
	node->next = head;
	head = node;
}

template<typename T>
void ForwardList<T>::push_back(T value){
	if(head == nullptr){
		head = new Node<T>(value);
		return;
	}
	Node<T>* current = head;
	while(current->next != nullptr){
		current = current->next;	
	}
	current->next = new Node<T>(value);
}

template<typename T>
void ForwardList<T>::pop_front(){
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}

template<typename T>
void ForwardList<T>::pop_back(){
	Node<T>* current = head;
	if(current->next == nullptr){
		delete current;
		head = nullptr;
		return;
	}
	while(current->next->next != nullptr){
		current = current->next;
	}
	Node<T>* temp = current->next;
	current->next = nullptr;
	delete temp;
}

template<typename T>
T ForwardList<T>::operator[](int ite){
	Node<T>* current = head;
	while(ite--){
		current = current->next;
	}
	return current->data;
}

template<typename T>
bool ForwardList<T>::empty(){
	if(head == nullptr) return true;
	return false;
}

template<typename T>
int ForwardList<T>::size(){
	Node<T>* current = head;
	int sz = 0;
	while(current != nullptr){
		current = current->next;
		sz++;
	}
	return sz;
}

template<typename T>
void ForwardList<T>::clear(){
	while(head != nullptr){
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void ForwardList<T>::reverse(){
	if(head == nullptr || head->next == nullptr){
		return;
	}
	
	Node<T>* current1 = head;
	Node<T>* current2 = head->next;

	head->next = nullptr;
	
	while(current2 != nullptr){
		Node<T>* temp = current2->next;
		current2->next = current1;
		current1 = current2;
		current2 = temp;
	}
	head = current1;
}

template<typename T>
void ForwardList<T>::showElements(){
	Node<T>* current = head;

	while(current != nullptr){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<"\n";
}

template<typename T>
void ForwardList<T>::removeElements(T value){
	if(head == nullptr){
		return;
	}
	Node<T>* current = head;
	while(current->next != nullptr){
		Node<T>* temp = current->next;
		if(temp->data == value){
			current->next = temp->next;
			delete temp;
		}
		else current = current->next;
	}
	//if(head->data == value) pop_front();
}