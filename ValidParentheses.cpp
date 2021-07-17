//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        int normal = 0; int curly = 0; int square = 0;
        vector<char> parens;
        try {
            for(size_t i = 0; i < s.size(); i++) {
                if(s[i] == '(') {normal++; parens.push_back(s[i]);}            
                if(s[i] == ')') {
                    if(parens.size() == 0) return false; //No opening paranthesis exists
                    if(parens.back() == '(') {
                        normal--; 
                        parens.pop_back();    
                    } else return false;
                }
                if(s[i] == '{') {curly++; parens.push_back(s[i]);}            
                if(s[i] == '}') {
                    if(parens.size() == 0) return false; //No opening paranthesis exists
                    if(parens.back() == '{') {
                        curly--; 
                        parens.pop_back();    
                    } else return false;
                }
                if(s[i] == '[') {square++; parens.push_back(s[i]);}            
                if(s[i] == ']') {
                    if(parens.size() == 0) return false; //No opening paranthesis exists
                    if(parens.back() == '[') {
                        square--; 
                        parens.pop_back();    
                    } else return false;
                }
            }
        } catch (...) { //happens when there is no opening paranthesis in parens vector
            return false;
        }
        return (normal==0) && (curly==0) && (square==0);
    }
};
