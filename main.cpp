#include<iostream>

using namespace std;

#include "DoublyLinkedList.h"

int main(){
	DoublyLinkedList v;
	
	//v.push_back(1);
	v.insert(10,0);
	v.showElements();
	
	return 0;
}