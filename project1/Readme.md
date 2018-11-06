System Software Experiment#3 2013310791 김주영
======
Compile with Makefile, and Result data saved in output.txt. 
======
##main.cpp

just creates "lirary" class and execute.
library start; and execute library();

##member.cpp

```
 private:
        string name; // member name
        int number; //not using 
        int delay;	//not using
        int b_num;	//not using
        int borrow_num;	//count books borrowing. max = 1
        string ret_date;	//date when member return.
        string until_date;	//date that member has to return.
        string b_name;		//book's name member borrowed.
        vector <string> book_list;	//not using
        string type;	//not using but set with undergraduate.
        int ban;	//when this member be restricted, ban is setted with 1.
        string ban_date;	// until this ban_date, member can't borrow.

```
---
```
 member();
        member(string type, string name);// constructor
        string show_name();	//return member's name. 
        int show_borrow();	//return number of book member borrowed.
        string show_book();	//return book's name member borrowed.
        string show_ret_date();	//return ret_date
        string show_until_date();//return until_date
        void set_ret_date(string date);//when member borrow, set ret_date.
        int show_ban();		//return ban.
        string show_ban_date();	//return ban_date
        void set_when_ret(string date);//when member lately return, setting with 					restricted condition 
        //set(string type, string name);
        void set_borrow(string date, string b_name);// when borrowing, setting i							ntil_date, and b_name
        void set_restricted(string date);//same with set_when_ret.
        void ban_flush();// refresh restricted condition.

```

##resource.cpp

```
private:
        string name;	//resource's name
        int number;	//not using here
        string who;	//borrower name. = member's name
        string ret_date;//date that this resource has to be returned.
        int ret;	//when return, set with 1.

        string type;	//resource type. in here set with book.

```
---
```
 resource();
        resource(string name, string type);//constructor
        string show_name();	//return book's name
        void set(string a, string b);//set resource's name and type
        int exist();//not using here
        int exe(string name, int num, string type, string date);//no use
        void set_borrow(string date, string u_name);
		//when borrowed, set who, ret_date.

```

##library.cpp
```
vector <book> b_list;	//list of book
        vector <undergraduate> u_list;//list of member
        vector <string> input;	//list for input.dat
        int op_size;	//no use
        vector <int> ret_code;	//no use.

```
---
```
	library();
	: in here, take input.dat and resource.dat.
	save input.dat in vector<string>input, resource.dat in b_list.
	finally, with these data, call the function borrow_b and ret_b.

        void op2rec(int n);
	:when take number "n", printout as this value of'n'

        int borrow_b(int i);
	:as conditions, set the value 'n', and call op2rec(n).

        int ret_b(int i);
	: :as conditions, set the value 'n', and call op2rec(n).
```
