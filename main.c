#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define size 50
void printArray(int arr[]){
    for(int k=0;k<size;k++){
            for(int f=0;f<arr[k];f++)
                    printf("_");
            printf("\n");
    }
    usleep(50000);
    //printf("\e[1;1H\e[2J");
    system("clear");
}

/*SelectionSort begins*/

void selectionSort(int arr[]){

    for(int i=0;i<size;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        if(min!=i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        printf("Selection Sort \n");
        printArray(arr);
    }
}
/*Selection Sort ends*/

/*QuickSort Begins*/

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int arr[], int low, int high) 
{ 
  

    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
  
    while (i < j) { 
  

        while (arr[i] <= pivot && i <= high - 1) { 
            i++; 
        } 

        while (arr[j] > pivot && j >= low + 1) {    
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    printf("Quick Sort \n");
    printArray(arr);
    swap(&arr[low], &arr[j]); 
    printf("Quick Sort \n");
    printArray(arr);
    return j; 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
  
  
        int partitionIndex = partition(arr, low, high); 
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high); 
    } 
} 
/*QuickSort ends*/

/*Bubble Sort Begins*/
void bubbleSort(int arr[]){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
            printf("BubbleSort \n");
            printArray(arr);
        }
    }
}    
/*BubbleSort Ends*/
/*Insertion Sort Begins*/
void insertionSort(int array[]) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      printf("Insertion Sort \n");
      printArray(array);

      --j;
    }
    array[j + 1] = key;
    printf("Insertion Sort \n");
    printArray(array);
  }
}
/*Insertion Sort Ends*/
/*Merge Sort Begins*/
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
    printf("Merge Sort\n");
    printArray(arr); 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 

        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 

    } 
} 
 
/*Merge Sort Ends*/
int main(){
	
    srand(time(0));
    system("clear");
    int selsortArray[size],qksortArray[size],bubblesortArray[size],InsertionsortArray[size],mergesortArray[size];
    for(int i=0;i<size;i++)
        selsortArray[i]=qksortArray[i]=InsertionsortArray[i]=bubblesortArray[i]=mergesortArray[i]=rand()%100;
    selectionSort(selsortArray);
    quickSort(qksortArray,0,size);
    bubbleSort(bubblesortArray);
    insertionSort(InsertionsortArray);
    mergeSort(mergesortArray,0,size);
    return 0;
}
