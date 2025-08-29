#include <iostream>
#include <vector>

void merge(std::vector<int>& array, std::vector<int>& left, std::vector<int>& right) {
    int i = 0, j = 0, k = 0;

    // Merge the two halves into the original array
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        }
        else {
            array[k++] = right[j++];
        }
    }

    // Copy any remaining elements of left
    while (i < left.size()) {
        array[k++] = left[i++];
    }

    // Copy any remaining elements of right
    while (j < right.size()) {
        array[k++] = right[j++];
    }
}

void mergeSort(std::vector<int>& array) {
    if (array.size() <= 1) return;

    int mid = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + mid);
    std::vector<int> right(array.begin() + mid, array.end());

    mergeSort(left);
    mergeSort(right);
    merge(array, left, right);
}

int main() {
    std::vector<int> data = { 7, 4, 6, 1 };

    std::cout << "Original array:\n";
    for (int num : data) std::cout << num << " ";
    std::cout << "\n";

    mergeSort(data);

    std::cout << "Sorted array:\n";
    for (int num : data) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
