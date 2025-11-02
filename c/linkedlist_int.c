#include <stdio.h>
#include <stdlib.h>

// TODO: pop, insert, reverse, sort, index, clear, copy

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

void insert(LinkedListInt* pList, uint16_t index, int elem){
   struct node** current = pList;

   for(int i = 0; i < index; i++)
      current = &(*current)->tail;

   struct node* pNewNode = (struct node*) malloc(sizeof(struct node));
   pNewNode->head = elem;
   pNewNode->tail = *current;

   *current = pNewNode;
}

void append(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while(*current != NULL)
      current = &(*current)->tail;

   struct node* pNewNode = (struct node*) malloc(sizeof(struct node));
      pNewNode->head = elem;
      pNewNode->tail = NULL;

      *current = pNewNode;
}

void from_array(LinkedListInt* pList, int* arr, int arr_size){
   struct node** current = pList;

   for(int i = 0; i < arr_size; i++)
   {
      append(current, arr[i]);
      current = &(*current)->tail;
   }
}

void rem(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while((*current)->head != elem)
      current = &(*current)->tail;
   
   struct node* temp = *current;
   *current = temp->tail;
   free(temp);
}

void extend(LinkedListInt* pTargetList, LinkedListInt extension){
   struct node** current = pTargetList;

   while(*current != NULL)
      current = &(*current)->tail;

   *current = extension;
}

int main(){
   int arr[] = {1, 100, 102, 38484, 3777};
   LinkedListInt list = NULL;
   printf("array to linkedlist test\n");
   from_array(&list, arr, sizeof(arr) / sizeof(int));
   print(list);

   printf("\n\nremove element test\n");
   rem(&list, 100);
   print(list);

   printf("\n\nappend element test\n");
   append(&list, 78);
   print(list);

   printf("\n\nextend list test\n");
   LinkedListInt list2 = NULL;
   int arr2[] = {1, 2, 303};
   from_array(&list2, arr2, sizeof(arr2) / sizeof(int));
   extend(&list, list2);
   print(list);

   printf("\n\ninsert element test\n");
   insert(&list, 5, 1000);
   print(list);
}
