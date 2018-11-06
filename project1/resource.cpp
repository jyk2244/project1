#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
//#include <boost/lexical_cast.hpp>
#include "resource.h"
#include "member.h"
using namespace std;

resource::resource(){
}

resource::resource(string t, string n){
	name = n;
	type = t;
	ret = 1;
}

string resource::show_name(){
	return name;
}

int resource:: exist(){
	return ret;
}

int resource:: exe(string name, int num, string type, string date){
	if(ret == 0)
		cout<< "Other memver already borrowed this book. This book will be returned at"<< ret_date<< endl;
	else{
		cout<<"Success"<<endl;
		who = num;
		ret = 0;
	}
}
void resource:: set(string t, string n){
	type = t;
	name = n;
}
void resource:: set_borrow(string a, string b){
	int d1, d2, d3;
	string s1, s2, s3;
	s1 = a.substr(0,2);
	s2 = a.substr(3,2);
	s3 = a.substr(6,2);
	d1 = atoi(s1.c_str());
	d2 = atoi(s2.c_str());
	d3 = atoi(s3.c_str());
	//cout<< d1<<endl;
	d3+= 13;
	if(d3>30){
		d2++;
		d3-=30;
	}
	if(d2>12){
		d1++;
		d2-=12;
	}
	int result = d3+d2*100+d1*10000;
	s1 = to_string(d1);
	s2 = to_string(d2);
	s3 = to_string(d3);
	ret_date = to_string(result);
        ret_date.insert(4,"/");
        ret_date.insert(2,"/");

	who = b;
}

book::book(){
}

book::book(string n, string t):resource(n,t){
	
}
