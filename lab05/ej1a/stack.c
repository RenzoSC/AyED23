#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack
{
  stack_elem elem;
  struct _s_stack *next;
};

stack stack_empty(){
  stack s = NULL;
  return s;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;                         
    s = p;
    return s;
}

stack stack_pop(stack s){
  stack s2 = s;
  s = s->next;
  free(s2);
  return s;
}

unsigned int stack_size(stack s){
  unsigned int len =0;
  stack p;
  p = s;
  while (p!=NULL)
  {
      len+=1;
      p = p->next;
  }
  return len;
}

stack_elem stack_top(stack s){
  assert(stack_size(s)>0);
  return s->elem;
}

bool stack_is_empty(stack s){
  return s == NULL;
}

stack_elem *stack_to_array(stack s){
  stack_elem *s_array = malloc(sizeof(stack_elem) * stack_size(s));
  for (size_t i = stack_size(s); i >0; i--)
  {
    s_array[i-1] = stack_top(s);
    s = stack_pop(s);
  }
  return s_array;
}

stack stack_destroy(stack s){
  stack s2;
  s2=s;
  while (s!=NULL)
  {
      s = s->next;
      free(s2);
      s2 = s;
  }
  return NULL;
}
