#include <stdio.h>
#include <stdlib.h>

struct node {
   int head;
   struct node* tail;
};

typedef struct node* LinkedListInt;

void print(LinkedListInt list){
   struct node** current = &list;

   while(*current != NULL)
   {
      printf("%i ", (*current)->head);
      current = &(*current)->tail;
   }
}

void from_array(LinkedListInt* listPtr, int* arr, int arr_size){
   struct node** current = listPtr;

   for(int i = 0; i < arr_size; i++)
   {
      struct node* pnew_node = (struct node*) malloc(sizeof(struct node));
      pnew_node->head = arr[i];
      pnew_node->tail = NULL;
      
      *current = pnew_node;
      current = &pnew_node->tail;
   }
}

void rem(LinkedListInt* listPtr, int elem){
   struct node** current = listPtr;

   while((*current)->head != elem)
      current = &(*current)->tail;
   
   struct node* temp = *current;
   *current = (*current)->tail;
   free(temp);
}

int main(){
   int arr[] = {1, 100, 102, 38484, 3777};
   LinkedListInt list = NULL;
   
   printf("array to linkedlist test\n");
   from_array(&list, arr, 5);
   print(list);

   printf("\nremove element test\n");
   rem(&list, 100);
   print(list);


}
