#include <iostream>

int fib(int n){
   if(n == 0)
      return 1;

   int F1 = 0;
   int F2 = 1;
   int F3 = 1;

   for(int i = 1; i < n; i++){
      F3 = F2 + F1;
      F1 = F2;
      F2 = F3;
   }

   return F3;
}

int main(){
   std::cout << "Enter a number: ";
   int x;
   std::cin >> x;
   std::cout << "The Fibonacci number at index " << x << " is " << fib(x) << "\n";
}
