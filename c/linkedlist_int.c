#include <stdio.h>
#include <stdlib.h>

struct node {
   int head;
   struct node* tail;
};

typedef struct node* LinkedListInt;

void print(LinkedListInt list){
   LinkedListInt* current = &list;

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

int main(){
   int arr[] = {1, 2, 33, 444, 5555};
   LinkedListInt list = NULL;

   from_array(&list, arr, 5);

   print(list);
}
