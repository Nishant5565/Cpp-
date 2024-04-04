#include <iostream> 
using namespace std;

int insertionSort(int arr[], int n) {
    int comparisons = 0;
     for (int i = 1; i < n; i++) {
          int temp = arr[i];
          int j = i - 1;
          while (j >= 0 && comparisons++ && arr[j] > temp) {
               arr[j + 1] = arr[j];
               j--;
          }
          arr[j + 1] = temp;
     }
    return comparisons;
}
int main(){
    cout << "Enter the size of the array: ";
    int n;
    cin>> n ;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = insertionSort(arr, n);
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Total number of comparisons made: " << comparisons << endl;
    return 0;
}