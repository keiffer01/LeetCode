class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Average O(n) time, O(n) space.
        std::unordered_map<int, int> indexToNum(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (indexToNum.find(nums[i]) == indexToNum.end()) {
                indexToNum[target - nums[i]] = i;
            } else {
                return {indexToNum[nums[i]], i};
            }
        }
        // Not possible.
        return {};
    }
};