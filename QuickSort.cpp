#include <iostream>
#include <vector>
using namespace std;

void Display(vector<int>&array, int lBound, int rBound){
    for(int i = lBound; i < rBound; i++){
        cout<< array[i] << " ";
    }
}


unsigned int pivotIndexSelector(const vector<int>& array) {
   return rand() % array.size();

}

void swap(int* memoryLoc1, int* memoryLoc2){

    int* tempMemory = new int;
    *tempMemory = *memoryLoc1;
    *memoryLoc1 = *memoryLoc2;
    *memoryLoc2 = *tempMemory;
    delete tempMemory;
}

void partition (vector<int> &array,int leftBound,int RightBound){
    if(RightBound  -  leftBound <= 1){
        return;
    }
    int pivotIndex = leftBound;
    int lower = leftBound + 1;
    int upper = leftBound + 1;
    for(int i  = leftBound + 1; i < RightBound; i++){

        if(array[i] > array[pivotIndex]){
            upper++;

        }
        else{
            swap(&array[lower],&array[i]);
            lower++;
            upper++;
        }
    }
    swap(&array[pivotIndex],&array[lower - 1]);
    lower = lower - 1;
    partition(array,leftBound,lower);
    partition(array,lower + 1, RightBound);


}



int main(){
    vector<int> array = {65, 20, 6, 7, 3, 6, 7, 92, 0, -80};
    partition(array,0, size(array));
    Display(array,0, size(array));


}
