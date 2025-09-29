#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

	double low_bnd, up_bnd;
	double result;
	double current_pow = 0;

	cout << "Calculate the definite integral of a polynomial!" << endl;
   cout << "Enter the lower bound: ";
	cin >> low_bnd;
	cout << "Enter the upper bound: ";
	cin >> up_bnd;

	while(true){
	   cout << "Enter the factor of the term whose degree is " << current_pow << " (\"exit\" for exiting): ";
      string input;
      cin >> input;
      
      if(input == "exit")
         break;

      double coeff;

      try {
        coeff = stod(input);
      } catch(invalid_argument& _) {
         cout << "Invalid input!\n";
         continue;
      } catch(out_of_range& _) {
         cout << "Out of range!\n";
         continue;
      }

   	result += coeff / (current_pow + 1) * (pow(up_bnd, current_pow + 1) - pow(low_bnd, current_pow + 1));
		current_pow++;
	}
	
	cout << "The result is: " << result << endl;

	return 0;
}
