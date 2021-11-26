#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 4

struct point {int x; int y;};
typedef struct point point;

struct list_node {
  void             *data;
  struct list_node *next;
};
typedef struct list_node list_node;

typedef struct listHandle {
    struct list_node *tail;
    int size;
} listHandle;

void print_point(point *p);
void print_circular_point_list(const listHandle *);
void insert_head(listHandle *list, list_node *node);
void insert_tail(listHandle *list, list_node *node);
void delete_head(listHandle *list);
void delete_tail(listHandle *list);
int length_of_circular_list(listHandle *list);
list_node *find_previous_node(list_node *cl);
listHandle CreateList ();
list_node CreateNode ();

int main(void) {
    point p1 = {1,2}, p2 = {3,4}, p3 = {5,6}, p4 = {7,8}, p5 = {9,10}, p6 = {11,12};

    listHandle circular_list = CreateList();
    list_node node1 = CreateNode();
    node1.data = &p1;
    insert_head(&circular_list, &node1);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node2 = CreateNode();
    node2.data = &p2;
    insert_head(&circular_list, &node2);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node3 = CreateNode();
    node3.data = &p3;
    insert_head(&circular_list, &node3);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node4 = CreateNode();
    node4.data = &p4;
    insert_head(&circular_list, &node4);

    print_circular_point_list(&circular_list);
    printf("\n");





    list_node node5 = CreateNode();
    node5.data = &p5;
    insert_head(&circular_list, &node5);
    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node6 = CreateNode();
    node6.data = &p6;
    insert_tail(&circular_list, &node6);
    print_circular_point_list(&circular_list);
    printf("\n");

    delete_head(&circular_list);
    print_circular_point_list(&circular_list);
    printf("\n");

    delete_tail(&circular_list);
    print_circular_point_list(&circular_list);
    printf("\n");



    print_circular_point_list(&circular_list);
    printf("\n");

    printf("Length of circular list: %d\n", length_of_circular_list(&circular_list));

    return EXIT_SUCCESS;
}

listHandle CreateList () {
    listHandle temp;
    temp.size = 0;
    temp.tail = NULL;
    return temp;
}

list_node CreateNode () {
    list_node temp;
    temp.data = NULL;
    temp.next = NULL;
    return temp;
}

void print_point(point *p){
    printf("(%1d, %1d)\n", p->x, p->y);
}

void print_circular_point_list(const listHandle *list){
    list_node *cur, *prev;

    if (list->tail != NULL){
        cur = list->tail->next;
        do{
            prev = cur;
            print_point((point*)cur->data);
            cur = cur->next;
        } while(prev != list->tail);
    }
}

/* An exercise */
int length_of_circular_list(listHandle *list){
    return list->size; 
}

void insert_head(listHandle *list, list_node *node) {
    if (list->size > 0){
        node->next = list->tail->next;
        list->tail->next = node;
    } else {
        node->next = node;
        list->tail = node;
    }
    list->size++;
}
void insert_tail(listHandle *list, list_node *node) {
    if (list->size > 0){
        node->next = list->tail->next;
        list->tail->next = node;
        list->tail = node;

    } else {
        node->next = node;
        list->tail = node;
    }
    list->size++;
}
/* Denne funktion kører ikke i konstant tid */
void delete_head(listHandle *list) {
    list->tail->next = list->tail->next->next;
    list->size--;
}
void delete_tail(listHandle *list){
    list_node *current = list->tail->next, *prev;
    while (current != list->tail) {
        prev = current;
        current = current->next;
    }
    /* Current now equals list start */
    prev->next = current->next;
    list->tail = prev;
    list->size--;
}