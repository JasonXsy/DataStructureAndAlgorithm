#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

const int SELECTION = 0;
const int QUICK = 1;
const int MERGE = 2;
const int SHELL = 3;

// FUNCTION PROTOTYPES
template <class T>
T* ReadFile(string infile, int& n);

template <class T>
bool Sorted(T arr[], int n);

template <class T>
bool Contains(T arr1[], T arr2[], int n);

template <class T>
bool Search(T arr[], int n, T target);

template <class T>
void SortTestResult(T arr[], int n, int sort);

void SelSTest();
void QSTest();
void MSTest();
void ShSTest();

// declare your sort function prototypes here

// SelectionSort
template <class T>
int SelectionSort(T arr[], int size);

// Quicksort
template <class T>
int Quicksort(T arr[], int size);
// Helper Function
template <class T>
void Quicksort_Helper(T arr[],int startIndex,int endIndex, int& comparison);
// Partitioning Function
template <class T>
int Partitions(T arr[],int startIndex,int endIndex, int& comparison);

// Mergesort
template <class T>
int Mergesort(T arr[], int size);
// Helper Function
template <class T>
void Mergesort_Helper(T arr[], int low, int high,int & comparison);
// Merging Function
template <class T>
void Merging(T arr[], int low, int mid, int high, int & comparison);

// Shell Sort
template <class T>
int ShellSort(T arr[], int size);


// Main function
//int main()
//{
//    // insert your own testing code here
//    int arr[] = {24, 5, 3, 35, 14, 23, 19, 43, 2};
//    int arr_size = 9;
//    
//    cout << ShellSort(arr, arr_size) << endl;
//    
//    // Output sorted array
//    for (int i = 0; i < arr_size; i++){
//        cout << arr[i] << "  ";
//    }
//    cout << endl;
//
//    
//    return 0;
//}

// Main function
// Uncomment this and comment the above main function before submitting
int main()
{
    SelSTest();
    QSTest();
    MSTest();
    ShSTest();
    
    return 0;
}


// FUNCTION IMPLEMENTATIONS

