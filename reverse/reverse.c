#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


/*int reverse(int x)
{
	long reversed = 0;
	while (x != 0)
	{
		int digit = x % 10;
		reversed = reversed * 10 + digit;
		x/= 10;
	}
	if (reversed > INT_MAX || reversed < INT_MIN)
		return (0);

	return((int)reversed);

}*/

int reverse(int x){
	long int rev=0;

	while(x != 0)
	{
		rev=rev*10+x%10;
		x=x/10;
	}
	if(rev>INT_MAX-1 || rev<INT_MIN)
		return 0;
	else
	return rev; 
}


int main()
{


	printf("%d\n", reverse(-45646));

	return 0;
}
