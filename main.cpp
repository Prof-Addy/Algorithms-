#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <windows.h>

using namespace std;

//comparing merge sort, quick sort and heap sort

void merge(vector<int>&array, int start, int mid, int end)
{
    vector<int>left_arr;
    vector<int>right_arr;

    int left_side = mid - start+1;
    int right_side = end - mid;

    for (int i = 0; i <left_side; ++i) {
        left_arr.push_back(array[start+i]);
    }

    for (int j = 0; j < right_side; ++j) {
        right_arr.push_back(array[mid+1+j]);
    }

    int left = 0;
    int right= 0;
    int subm = start;

    while(left < left_side && right < right_side){
        if(left_arr[left] <= right_arr[right]){
            array[subm]=left_arr[left++];
        }
        else{
            array[subm]=right_arr[right++];
        }
        subm++;
    }

    while(left < left_side){
        array[subm++] = left_arr[left++];

    }

    while(right < right_side){
        array[subm++] = right_arr[right++];
    }

}

void mergeSort(vector<int>&arr , int start , int end ) {

    if(start >= end)
    {
        return;
    }
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);

}


void  swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>&array, int start , int end) {
    int mid = array[start];
    int left = start;
    int right = end;
    while (left < right) {
        do {
            left++;

        } while (array[left] <= mid);
        do {
            right--;
        } while (array[right] > mid);
        if (left < right)
            swap(&array[left], &array[right]);
    }
    swap(&array[start], &array[right]);
    return right;
}

void quickSorting(vector<int>&arr, int left , int right) {

    if (left < right) {
        int index = partition(arr, left, right);
        quickSorting(arr, left, index);
        quickSorting(arr, index + 1, right);
    }

}



void heapify(vector<int>&array, int size, int index)
 {
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < size && array[left] > array[largest]) {

        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&array[index], &array[largest]);
        heapify(array, size, largest);
    }

}
void heapSort(vector<int>&array, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int j = size - 1; j >= 0; j--) {
        swap(&array[0], &array[j]);
        heapify(array, j, 0);
    }

}


int main() {
    size_t array_size[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    std::random_device random_number;
    std::mt19937_64 gen(random_number());

    int times = 10000;

    cout << setw(10) << "\t Merge Sorting " <<  "  Quick Sorting " <<  " Heap Sorting " << endl;
    cout << endl;
    for ( size_t size : array_size)
    {
        std::chrono::nanoseconds sum_merge(0);
        std::chrono::nanoseconds sum_quick(0);
        std::chrono::nanoseconds sum_heap(0);
        std::uniform_int_distribution<> dis(-2 * size, 2 * size);

        for (int j = 0; j < times; ++j) {

            std::vector <int> array(size);
            std::vector <int> Copy_array1(size);
            std::vector <int> Copy_array2(size);


            for (int i = 0; i < size; ++i){
                int n = dis(gen);
                array[i]= n;
            }

            Copy_array1 = array;
            Copy_array2 = array;


            auto t1_merge = std::chrono::high_resolution_clock::now();
                mergeSort(array, 0, array.size()-1);
                auto t2_merge = std::chrono::high_resolution_clock::now();
                std::chrono::nanoseconds time_span1 = t2_merge - t1_merge;
                sum_merge += time_span1;

            auto t1_quick = std::chrono::high_resolution_clock::now();
                quickSorting(Copy_array1, 0, Copy_array1.size());
                auto t2_quick = std::chrono::high_resolution_clock::now();
                std::chrono::nanoseconds time_span2 = t2_quick - t1_quick;
                sum_quick += time_span2;

            auto t1_heap = std::chrono::high_resolution_clock::now();
                heapSort(Copy_array2, Copy_array2.size());
                auto t2_heap = std::chrono::high_resolution_clock::now();
                std::chrono::nanoseconds time_span3 = t2_heap - t1_heap;
                sum_heap += time_span3;
        }
        std::cout << std::setw(8)  << std::fixed << size <<  " : " << sum_merge.count() / times / (std::nano::den * 1.0);
        std::cout << std::setw(14)  <<  sum_quick.count() / times / (std::nano::den * 1.0);
        std::cout << std::setw(16)  << sum_heap.count() / times / (std::nano::den * 1.0);
        cout << endl;
    }
    return 0;
}
