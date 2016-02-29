#include "iterator.h"
#include <iostream>
#include "composite.h"
#include <stack>


OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr) {
		this->self_ptr = ptr;
		nextnum = 0;
		done = false;
	 }
void OperatorIterator::first() {
	if(current_ptr->get_left() != NULL && nextnum == 0) {
		current_ptr = self_ptr->get_left();
		nextnum = 1;
	}
}
void OperatorIterator::next() {
	if(current_ptr->get_right() != NULL && nextnum == 1) {
		current_ptr = self_ptr->get_right();
		nextnum++;
		done = true;
	}
	else {
		current_ptr = NULL;
		done = true;
	}
}
bool OperatorIterator::is_done() {
	if(done) {
		return true;
	}
	return false;
}
Base* OperatorIterator::current() {
	return current_ptr;
}


UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {
		done = false;
		this->self_ptr = ptr;
}
void UnaryIterator::first() {
	current_ptr = self_ptr->get_left();
	done = false;
}
void UnaryIterator::next() { current_ptr = NULL; }
bool UnaryIterator::is_done() {
	if(done) {
		return true;
	}
	return false;
}
Base* UnaryIterator::current() {
	return current_ptr;
}

NullIterator::NullIterator(Base* ptr) : Iterator(ptr) { 
	this->self_ptr = ptr;
	this->current_ptr = NULL;
	
 }
void NullIterator::first() {}
void NullIterator::next() {}
bool NullIterator::is_done() { return true; }
Base* NullIterator::current() { return NULL; }



PreOrderIterator::PreOrderIterator(Base* ptr) : Iterator(ptr) 
	{ this->self_ptr = ptr;}
void PreOrderIterator::first() {
	while(!iterators.empty()) {
		iterators.pop();
	}
	cout << "meow" << endl;
	Iterator* temp = self_ptr->create_iterator();
	temp->first();
	iterators.push(temp);
	self_ptr->print();
	//iterators.top()->first();
}
void PreOrderIterator::next() {
	cout << "dog" << endl;
	Iterator* temp = iterators.top()->current()->create_iterator();
	temp->first();
	iterators.push(temp);
	//iterators.top()->first();
	cout << "woof" << endl;
	while(iterators.top()->is_done()) {
		iterators.pop();
	}
}
bool PreOrderIterator::is_done() {
	if(iterators.empty()) {
		return true;
	}
	return false;
}
Base* PreOrderIterator::current() {
	cout << "sheep" << endl;
	return iterators.top()->current();
}




