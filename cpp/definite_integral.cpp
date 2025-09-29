#include <iostream>

double f(double x)
{
   return 2*x;
}

double def_integral(double (*func)(double), double lower, double upper, double delta_x)
{ 
   if(lower > upper)
      return -1 * def_integral(func, upper, lower, delta_x);

   if(lower == upper)
      return 0;

   double riemann_sum = 0;

   for(double x = lower; x <= upper; x += delta_x)
      riemann_sum += delta_x * func(x);

   return riemann_sum;
}

void askAndSetDouble(double* pVal, std::string valueName)
{
   std::cout << "Enter " << valueName << ": ";
   std::cin >> *pVal;
   std::cout << "\n";
}

int main()
{
   double x;
   double lower;
   double upper;
   double delta_x;

   askAndSetDouble(&lower, "the lower bound");
   askAndSetDouble(&upper, "the upper bound");
   askAndSetDouble(&delta_x, "delta_x");

   std::cout << "The result is " << def_integral(f, lower, upper, delta_x) << "\n";
}
