#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"

//=====================================================================================
vector<long> InsertionSort(vector<long> nums)
{
	long array [nums.size()];
	int j;
	array[0]=nums[0];
	for (int i=0; i<nums.size(); i++){
		array[i]=0;
	}
	for (int i=1; i<nums.size(); i++){
		j=i;
		while (j>0 && array[j-1]>nums[i]){
			array[j]=array[j-1];
			j--;
		}
		array[j]=nums[i];

	}
	for (int i=0; i<nums.size(); i++){
		nums[i]=array[i];
	}
	return nums;	


}

//=====================================================================================
vector<long> MergeSort(vector<long> nums)
{
	List<long> temp;
	if (nums.size()==1){
		return nums;
	}
	for (int i=0; i<nums.size(); i++){
		temp.insertAtTail(nums[i]);
	}
	List<long> asd;
	asd = MergeSort2(temp);
	ListItem<long>* temp2=asd.getHead();
        for (int i=0; i<nums.size(); i++){
                nums[i]=temp2->value;
		temp2=temp2->next;
        }
	return nums;
}

List<long> MergeSort2(List<long> temp)
{
	if (temp.length()==1){
		return temp;
	}
	ListItem<long>* a;
	a=temp.getHead();
	for (int i=0; i<(temp.numel)/2; i++){
		a=a->next;
	}
	a->prev->next=NULL;
	a->prev=NULL;
	temp.numel=temp.length();
	List<long> right;
	right.inshead(a);
	right.numel=right.length();
	temp=MergeSort2(temp);
	right=MergeSort2(right);
	return Merge(temp, right);	
}

List<long> Merge(List<long> temp, List<long> right)
{
	ListItem<long>* x;
	x=right.getHead();
	while (x!=NULL){
		temp.insertSorted(x->value);
		x=x->next;
	}
	return temp;
}
//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
	long array[nums.size()];
	for (int i=0; i<nums.size(); i++){
		array[i]=nums[i];
	}
	int a=0;
	cout<<"What should be the pivot?\nPress 1 for first value of array\nPress 2 for last value of array\nPress 3 for median of three pivot"<<endl;
	cin>>a;
	if (a==1){
		quicksort1(array, 0, nums.size()-1);
	}
        else if (a==2){
                quicksort2(array, 0, nums.size()-1);
        }
        else if (a==3){
                quicksort3(array, 0, nums.size()-1);
        }
	else{
		cout<<"INVALID OPTION\nReturning the same vector"<<endl;
		return nums;
	}
	for (int i=0; i<nums.size(); i++){
		nums[i]=array[i];
	}
	return nums;	
}

long* quicksort1(long array[], int start, int size)
{
        int low = start;
	int high = size;
        long temp;
        long pivot = array[low];
        while (low <= high) {
                while (array[low] < pivot){
                        low++;
                }
                while (array[high] > pivot){
                        high--;
                }
                if (low <= high) {
  	                temp = array[low];
	                array[low] = array[high];
			array[high] = temp;
	                low++;
	                high--;
         	}
        }
	if (start < high)
            array=quicksort1(array, start, low);

	if (low < size)
            array=quicksort1(array, low, size);

	return array;
}

long* quicksort2(long array[], int start, int size)
{
        int low = start;
        int high = size;
        long temp;
        long pivot = array[high];
        while (low <= high) {
                while (array[low] < pivot){
                        low++;
                }
                while (array[high] > pivot){
                        high--;
                }
                if (low <= high) {
                        temp = array[low];
                        array[low] = array[high];
                        array[high] = temp;
                        low++;
                        high--;
                }
        }
        if (start < high)
            array=quicksort2(array, start, high);

        if (low < size)
            array=quicksort2(array, low, size);

        return array;
}

long* quicksort3(long array[], int start, int size)
{
        int low = start;
        int high = size;
        long temp;
        long pivot;
	if (array[low]<array[high] && array[low]>array[(low+high)/2] || array[low]>array[high] && array[low]<array[(low+high)/2]){
		pivot=array[low];
	}
        else if (array[high]<array[low] && array[high]>array[(low+high)/2] || array[high]>array[low] && array[high]<array[(low+high)/2]){
                pivot=array[high];
        }
	else{
                pivot=array[(low+high)/2];
        }

        while (low <= high) {
                while (array[low] < pivot){
                        low++;
                }
                while (array[high] > pivot){
                        high--;
                }
                if (low <= high) {
                        temp = array[low];
                        array[low] = array[high];
                        array[high] = temp;
                        low++;
                        high--;
                }
        }
        if (start < high)
            array=quicksort3(array, start, high);

        if (low < size)
            array=quicksort3(array, low, size);

        return array;
}


