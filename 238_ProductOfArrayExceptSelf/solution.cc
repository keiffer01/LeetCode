class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size());
        vector<int> right_product(nums.size());
        vector<int> output(nums.size());

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        right_product[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            right_product[i] = right_product[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); ++i) {
            output[i] = left_product[i] * right_product[i];
        }
        return output;
    }
};