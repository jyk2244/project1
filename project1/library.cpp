//#include "member.h"
//#include "resource.h"
#include "library.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ofstream out("output.txt");
library::library(){
	//////////////resource.dat
	ifstream in("resource.dat");
        vector <string> s1;
        string ass;
        int i =0;
	in >>ass;
	in >>ass;
        while(in.is_open()){
                in >>ass;
                s1.push_back(ass);
		//cout << i << endl;
                i++;
                if(in.eof()){
                        break;
                }
        }
	s1.pop_back();

        for(i =0; i<s1.size()-1; i++){
                ass = s1.at(i);
        }

        vector <book> b;
        string s_a, s_b;
        int resource_size = (s1.size())/2;
        for(i=0; i<resource_size; i++){
                s_a = s1.at(i*2);
                s_b = s1.at(1+i*2);
		
                book material = book(s_a, s_b);
                b_list.push_back(material);///////////////modify
                
        }
	
	/////////////input.dat
	ifstream in2("input.dat");
        string date, r_type, r_name, op, m_type, m_name, throu;
	int op_n=0;
        vector <undergraduate> p;
        undergraduate material2;
	op_size = 0;
	////first line
	for(i=0; i<6;i++)
		in2>>throu;
        while(1){
			in2 >>throu;
			input.push_back(throu);
                if(in2.eof())
                        break;
		
        }
	input.pop_back();
	///////////output
	//ofstream out("output.txt");
	out<<"Op_#\t";
	out<<"Return_code\t";
	out<<"Description"<<endl;

	int result;
	for(i=0; i<input.size()/6; i++){
		out<<i+1<<"\t";
		

	
		date = input.at(i*6); 
		r_type = input.at(i*6+1);
		r_name = input.at(i*6+2);
		op = input.at(i*6+3);
		m_type = input.at(i*6+4);
		m_name = input.at(i*6+5);
		
		if(op == "B"){
			result = borrow_b(i);
		}	
		else if(op == "R"){
			result = ret_b(i);
		}
	}
	
	 
}
void library:: op2rec(int n){
	//ofstream out("output.txt");
	out<<n<<"\t";

	if(n == 0)
		out << "Success."<<endl;
	else if(n == 1)
		out << "Non exist resource."<<endl;
	else if(n == 2)
		out << "Exceeds your possible number of borrow. Possible # of borrows: 1"<<endl;
	else if(n == 3)
		out << "You did not borrow this book."<<endl;
	else if(n == 4)
		out << "You already borrowed this book at ";
	else if(n == 5)
		out << "Other member already borrowed this book. This book will be returned at ";
	else if(n == 6)
		out << "Restricted member until ";
	else if(n == 7)
		out << "Delayed return. You'll be restricted until ";


}



