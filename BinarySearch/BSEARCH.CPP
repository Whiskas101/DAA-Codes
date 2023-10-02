#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int * arr, int len);
int binarySearch(int* array, int start, int end, int target);

void display(int* arr, int len){
 printf("\n");
 int i;
 for(i = 0; i < len; i++){
  printf("%d, ", arr[i]);
 }
}

int binarySearch(int* array, int start, int end, int target){
 if(end-start < 1){
  return -1;
 }
 int mid = (start+end)/2;

 if(target == array[mid]){
  return mid;
 }

 if(target > array[mid]){
  start = mid+1;
 }else{
  end = mid-1;
 }
 return binarySearch(array, start, end, target);

}

void main(){
 clrscr();
 int len;
 printf("\nEnter length of array : ");
 scanf("%d", &len);
 int* arr = (int*)malloc(sizeof(int)*len);

 //input
 printf("\nEnter Data in ascending order");
 for(int k =0; k < len; k++){
  printf("\n--> ");
  scanf("%d", &arr[k]);
 }
 //target
 printf("\nEnter target value : ");
 int target;
 scanf("%d", &target);

 display(arr, len);
 int found = binarySearch(arr, 0, len-1, target);
 if(found > -1){
  printf("\nFound at index %d", found);
 }else{
  printf("\nDid not find target in array");
 }

 getch();
}