#include "iterator.h"
#include <iostream>
#include "composite.h"
#include <stack>


OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr) {
		this->self_ptr = ptr;
	 }
void OperatorIterator::first() {
		current_ptr = self_ptr->get_left();
}
void OperatorIterator::next() {
	if(current_ptr == self_ptr->get_left()) {
		current_ptr = self_ptr->get_right();
	}
	else if(current_ptr == self_ptr->get_right()) {
		current_ptr = NULL;
	}
}
bool OperatorIterator::is_done() {
	if(current_ptr == NULL) {
		return true;
	}
	return false;
}
Base* OperatorIterator::current() {
	return current_ptr;
}


UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {
		this->self_ptr = ptr;
}
void UnaryIterator::first() {
	current_ptr = self_ptr->get_left();
}
void UnaryIterator::next() {
	current_ptr = NULL;
 }
bool UnaryIterator::is_done() {
	if(current_ptr) {
		return false;
	}
	return true;
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
	Iterator* temp = self_ptr->create_iterator();
	if(temp) {
		while(!iterators.empty()) {
			iterators.pop();
		}
		cout << "meow" << endl;
		temp->first();
		iterators.push(temp);
		//iterators.top()->first();
	}
}
void PreOrderIterator::next() {
	Iterator* temp = iterators.top()->current()->create_iterator();
	temp->first();
	iterators.push(temp);
	iterators.top()->first();
	while(iterators.top()->is_done() && iterators.size() > 1) {
		iterators.pop();
		iterators.top()->next();
	}
}
bool PreOrderIterator::is_done() {
	if(iterators.size() == 1 && iterators.top()->is_done()) {
		return true;
	}
	return false;
}
Base* PreOrderIterator::current() {
	if(iterators.size() > 0) {
		return iterators.top()->current();
	}
	else {
		return NULL;
	}
}




