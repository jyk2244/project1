#include <iostream>

using namespace std;

class String{
        private:
        char* name;

        public:
        String(){
	}
	String(char* a){
		//String :: String(char* a){
        	name = a;
	}

        String operator+(String o);
	void print();
	//String String operator+=(class String o);
	//String String operator==(class String o);
	//String String operator>(class String o);
	//String String operator<(class String o);

};

