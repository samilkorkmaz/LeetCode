//https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;        
        //printf("si = %d\n", strstr(haystack.c_str(), needle.c_str())); --> returns 0 when is haystack = "aaa" and needle = "aaaa" where LeetCode expected result is 2, which is wrong!
        int k = -1;
        for(size_t i = 0; i<haystack.size(); i++) {
            k = -1;
            if(haystack[i] == needle[0]) {
                bool isSubStr = true;
                k = i;
                for(size_t j = 1; j<needle.size(); j++) {                    
                    isSubStr = isSubStr && (haystack[i+j] == needle[j]);
                }
                if(isSubStr) {
                    break;
                }
            }
        }
        return k;
    }
};
