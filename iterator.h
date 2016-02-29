#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include "composite.h"
#include <stack>


class Iterator {
	protected:
		Base* self_ptr;
		Base* current_ptr;

	public:
		Iterator (Base* ptr) {this->self_ptr = ptr; }

		virtual void first() = 0;
		virtual void next() = 0;
		virtual void is_done() = 0;
		virtual Base* current() = 0;

};

class OperatorIterator : public Iterator {
	protected:
		int nextnum;
		bool done;
	public:
		OperatorIterator(Base* ptr) {
			this->self_ptr = ptr;
			nextnum = 0;
			done = false;
		 }
		void first() {
			if(current_ptr->get_left() != NULL && nextnum == 0) {
				current_ptr = self_ptr->get_left();
				nextnum = 1;
			}
	
		};
		void next() {
			if(current_ptr->get_right() != NULL && nextnum == 1) {
				current_ptr = self_ptr->get_right();
				nextnum++;
				done = true;
			}
			else {
				current_ptr = NULL;
				done = true;
			}
		};
		bool is_done() {
			if(done) {
				return true;
			}
			return false;
		};
		Base* current() {
			return current_ptr;
		};

};

class UnaryIterator : public Iterator {
	protected:
		bool done;
	public:
		UnaryIterator(base* ptr) {
			this->self_ptr = ptr;
			done = false;
		}
		void first() {
			current_ptr = self_ptr->get_left();
			done = true;
		}
		void next() { current_ptr = NULL; }
		bool is_done() {
			if(done) {
				return true;
			}
			return false;
		}
		Base* current() {
			return current_ptr;
		}

};

class NullIterator : public Iterator {
	public:
		NullIterator(base* ptr) { 
			this->self_ptr = ptr;
			this->current_ptr = NULL;
		 }
		void first();
		void next();
		bool is_done() { return true; }
		Base* current() { return NULL; }

};

class PreOrderIterator : public Iterator {
	protected:
		stack<Iterator*> iterators;

	public:
		PreOrderIterator(base* ptr) { this->self_ptr = ptr; }
		void first() {
			while(!iterators.empty()) {
				iterators.pop();
			}
			iterators.push(ptr->create_iterator());
		void next() {
			iterators.push(iterators.top()->create_iterator());
			while(iterators.top()->is_done()) {
				iterators.pop();
			}
		bool is_done() {
			if(iterators.empty()) {
				return true;
			}
			return false;
		Base* current() {
			iterators.top()->current();
		}

};

#endif
