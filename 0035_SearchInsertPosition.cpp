//https://leetcode.com/problems/search-insert-position/
#include<stdio.h>
#include<vector>
using namespace std;

int searchInsertON(vector<int>& nums, int target) {
    int k = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (target > nums[i]) {
            k = i + 1;
            //printf("nums[%d] = %d\n", i, nums[i]);
        }
    }
    return k;
}

int searchInsertOLogN(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    if (target <= nums[0]) return 0;
    if (target == nums[nums.size() - 1]) return nums.size() - 1;
    if (target > nums[nums.size()-1]) return nums.size();
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int middleNum = nums[middle];
        //printf("left = %d, right = %d, middle = %d, middleNum = %d\n", left, right, middle, middleNum);
        if (target == middleNum) return middle;
        if (target < middleNum) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return left; //target does not exist in vector but is larger than first element
}

int main() {
    printf("Test for Search Insert Position started, please wait...\n");
    //vector<int> nums{ 1,3,5 }; int target = 2;
    //vector<int> nums{ 1,3 }; int target = 3;
    //vector<int> nums{ 1,3,5,6 }; int target = 7;
    printf("Constructing input vector...\n");
    vector<int> nums; for (int i = -5000000; i < 5000000; i++) nums.push_back(i); int target = 1309;
    printf("Running O(N) function...\n");
    int k1 = searchInsertON(nums, target); //~332ms for vector with 1M elements and target close to the middle
    printf("Running O(log(N)) function...\n");
    int k2 = searchInsertOLogN(nums, target); //~1ms for vector with 1M elements and target close to the middle

    printf("k1 = %d, k2 = %d\n", k1, k2);
	printf("Press enter...\n");
	getchar();
}
