/*
    Different methods to solve Leetcode 136. Single Number problem.
    https://leetcode.com/problems/single-number/
    Şamil Korkmaz, 15.07.2021
 */

#include <stdio.h>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    bool isRepeating;
    for (size_t i = 0; i < nums.size(); i++) {
        isRepeating = false;
        for (size_t j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            if (nums[i] == nums[j]) {
                isRepeating = true;
                break;
            }
        }
        if (!isRepeating) return nums[i];
    }
    return -1;
}

int singleNumber2(vector<int>& nums) {
    while (nums.size() > 1) {
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                if (nums[i] == nums[j]) {
                    //printf("%d is repeating, i=%d, j=%d.\n", nums[i], i, j);
                    nums.erase(nums.begin() + i);
                    nums.erase(nums.begin() + (j - 1));
                    /*printf("nums after erase:\n");
                    printf("size() = %d\n", nums.size());
                    for(int k=0; k<nums.size(); k++) printf("%d,", nums[k]);
                    printf("\n");*/
                    i--;
                    break;
                }
            }
        }
    }
    return nums[0];
}

int singleNumber3(vector<int>& nums) {
    vector<int> noDuplicate;
    for (size_t i = 0; i < nums.size(); i++) {
        std::vector<int>::iterator it = std::find(noDuplicate.begin(), noDuplicate.end(), nums[i]);
        if (it != noDuplicate.end()) {
            //printf("Deleting i=%d, nums[i] = %d...\n", i, nums[i]);
            noDuplicate.erase(it);
        }
        else {
            //printf("adding %d\n", nums[i]);
            noDuplicate.push_back(nums[i]);
        }
    }
    return noDuplicate[0];
}

vector<int> getVec() {
    vector<int> v;
    for (size_t i = 1; i < 20e3; i += 2) {
        v.push_back(i);
        v.push_back(i);
    }
    v.push_back(0);
    return v;
}

int main() {
    printf("Leetcode Single Number tests started, please wait...\n");
    //vector<int> nums{ 2,2,1 };
    //vector<int> nums{ 4,1,2,1,2 };
    vector<int> nums1 = getVec();
    vector<int> nums2 = getVec();
    vector<int> nums3 = getVec();

    int sn1 = singleNumber(nums1); // ~ 12e3ms
    printf("Test 1/3 finished.\n");
    int sn2 = singleNumber2(nums2); // ~ 60ms
    printf("Test 2/3 finished.\n");
    int sn3 = singleNumber3(nums3); // ~ 50ms
    printf("Test 3/3 finished.\n");

    printf("Single number 1 = %d\n", sn1);
    printf("Single number 2 = %d\n", sn2);
    printf("Single number 3 = %d\n", sn3);
	printf("Press enter...\n");
	return getchar();
}
