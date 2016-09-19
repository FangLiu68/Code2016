class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
        stack<char> stk;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }else if(s[i] == ')'){
                if(stk.empty() || stk.top()!='('){
                    return false;
                }
                stk.pop();
            }else if(s[i] == '}'){
                if(stk.empty() || stk.top()!='{'){
                    return false;
                }
                stk.pop();
            }else if(s[i] == ']'){
                if(stk.empty() || stk.top()!='['){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};