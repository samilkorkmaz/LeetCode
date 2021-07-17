//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        vector<char> parens;
        for(size_t i = 0; i < s.size(); i++) {
            if(s[i] == '(') parens.push_back(s[i]);            
            if(s[i] == ')') {
                if(parens.size() == 0) return false; //No opening paranthesis exists
                if(parens.back() == '(') {
                    parens.pop_back();    
                } else return false;
            }
            if(s[i] == '{') parens.push_back(s[i]);            
            if(s[i] == '}') {
                if(parens.size() == 0) return false; //No opening paranthesis exists
                if(parens.back() == '{') {
                    parens.pop_back();    
                } else return false;
            }
            if(s[i] == '[') parens.push_back(s[i]);            
            if(s[i] == ']') {
                if(parens.size() == 0) return false; //No opening paranthesis exists
                if(parens.back() == '[') {
                    parens.pop_back();    
                } else return false;
            }
        }
        return parens.size()==0;
    }
};
