def findPartitionCost(cost, k):
    def isValidPartition(max_cost):
        partitions = 1
        partition_sum = cost[0] + cost[0]  # First element's cost

        for i in range(1, len(cost)):
            new_sum = cost[i] + cost[i]  # Cost of starting new partition

            if partition_sum + cost[i] > max_cost:
                partitions += 1
                partition_sum = new_sum  # Start a new partition
            else:
                partition_sum += cost[i]

        return partitions <= k

    # Binary search for minimum possible maximum cost
    left, right = max(cost) * 2, sum(cost) * 2  
    while left < right:
        mid = (left + right) // 2
        if isValidPartition(mid):
            right = mid
        else:
            left = mid + 1
    min_cost = left

    # Binary search for maximum possible maximum cost
    left, right = max(cost) * 2, sum(cost) * 2  
    while left < right:
        mid = (left + right) // 2
        if isValidPartition(mid):
            left = mid + 1
        else:
            right = mid
    max_cost = left

    return [min_cost, max_cost]

# Example Test Case
cost = [1, 2, 3, 4]
k = 2
print(findPartitionCost(cost, k))  # Expected Output: [8, 12]