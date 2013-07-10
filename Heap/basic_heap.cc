#include<iostream>
#include<vector>

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

template<typename T>
void build_max_heap(std::vector<T>& A)
{
	int heapsize = A.size();
	for(int i = (heapsize - 1)/2; i >= 0; --i)
		max_heapify(A, i, heapsize);
}

int main()
{
	std::vector<int> A;
	A.push_back(4);
	A.push_back(1);
	A.push_back(3);
	A.push_back(2);
	A.push_back(16);
	A.push_back(9);
	A.push_back(10);
	A.push_back(14);
	A.push_back(8);
	A.push_back(7);
	
	for(std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	build_max_heap(A);
	
	for(std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	return 0;
}
	
