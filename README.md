# Comparing Sorting-algorithms
Sorting algorithms with the time taken to sort arrays of diff sizes

Introduction

In this paper,  we investigate a classical problem:  sorting.  The problem is to arrange an array of n integers according to some total order which is computed in O(1).  
In this paper we compare three comparison-based sorting algorithms:  merge sort, quick sort, and heap sort.


Merge sort

This algorithm uses the divide and conquer method in sorting an array of n size. Merge sort first divides the array into two parts, sort each half and then merges the two sorted parts. 
To sort an array of size n, we have to sort two arrays of size n/2 and then merge them, which we know takes O(n) time. To sort two arrays of size n/2, we have to sort four arrays 
of size n/4, then perform two merges (one for each two arrays of size n4), which takes O(n) time, and one for two arrays of size n/2, which takes O(n) time.
The sizes of the arrays to sort are divided by 2 for each level of recursion. Therefore, there will be no more than log2n levels of recursion.
The best case for merge sort is O(nlog(n)) and it remains the same for its average and worst case. In my case its stable.


Quick sort

In quicksort, we partition the array by some value found in the array.
First, we have to choose which value to actually use. The simplest choice is to choose the first value in the array, and partition the data according to that value. 
Any element may be chosen as the pivot, but it is easiest to take the first or the last.
So in my case, the first element is chosen as the pivot. Any element less than the pivot comes before the pivot and any element greater than the pivot is placed after the pivot.
In every stage of the sort, a pivot is considered. Partitioning of an n element array is O(n). The best case and average case is O(n log n) and its worst case is O(n)^2.
The worst case occur when the array is sorted already in same order thus ascending or descending order.


Heap sort

A heap is a data structure.
The main goal of a heap is to provide a method to take the largest element in a set of values and fast. The largest element has to be provided in constant time.
The maximum value in the array is located and its then swapped with the last value at the end of the array. This method is then repeated until the whole array is sorted completely. 
Its worst case is O(n log(n)).


Methodology

The  algorithms  were  implemented  in  C++. 
Randomly shuffled arrays of values 0, 1, . . . ,n−1 were generated. The algorithms were tested on arrays of sizes from 100, 200, 300, . . . , 10000. 
Each algorithm was given the same input data.  Each array ize was tested 100 times.The result for each size is the average time it took for each algorithm to sort the input array.
