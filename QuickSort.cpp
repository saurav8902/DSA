#include <iostream>
#include <vector>
using namespace std;


template<typename dataType>
void Display(const vector<dataType>array){
    for(dataType& i:array ){
        cout<< i<< " ";
    }
    cout<<endl;
}

template<typename T>
void swap(T *address1, T *address2) {
    T temp = *address1;
    *address1 = *address2;
    *address2 = temp;
}


template <typename dataType>
void partition(vector<dataType>&array, int leftBound, int rightBound){

    if(rightBound - leftBound <= 1){
        return;
    }

    int pivotIndex = leftBound;
    int upper = leftBound + 1;
    int lower = leftBound + 1;

    for(int i = leftBound + 1; i < rightBound; i++){
        if(array[pivotIndex] < array[i] ){
            upper++;
        }
        else{
            swap(&array[i],&array[lower]);
            lower++;
            upper++;

        }
    }

    lower = lower - 1;
    swap(&array[pivotIndex], &array[lower]);
    partition(array, leftBound, lower);
    partition(array,lower + 1, rightBound);

}



int main(){
    vector<int> array = {65, 20, 6, 7, 3, 6, 7, 92, 0, -80};
    partition(array,0, size(array));
    Display(array);


}
