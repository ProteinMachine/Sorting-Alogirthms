#include <iostream>
#include <array>
#include <algorithm>
#include <utility>

using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //pivot
    int i = (low - 1);  //index of the smaller element

    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1); //runs with all values lesser than partitioning index
        quicksort(arr, pi + 1, high);  //runs with all values greater than partitioning index
    }
}

int main() {
     int arr[] = {30, 91, 2, 7, 100, 80, 20,53, 82, 14, 16, 25, 51, 31, 9, 68, 92, 18, 35, 64, 15, 73, 34, 63, 42, 24, 67, 5, 97, 87, 11, 52, 39, 81, 66, 62, 56, 69, 83, 41, 54, 46, 12, 27, 43, 55, 22, 32, 29, 65, 96, 71, 19, 26, 78, 70, 76, 48, 93, 57, 77, 23, 44, 72, 17, 95, 49, 88, 3, 8, 40, 94, 21, 47, 85, 61, 90, 38, 13, 28, 59, 50, 84, 37, 86, 99, 36, 75, 4, 89, 33, 74, 60, 45, 98, 58, 6, 10, 1, 79};

    int n = 100; //size of array
    int low = 0;
    int high = 100;
    
//    while( cin >> input ){
//        to_be_sorted.push_back(input);
//    }
    
    quicksort(arr, 0, n-1);
    
    for ( int i = 0; i < n ; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0;
}