// Tests the SelectionSort function
void SelSTest()
{
    try
    {
        cout << "SELECTION SORT" << endl << "--------------" << endl;
        int n = 0;
        int* arr1 = ReadFile<int>("test1.txt", n);
        SortTestResult(arr1, n, SELECTION);
        float* arr2 = ReadFile<float>("test2.txt", n);
        SortTestResult(arr2, n, SELECTION);
        string* arr3 = ReadFile<string>("test3.txt", n);
        SortTestResult(arr3, n, SELECTION);
        int* arr4 = ReadFile<int>("test4.txt", n);
        SortTestResult(arr4, n, SELECTION);
        cout << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}

// Tests the Quicksort function
void QSTest()
{
    try
    {
        cout << "QUICKSORT" << endl << "---------" << endl;
        int n = 0;
        int* arr1 = ReadFile<int>("test1.txt", n);
        SortTestResult(arr1, n, QUICK);
        float* arr2 = ReadFile<float>("test2.txt", n);
        SortTestResult(arr2, n, QUICK);
        string* arr3 = ReadFile<string>("test3.txt", n);
        SortTestResult(arr3, n, QUICK);
        int* arr4 = ReadFile<int>("test4.txt", n);
        SortTestResult(arr4, n, QUICK);
        cout << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}

// Tests the Mrgesort function
void MSTest()
{
    try
    {
        cout << "MERGESORT" << endl << "---------" << endl;
        int n = 0;
        int* arr1 = ReadFile<int>("test1.txt", n);
        SortTestResult(arr1, n, MERGE);
        float* arr2 = ReadFile<float>("test2.txt", n);
        SortTestResult(arr2, n, MERGE);
        string* arr3 = ReadFile<string>("test3.txt", n);
        SortTestResult(arr3, n, MERGE);
        int* arr4 = ReadFile<int>("test4.txt", n);
        SortTestResult(arr4, n, MERGE);
        cout << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}

// Tests the shellsort function
void ShSTest()
{
    try
    {
        cout << "SHELL SORT" << endl << "---------" << endl;
        int n = 0;
        int* arr1 = ReadFile<int>("test1.txt", n);
        SortTestResult(arr1, n, SHELL);
        float* arr2 = ReadFile<float>("test2.txt", n);
        SortTestResult(arr2, n, SHELL);
        string* arr3 = ReadFile<string>("test3.txt", n);
        SortTestResult(arr3, n, SHELL);
        int* arr4 = ReadFile<int>("test4.txt", n);
        SortTestResult(arr4, n, SHELL);
        cout << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}

// Tests that array is correctly sorted
template <class T>
void SortTestResult(T arr[], int n, int sort)
{
    T* arrcopy = new T[n];
    for (int i = 0; i < n; i++)
    {
        arrcopy[i] = arr[i];
    }
    
    cout << "n = " << n;
    if (sort == SELECTION)
    {
        cout << ", comparisons = " << SelectionSort(arr, n);
    }
    else if (sort == QUICK)
    {
        cout << ", comparisons = " << Quicksort(arr, n);
    }
    else if (sort == MERGE)
    {
        cout << ", comparisons = " << Mergesort(arr, n);
    }
    else if (sort == SHELL)
    {
        cout << ", comparisons = " << ShellSort(arr, n);
    }
    cout <<", values = " << Contains(arr, arrcopy, n);
    cout <<", sorted = " << Sorted(arr, n) << endl;
    delete[] arr;
    delete[] arrcopy;
}

// Opens a file and reads the contents into an array
// PARAM: infile = name of the file to be opened
//        n = the size of the result array
// PRE: the file contains values separated by white space
// POST: returns an array containing the contents of infile
template <class T>
T* ReadFile(string infile, int& n)
{
    T* result;
    T next;
    n = 0;
    
    ifstream ist(infile.c_str()); // open file
    // Check if file opened correctly
    if(ist.fail())
        throw runtime_error(infile + " not found");
    
    // Find file size
    while(ist >> next)
    {
        n++;
    }
    
    // Read file into array
    ist.close();
    ist.open(infile.c_str());
    result = new T[n];
    for (int i = 0; i < n; i++)
    {
        ist >> result[i];
    }
    
    ist.close();
    
    return result;
}

// Checks to see if the input array is in ascending order
// PARAM: arr = name of the array
//        n = size of arr
// PRE:
// POST: returns true iff arr is in ascending order
template <class T>
bool Sorted(T arr[], int n)
{
    // Check to see each element i <= element i+1
    for(int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

// Checks to see if the two arrays contain the same values
// PARAM: arr1, arr2 = name of the arrays
//        n = size of both arrays
// PRE: arr1 and arr2 are the same size, arr1 is sorted
// POST: returns true iff arr1 contains all values in arr2
template <class T>
bool Contains(T arr1[], T arr2[], int n)
{
    // Check to see each element of arr2 is in arr1
    for (int i = 0; i < n; i++)
    {
        if (!Search(arr1, n, arr2[i]))
        {
            return false;
        }
    }
    return true;
}

// Checks to see if target value is in array
// PARAM: arr = array to be searched
//        n = size of array
//        target =  value to be searched for
// PRE: arr is sorted
// POST: returns true iff target is in arr
template <class T>
bool Search(T arr[], int n, T target)
{
    int low = 0;
    int high = n-1;
    int mid = 0;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

// Complete your sorting algorithm function implementations here

// SelectSort
// PURPOSE: sorts its array parameter using the SelectionSort algorithm
// PARAM: arr = array to be sorted, size = size of the array
// PRE: an array type parameter and its size
// POST: number of time its barometer comparison is made during its execution
template <class T>
int SelectionSort(T arr[], int size)
{
    int comparsion = 0;
    for(int i=0; i < size-1; i++)
    {
        int smallest = i;
        // Find the index of the smallest element
        for(int unsorted = i+1; unsorted < size; unsorted++)
        {
            comparsion++;
            if (arr[unsorted] < arr[smallest])
            {
                smallest = unsorted;
            }
        }
        // Swap the smallest with the current item 'i'
        T temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
    return comparsion;
}




// Quicksort
// PURPOSE: sorts its array parameter using the quick-sort algorithm
// PARAM: arr = array to be sorted, size = size of the array
// PRE: using quicksort_helper method
// POST: number of times its barometer comparison is made during its execution
template <class T>
int Quicksort(T arr[], int size)
{
    int comparison = 0;
    Quicksort_Helper(arr, 0, size -1,comparison);
    return comparison;
}
// Quicksort_helper
// PURPOSE: function that keeps getting called to sort partitions of arrays
// PARAM: array, start index, end index and comparison
// PRE: using quicksort_helper and partitions methods
// POST: a sorted array
template <class T>
void Quicksort_Helper(T arr[], int startIndex, int endIndex, int& comparison)
{
    if (startIndex < endIndex)
    {
        // Creates partition
        int indexOfPartition = Partitions(arr,startIndex,endIndex,comparison);
        
        // Quick-sort the LOWER half of the array
        Quicksort_Helper(arr, startIndex, indexOfPartition -1, comparison);
        
        // Quick-sort the UPPER half of the array
        Quicksort_Helper(arr, indexOfPartition +1, endIndex, comparison);
    }
}
// Partitions
// PURPOSE: the algorithm helps quick-sort to search for partitions
// PARAM: array, start and end index, comparison
// PRE: know the starting index and the ending index of partitions
// POST: sets the pivot value and increment left and decrement right
//		pointers until low value can be swapped with high value, finally,
//		return the index of partitionpivot_index = end_index;
template <class T>
int Partitions(T arr[], int startIndex, int endIndex,int &comparison)
{
    // Pointer points to the elements in array
    int low = startIndex ;
    int high = endIndex -1;
    
    // Set the pivot as the last element in the array initially
    int pivotIndex = endIndex;
    
    while(low < high)
    {
        // Finds the element greater than the pivot value
        while(low < high && arr[low] <= arr[pivotIndex])
        {
            low++;
            comparison++ ;
        }
        // Find the element less than the pivot value
        while(low < high && arr[high] > arr[pivotIndex])
        {
            high--;
            comparison++ ;
        }
        // Swap the elements at the low and high indices
            T temp = arr [low];
            arr[low] = arr[high];
            arr[high] = temp;
    }
    // End of outer while loop
    // Move our pivot into the right place: swap pivot
    // with the first item greater than it
    if(arr[pivotIndex] < arr[low])
    {
        T temp = arr[low];
        arr[low] =arr[pivotIndex];
        arr[pivotIndex] = temp;
        pivotIndex = low;
    }
    return pivotIndex;
}




// Mergesort
// PURPOSE: sorts its array parameter using the merge-sort algorithm
// PARAM: arr = array to be sorted, size = size of the array
// PRE: using merges & mergesort_helper methods
// POST: number of times its barometer comparison is made during its execution.
template <class T>
int Mergesort(T arr[], int size)
{
    int comparisons = 0;
    Mergesort_Helper(arr,0,size-1, comparisons);
    return comparisons;
}
// Mergesort_Helper
// PURPOSE: recursively call itself to sorts different sub-arrays
// PARAM: array, low index, high index and comparison
// PRE: array type parameter,size, and the first and last index of the main array
// POST: a sorted array
template <class T>
void Mergesort_Helper(T arr[], int low, int high,int & comparison)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        
        Mergesort_Helper(arr,low, mid,comparison); // sorts the LOWER sub-array
        
        Mergesort_Helper(arr, mid+1, high,comparison); // sort the UPPER sub-array
        
        Merging(arr,low,mid,high,comparison);
    }
}
// Merging Function
// PURPOSE: merges 2 sub-array to extra sized one iteratively
// PARAM: array, low index, mid index, high index and comparison
// PRE:
// POST: generates a bigger array from 2 smaller sorted sub-arrays
template <class T>
void Merging(T arr[], int low, int mid, int high,int & comparison)
{
    T *temp = new T[high-low+1];
    
    int low1 = low, high1 = mid; // first and last indexes of 1st sub-array
    
    int low2 = mid+1, high2 = high; //fist and last indexed of 2nd sub-array
    
    int indexOfTemp = 0; //next index of temp opened
    
    //compare values from 2 sub-arrays, copy the smaller one from each sub-array
    // store in the temp array until one of the sub-arrays exhausts
    while(low1 <=high1 && low2 <= high2)
    {
        if(arr[low1] < arr[low2])
        {
            temp[indexOfTemp] = arr[low1];
            low1 ++;
            indexOfTemp++;
            comparison++;
        }
        else // arr[low2] < arr[low1]
        {
            temp[indexOfTemp] = arr[low2];
            low2 ++;
            indexOfTemp++;
            comparison++;
        }
    }
    //if there is any left over elements from the 1st sub-array copy over
    while (low1 <= high1)
    {
        temp[indexOfTemp] = arr[low1];
        low1++;
        indexOfTemp++;
    }
    //if there is any left over elements from the 2nd sub-array, copy over
    while (low2 <= high2)
    {
        temp[indexOfTemp] = arr[low2];
        low2++;
        indexOfTemp++;
    }
    //copy the merged array (temp) into the original calling array
    int i, j;
    for ( i = low,  j = 0; i<= high; i++, j++)
    {
        arr[i] = temp[j];
    }
    delete[] temp;
}




// Shell Sort
// Resource : http://www.cplusplus.com/forum/general/123961/
// PURPOSE: sorts its array parameter using the Shell sort algorithm
// PARAM: arr = array to be sorted, size = size of the array
// PRE: an array type parameter and its size
// POST: number of times its barometer comparison is made during its execution
template <class T>
int ShellSort(T arr[], int size)
{
    int comparison = 0;
    int gap; // Determine the distance between two swapping values
    T temp; // Store the temporary element
    
    for (gap = size/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < size; i++)
        {
            for (int j = i-gap; j >= 0; j-=gap)
            {
                comparison++;
                if(arr[j] < arr[j+gap])
                {
                    break;
                }
                // if arr[j] > arr[j+gap], sweap j & i
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
        }
    }
    return comparison;
}