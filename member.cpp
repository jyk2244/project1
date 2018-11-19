#include <iostream>
#include <string>
#include <vector>
#include "member.h"
using namespace std;

member::member(){
}

member::member(string t, string n){
	name = n;
	type = t;
	borrow_num = 0;
	b_name = "";
}
string member:: show_name(){
	return name;
}
int member:: show_borrow(){
	return borrow_num;
} 
string member::show_book(){
	return b_name;
}
string member:: show_ret_date(){
	return ret_date;
}
string member:: show_until_date(){
	return until_date;
}
void member::set_ret_date(string a){
	ret_date = a;
}
int member::show_ban(){
	return ban;
}
void member:: set_when_ret(string dat){
	ban = 1;
	ban_date = 10;//
	borrow_num = 0;
	ret_date = "";
	b_name = "";
	until_date = "";

}
string member::show_ban_date(){
	return ban_date;
}
void member::set_borrow(string a, string book_name){
	
	borrow_num = 1;
	b_name = book_name;
	int d1, d2, d3;
        string s1, s2, s3;
        s1 = a.substr(0,2);
        s2 = a.substr(3,2);
        s3 = a.substr(6,2);
        d1 = atoi(s1.c_str());
        d2 = atoi(s2.c_str());
        d3 = atoi(s3.c_str());
        d3+= 13;
        if(d3>30){
                d2++;
                d3-=30;
        }
        if(d2>12){
                d1++;
                d2-=12;
        }
        s1 = to_string(d1);
	s2 = to_string(d2);
	s3 = to_string(d3);
	int result = d1*10000+d2*100+d3;
        until_date = to_string(result);
	until_date.insert(4,"/");
	until_date.insert(2,"/");
}
void member:: set_restricted(string d){
	ban = 1;
	ban_date = d;
	borrow_num = 0;
	ret_date = "";
	until_date = "";
	b_name = "";
}
void member:: ban_flush(){
	ban = 0;
	ban_date = "";
}
undergraduate::undergraduate(){
}

undergraduate:: undergraduate(string type, string name):member(type, name){
}                   
