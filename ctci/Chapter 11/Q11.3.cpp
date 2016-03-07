/* Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order. */
#include <iostream>

// O(logn) if all the elements are unique
// With duplicates, the algorithm is O(n)

int search(int arr[], int low, int high, int x) {
    int mid = (low + high) / 2;
    // If x is our midpoint, return it
    if (arr[mid] == x)
        return mid;
    // Check for error in values provided
    if (low > high)
        return -1;
    // If left is normally ordered
    if (arr[low] < arr[mid]) {
        if (x <= arr[mid] && x >= arr[low])
            // Search the lower half of the array
            return search(arr, low, mid-1, x);
        else
            // Otherwise, search the upper half of the array
            return search(arr, mid+1, high, x);
    }
    // If right is normally ordered
    else if (arr[mid] < arr[high]) {
        if (x >= arr[mid] && x <= arr[high])
            // We want to search the upper half of the array
            return search(arr, mid+1, high, x);
        else
            // Otherwise we search the lower half of the array
            return search(arr, low, mid-1, x);
    }
    // If our left half is all the same values
    else if (arr[low] == arr[mid]) {
        if (arr[mid] != arr[high])
            // We search the upper half of the array
            return search(arr, mid+1, high, x);
        else {
            // Otherwise we search the lower half
            int result = search(arr, low, mid-1, x);
            if (result == -1)
                // Then the upper half
                return search (arr, mid+1, high, x);
            else
                return -1;
        }
    }
    return -1;
}
