#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(const vector<int>& array1, const vector<int>& array2) {
    vector<int> finalArray;
    int topPointer1 = 0, topPointer2 = 0;

    while (topPointer1 < array1.size() && topPointer2 < array2.size()) {
        if (array1[topPointer1] < array2[topPointer2]) {
            finalArray.push_back(array1[topPointer1]);
            topPointer1++;
        } else {
            finalArray.push_back(array2[topPointer2]);
            topPointer2++;
        }
    }

    while (topPointer1 < array1.size()) {
        finalArray.push_back(array1[topPointer1]);
        topPointer1++;
    }

    while (topPointer2 < array2.size()) {
        finalArray.push_back(array2[topPointer2]);
        topPointer2++;
    }

    return finalArray;
}

void display(const vector<int>& array) {
    cout << endl;
    for (const int& i: array) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> divide(const vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }

    int midPoint = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + midPoint);
    vector<int> right(array.begin() + midPoint, array.end());

    vector<int> leftSorted = divide(left);
    vector<int> rightSorted = divide(right);

    return merge(leftSorted, rightSorted);
}

int main() {
    vector<int> array = {65, 20, 6, 7, 3, 6, 7, 92, 0, -80};
    vector<int> sortedArray = divide(array);
    display(sortedArray);
}
