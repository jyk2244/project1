#include <iostream>
#include <string>
#include <vector>
using namespace std;

class member{
	private:
	string name;
	int number;
	int delay;
	int b_num;
	int borrow_num;
	string ret_date;
	string until_date;
	string b_name;
	vector <string> book_list;
	string type;
	int ban;
	string ban_date;
	
	public:
	member();
	member(string type, string name);
	string show_name();
	int show_borrow();
	string show_book();
	string show_ret_date();
	string show_until_date();
	void set_ret_date(string date);
	int show_ban();
	string show_ban_date();
	void set_when_ret(string date);
	//set(string type, string name);
	void set_borrow(string date, string b_name);
	void set_restricted(string date);
	void ban_flush();
	
};

class undergraduate: public member{
	private:
	public:
	undergraduate();
	undergraduate(string type, string name);
};
