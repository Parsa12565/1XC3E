#include <stdio.h>
#include <stdlib.h>

// Use typedef and struct to create a Set type

typedef struct _set 
{
  int *elements;
  int length;
} Set;

Set* init(int member);
void insert(Set *set, int member);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);

int main()
{
  Set *setA = init(4);
  insert(setA, 5);
  insert(setA, 6);
  insert(setA, 7);
  insert(setA, 7);
  print_set(setA);

  Set *setB = init(6);
  insert(setB, 7);
  insert(setB, 8);
  insert(setB, 9);
  insert(setB, 10);
  print_set(setB);

  Set *setC = set_union(setA, setB);
  print_set(setC);
}

// Create the set functions

Set* init(int member)
{
  Set *new=calloc(1,sizeof(Set));
  new->elements=malloc(sizeof(int));
  new->elements[0]=member;
  new->length=1;
  return new;
}

void insert(Set *set, int member)
{
  for(int i=0;i<set->length;i++)
  {
    if(member==set->elements[i])
    {
      return;
    }
  }
  set->length++;
  set->elements=realloc(set->elements,sizeof(int)*(set->length));
  set->elements[set->length-1]=member;
}

void print_set(Set *set)
{
  for(int i=0;i<set->length;i++)
  {
    if(i==(set->length)-1)
    {
      printf("%d\n",set->elements[i]);
    }
    else
    {
      printf("%d,",set->elements[i]);
    }
  }
}

Set *set_union(Set *setA, Set *setB)
{
  Set *new=init(setA->elements[0]);
  for(int i=1;i<setA->length;i++)
  {
    insert(new,setA->elements[i]);
  }
  for(int i=0;i<setB->length;i++)
  {
    insert(new,setB->elements[i]);
  }
  return new;
}