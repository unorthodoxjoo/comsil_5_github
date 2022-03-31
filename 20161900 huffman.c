#include <stdio.h>
#include <stdlib.h> //qsort이용

#define N 5

typedef struct node *NODE; 
struct node {
    int w;        // 가중치
    NODE lc, rc;  
    NODE next;    
};

NODE List = NULL; 
int a[] = {15,5,8,12,4};
int array_size = sizeof(a)/sizeof(int);

NODE least() {
  NODE t;

  if (List == NULL)
     return NULL;
  t = List;
  List = List->next;
  return t;
}

NODE newnode() {
  NODE t;

  t = (NODE)malloc(sizeof(struct node));
  t->lc = NULL;
  t->rc = NULL;
  t->next = NULL;
  return t;
}


void insert(NODE t) {
  NODE pt, old;
  if (list == NULL || t->w <list->w)
  {
    t->next = list;
    list = t;
  }
  else 
  {
      old = list;
      pt = old-> next;
      while (pt != NULL && pt->w <t ->w)
      {
          old = pt;
          pt = pt -> next;
      }
      t -> next = pt;
      old -> next = t;
  }



}

int compare(const void *a, const void *b)    
{
    int num1 = *(int *)a;    
    int num2 = *(int *)b;    

    if (num1 < num2)    
        return -1;     

    if (num1 > num2)    
        return 1;       

    return 0;    
}

void init(){
  int i;
  NODE t, pre;

  qsort(a, array_size, sizeof(int), compare);

  printf("after sorting\n");
  for (i=0; i < array_size; i++) 
     printf("%d ", a[i]);
  printf("\n");

  printf("after linked list making\n");
  for (i=0; i < array_size; i++) {
     t = newnode();
     t->w = a[i];
     printf("%d ", t->w);

     if (i==0) {
	 List = t;
     }
     else {
	 pre->next = t; 
     }
     pre = t;
  }
  printf("\n");

  t = List;
  while (t->next!=NULL) 
  {
     printf("%d ", t->w);
     t = t->next;
  }
  printf("%d\n", t->w);
}

void free_all(){
  int i;
  NODE t;

  t = List;
  for (i=0; i < array_size; i++) {
     free(t);
     t = t->next;
  }
}

void preorder(NODE t)
{
    if (t != NULL) {
       printf("%d ", t->w);
       preorder(t->lc);
       preorder(t->rc);
    }
}

int main(void) {
  int i;
  NODE pt;

  printf("array_size %d\n", array_size);
  init(); 

  
  for (i = 1; i < N; i++) {
    pt = newnode();
    pt->lc = least();
    pt->rc = least();
    pt->w = (pt->lc)->w + (pt->rc)->w;
    insert(pt);
  }
  preorder(List);
  printf("preorder done\n");
  //free_all();

  return 0;
}
