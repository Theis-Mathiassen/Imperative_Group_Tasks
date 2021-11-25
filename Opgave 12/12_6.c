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
    struct list_node *start;
    int size;
} listHandle;

void print_point(point *p);
void print_circular_point_list(const listHandle *);
list_node *insert_head(listHandle *list, list_node *node);
list_node *insert_tail(listHandle *list, list_node *node);
list_node *delete_head(listHandle *list);
list_node *delete_tail(listHandle *list);
int length_of_circular_list(listHandle *list);
list_node *find_previous_node(list_node *cl);
void insertListNode (list_node *node, listHandle *list, int index);
listHandle CreateList ();
list_node CreateNode ();

int main(void) {
    point p1 = {1,2}, p2 = {3,4}, p3 = {5,6}, p4 = {7,8};

    listHandle circular_list = CreateList();
    list_node node1 = CreateNode();
    node1.data = &p1;
    insertListNode(&node1, &circular_list, 0);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node2 = CreateNode();
    node2.data = &p2;
    insertListNode(&node2, &circular_list, 0);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node3 = CreateNode();
    node3.data = &p3;
    insertListNode(&node3, &circular_list, 0);

    print_circular_point_list(&circular_list);
    printf("\n");

    list_node node4 = CreateNode();
    node4.data = &p4;
    insertListNode(&node4, &circular_list, 0);



    print_circular_point_list(&circular_list);
    printf("\n");

    printf("Length of circular list: %d\n", length_of_circular_list(&circular_list));

    return EXIT_SUCCESS;
}

listHandle CreateList () {
    listHandle temp;
    temp.size = 0;
    temp.start = NULL;
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

void insertListNode (list_node *node, listHandle *list, int index) {
    index = 0;
    if (list->size == 1){
        list->start->next = node;
        node->next = list->start;
    } else if (list->size > 1){
        node->next = list->start->next;
        list->start->next = node;
    } else {
        node->next = node;
        list->start = node;
    }
    list->size++;
}

void print_circular_point_list(const listHandle *list){
    list_node *cur;

    if (list->start != NULL){
        cur = list->start;
        do{
            print_point((point*)cur->data);
            cur = cur->next;
        } while(cur != list->start);
    }
}

/* An exercise */
int length_of_circular_list(listHandle *list){
    return list->size; 
}

list_node *insert_head(listHandle *list, list_node *node) {
    
}
list_node *insert_tail(listHandle *list, list_node *node) {

}
list_node *delete_head(listHandle *list) {

}
list_node *delete_tail(listHandle *list){

}