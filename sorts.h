#ifndef __SORTS_H
#define __SORTS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "list.cpp"

using namespace std;

struct heap
{
        int size;
        long* array;
	void checkstructure(int index);
	void insert(long value);
	long* sorting(long sorted[]);
	void check(int index);
};


List<long> quicksort4(List<long> list, int start, int size, ListItem<long>* head, ListItem<long>* tail);
long* quicksort3(long array[], int start, int size);
long* quicksort2(long array[], int start, int size);
long* quicksort1(long array[], int start, int size);
vector<long> InsertionSort(vector<long> nums);
vector<long> MergeSort(vector<long> nums);
List<long> MergeSort2(List<long> temp);
List<long> Merge(List<long> temp, List<long> right);
vector<long> QuickSortArray(vector<long> nums);
vector<long> QuickSortList(vector<long> nums);
vector<long> HeapSort(vector<long> nums);
vector<long> BucketSort(vector<long> nums, int max);

#endif

