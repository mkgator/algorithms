#include<stdio.h>
#include<stddef.h>

size_t my_strlen(const char* str)
{
	if(!str) return -1;
	const char* temp = str;
	while(*temp++);
	return temp - 1 - str;
}

int main()
{
	const char* str = "London";
	printf("Length of the string is %d\n", my_strlen(str));
	return 0;
}
