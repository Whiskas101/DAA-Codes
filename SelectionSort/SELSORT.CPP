#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int* array, int len);
void SelectionSort(int* arr, int len);

void display(int* array, int len){
 int i;
 printf("\n");
 for(i = 0; i < len; i++){
  printf("%d, ", array[i]);
 }
}


//Find the smallest element, put it at position 0
// find the 2nd smallest element, put it at position 1
// .
// .
// Until you have a sorted array!
void SelectionSort(int* arr, int len){
 int i;
 int j;
 int min;
 for(i = 0; i < len-1; i++){
  //We assume the i'th position is the i'th smallest element
  min = i;
  for(j = i+1; j < len; j++){
   //if we find an element smaller than our assumption made previously
   if(arr[j] < arr[min]){
     //we update min to be the new minimum (which is j)
     min = j;
   }
  }
  // We swap the elements if we found a new minimum
  // Otherwise, our assumption was right and we don't need to swap
  if(min != i){
   //Swap
   int temp = arr[min];
   arr[min] = arr[i];
   arr[i] = temp;
  }

 }
}

void main(){
 clrscr();
 int len;
 printf("\n Enter length of Array : ");
 scanf("%d", &len);

 int *arr = (int*)malloc(sizeof(int) * len);
 printf("Enter elements : ");
 for(int k = 0; k< len; k++){
  printf("\n==> ");
  scanf("%d", &arr[k]);

 }

 display(arr, len);
 SelectionSort(arr, len);
 display(arr, len);
 getch();
}
