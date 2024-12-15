#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
int linearSearch(int arr[], int n, int x);
void printArray(int arr[], int size);

int main() {
int arr[] = {64, 34, 25, 12, 22, 11, 90};
int n = sizeof(arr)/sizeof(arr[0]);
int choice;

cout << "Choose sorting algorithm:\n";
cout << "1. Bubble Sort\n";
cout << "2. Quick Sort\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
bubbleSort(arr, n);
cout << "Array sorted using Bubble Sort:\n";
break;
case 2:
quickSort(arr, 0, n - 1);
cout << "Array sorted using Quick Sort:\n";
break;
default:
cout << "Invalid choice!\n";
return 1;
}

printArray(arr, n);

int x;
cout << "Enter element to search: ";
cin >> x;
int result = linearSearch(arr, n, x);
if (result == -1) {
cout << "Element not present in array\n";
} else {
cout << "Element is present at index " << result << endl;
}

return 0;
}

void bubbleSort(int arr[], int n) {
for (int i = 0; i < n-1; i++) {
for (int j = 0; j < n-i-1; j++) {
if (arr[j] > arr[j+1]) {
                                            //swap
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}

void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}

int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
if (arr[j] < pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}

void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
}

int linearSearch(int arr[], int n, int x) {
for (int i = 0; i < n; i++) {
if (arr[i] == x) {
return i;
}
}
return -1;
}

void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
