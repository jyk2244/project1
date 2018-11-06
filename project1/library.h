#include "member.h"
#include "resource.h"
#include <string>
#include <iostream>
#include <vector>
class library{
	vector <book> b_list;
	vector <undergraduate> u_list;
	vector <string> input;
	int op_size;
	vector <int> ret_code;

	public:
	library();
	void op2rec(int n);
	int borrow_b(int i);
	int ret_b(int i);
};
