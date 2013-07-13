#include <vector>
#include <iostream>
#include <cstdlib>

template<typename T>
void selection_sort(std::vector<T>& A)
{
	for(ulong i = 0; i < A.size(); i++)
	{
		ulong min = i;	// index for min element
		ulong j = A.size();
		while(--j > i)	// loop from last elem till i+1
		{
			if(A[j] < A[min])
				min = j;	// find new min element
		}
		std::swap(A[i], A[min]);	// swap next element in sequence with new min element
	}
}

int main()
{
	std::vector<int> A;
	for(int i = 0; i < 20; i++)
		A.push_back(rand()%100);

	for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
	       std::cout << *it << " ";
	std::cout << std::endl;

	selection_sort(A);

	for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}	
