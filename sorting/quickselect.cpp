#include <bits/stdc++.h>
using namespace std;

// Function to partition the array around a pivot
int partition(vector<int>& v, int low, int high) {
    int pivot = v[high]; // Choosing the last element as the pivot
    int i = low; // Index for the smaller element

    // Iterate through the array and move elements smaller than pivot to the left
    for (int j = low; j < high; ++j) {
        if (v[j] < pivot) {
            swap(v[i], v[j]); // Swap elements
            i++;
        }
    }
    swap(v[i], v[high]); // Place the pivot in its correct position
    return i; // Return the index of the pivot
}

// Function to perform QuickSelect algorithm
int quickselect(vector<int>& v, int low, int high, int k) {
    if (low == high) return v[low]; // If the list contains only one element

    int pi = partition(v, low, high); // Partition the array and get the pivot index

    // If the pivot index matches the K value (adjusted for zero-based indexing)
    if (pi < k) {
        return quickselect(v, pi + 1, high, k); // Recur for the right subarray
    } else if (pi > k) {
        return quickselect(v, low, pi - 1, k); // Recur for the left subarray
    } else {
        return v[k]; // If the pivot index is the K value, return the element
    }
}

// Function to find the Kth smallest and Kth largest elements
vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    // Find the Kth smallest element (0-indexed, so we use k-1)
    int sm = quickselect(arr, 0, n - 1, k - 1);
    // Find the Kth largest element (0-indexed, so we use n-k)
    int mx = quickselect(arr, 0, n - 1, n - k);

    return {sm, mx}; // Return the Kth smallest and Kth largest elements
}

int main() {
    vector<int> arr = {1, 2, 5, 4};
    int k = 3;
    vector<int> result = kthSmallLarge(arr, arr.size(), k);
    cout << "The " << k << "rd smallest element is " << result[0] << endl;
    cout << "The " << k << "rd largest element is " << result[1] << endl;
    return 0;
}