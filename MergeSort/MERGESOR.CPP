#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mergeSort(int* arr, int start, int end);
void merge(int* arr,int start, int mid, int end);
void displayArr(int* arr, int start, int end);

void displayArr(int* arr, int start, int end){
 printf("\n");
 for(int l = 0; l < end-start+1; l++){
  printf("%d, ", arr[l]);
 }
}

//Finds a midpoints, sends the left and right subarrays to the merge function
void mergeSort(int* arr, int start, int end){
 //Finding length: If length is 1 or <1 no point in merging it

 //end-start+1 just represents the length of the array that was input
 if((end-start+1) < 2){
  return;
 }
 //otherwise, find midpoint, and call mergeSort recursively
 int mid = (end+start)/2;
 mergeSort(arr, start, mid);
 mergeSort(arr, mid+1, end);
 merge(arr, start, mid, end);

}

// Takes an array input, and combines to give a sorted order
void merge(int* arr, int start, int mid, int end){
 //Calculating length of two arrays
 int leftLen = mid-start+1;
 int rightLen = end-mid;

 //Creating two arrays into which we will copy the data
 int* left = (int*)malloc(sizeof(int)* leftLen);
 int* right = (int*)malloc(sizeof(int)* rightLen);

 //Copying data into these arrays
 int i, j, k;
 k = start;

 for(i = 0; i < leftLen; i++){
  left[i] = arr[k];
  k++;
 }

 for(j = 0; j < rightLen; j++){
  right[j] = arr[k];
  k++;
 }
 //After copying the values we start comparing and overiding the input array
 //We set k to the start of the subarray, as the start can be in the middle
 // for right subarrays!!
 k = start;
 i = 0;
 j = 0;

 while(i < leftLen && j < rightLen){
  if(left[i] < right[j]){
    arr[k] = left[i];
    i++;
  }else{
   arr[k] = right[j];
   j++;
  }
  k++;
 }

 while(i < leftLen){
  arr[k] = left[i];
  i++;
  k++;
 };
 while(j < rightLen){
  arr[k] = right[j];
  j++;
  k++;
 };
 free(left);
 free(right);
}

void main(){
 clrscr();

 int arrLen;
 printf("\nEnter array length : ");
 scanf("%d", &arrLen);
 int* arr = (int*)malloc(sizeof(int) * arrLen);

 printf("\n Enter Length");
 for(int m = 0; m < arrLen; m++){
  printf("\n--> ");
  scanf("%d", &arr[m]);
 }

 displayArr(arr, 0, arrLen-1);
 mergeSort(arr, 0, arrLen-1);
 printf("\n\n The sorted array is : ");
 displayArr(arr, 0, arrLen-1);

 getch();

}