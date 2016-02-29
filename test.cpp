#include <iostream>
#include <vector>
#include "composite.h"

using namespace std;

int main() {
	int count = 0;

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	cout << "chirp" << endl;
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		cout << "ERR before print" << endl;
		pre_itr->current()->print();
		cout << count << endl;
		count++;
	}
};

