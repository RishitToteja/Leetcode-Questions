class Solution {
public:
    int firstMissingPositives(int* nums, int numsSize) {
    int i, j, temp;
    for (i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
    int firstMissingPositive(vector<int>& nums) {
        int a[nums.size()];
        
        for(int i = 0; i<nums.size(); i++){
            a[i] = nums[i];
        }
        
        
        return firstMissingPositives(a, nums.size());
    }
};