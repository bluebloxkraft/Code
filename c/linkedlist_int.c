/**
 * @author bluebloxkraft
 *
*/

/*
 * this thing is bad
 */

/*
 * TODO:
 * - more safety and checks
 * - get better at doing this
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _llist_int{
   int head;
   struct _llist_int* tail;
} LLI; //LLI is short for linked list integer

// pointer to a new integer linked list instance
LLI* pNewLLI(int head, LLI* tail) {
   LLI* ptr = (LLI*) malloc(sizeof(LLI));   
   if(ptr != NULL)
   {
      ptr->head = head;
      ptr->tail = tail;
   }

   return ptr;
}

// linked list creation functions

LLI arrToLl(int* arr, int length) {
   LLI res = {arr[0], NULL};
   LLI* current = &res;

   for(int i = 1; i < length; i++){
      LLI* ptr = pNewLLI(arr[i], NULL);

      current->tail = ptr;
      current = current->tail;
   }

   return res;
}

// linked list modification functions

void ll_append(LLI* targetList, int elem) {
   LLI* current = targetList;

   while(current->tail != NULL)
      current = current->tail;
   
   current->tail = pNewLLI(elem, NULL);
}

void ll_insert(LLI* targetList, int index, int elem) {
   // this aint gonna work for index 0... yikes
   LLI* current = targetList;
   
   for(int i = 0; i < index - 1; i++)
   {
      current = current->tail;
      if(current == NULL)
         break;
   }
   
   current->tail = pNewLLI(elem, current->tail);
}

// doesnt work as i intended for now
LLI* ll_pop(LLI* targetList, int index) {
   LLI* current = targetList;
   LLI* res;

   for(int i = 0; i < index - 1; i++)
   {
      current = current->tail;
      if(current == NULL)
      {
         printf("ERROR: index %i is out of bounds\n", index);
         return NULL;
      }
      
      res = current->tail;
      current->tail = current->tail->tail;
   }

   return res;
}

void ll_delete(LLI* targetList, int index) {
   free(ll_pop(targetList, index));
}

void ll_remove(LLI* targetList, int elem) {
   LLI** current = &targetList;
   
}

// misc.
void ll_print(LLI ll){
   LLI* curr = &ll;
   
   while(curr != NULL)
   {
      printf("%i ", curr->head);
      curr = curr->tail;
   }
}

// test
int main(){
   printf("print test");
   LLI l1 = {1, NULL};
   LLI l2 = {2, &l1};
   LLI l3 = {3, &l2};
   ll_print(l3);
   
   printf("\narray to linked list test\n");
   int iArr[] = {1,2,3,4,5};
   LLI theList = arrToLl(iArr, 5);
   ll_print(theList);
   
   printf("\nappend test\n");
   ll_append(&theList, 10);
   ll_print(theList);
   
   printf("\ninsert\n");
   ll_insert(&theList, 2, 600);
   ll_print(theList);

   printf("\ndel test\n");
   ll_delete(&theList, 3);
   ll_print(theList);
}
