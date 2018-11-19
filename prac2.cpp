#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	cout<< "selcet type, int: 1, string : 2"<<endl;
	int type;
	cin >>type;
	vector<int> i_list;
	vector<string> s_list;
	int i2;
	string s2;
		
	if(type == 1){
		 
		for(int i=0; i<5; i++){
			cin>>i2;
			i_list.push_back(i2);
			vector<int> ::iterator itr;
			if(i_list.at(i)%2 == 0)
				cout << i_list.at(i)<< " ";
		}
		
	}
	
	else if(type ==2){
		for(int i=0; i<5; i++){
                        cin>>s2;
                        s_list.push_back(s2);
                }

	}
	return 0;
}
