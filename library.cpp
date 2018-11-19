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
	/*ifstream in("resource.dat");
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
	
	 */
	library2();
}
void library :: library2() {
	day_check = 0;
	int i;
	for(i=0;i<10;i++){                  //make studyroom
		studyroom S;
		S.set_studyroom_number(i+1);
		studyrooms.push_back(S);
	}
	int j;
	for(i=0;i<3;i++){				//make seat
		for(j=0;j<50;j++){
			seat T;
			T.set_seat_floor(i+1);
			seats.push_back(T);
		}
	}
	input2();
}
void library :: input2(){

	ifstream input_file;
	ifstream input_file2;
	ofstream output_file;
	input_file.open("input.dat");
	input_file2.open("space.dat");
	output_file.open("output.dat");
	string line;
	for(int i=0; i<6; i++){
		input_file >> line;
	}
	for(int i=0; i<8; i++){
		input_file2 >> line;
	}

	int count = 1;
	string date, resource_type, resource_name, operation, member_type, member_name;
	string date2, space_type, space_number, operation2, member_type2, member_name2, number_of_member, in_time;
	output_file << "Op_#\tReturn_code\tDescription" << endl;
	int flag=0;
	int flag_book_file=0;
	int flag_space_file=0;
	while(1) {
		
		if((flag == 0 || flag == 1) && flag_book_file == 0) {
			if(!(input_file >> date)) {
				flag_book_file = 1;
				date = "99/12/30";
			}
		}

		if((flag == 0 || flag == 2) && flag_space_file == 0) {
			if(!(input_file2 >> date2)){
				flag_space_file = 1;
				date2 = "9999/12/30/10";
			}
			if(day_check ==0 ) {
				day_check = date2int2(date2);
			}
		}

		if(flag_book_file ==1 && flag_space_file ==1){
			break;
		}
		int int_date = date2int(date);
		int int_date2 = date2int2(date2);

		if(int_date <= int_date2){
			input_file >> resource_type;
			input_file >> resource_name;
			input_file >> operation;
			input_file >> member_type;
			input_file >> member_name;
			flag = 1;
		}
		else{
			input_file2 >> space_type;
			input_file2 >> space_number;
			input_file2 >> operation2;
			input_file2 >> member_type2;
			input_file2 >> member_name2;
			if(operation2 == "B") {
				input_file2 >> number_of_member;
				input_file2 >> in_time;
			}
			flag = 2;
			ec(date2);
			s_data(count, date2, space_type, space_number, operation2, member_type2, member_name2, stoi(number_of_member), stoi(in_time));
		}
		
		count ++;
	
	}

	input_file.close();
	input_file2.close();
	output_file.close();	
}

