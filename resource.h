#include <iostream>
#include <string>
#include <vector>
using namespace std;

class resource{
        private:
        string name;
	int number;
        string who;
	string ret_date;
	int ret;
        
        string type;

        public:
        resource();
        resource(string name, string type);
	string show_name();
	void set(string a, string b);
	int exist();
	int exe(string name, int num, string type, string date);
	void set_borrow(string date, string u_name);
};

class book: public  resource{
        public:
	book();
	book(string n, string t);
};
