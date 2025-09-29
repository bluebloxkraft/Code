#include <stdio.h>

// takes the IEEE 754 float in binary, then returns what integer those bits represent.

int floatBitToInt(float theFloat) {
   return *(int*) &theFloat;
}

// test
int main(){
   printf("%i", floatBitToInt(-6.9));
}
