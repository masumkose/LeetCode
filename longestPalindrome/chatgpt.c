
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int expandAroundCenter(char *s, int left, int right);

char *longestPalindrome(char *s) {
    int start = 0, end = 0; // Variables to store the start and end indices of the longest palindrome
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        // Expand around the current character as the center (odd-length palindrome)
        int len1 = expandAroundCenter(s, i, i);
        // Expand around the space between current and next character as the center (even-length palindrome)
        int len2 = expandAroundCenter(s, i, i + 1);
        // Find the length of the longest palindrome centered at position i
        int maxLen = fmax(len1, len2);
        // Update start and end indices if a longer palindrome is found
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    // Allocate memory for the longest palindrome substring
    char *result = malloc(sizeof(char) * (end - start + 2));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}

// Function to expand around a center and find the length of the longest palindrome
int expandAroundCenter(char *s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}


int main()
{
	char s[] = "musudfgddgfdusufgm";


	//printf("%d", is_palindrome(s + 1 , 4));
	printf("%s", longestPalindrome(s));


	return (0);
}
