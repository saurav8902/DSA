#include <iostream>
#include <vector>
using namespace std;

unsigned int smallestIndex(vector<int> array,int begIndex = 0){

    if(size(array) - begIndex > 0) {

        int minIndex = begIndex;
        for (int i = begIndex; i < size(array); i++) {
            if (array[minIndex] > array[i]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
    else{
        return 0;
    }
}
void swap(int* memoryLoc1, int* memoryLoc2){

    int* tempMemory = new int;
    *tempMemory = *memoryLoc1;
    *memoryLoc1 = *memoryLoc2;
    *memoryLoc2 = *tempMemory;
    delete tempMemory;
}
void Display(vector<int>array){
    for(int &i: array){
        cout<< i << " ";
    }
}


int main(){

    vector<int> array = {10,2,3,4,5};
    int invariant = 0;


    for(int i = 0; i < size(array); i ++){

       int minIndex =  smallestIndex(array,0 + i);
        swap(&array[invariant],&array[minIndex]);
        invariant++;

    }
    Display(array);
}