int library:: borrow_b(int i){
	/////////////none exist
	//ofstream out("output.txt");
	int j, ex =0;
	for(j=0; j<b_list.size(); j++){
		if( ( input.at(2+i*6) ).compare( b_list.at(j).show_name() )==0 )		{
			ex = 1;	
			break;
		}
	}
	if(ex == 0){
		ret_code.push_back(1);
		op2rec(1);
		return 0;
	}
	
	/////////////exceed borrow
	////1. none u-list -> add
	ex = 0;
	if(u_list.size() == 0)
		goto L;
	for(j=0; j<u_list.size(); j++){
		if( ( input.at(5+i*6) ).compare( u_list.at(j).show_name() )==0 )		{
      			ex = 1;  
			break;
		 }
        }
        if(ex == 0){
		L:
                u_list.push_back(undergraduate(input.at(4+i*6), input.at(5+i*6) ));
		
		
	}
	
	////2. confirm exceed 
	if(u_list.at(j).show_borrow() >= 1){
		ret_code.push_back(2);
		op2rec(2);
		return 0;	
	}
	////4. already borrow
	for(j=0; j<u_list.size(); j++){
                if( ( input.at(5+i*6) ).compare( u_list.at(j).show_name() )==0 )                {
                        break;
                }

        }
        if( ( input.at(2+i*6) ).compare( u_list.at(j).show_book() ) == 0 ){
                ret_code.push_back(4);
		op2rec(4);
                return 0;
        }
	////5. other borrow
	for(j=0; j<u_list.size(); j++){
                if( ( input.at(2+i*6) ).compare( u_list.at(j).show_book() )==0 )                {
                        ret_code.push_back(5);
			op2rec(5);
			out << u_list.at(j).show_until_date()<<endl;
			return 0;
                }

        }
	
	////6. restricted
	for(j=0; j<u_list.size(); j++){
                if( ( input.at(5+i*6) ).compare( u_list.at(j).show_name() )==0 )                {
                        break;
                }

        }
		///////////////flush ban_date
	string ban_d = u_list.at(j).show_ban_date();
	string today = input.at(0+i*6);
	if(atoi(today.substr(0,2).c_str())> atoi(ban_d.substr(0,2).c_str()))
		u_list.at(j).ban_flush();
	else{

	if(atoi(today.substr(3,2).c_str())> atoi(ban_d.substr(3,2).c_str()))
                u_list.at(j).ban_flush();
	else{

	if(atoi(today.substr(6,2).c_str())> atoi(ban_d.substr(6,2).c_str()))
                u_list.at(j).ban_flush();
	}
	}

	if(u_list.at(j).show_ban() == 1){
		ret_code.push_back(6);
		op2rec(6);
		out<< u_list.at(j).show_ban_date()<<endl;;
		return 0;
	}
	////////////////member
	ret_code.push_back(0);
	u_list.at(j).set_borrow(input.at(i*6), input.at(i*6+2));
	////////resource
	for(j=0; j<b_list.size(); j++){
                if( ( input.at(2+i*6) ).compare( b_list.at(j).show_name() )==0 )                {
                 
                        break;
                }
        }
	b_list.at(j).set_borrow(input.at(i*6), input.at(i*6+2));

	op2rec(0);
	return 0;
	



	
	
      
}
int library:: ret_b(int i){
	//ofstream out("output.txt");
	 /////////////none exist
        int j, ex =0;
        for(j=0; j<b_list.size(); j++){
                if( ( input.at(2+i*6) ).compare( b_list.at(j).show_name() )==0 )		{      
                        ex = 1;  
			break;
		}
        }
        if(ex == 0){
                ret_code.push_back(1);
		op2rec(1);
		return 0;
	}

	//////////3. didn't borrow
	for(j=0; j<u_list.size(); j++){
                if( ( input.at(5+i*6) ).compare( u_list.at(j).show_name() )==0 )		{
			break;
		} 
                        
        }
	if( ( input.at(2+i*6) ).compare( u_list.at(j).show_book() ) != 0 ){
		ret_code.push_back(3);
		op2rec(3);
		return 0;
	}
	//////////7. delay return
	string ret_t = input.at(0+i*6);
	string until_d = u_list.at(j).show_until_date();
	int condition = 0;
	if( atoi(ret_t.substr(0,2).c_str())> atoi(until_d.substr(0,2).c_str()) ){
		condition = 1;
		goto L1;
	}
	if( atoi(ret_t.substr(3,2).c_str())> atoi(until_d.substr(3,2).c_str()) ){
                condition = 1;
                goto L1;
        }
	if( atoi(ret_t.substr(6,2).c_str())> atoi(until_d.substr(6,2).c_str()) ){
                condition = 1;
                goto L1;
        }
	
	L1:
	if(condition == 1){
		int year = atoi(ret_t.substr(0,2).c_str())- atoi(until_d.substr(0,2).c_str());
		int month = atoi(ret_t.substr(3,2).c_str())- atoi(until_d.substr(3,2).c_str());
		int day = atoi(ret_t.substr(6,2).c_str())- atoi(until_d.substr(6,2).c_str());
		int delay = year*360 + month*30 + day;
		int r_y, r_m, r_d;
		r_y = atoi(ret_t.substr(0,2).c_str());
		r_m = atoi(ret_t.substr(3,2).c_str());
		r_d = atoi(ret_t.substr(6,2).c_str())+ delay;
		while(r_d>30){
			r_d-=30;
			r_m++;
		}
		while(r_m>12){
			r_m-=12;
			r_y++;
		}
		int result = r_y*10000+ r_m*100+ r_d;
		string result_s = to_string(result);
		result_s.insert(4,"/");
		result_s.insert(2,"/");
		
		
		ret_code.push_back(7);
		u_list.at(j).set_restricted(result_s);
		op2rec(7);
		out<< u_list.at(j).show_ban_date()<<endl;
		return 0;
	}
	///////////////////////
	ret_code.push_back(0);
	op2rec(0);
	return 0;
	

}

