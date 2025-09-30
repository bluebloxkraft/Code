#include <iostream>

using namespace std;

int main() {
	for(int i = 1; i <= 100; i++){
		string output = "";
		
		if(i % 3 == 0) output = output + "fizz";
		if(i % 5 == 0) output = output + "buzz";
		if(output == "") output = to_string(i);
		
		cout << output << endl;
	}
}
