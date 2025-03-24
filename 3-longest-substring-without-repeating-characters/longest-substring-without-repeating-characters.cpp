class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = -1;
        int i=0;
        int j = 0;
        int n = s.size();
        unordered_set<char>st;
        while(j<n){
            char ch = s[j];
            if(st.find(ch)==st.end()){
                size = max(size,j-i+1);
                st.insert(s[j]);
                j++;
            
            }else{
                st.erase(s[i]);
                i++;
            }

        }
       
         size = max(size,j-i);
        return size;
    }
};