class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>open;
        stack<int>unlock;
        if(s.size()%2!=0) return false;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0') unlock.push(i);
            else if(s[i]=='(') open.push(i);
            else{
                if(!open.empty() && open.top() < i ) open.pop();
                else if(!unlock.empty() && unlock.top()<i) unlock.pop();
                else return false;
            }
        }

        // if(unlock.size()<open.size() ) return false;
        while(!open.empty()){
            if(!unlock.empty() && unlock.top() > open.top()){
                open.pop(),unlock.pop();
            }
            else return false;
        }

        if(unlock.size()%2!=0) return false;
        return true;
    }
};