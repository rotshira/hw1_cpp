

//In this assignment, I used the test of the course Programming Systems A. Date A. in the team solution.
//In addition, I used the file that the practitioner directed us to
 // .file:///C:/Users/shira/Downloads/%D7%AA%D7%A8%D7%92%D7%95%D7%9C%2011%D7%91%20ADT%20(1).pdf

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "book.h"
#include "AdptArray.h"
// #include <stddef.h>
#include <assert.h>


typedef struct AdptArray_
{
PElement *ArrElements;
int len;
/* Function Pointers */
COPY_FUNC copy;
PRINT_FUNC print;
DEL_FUNC del;

} AdptArray, *PAdptArray;

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

void DeleteAdptArray(PAdptArray myArray)
{
  int i;
	if (myArray == NULL)
  {
    	return;
  }
	
	for(i = 0; i < myArray->len; ++i)
	{
    if(myArray->ArrElements[i]!= NULL)
		myArray->del((myArray->ArrElements)[i]);
	}
	free(myArray->ArrElements);
	free(myArray);

}

Result SetAdptArrayAt(PAdptArray parray, int x, PElement pe)
{
  printf("ddddddddddd:\n");
PElement* new_elemnt;
	if (parray == NULL)
		return FAIL;
if (x >= parray->len)
	{
    //WE NEED TO EXTEND:
    if ((new_elemnt = (PElement*)calloc((x + 1), sizeof(PElement))) == NULL)
			return FAIL;
      //copies n =((parray->len) * sizeof(PElement)) characters from memory area src to memory area dest.
      memcpy(new_elemnt, parray->ArrElements, (parray->len) * sizeof(PElement));
		free(parray->ArrElements);
		parray->ArrElements = new_elemnt;
      printf("rrrrrrrrrrrrrr:\n");
}
//if existe so -  we Delete Previous Element.
if((parray->ArrElements)[x])
{
  parray->del((parray->ArrElements)[x]);
}
(parray->ArrElements)[x] = parray->copy(pe);
  printf("ccccccccc:\n");
// Update Array Size
if (x >= parray->len){
parray->len = x + 1;
}
else{
parray->len = parray->len;
}
  printf("lllllllllll:\n");

	return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray parray , int x)
{
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
///
int GetAdptArraySize(PAdptArray parray)
{
  if(parray->ArrElements == NULL)
  {
    return -1;
  }
  printf("kkkkkkkkkk:\n");
return parray->len;
}

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