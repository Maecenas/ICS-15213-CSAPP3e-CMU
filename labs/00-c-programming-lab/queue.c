/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new() {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->q_size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q) {
    /* How about freeing the list elements and the strings? */
    if (q == NULL) {
        return;
    }
    if (q->q_size > 0) {
        list_ele_t *ptr = q->head;
        while (ptr != NULL) {
            list_ele_t *node = ptr;
            ptr = ptr->next;
            free(node->value);
            free(node);
        }
    }
    /* Free queue structure */
    free(q);
    return;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s) {
    /* What should you do if the q is NULL? */
    if (q == NULL) {
        return false;
    }
    list_ele_t *newh = (list_ele_t *)malloc(sizeof(list_ele_t));
    /* What if either call to malloc returns NULL? */
    if (newh == NULL) {
        return false;
    }
    /* Don't forget to allocate space for the string and copy it */
    newh->value = (char *)malloc(strlen(s) + 1);
    if (newh->value == NULL) {
        free(newh);
        return false;
    }
    strcpy(newh->value, s);
    newh->next = NULL;
    if (q->q_size > 0) {
        newh->next = q->head;
    }
    q->head = newh;
    if (q->q_size == 0) {
        q->tail = newh;
    }
    q->q_size += 1;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s) {
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) {
        return false;
    }
    list_ele_t *newt = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (newt == NULL) {
        return false;
    }
    newt->value = (char *)malloc(strlen(s) + 1);
    if (newt->value == NULL) {
        free(newt);
        return false;
    }
    strcpy(newt->value, s);
    newt->next = NULL;
    if (q->q_size > 0) {
        q->tail->next = newt;
    }
    q->tail = newt;
    if (q->q_size == 0) {
        q->head = newt;
    }
    q->q_size += 1;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize) {
    if (q == NULL || q->q_size == 0) {
        return false;
    }
    /* You need to fix up this code. */
    list_ele_t *oldh = q->head;
    q->head = q->head->next;
    q->q_size -= 1;
    if (sp != NULL) {
        strncpy(sp, oldh->value, bufsize - 1);
        *(sp+bufsize-1) = '\0';
    }
    free(oldh->value);
    free(oldh);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q) {
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) {
        return 0;
    }
    return q->q_size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q) {
    /* You need to write the code for this function */
    if (q == NULL || q->q_size <= 1) {
        return;
    }
    list_ele_t *prev, *current, *next;
    prev = q->head;
    current = q->head->next;
    next = q->head->next->next;
    prev->next = NULL;
    current->next = prev;

    while (next != NULL) {
        prev = current;
        current = next;
        next = next->next;
        current->next = prev;
    }
    q->tail = q->head;
    q->head = current;
}

