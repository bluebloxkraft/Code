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
 * - fix the functions that dont work right now
 */

#include <stdio.h>
#include <stdlib.h>

struct _llist_int {
   int head;
   struct _llist_int* tail;
}; //LLI is short for linked list integer

typedef struct _llist_int* LLI;

// pointer to a new integer linked list instance
LLI newLLI(int head, LLI tail) {
   LLI ptr = (LLI) malloc(sizeof(struct _llist_int));   
   if(ptr != NULL)
   {
      ptr->head = head;
      ptr->tail = tail;
   }

   return ptr;
}

// linked list creation functions

LLI arrToLl(int* arr, int length) {
   LLI res = newLLI(arr[0], NULL);
   LLI current = res;

   for(int i = 0; i < length; i++)
   {
      LLI next = newLLI(arr[i], NULL);
      current->tail = next;
      current = current->tail;
   }

   return res;
}

// linked list modification functions

void ll_append(LLI targetList, int elem) {
   LLI current = targetList;

   while(current->tail != NULL)
      current = current->tail;
   
   current->tail = newLLI(elem, NULL);
}

void ll_insert(LLI targetList, int index, int elem) {
   // this aint gonna work for index 0... yikes
   LLI current = targetList;
   
   for(int i = 0; i < index - 1; i++)
   {
      current = current->tail;
      if(current == NULL)
         break;
   }
   
   current->tail = newLLI(elem, current->tail);
}
/*
// doesnt work as i intended for now
LLI ll_pop(LLI targetList, int index) {
   LLI current = targetList;
   LLI res;

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
}*/
/*
void ll_delete(LLI targetList, int index) {
   free(ll_pop(targetList, index));
}
*/
/*
void ll_remove(LLI targetList, int elem) {
   LLI* current = &targetList;
   
}*/

// misc.
void ll_print(LLI ll){
   LLI curr = ll;
   
   while(curr != NULL)
   {
      printf("%i ", curr->head);
      curr = curr->tail;
   }
}

// test
int main(){
   printf("print test");
   struct _llist_int l1 = {1, NULL};
   struct _llist_int l2 = {2, l1};
   struct _llist_int l3 = {3, l2};
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
/*
   printf("\ndel test\n");
   ll_delete(&theList, 3);
   ll_print(theList); */
}
