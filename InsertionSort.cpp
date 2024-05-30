#include <iostream>
#include <vector>

using namespace std;

unsigned int findInsertionIndex(vector<int> array,int value,unsigned int lBound = 0, unsigned int rBound = 0){

    //finds the correct position for a value to insert
    //lbound and rBound ensure that we can do this is in certain range

    if(rBound == 0){
        rBound = size(array);
    }
    unsigned int i = lBound;
    while( i < rBound and array[i] < value ){
        i++;
    }
    return i;


}

void shift(vector<int> &array, int lBound, int rBound){
    //shifts elements to the right
    if(rBound < size(array) and lBound >= 0) {
        for (int i = rBound; i > lBound; i--){
            array[i] = array[i - 1];
        }
    }
    else{
        throw invalid_argument("one of Bounds is incorrect" );
    }
}

void display(const vector<int>& array){
    cout<<endl;
    for(const int &i : array){
        cout<< i << " ";
    }
}

void insertionSort(vector<int>&array){

    for(int i = 1; i < size(array); i ++){
        //1. Choosing the item
        int value = array[i];
        //2.finding the correct Index
        unsigned correct = findInsertionIndex(array,value,0, i);
        //3.Shifting
        shift(array,correct,i);
        //Inserting
        array[correct] = value;
    }
}

int main (){

    vector<int> array = {1,2,5,9,7,0,-1,88,2};
    insertionSort(array);
    display(array);


}
