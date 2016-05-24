//
//  SortingAlgorithm.cpp
//  
//
//  Created by JasonYang on 2014-11-06.
//
//

#include <stdio.h>

using namespace std;

// FUNCTION PROTOTYPES
void InsertionSort(int arr[], int size);

void SelectionSort(int arr[], int size);

int LinearSearch(int arr[], int size, int target);
int Rec_LinearSearch(int arr[], int current, int size, int target);

int BinarySearch(int arr[], int size, int target);
int Rec_BinarySearch(int arr[], int size, int low, int high, int target);

void Quicksort(int arr[], int size);
void Quicksort_Helper(int arr[], int startIndex, int endIndex);
int Partitions(int arr[], int startIndex, int endIndex);

void Mergesort(int arr[], int size);
void Mergesort_Helper(int arr[], int low, int high);
void Merging(int arr[], int low, int mid, int high);

void ShellSort(int arr[], int size);

void BubbleSort(int arr[], int size);
void BubbleUp(int i);
void Rec_BubbleUp(int i);
void BubbleDown(int i);


// InsertionSort
void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int pos = i;
        while (pos > 0 && arr[pos-1] > arr[pos])
        {
            temp = arr[pos];
            arr[pos] = arr[pos-1];
            arr[pos - 1] = temp;
            pos--;
        }
    }
}


// SelectionSort
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int smallest = i;
        for (int unsorted = i+1; unsorted < size; unsorted++)
        {
            if (arr[unsorted] < arr[smallest])
            {
                smallest = unsorted;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}


// LinearSearch
int LinearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}
// Recursive case
int Rec_LinearSearch(int arr[], int current, int size, int target)
{
    if(current >= size) // end of array reached
        return -1;
    else if( target == arr[current]) // target found
        return current;
    else // not found, search from different starting index
        return Rec_LinearSearch(arr, current+1, size, target);
}


// BinarySearch
int BinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
    
    while(low <= high)
    {
        mid = (high + low) / 2;
        
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
        
}
// Recursive case
int Rec_BinarySearch(int arr[], int size, int low, int high, int target)
{
    int mid = (high + low) / 2;
    
    if(low > high)
        return -1; // base case: one item, not found
    
    else if(arr[mid] == target)
        return mid; // second base case: item found
    
    else if(arr[mid] < target)
        return Rec_BinarySearch(arr, size, mid+1, high, target); // search upper half
    
    else
        return Rec_BinarySearch(arr, size, low, mid-1, target); // search lower half
}



// QuickSort
void Quicksort(int arr[], int size)
{
    Quicksort_Helper(arr, 0, size-1);
}

// Quicksort_helper
void Quicksort_Helper(int arr[], int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int pivot = Partitions (arr, startIndex, endIndex); // creates pivot
        Quicksort_Helper (arr, startIndex, pivot-1); // Lower half
        Quicksort_Helper (arr, pivot+1, endIndex); // Upper half
    }
}

// Partitions
int Partitions(int arr[], int startIndex, int endIndex)
{
    int low = startIndex;
    int high = endIndex-1;
    int pivotIndex = endIndex; // set the pivot as the last element in the array
    
    while (low < high)
    {
        while (low < high && arr[low] <= arr[pivotIndex])
        {
            low++;
        }
        while (low < high && arr[high] > arr[pivotIndex])
        {
            high--;
        }
        // Swap the elements at the low and high indices
        T temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    // End of outer while loop
    // Move our pivot into the right place: swap pivot
    // with the first item greater than it
    if(arr[pivotIndex] < arr[low])
    {
        T temp = arr[low];
        arr[low] = arr[pivotIndex];
        arr[pivotIndex] = temp;
        pivotIndex = low;
    }
    return pivotIndex;
}




// MergeSort
void Mergesort(int arr[], int size)
{
    Mergesort_Helper(arr, 0, size-1);
}

void Mergesort_Helper(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        Mergesort_Helper(arr, low, mid);
        Mergesort_Helper(arr, mid+1, high);
        Merging(arr, low, mid, high);
    }
}

void Merging(int arr[], int low, int mid, int high)
{
    int *temp = new int[high-low+1];
    int low1 = low, high1 = mid;        // 1st and last indexes of 1st sub-array
    int low2 = mid+1, high2 = high;     // 1st and last indexes of 2nd sub-array
    int indexOfTemp = 0; // next index of temp opened
    
    // Compare values from 2 sub-array
    while (low1 <= high1 && low2 <= high2)
    {
        if (arr[low1] < arr[low2])
        {
            temp[indexOfTemp] = arr[low1];
            low1++;
            indexOfTemp++;
        }
        else // arr[low2] < arr[low1]
        {
            temp[indexOfTemp] = arr[low2];
            low2++;
            indexOfTemp++;
        }
    }
    // if there any left over elements from the 1st sub-array copy over
    while (low1 <= high1)
    {
        temp[indexOfTemp] = arr[low1];
        low1++;
        indexOfTemp++;
    }
    while (low2 <= high2)
    {
        temp[indexOfTemp] = arr[low2];
        low2++
        indexOfTemp++;
    }
    // Copy the merged array(temp) into the original calling array
    int i , j;
    for(i = low; j = 0; i <= high; i++, j++)
    {
        arr[i] = temp[j];
    }
    delete[] temp;
}


// Shell Sort
// Worst case : O(n^2)
// Best case : O(n log n)
// Average case : depends on gap sequence
void ShellSort(int arr[], int size)
{
    int gap;
    int temp;
    
    for (gap = size /2; gap > 0 ; gap/=2)
    {
        for(int bigger = gap; bigger < size; bigger++)
        {
            for(int smaller = bigger-gap; smaller>=0; smaller-=gap)
            {
                if(arr[smaller] < arr[smaller+gap])
                {
                    break;
                }
                // if arr[smaller] > arr[smaller+gap], swap smaller & bigger
                temp = arr[smaller];
                arr[smaller] = arr[smaller+gap];
                arr[smaller+gap] = temp;
            }
        }
    }
}


// BubbleSort        O(n^2)
void BubbleSort(int arr[], int size)
{
    bool swapped = ture;
    
    while(swapped)
    {
        swapped = false;
        
        for(int i = 0; i < size-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    }
}


// BubbleUp
void Rec_BubbleUp(int i)
{
    int parent = (i - 1) / 2;
    if(i > 0 && arr[i] > arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        BubbleUp(parent);
    }
}

// BubbleUp
void BubbleUp(int i)
{
    int parent = (i - 1) / 2;
    while(i > 0 && arr[i] > arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
        parent = (i - 1) / 2;
    }
}

// BubbleDown
void BubbleDown(int i)
{
    int left_child = 2 * i + 1;
    int right child = 2 * i + 2;
    bool swap = true;
    
    while(swap)
    {
        swap = false
        if(left_child < max_size && arr[i] < arr[left_child])
        {
            //swap
            swap = true;
        }
        if(right_child < max_size && arr[i] < arr[right_child])
        {
            //swap
            swap = true;
        }
        i--;
    }

}
