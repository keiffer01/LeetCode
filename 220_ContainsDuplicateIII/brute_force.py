class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        # Brute-force solution, performs a sliding window across the array and
        # checks all possible pairs within the window.
        # Time complexity: O(nums.length^2 * valueDiff)
        if indexDiff == len(nums):
            indexDiff -= 1
        for windowStart in range(0, len(nums) - indexDiff):
            for i in range(windowStart, windowStart + indexDiff):
                for j in range(i + 1, windowStart + indexDiff + 1):
                    if abs(nums[i] - nums[j]) <= valueDiff:
                        return True
        return False
