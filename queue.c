#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t* q_new()
{
    queue_t* q = malloc(sizeof(queue_t));
    if (q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t* q)
{
    /* TODO: How about freeing the list elements and the strings? */
    if(q == NULL) return;

    list_ele_t* traversal = q->head;
    while (traversal != NULL){
        list_ele_t* cur = traversal;
        traversal = cur->next;
        free(cur->value);
        free(cur);
    }

    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t* q, char* s)
{
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if(q == NULL) return false;

    // new element
    list_ele_t* newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) return false;
    newh->value = malloc(sizeof(char*));
    if (newh->value == NULL) return false;
    strcpy(newh->value, s);
    newh->next = NULL;

    if (q->tail == NULL)    q->tail = newh;
    if (q->head == NULL)
    {
        q->head = newh;
    }else{
        newh->next = q->head;
        q->head = newh;
    }
    q->size++;

    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t* q, char* s)
{
    if(q == NULL) return false;

    // new element
    list_ele_t* newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) return false;
    newh->value = malloc(sizeof(char*));
    if (newh->value == NULL) return false;
    strcpy(newh->value, s);
    newh->next = NULL;

    if(q->head == NULL) q->head = newh;
    if(q->tail == NULL) q->tail = newh;
    else q->tail->next = newh;
    q->tail = newh;

    q->size++;

    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t* q, char* sp, size_t bufsize)
{
    if (q == NULL)  return false;
    if (q->size == 0) return false;

    if (sp != NULL)
    {
        strcpy(sp, q->head->value);
    }

    list_ele_t* removeh = q->head;
    q->head = q->head->next;
    q->size--;

    free(removeh->value);
    free(removeh);

    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t* q)
{
    if(q == NULL) return 0;

    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t* q)
{
    if(q == NULL) return;
    if(q->size < 2) return;

    list_ele_t *old_head = q -> head;
    list_ele_t *old_tail = q -> tail;
    list_ele_t *a = q -> head;
    list_ele_t *b = q -> head -> next;
    list_ele_t *c = q -> head -> next -> next;

    b -> next = a;
    a -> next = NULL;
    while(c != NULL) {
        a = b;
        b = c;
        c = c -> next;
        b -> next = a;
    }
    q -> head = old_tail;
    q -> tail = old_head;
}

void swap(list_ele_t* a, list_ele_t* b)
{
    char* temp;
    temp = a->value;
    a->value = b->value;
    b->value = temp;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t* q)
{
    if (q == NULL)  return;

    /* Bubble sort the given linked list */
    int swapped;
    list_ele_t* ptr1;
    list_ele_t* lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = q->head;
        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
