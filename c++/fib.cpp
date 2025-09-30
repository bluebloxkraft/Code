#include <iostream>

using namespace std;

int fib(int n) {
	int n0 = 1;
	int  n1 = 0;
	int n2 = 1;
	
	for(int k = 1; k < n; k++){
		n1 = n2;
		n2 = n0;
		n0 = n1 + n2;
	}
	
	return n0;	

}

int main() {
        int n;
	cout << "Enter the index of the number in the fibonacci sequence you want to find: ";
	cin >> n;
	cout << to_string(fib(n)) << endl;
	return 0;
}
