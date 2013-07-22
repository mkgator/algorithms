#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

// len should be 1 more than strlen(src)
void safe_strcpy(char* dest, const char* src, size_t len)
{
	// if src and dest are the same
	if(dest == src) return;
	// if either src or dest doesn't exist
	if(!src || !dest) return;
	// overlap
	if(src < dest && dest < (src + len))
		while(len--)
			*(dest + len) = *(src + len); // copy to dest locations that aren't overlapping
	else
		while(len--)
			*dest++ = *src++;
}

int main()
{
const char* src = "Stringy";
char* dest = malloc(8*sizeof(src));
safe_strcpy(dest, src, strlen(src) + 1);
puts(dest);
return 0;
}

