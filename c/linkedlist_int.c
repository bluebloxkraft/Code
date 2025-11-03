#include <stdio.h>
#include <stdlib.h>

// TODO: pop, reverse, sort, clear, copy

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

struct node* make_node(int head, struct node* tail){
   struct node* pNewNode = (struct node*) malloc(sizeof(struct node));
   pNewNode->head = head;
   pNewNode->tail = tail;

   return pNewNode;
}

void insert(LinkedListInt* pList, uint16_t index, int elem){
   struct node** current = pList;

   for(int i = 0; i < index; i++)
      current = &(*current)->tail;

   *current = make_node(elem, *current);
}

void append(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while(*current != NULL)
      current = &(*current)->tail;

   *current = make_node(elem, NULL);
}

void from_array(LinkedListInt* pList, int* arr, int arr_size){
   struct node** current = pList;

   for(int i = 0; i < arr_size; i++)
   {
      append(current, arr[i]);
      current = &(*current)->tail;
   }
}

void remove_elem(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while((*current)->head != elem)
      current = &(*current)->tail;
   
   struct node* temp = *current;
   *current = temp->tail;
   free(temp);
}

void remove_index(LinkedListInt* pList, uint16_t index){
   struct node** current = pList;

   for(int i = 0; i < index; i++)
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

int get_index(LinkedListInt list, uint16_t index){
   struct node** current = &list;

   for(int i = 0; i < index; i++)
      current = &(*current)->tail;

   return (*current)->head;
}

uint16_t elem_index(LinkedListInt list, int elem){
   struct node** current = &list;
   uint16_t i = 0;

   while((*current)->head != elem)
   {
      current = &(*current)->tail;
      i++;
   }

   return i;
}

void copy(LinkedListInt* pWriteList, LinkedListInt readList){
   struct node** r_current = &readList;
   struct node** w_current = pWriteList;


}

int main(){
   int arr[] = {1, 100, 102, 38484, 3777};
   LinkedListInt list = NULL;
   printf("array to linkedlist test\n");
   from_array(&list, arr, sizeof(arr) / sizeof(int));
   print(list);

   printf("\n\nremove element by value test\n");
   remove_elem(&list, 100);
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
   
   printf("\n\nremove element by index test\n");
   remove_index(&list, 4);
   print(list);

   printf("\n\nget element by index test\n2-nd elem: %i", get_index(list, 2));

   printf("\n\nget index by element test\nindex of 2: %i", elem_index(list, 2));

   
}
