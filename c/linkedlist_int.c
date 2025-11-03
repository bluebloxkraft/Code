#include <stdio.h>
#include <stdlib.h>

// TODO: pop, reverse, sort, clear

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

   current = NULL;
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

   current = NULL;
}

void append(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while(*current != NULL)
      current = &(*current)->tail;

   *current = make_node(elem, NULL);
   
   current = NULL;
}

void from_array(LinkedListInt* pList, int* arr, int arr_size){
   struct node** current = pList;

   for(int i = 0; i < arr_size; i++)
   {
      append(current, arr[i]);
      current = &(*current)->tail;
   }

   current = NULL;
}

void remove_elem(LinkedListInt* pList, int elem){
   struct node** current = pList;

   while((*current)->head != elem)
      current = &(*current)->tail;
   
   struct node* temp = *current;
   *current = temp->tail;
   free(temp);
   temp = NULL;
   current = NULL;
}

void remove_index(LinkedListInt* pList, uint16_t index){
   struct node** current = pList;

   for(int i = 0; i < index; i++)
      current = &(*current)->tail;
   
   struct node* temp = *current;
   *current = temp->tail;
   free(temp);
   current = NULL;
}

void extend(LinkedListInt* pTargetList, LinkedListInt extension){
   struct node** current = pTargetList;

   while(*current != NULL)
      current = &(*current)->tail;

   *current = extension;
   current = NULL;
}

int get_index(LinkedListInt list, uint16_t index){
   struct node** current = &list;

   for(int i = 0; i < index; i++)
      current = &(*current)->tail;
   
   int temp = (*current)->head; 
   current = NULL;
   return temp;
}

uint16_t index_elem(LinkedListInt list, int elem){
   struct node** current = &list;
   uint16_t i = 0;

   while((*current)->head != elem)
   {
      i++;
      current = &(*current)->tail;
   }

   current = NULL;
   return i;
}

void copy(LinkedListInt* pWriteList, LinkedListInt readList){
   struct node** r_current = &readList;
   struct node** w_current = pWriteList;

   while(*r_current != NULL)
   {
      *w_current = make_node((*r_current)->head, NULL);
      r_current = &(*r_current)->tail;
      w_current = &(*w_current)->tail;
   }

   r_current = NULL;
   w_current = NULL;
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

   printf("\n\nget index by element test\nindex of 2: %i", index_elem(list, 2));

   printf("\n\nshallow copy list test\n");
   LinkedListInt list3 = list;
   LinkedListInt list4 = NULL;
   copy(&list4, list);
   insert(&list3, 3, 4900);
   insert(&list4, 5, 8192);
   printf("original (no changes made by code): ");
   print(list);
   printf("\nimproper copy (insert 4900 at 3): ");
   print(list3);
   printf("\nshallow copy (insert 8192 at 5): ");
   print(list4);
}
