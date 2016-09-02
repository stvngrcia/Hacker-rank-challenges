#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rotate(int *, int, int, int);

int main() {
  int size;
  int rotation;
  int times;
  int i;
  int number;

  /*Reading the STDIO*/
  scanf("%d %d %d",&size , &rotation, &times);
  int array[size];
  for (i = 0; i < size; i++)
  {
    scanf("%d",&number);
    array[i] = number;
  }

  rotate(array, rotation, times, size);
    return 0;
}
void rotate(int *array, int rotation, int times, int size)
{
  int i;
  int j;
  int tmp;
  int position;

  for (i = 0; i < rotation; i++)
  {
    for(j = size-1 ; j >= -1; j--)
    {
      if (j == size-1)/*checking is happening for the first time*/
      {
        tmp = array[j];
      }
      else if(j == -1)
      {
        array[j+1] = tmp;
      }
      else
      {
        array[j+1] = array[j];
      }
    }
  }
  for (i = 0; i < times; i++)
  {
    scanf("%d",&position);
    printf("%d\n", array[position]);
  }
}
