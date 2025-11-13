#include <stdio.h>

void takeMark(char subname[10],  float* pMark)
{
   printf("Enter the mark for %s", subname);
   printf(": ");
   scanf("%f", pMark);
   printf("\n");
}

void printMark(char subname[10], float mark)
{
   printf("| %11s | %5.1f |\n", subname, mark);
}

int main()
{
   float eng;
   float mat;
   float sci;
   float cs;
   float hpe;
   float avg;

   takeMark("Science", &sci);
   takeMark("English", &eng);
   takeMark("Comp. Sci.", &cs);
   takeMark("HPE", &hpe);
   takeMark("Maths", &mat);

   avg = (eng + mat + sci + cs + hpe) / 5;

   printf("+-------------+-------+\n");
   printf("|   Subject   |  Mks. |\n");
   printf("+-------------+-------+\n");
   printMark("Science", sci);
   printMark("English", eng);
   printMark("Comp. Sci.", cs);
   printMark("HPE", hpe);
   printMark("Maths", mat);
   printf("+-------------+-------+\n");
   printMark("Average", avg);
   printf("+-------------+-------+\n");
}