void library :: s_data(int count, string date2, string space_type, string space_number, string operation2, string member_type2, string member_name2, int number_of_member, int in_time) {
	// code = 8
	if(space_type == "StudyRoom"){
		if(stoi(space_number) > 10 || stoi(space_number) ==0 ){
			output(count, 8, "Invalid space id.");
			return;
		}
	}
	if(space_type == "Seat"){
		if(stoi(space_number) > 3 || stoi(space_number) == 0){
			output(count, 8, "Invalid space id.");
			return;
		}
	}


	//code 9
	int hour = date2hour(date2);

	if(space_type == "StudyRoom"){
		if(hour >= 18 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 18.");
			return;
		}
	}
	else if(stoi(space_number) == 2){
		if(hour >= 21 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 21.");
			return;
		}
	}
	else if(stoi(space_number) == 3){
		if(hour >= 18 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 18.");
			return;
		}
	}



	//code 10
	if(operation2 != "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_studyroom_number()==stoi(space_number)){
					if(s.get_name() != member_name2){
						output(count, 10, "You did not borrow this space.");
						return;
					}
				}
			}
		}
		else{
			for(auto s : seats){
				if(s.get_seat_floor()==stoi(space_number)){
					if(s.get_name() != member_name2){
						output(count, 10, "You did not borrow this space.");
						return;
					}
				}
			}
		}

	}
	
	//code 11
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_name() == member_name2){
					output(count, 11, "You already borrowed this kind of space.");
					return;
				}
			}
		}
		else{
			for(auto s : seats){
				if(s.get_name() == member_name2){
					output(count, 11, "You already borrowed this kind of space.");
					return;
				}
			}
		}
	}

	//code 12
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			if(number_of_member > 6){
				output(count, 12, "Exceed available number.");
				return;
			}
		}
		else{
			if(number_of_member > 1){
				output(count, 12, "Exceed available number.");
				return;
			}
		}
	}

	//code 13
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			if(in_time > 3){
				output(count, 13, "Exceed available time.");
				return;
			}
		}
		else{
			if(in_time > 3){
				output(count, 13, "Exceed available time.");
				return;
			}
		}
	}

	//code 14
	string error;
	int limit;
	string s_limit;
	int seat_limit=24;
	int flag_limit=0;
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					if(s.get_status() != 0){
						limit = s.get_time()+3;
						if(limit >= 18) limit = 18;
						s_limit = to_string(limit);
						if(limit>=0 && limit <=9){
							s_limit = "0" + s_limit;
						}
						error = "There is no remain space. This space is available after " + s_limit + ".";
						output(count, 14, error);
						return;
					}
					
				}
			}
		}
		else{
			if(stoi(space_number) == 3){           // 3 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 3){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 18) seat_limit = 18;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
			else if(stoi(space_number) == 2){           // 2 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 2){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 21) seat_limit = 21;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
			else if(stoi(space_number) == 1){           // 1 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 1){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 24) seat_limit = 24;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					if(seat_limit == 24) s_limit = "00";
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
		}
	}

	//code =0 success
	int i;
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_name(member_name2);
					s.set_time(date2hour(date2));
					s.set_status(1);
					s.set_use_time(in_time);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_status() == 0){
					s.set_name(member_name2);
					s.set_time(date2hour(date2));
					s.set_status(1);
					s.set_use_time(in_time);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
					break;
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "R"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_name("");
					s.set_time(24);
					s.set_status(0);
					s.set_use_time(0);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name()==member_name2){
					s.set_name("");
					s.set_time(24);
					s.set_status(0);
					s.set_use_time(0);
					s.set_wantempty(0);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "E"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_status(2);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name() == member_name2){
					s.set_status(2);
					s.set_wantempty(date2hour(date2));
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "C"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_status(1);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name() == member_name2){
					s.set_status(1);
					s.set_wantempty(0);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
}

void library :: output(int op_num, int return_code, string description) {
	ofstream file;
	file.open("output.dat", ios::app);
	file << op_num << "\t" << return_code << "\t" << description << endl;
	file.close();
}

int library :: date2int(string date) {

	string year, month, day;

	year = date[0];
	year += date[1];
	month = date[3];
	month +=date[4];
	day = date[6];
	day += date[7];

	int result = stoi(year) * 360 + stoi(month)*30 + stoi(day);

	return result;
}

int library :: date2int2(string date2) {

	string year, month, day, hour;

	year = date2[2];
	year += date2[3];
	month = date2[5];
	month +=date2[6];
	day = date2[8];
	day += date2[9];

	int result = stoi(year) * 360 + stoi(month)*30 + stoi(day);
	return result;
}

int library :: date2hour(string date2) {
	string hour;
	hour = date2[11];
	hour += date2[12];
	int result = stoi(hour);
	return result;
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

void library :: ec(string date2) {
	int i;
	if(day_check < date2int2(date2)){                     //change date
		studyrooms.clear();
		seats.clear();
		for(i=0;i<10;i++){                  //make studyroom
			studyroom S;
			S.set_studyroom_number(i+1);
			studyrooms.push_back(S);
		}
		int j;
		for(i=0;i<3;i++){				//make seat
			for(j=0;j<50;j++){
				seat T;
				T.set_seat_floor(i+1);
				seats.push_back(T);
			}
		}
		day_check = date2int2(date2);
	}
	else {
		i = 0;
		for(auto s : studyrooms){
			if(s.get_status() != 0 && date2hour(date2) >= (s.get_use_time() + s.get_time())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				studyrooms.push_back(s);
				studyrooms.erase(studyrooms.begin() + i);
				i--;
			}
			i++;
		}			

		i = 0;
		for(auto s : seats){
			if(s.get_status() == 1 && date2hour(date2) >= (s.get_use_time() + s.get_time())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				s.set_wantempty(0);
				seats.push_back(s);
				seats.erase(seats.begin() + i);
				i--;
			}
			else if(s.get_status() == 2 && date2hour(date2) >= (1 + s.get_wantempty())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				s.set_wantempty(0);
				seats.push_back(s);
				seats.erase(seats.begin() + i);
				i--;
			}
			i++;
		}

	}
}

