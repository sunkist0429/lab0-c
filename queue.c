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
    if(q->head->value) free(q->head->value);
//    if(q->head) free(q->head);
//    if(q->tail) free(q->tail);
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

    list_ele_t* newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) return false;

    newh->next = q->head;
    newh->value = malloc(sizeof(char*));
    if (newh->value == NULL) return false;
    strcpy(newh->value, s);

    q->head = newh;
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
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t* q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
