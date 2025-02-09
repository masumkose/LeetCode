def longestBitonicSequence(nums):
    n = len(nums)
    if n == 0:
        return 0

    # Step 1: Compute LIS ending at i
    inc = [1] * n
    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                inc[i] = max(inc[i], inc[j] + 1)

    # Step 2: Compute LDS starting at i (Reverse LIS)
    dec = [1] * n
    for i in range(n-1, -1, -1):
        for j in range(i+1, n):
            if nums[j] < nums[i]:  # Only take decreasing values
                dec[i] = max(dec[i], dec[j] + 1)

    # Step 3: Find max (inc[i] + dec[i] - 1)
    max_bitonic = 0
    for i in range(n):
        max_bitonic = max(max_bitonic, inc[i] + dec[i] - 1)

    return max_bitonic
