#include <stdio.h>

int main(){
   for(int r = 0; r < 32; r++)
      for(int g = 0; g < 32; g++)
         for(int b = 0; b < 32; b++)
            printf("\033[38;2;%i;%i;%imA\033[0m", 8 * r, 8 * g, 8 * b);
}
