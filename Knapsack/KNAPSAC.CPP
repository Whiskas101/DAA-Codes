#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void KnapSack(float* values, float* weights, int len, float capacity);
void display(float* arr, int len);

void display(float* arr, int len){
 int i;
 printf("\n");
 for(i  = 0; i < len; i++){
  printf("%f, ", arr[i]);
 }
}

void KnapSack(float* values, float* weights, int len, float capacity){
  //Firstly generate a profit ratio array
  float* profits = (float*)malloc(sizeof(float)*len);
  int i;
  for(i = 0; i < len; i++){
    profits[i] = (float)values[i]/weights[i];
  }
  //Rearranging the array in descending order
  //Via selection sort algorithm
  i = 0;
  int min;
  for(i = 0; i < len-1; i++){
   min = i;
   for(int j = i+1; j < len; j++){
     if(profits[j] < profits[min]){
      min = j;
     }
   }
   //If found a new minimum, we swap the values
   if(min != i){
    //Swapping profit values
    float temp = profits[i];
    profits[i] = profits[min];
    profits[min] = temp;
   //Swapping values array elements too
    temp = values[i];
    values[i] = values[min];
    values[min] = temp;
   //Swapping weights array
    temp = weights[i];
    weights[i] = weights[min];
    weights[min] = temp;
   }//Sel sort inner loop end

  }//Selection sort outer loop end
  printf("\nProfits array in ascending order :");
  display(profits, len);
  printf("\nValues array:");
  display(values, 5);
  printf("\nWeights array:");
  display(weights, 5);
  //traversing in reverse because we need to read the array in desc order
  float totalProfit;
  float curCapacity = 0.0;
  for(i = len-1; i >= 0; i--){
   //we add most profitable element's weight and check capacity
   curCapacity = curCapacity + weights[i];
   if(curCapacity < capacity){
    printf("\nCurrent weight %f < %f (capacity) so we add the item", curCapacity, capacity);
    totalProfit = totalProfit + values[i];
   }else{
    // if it exceeds the total capcity, we first find the value by which
    // it exceeds it
    printf("\nCurrent weight %f > %f so we subtract it back", curCapacity, capacity);
    curCapacity = curCapacity - weights[i];

    float delta = capacity - curCapacity;
    float fraction = (float)delta/weights[i];
    printf("\nFraction is %f", fraction);
    curCapacity = curCapacity + delta;
    totalProfit = totalProfit + (float)fraction*values[i];
    break;
   }

  }
  printf("\nTotal Profit : %f \n Capacity : %f", totalProfit, curCapacity);
  free(profits);
}


void main(){
  clrscr();
  int capacity = 15;
  float values[] =  {10.0f,20.0f,30.0f,22.0f,40.0f};
  float weights[] = {6.0,4.0,3.0,3.0,3.0};
  printf("\nValues array:");
  display(values, 5);
  printf("\nWeights array:");
  display(weights, 5);
  KnapSack(values, weights, 5, capacity);

  getch();

}