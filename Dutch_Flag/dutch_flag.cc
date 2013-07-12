#include<iostream>
#include<vector>
#include<cstdlib>

template<typename T>

/**
vector<T>& v : vector of values that needs to be partitioned
int& pivot : the index for pivot value
*/
void dutch_flag(std::vector<T>& v, int& pivot)
{
	T pivot_elem = v[pivot];
	int small_ptr = 0, equal_ptr = 0;
	int large_ptr = v.size() - 1;
	//equal_ptr keeps moving to the right to create three partitions
	while(equal_ptr <= large_ptr)
	{
		if(v[equal_ptr] < pivot_elem)	//compare new element with pivot element
			std::swap(v[equal_ptr++], v[small_ptr++]);
		else if(v[equal_ptr] == pivot_elem)
			equal_ptr++;
		else std::swap(v[equal_ptr], v[large_ptr--]);
	}
}


int main()
{
	std::vector<int> vec;

	for(int i = 0; i < 10; i++)
		vec.push_back(rand()%100);
	
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout<<std::endl;
	
	int x = rand()%10;
	std::cout << "The pivot element is "<< vec[x] << std::endl;
	dutch_flag(vec, x);
	
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout<<std::endl;
	return 0;
}
