class Solution {
public:
    int countConsistentStrings(string a, vector<string>& words) {

        unordered_set<int>st;
        for(auto i:a) st.insert(i);
        int cnt =0;
        for(auto str : words){
            bool totake = true;
            for(auto j : str){
                if(st.find(j)==st.end()){
                    totake=false;
                    break;
                }
            }
            if(totake)cnt+=1;
    
        } 
        return cnt;       
    }
};