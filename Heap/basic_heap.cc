#include<iostream>
#include<vector>
#include<cstdlib>

/*
Function that maintains the heap property
Allows element at index to float down the heap into position
*/
template<typename T>
void max_heapify(std::vector<T>& A, int const& index, int const& heapsize)
{
	int left_index = index<<1;
	int right_index = (index<<1) + 1;
	int largest = 0;
	
	if(left_index < heapsize && A[left_index] > A[index])
		largest = left_index;
	else largest = index;
	
	if(right_index < heapsize && A[right_index] > A[largest])
		largest = right_index;
		
	if(largest != index)
	{
		std::swap(A[index], A[largest]);
		max_heapify(A, largest, heapsize);
	}
}

/*
Function that builds a max heap from the elements in vector A
*/
template<typename T>
void build_max_heap(std::vector<T>& A)
{
	int heapsize = A.size();
	for(int i = (heapsize - 1)/2; i >= 0; --i)
		max_heapify(A, i, heapsize);
}

/*
Function that sorts the elements in vector A in place
*/
template<typename T>
void heap_sort(std::vector<T>& A)
{
	build_max_heap(A);
	int heapsize = A.size();
	for(int i = A.size() - 1; i >= 1; --i)
	{
		std::swap(A[0], A[i]);
		heapsize--;
		max_heapify(A, 0, heapsize);
	}
}


int main()
{
	std::vector<int> A;
	
	for(int i = 0; i < 10; i++)
		A.push_back(rand()%100);	
	for(std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	build_max_heap(A);
	heap_sort(A);
	
	for(std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	return 0;
}
	