//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{
        List<long> list;
        for (int i=0; i<nums.size(); i++){
                list.insertAtTail(nums[i]);
        }
	quicksort4(list, 1, list.numel, list.getHead(), list.getTail());
	ListItem<long>* temp;
	temp=list.getHead();
	int i=0;
	while (temp!=NULL){
		nums[i]=temp->value;
		temp=temp->next;
		i++;
	}
	return nums;
}

List<long> quicksort4(List<long> list, int start, int size, ListItem<long>* head, ListItem<long>* tail)
{
		cout<<"hello"<<endl;
	if (start==size){
		return list;
	}
	int x=start;
	int y=size;
//	for (int i=0; i<)
        ListItem<long>* i = head;
        ListItem<long>* j = tail;
        long tmp;
	int randNum = rand()%(size-start + 1) + start;
	ListItem<long>* pivnode=head;

	for (int i=0; i<randNum; i++){
		if (pivnode!=NULL)
		pivnode=pivnode->next;
	}

	long pivot;

	if (pivnode!=NULL)
		pivot=pivnode->value;
	else
		pivot=head->value;

        while (x <= y) {

		if (i!=NULL){
                while (i->value < pivot){
                        i=i->next;
			x++;
			if (i==NULL){
				break;
			}
                }
		}

		if (j!=NULL){
                while (j->value > pivot){
                       j=j->prev;
			y--;
			if (i==NULL){
				break;
			}
                }
		}

                if (x<=y) {
			if (j!=NULL && i!=NULL){
		//		cout<< i->value<<endl;
		//		cout<< j->value<<endl;
                	        tmp = i->value;
				i->value = j->value;
				j->value = tmp;
                	        i=i->next;
                	        j=j->prev;
				x++;
				y--;
			}
                }
        }

        if (start < y){
		cout<<"hi"<<endl;
            quicksort4(list, start, y, head, j);
	}
        if (x < size){
            quicksort4(list, x, size, i, tail);
	}

        return list;
}


//=====================================================================================

vector<long> HeapSort(vector<long> nums)
{
	heap a;
	a.size=0;
	a.array=new long[nums.size()];
	for (int i=0; i<nums.size(); i++){
		a.insert(nums[i]);
	}
	long sorted[nums.size()];
	a.sorting(sorted);
	for (int i=0; i<nums.size(); i++){
		nums[i]=sorted[i];
	}
	return nums;
}

long* heap::sorting(long sorted[])
{
	int i=0;
	long temp;
	while (size!=0){
		temp=array[size-1];
		array[size-1]=array[0];
		array[0]=temp;
		sorted[i]=array[size-1];
		size--;		
		i++;
		check(0);
	}
	return sorted;
}

void heap::check(int index){
	long temp;
	int childl=index*2+1;
	int childr=index*2+2;
	if (childl<size && childr<size){
	if (array[childl]<array[childr] && array[index]>array[childl]){
		temp=array[index];
		array[index]=array[childl];
		array[childl]=temp;
		check(childl);
		return;
	}
	else if (array[childl]>array[childr] && array[index]>array[childr]){
                temp=array[index];
                array[index]=array[childr];
                array[childr]=temp;
                check(childr);
		return;
	}
	else if (array[childl]==array[childr] && array[index]>array[childr]){
                temp=array[index];
                array[index]=array[childr];
                array[childr]=temp;
                check(childr);
                return;
	}
	}
	if (childl<size && childr>size){
	if (array[index]>array[childl]){
                temp=array[index];
                array[index]=array[childl];
                array[childl]=temp;
                check(childl);
                return;
        }
	}
	//for (int i=0; i<size; i++){
	//	cout<<array[i]<<endl;
	//}
}


void heap::insert(long value)
{
	if (size==0){
		array[0]=value;
		size++;
	}
	else{
		array[size]=value;
		size++;
		checkstructure(size-1);
	}
}

void heap::checkstructure(int index)
{
	int parent;
	long temp;
	if (index!=0){
		parent=(index-1)/2;
		if (array[parent]>array[index]){
			temp=array[parent];
			array[parent]=array[index];
			array[index]=temp;
			checkstructure(parent);
		}
	}
}


//=====================================================================================
vector<long> BucketSort(vector<long> nums, int max)
{
	max=0;
	for(int i=0; i<nums.size(); i++){
		if (nums[i]>max){
			max=nums[i];
		}
	}
	int hash;
	List<long> hashtable[nums.size()];
	for (int i=0; i<nums.size(); i++){
		hash=(nums[i]*nums.size())/(max+1);
		hashtable[hash].insertSorted(nums[i]);
	}
	int j=0;
	ListItem<long>* temp;
	for (int i=0; i<nums.size(); i++){
		if (hashtable[i].getHead()!=NULL){
			temp=hashtable[i].getHead();
			while (temp!=NULL){
				nums[j]=temp->value;
				temp=temp->next;
				j++;
			}
		}
	}
	return nums;
}

#endif
