#ifndef __LIST_H_
#define __LIST_H_

typedef struct List{ /* Creating the structure for the node*/
  int number;
  struct List *prev;
  struct List *next;
}List;
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int create_node(List **root, int number);
void print_node(List **root);
List *rotate(List **root);

/**
 * main -
 * @void: Takes no arguments
 * Description: This Program will scan for numbers then store this numbers in a
 * Double linked list and then rotate the numbers (n) amount of times to the left.
 * Theb it will print the rotated sequences.
 */
int main(void)
{
  List *root;
  int number;
  int size;
  int rotation;
  int i;
  root = NULL; /*Initializing root*/
  size = -1;
  rotation = -1;
  number = -1;
  /*
  * size - How many nodes in the linked list
  * rotation - How many rotations will be made
  */
  printf("Please enter an integer representing how many nodes you want in the double liked list.Then press enter: ");
  fflush(stdout);
  scanf("%d", &size); /*scaning for variables*/
  if (size == -1) /*if incorrect input scanf will do nothing. checking for wrong input*/
  {
    fprintf(stderr, "Need an integer\n");
    return (1);
  }
  printf("Please enter an integer representing how many times you want to rotate the numbers.Then press enter: ");
  fflush(stdout);
  scanf("%d", &rotation);
  if (rotation == -1) /*if incorrect input scanf will do nothing. checking for wrong input*/
  {
    fprintf(stderr, "Need an integer\n");
    return (1);
  }
  printf("Please enter the numbers you want to use in the nodes separated by a space.Then press enter: ");
  fflush(stdout);
  for(i = 0; i < size; i++) /*Taking as many numbers as size dictates*/
  {
    scanf("%d", &number);
    if (number == -1) /*if incorrect input scanf will do nothing. checking for wrong input*/
    {
      fprintf(stderr, "Need an integer\n");
      return (1);
    }
    if(create_node(&root, number) != 0) /*checking for success of the create_node function*/
    {
      return (1);
    }
  }
  printf("----------\n");
  printf("Original\n");
  print_node(&root); /*calling the function to print the nodes*/
  printf("----------\n");

  for (i = 0; i < rotation; i++) /*printing the rotated sequences*/
  {
    printf("Rotation [%d]\n", i+1);
    rotate(&root); /*calling the function to rotate the nodes*/
    print_node(&root); /*calling the function to print the nodes*/
    printf("----------\n");
  }
  return (0);
}

/**
 * create_node -
 * @root: A double pointer containing the address of the nodes
 * @number: stores the number that will go into the linked list
 * Description: This function will create a node, with the given
 * information passed as an argument. The first time this funciton
 * gets called root will be null. This funciton will also double link the nodes
 */
int create_node(List **root, int number)
{
  List *node;
  List *prev_node;

  prev_node = *root;
  node = malloc(sizeof(List)); /*Allocating enough memory to hold the struct*/
  if (node == NULL) /*Checking for errors*/
  {
    return (1);
  }
  /*Initializing the node*/
  node->number = number;
  node->prev = NULL;
  node->next = NULL;
  /*when root is NULL it means that is the first node*/
  if (*root == NULL)
  {
    *root = node;
  }
  else
  {
    node->next = *root;
    (*root)->prev = node;
    if (prev_node->next == NULL)
    {
      prev_node->next = node;
    }
    else
    {
      while(prev_node->next != *root) /*Iterates untill prev node*/
      {
        prev_node = prev_node->next; /*moving the reference to node*/
      }
      prev_node->next = node;
    }
    node->prev = prev_node; /*connects the current node to the prev node*/
  }
  return (0);
}

/**
 * print_node -
 * @root: A double pointer containing the address of the nodes
 * Description: This function prints a double linked list
*/
void print_node(List **root)
{
  List *current_node;
  current_node = *root;

  while(current_node->next != *root) /*Iterates thorugh all the nodes*/
  {
    printf("%d\n", current_node->number);
    current_node = current_node->next; /*moving the reference to node*/
  }
  printf("%d\n", current_node->number); /* prints the last node*/
}

/**
 * rotate -
 * @root: A double pointer containing the address of the nodes
 * Description: This funciton rotates the circular linked list by moving the
 * reference of the root.
*/
List *rotate(List **root)
{
  List *prev_node;

  prev_node = (*root)->prev;
  *root = prev_node;

  return (*root);
}
