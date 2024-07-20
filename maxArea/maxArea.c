#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int	maxArea(int *height, int heightSize)
{
	int	area = 0;
	int	currentarea = 0;
	int	left = 0;
	int right = heightSize - 1;

	while(left < right)
	{
		currentarea = (right - left)  * (height[left] < height[right] ? height[left] : height[right]);

		if (area < currentarea)
			area = currentarea;
		
		if (height[left] < height[right])
			left++;
		else
			right--;
	}

	return (area);
}


int	main()
{
	int height[] = {1,8,6,2,5,4,8,3,7};
	int heightSize = sizeof(height) / sizeof(height[0]);


	printf("max area == %d\n", maxArea(height, heightSize));

	return (EXIT_SUCCESS);
}
