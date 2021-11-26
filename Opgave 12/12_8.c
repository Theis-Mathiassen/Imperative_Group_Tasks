#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_node{
  int key;
  struct tree_node *leftp, *rightp;
};

typedef struct tree_node tree_node;

tree_node *make_tree(int key, tree_node *left, tree_node *right);
void assert_allocation_success(void *alloc_pointer);
void print_tree(tree_node *tree_ptr);
void print_tree_helper(tree_node *tree_ptr, int level);
tree_node *insert_in_binary_search_tree(tree_node *tree_ptr, int e);
int is_binary_search_tree(tree_node *tree_ptr);
int IsLeaf (tree_node *node);

int main(void) {
  tree_node *tree4 = NULL;
  tree4 = insert_in_binary_search_tree(tree4, 6);
  tree4 = insert_in_binary_search_tree(tree4, 2);
  tree4 = insert_in_binary_search_tree(tree4, 1);
  tree4 = insert_in_binary_search_tree(tree4, 4);
  tree4 = insert_in_binary_search_tree(tree4, 3);
  tree4 = insert_in_binary_search_tree(tree4, 5);
  tree4 = insert_in_binary_search_tree(tree4, 7);
  tree4 = insert_in_binary_search_tree(tree4, 9);
  tree4 = insert_in_binary_search_tree(tree4, 8);
  tree4->leftp->leftp->leftp = make_tree(10, NULL, NULL);

  /* Per construction, tree4 should be a binary search tree */
  /* You can use make_tree to construct other trees which are not binary search trees */

  printf("Is binary tree %d\n", is_binary_search_tree(tree4));

  printf("tree4:\n");
  print_tree(tree4);

  exit(EXIT_FAILURE);
}


tree_node *make_tree(int key, tree_node *left, tree_node *right){
  tree_node *the_tree = malloc(sizeof(tree_node));
  assert_allocation_success(the_tree);
  the_tree->key = key; 
  the_tree->leftp = left; 
  the_tree->rightp = right; 
  return the_tree;
} 

void assert_allocation_success(void *alloc_pointer){
  if (alloc_pointer == NULL){
    printf("Allocation problems. Your program stops.");
    exit(EXIT_FAILURE);
  }
}

/* Insert the element e i the binary search tree, designated by tree_ptr. 
   Drop the insertion if e is already in the tree. 
   Return the tree  in terms of a pointer to its root node. */
tree_node *insert_in_binary_search_tree(tree_node *tree_ptr, int e){
  if (tree_ptr == NULL){
    /* Make a small tree rooted with e and empty subtrees */
    /* This branch is never reached via recursion */
    tree_node *the_tree = make_tree(e, NULL, NULL);
    return the_tree;
  }
  else if (e == tree_ptr->key){
    /* Do nothing */
    return tree_ptr;
  }
  else if (e < tree_ptr->key && tree_ptr->leftp == NULL){
    tree_node *the_tree = make_tree(e, NULL, NULL);
    tree_ptr->leftp = the_tree;
    return tree_ptr;         
  }
  else if (e < tree_ptr->key){
    insert_in_binary_search_tree(tree_ptr->leftp, e);
    return tree_ptr;
  }
  else if (e > tree_ptr->key && tree_ptr->rightp == NULL){
    tree_node *the_tree = make_tree(e, NULL, NULL);
    tree_ptr->rightp = the_tree;
    return tree_ptr;         
  }
  else { /* e > tree_ptr->key) */
    insert_in_binary_search_tree(tree_ptr->rightp, e);
    return tree_ptr;
  }
}
/* void delete_tree(tree_node *tree_ptr)
   Rather difficult to program because it requires access to parents */


void print_tree(tree_node *tree_ptr){
  print_tree_helper(tree_ptr, 0);
}    

/* print the tree designated by tree_ptr as horizotally, as an indented text, on standard output.
   Empty subtrees are printed as "." if tree_ptr is passsed as NULL */
void print_tree_helper(tree_node *tree_ptr, int level){
  int i; 

  /* print indented root */
  for(i = 0; i < level; ++i) 
    printf("   ");
  if (tree_ptr == NULL)
    printf(".\n");  /* Missing part */
  else
    printf("%d\n", tree_ptr->key);

  if(tree_ptr != NULL){
    /* print branches */
    if (tree_ptr->leftp == NULL && tree_ptr->rightp == NULL){
      /* print nothing */
    }
    else if (tree_ptr->leftp != NULL && tree_ptr->rightp == NULL){
      print_tree_helper(tree_ptr->leftp, level+1);
      print_tree_helper(NULL, level+1);
    }   
    else if (tree_ptr->leftp == NULL && tree_ptr->rightp != NULL){
      print_tree_helper(NULL, level+1);
      print_tree_helper(tree_ptr->rightp, level+1);
    }
    else {  
      print_tree_helper(tree_ptr->leftp, level+1);
      print_tree_helper(tree_ptr->rightp, level+1);
    }
  }
}


int int_max(int a, int b){
  return a > b ? a : b;
}

/* Opgaven */
int is_binary_search_tree(tree_node *tree_ptr){
    tree_node *tempNode;
    int result = 0;

    if (tree_ptr->leftp == NULL && tree_ptr->rightp == NULL) {
      result = 1;
    } else if (tree_ptr->leftp != NULL && tree_ptr->rightp != NULL) {
      result = is_binary_search_tree(tree_ptr->leftp) && is_binary_search_tree(tree_ptr->rightp);
    } else {
      tempNode = tree_ptr->leftp != NULL ? tree_ptr->leftp : tree_ptr->rightp;
      if (IsLeaf(tempNode)) {
        if (tempNode->key < tree_ptr->key) {
          result = 1;
        }else {
          result = 0;
        }
      } else {
        result = is_binary_search_tree(tempNode);
      }
    }
    /* if (tree_ptr->leftp != NULL) {
      if (IsLeaf(tree_ptr->leftp)) {
        if (tree_ptr->leftp->key < tree_ptr->key) {
          leftResult = 1;
        }else {
          leftResult = 0;
        }
      }
    } else {
      if (IsLeaf(tree_ptr->rightp)) {
        if (tree_ptr->rightp->key < tree_ptr->key) {
            rightResult = 1;
        } else {
          rightResult = 0;
        }
      }
    } */

/* 
    if (tree_ptr->leftp == NULL) {
        leftResult = 1;
    } else if (IsLeaf(tree_ptr->leftp)) {
        if (tree_ptr->leftp->key < tree_ptr->key) {
          leftResult = 1;
        }else {
          leftResult = 0;
        }
    } else {
        leftResult = is_binary_search_tree(tree_ptr->leftp);
    }

    if (tree_ptr->rightp == NULL) {
        rightResult = 1;
    } else if (IsLeaf(tree_ptr->rightp)) {
        if (tree_ptr->rightp->key < tree_ptr->key) {
            rightResult = 1;
        } else {
          rightResult = 0;
        }
    } else {
        rightResult = is_binary_search_tree(tree_ptr->rightp);
    }
    result = leftResult && rightResult; */

    return result;
}

int IsLeaf (tree_node *node) {
    return (node->leftp == NULL && node->rightp == NULL) ? 1 : 0;
}