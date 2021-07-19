//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsertON(vector<int>& nums, int target) {
        int k = 0;
        for(size_t i=0; i<nums.size(); i++) {
            if(target > nums[i]) {
                k = i+1;
                printf("nums[%d] = %d\n", i, nums[i]);
            } 
        }
        return k;
    }
};
