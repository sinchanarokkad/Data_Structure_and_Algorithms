#include <iostream>

using namespace std ;

 #include <iostream>

// Assuming 'size' is a global variable or defined somewhere in your code
const int size = 10;

// Assuming there is a swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[]) {
    for (int i = 0; i < size; i++) {
        bool is_sorted = true;
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted) {
            break;
        }
    }
}

int main() {
    int arr[size] = {5, 2, 9, 1, 5, 6, 0, 8, 3, 7};

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Call the bubble_sort function
    bubble_sort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}