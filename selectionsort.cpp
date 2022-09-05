#include <iostream>

using namespace std;

void swapPtrs(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], unsigned int size){
    for(size_t i = 0; i < size - 1; i++){
        int* min = &array[i];
        for(size_t j = i + 1; j < size; j++){

            if(array[j] < *min){
                min = &array[j];
            }

        }

        swapPtrs(&array[i], min);
    }
}

void printArr(int array[], unsigned int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

int main(int argc, char** argv){
    int arr[] = {5, 3, 1, 2, 4};
    int firstElementSize = sizeof(arr[0]);
    int arrSize = sizeof(arr) / firstElementSize;
    selectionSort(arr, arrSize);
    printArr(arr, arrSize);
    return 0;
}