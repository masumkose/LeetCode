
#include<stdlib.h>
#include<stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	double median = 0;
	int		n = 0;
	int 	m = 0;
	int		t = 0;
	int		*sorted;
	int size = nums1Size + nums2Size;

	sorted = malloc (sizeof(int) * (size));
	while (t < size && n <nums1Size && m <nums2Size)
	{
		if (nums1[n] <= nums2[m])
			sorted[t++] = nums1[n++];
		else
			sorted[t++] = nums2[m++];
	}
	while (n < nums1Size && t < size)
		sorted[t++] = nums1[n++];
	while (m < nums2Size && t < size)
		sorted[t++] = nums2[m++];

	if (size % 2 == 0)
		median = (sorted[(size / 2) - 1] + sorted[(size / 2)]) / 2.0;
	else
		median = sorted[(size / 2)];
	free(sorted);
	return (median);
}

int main() {
	// Sample input arrays
	int nums1[] = {1,2};
	int nums1Size = 2;
	int nums2[] = {3,4};
	int nums2Size = 2;

	// Call the function to find median
	double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

	// Output the result
	printf("Median of the two sorted arrays: %.2f\n", median);

	return 0;
}
