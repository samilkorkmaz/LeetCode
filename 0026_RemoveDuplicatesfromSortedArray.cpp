//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicatesSlow(vector<int>& nums) {
        if(nums.size() == 0) return 0;                    
        int k = 0;
        for(size_t i=0; i < nums.size()-1; i++) {
            bool isDuplicate = false;
            for(size_t j=i+1; j < nums.size(); j++) {       
                if(nums[j] == nums[i]) {
                    //printf("duplicate nums[%d] = %d\n", i, nums[i]);
                    isDuplicate = true;
                }
            }
            if(!isDuplicate) {
                //printf("k = %d, %d\n", k, nums[i]);
                nums[k] = nums[i];
                k++;                
            }
        }        
        nums[k] = nums[nums.size()-1];//add last element
        return k+1;
    }
    
    int removeDuplicatesFast(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int k = 1;
        for(size_t i=1; i < nums.size(); i++) {
            bool isDuplicate = false;
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++; 
            }
        }        
        return k;
    }
};
