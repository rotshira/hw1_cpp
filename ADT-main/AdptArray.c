

/* Explanation -
In the assignment we were asked to write AdptArray.c
In the assignment, I was helped by the solution of a due date test.
In addition, I used the practice file that the practitioner gave us.
I also used Google - stack overflow, geeksforgeeks..
The assignment was clear.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "book.h"
#include "AdptArray.h"
#include <stddef.h>
#include <assert.h>

// the struct to adptarray 
typedef struct AdptArray_
{
PElement *ArrElements;
int len;
/* Function Pointers */
COPY_FUNC copy;
PRINT_FUNC print;
DEL_FUNC del;

} AdptArray, *PAdptArray;
//////////////////////////// CREATE AdptArray //////////////////////////////////////
PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC del,PRINT_FUNC print)
{
PAdptArray MyArray = (PAdptArray)malloc(sizeof(AdptArray));
if (MyArray == NULL)
return NULL;
MyArray-> len = 0;
MyArray-> ArrElements = NULL;
MyArray->copy = copy;
MyArray->print = print;
MyArray->del = del;
//RETURN
return MyArray;
}

//////////////////////////// Delete AdptArray //////////////////////////////////////
void DeleteAdptArray(PAdptArray myArray)
{
  int i;
	if (myArray == NULL)
  {
    	return; //stop
  }
	for(i = 0; i < myArray->len; ++i)
	{
    if(myArray->ArrElements[i]!= NULL)
		myArray->del((myArray->ArrElements)[i]);
	}
	free(myArray->ArrElements);
	free(myArray);

}

//////////////////////////// Set AdptArrayAt //////////////////////////////////////
Result SetAdptArrayAt(PAdptArray parray, int x, PElement pe)
{
  //IF THE INDEX IS NEGETIVE NUMBER
if (x < 0)
return FAIL;
PElement* new_elemnt;
	if (parray == NULL)
		return FAIL;
if (x >= parray->len)
	{
    // EXTEND the array:
    if ((new_elemnt = (PElement*)calloc((x + 1), sizeof(PElement))) == NULL) 
			return FAIL;
      //copies n =((parray->len) * sizeof(PElement)) characters from memory area src to memory area dest.
      memcpy(new_elemnt, parray->ArrElements, (parray->len) * sizeof(PElement));
		free(parray->ArrElements);
		parray->ArrElements = new_elemnt;
}
//if existe so -  we Delete Previous Element.
if((parray->ArrElements)[x])
{
  parray->del((parray->ArrElements)[x]);
}
(parray->ArrElements)[x] = parray->copy(pe);
// Update Array Size
if (x >= parray->len){
parray->len = x + 1;
}
else{
parray->len = parray->len;
}
	return SUCCESS;
}

//////////////////////////// Get AdptArrayAt //////////////////////////////////////
PElement GetAdptArrayAt(PAdptArray parray , int x)
{
//IF THE INDEX IS NEGETIVE NUMBER
if (x < 0)
return FAIL;
PElement element;
if(parray->ArrElements[x] != NULL){
element = parray->copy(parray->ArrElements[x]);
  }
  else
  {
   element = NULL;
  }
return element;
}

//////////////////////////// Get AdptArray Size //////////////////////////////////////
int GetAdptArraySize(PAdptArray parray)
{
  if(parray->ArrElements == NULL)
  {
    return -1;
  }
return parray->len;
}

//////////////////////////// PrintDB //////////////////////////////////////
void PrintDB(PAdptArray parray)
{ 
 if(parray->ArrElements!=NULL)
 {
    for(int i=0; i<parray->len;i++){
    if(parray->ArrElements[i]!=NULL){
    parray->print(parray->ArrElements[i]);
}
  }
 }
}