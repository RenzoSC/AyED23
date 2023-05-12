#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack
{
  stack_elem elem;
  struct _s_stack *next;
  unsigned int size;
};

static bool inv_repre (stack s){
    return (s != NULL ? s->size >0 && s->elem != NULL: true);  //NO SE SI ESTA BIEN ESTA INVREP preguntar al profe
}

stack stack_empty(){
  stack s = NULL;
  return s;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;
    p->size = s ==NULL? 1: s->size +1;                         
    s = p;
    return s;
}

stack stack_pop(stack s){
  assert(!stack_is_empty(s));
  stack s2 = s;
  s = s->next;
  free(s2);
  return s;
}

unsigned int stack_size(stack s){
  return s == NULL ? 0 : s->size;
}

stack_elem stack_top(stack s){
  assert(stack_size(s)>0);
  return s->elem;
}

bool stack_is_empty(stack s){
  return s == NULL;
}

stack_elem *stack_to_array(stack s){
  stack_elem *s_array = calloc(stack_size(s), sizeof(stack_elem));
  stack p = s;
  if (!stack_is_empty(s))
  {
    for (size_t i = stack_size(s); i >0; i--)
    {
      s_array[i-1] = stack_top(p);
      p = p -> next;
    }
  }else{
    s_array = NULL;
  }
  
  return s_array;
}

stack stack_destroy(stack s){
  stack s2 = NULL;
  s2=s;
  while (s!=NULL)
  {
      s = s->next;
      free(s2);
      s2 = s;
  }
  s=NULL;
  return s;
}

