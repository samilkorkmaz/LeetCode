//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref="";
        int minWordSize = INT_MAX;
        for(size_t i=0; i<strs.size(); i++) {
            if(strs[i].size() < minWordSize) minWordSize = strs[i].size();
        }
        for(size_t w=0; w<minWordSize; w++) {
            //printf("strs[0][%d] = %c\n",w, strs[0][w]);
            pref.append({strs[0][w]});
            bool allStrsContainPrefix = true;
            for(size_t i=0; i<strs.size(); i++) {
                if (strs[i].rfind(pref, 0) != 0) {
                    allStrsContainPrefix = false;
                    break;
                }                
            }
            if(!allStrsContainPrefix) {
                pref.pop_back(); //remove last char
                break;  
            } 
        }
        return pref;
    }
};
