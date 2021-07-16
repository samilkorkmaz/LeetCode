//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cmax = 0;
        for(size_t i = 0; i<s.size(); i++) {
            string sub = {s[i]};
            for(size_t j=i+1; j<s.size(); j++) {
                bool canAdd = true;
                for(size_t k=0; k<sub.size(); k++) {
                    if(s[j] == sub[k]) canAdd = false; //char to be added (s[j]) already exist in substring
                }
                if (canAdd) sub += s[j];
                else break;
            }
            //printf("i=%d, sub = %s, size = %d\n",i , sub.c_str(), sub.size());
            if(sub.size() > cmax) cmax = sub.size();
        }
        return cmax;        
    }
};
