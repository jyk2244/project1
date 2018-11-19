#include "member.h"
#include "resource.h"
#include "space.h"
#include <string>
#include <iostream>
#include <vector>
class library{
	vector <book> b_list;
	vector <undergraduate> u_list;
	vector <string> input;
	int op_size;
	vector <int> ret_code;

	vector<undergraduate> undergraduates;
	vector<studyroom> studyrooms;
	vector<seat> seats;
	int day_check;

	public:
	library();
	void library2();
	void input2();
	void s_data(int count, string date2, string space_type, string space_number, string operation2, string member_type2, string member_name2, int number_of_member, int in_time);
	void output(int op_num, int return_code, string description);
	int date2int(string date);
	int date2int2(string date);
	int date2hour(string date2);
	void op2rec(int n);
	int borrow_b(int i);
	int ret_b(int i);
	void ec(string date2);
	
};
