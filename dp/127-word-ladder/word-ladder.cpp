class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            for(int i=0;i<word.length();i++){
             string newWord = word;
                for(char ch='a';ch<='z';ch++){
                    newWord[i] =ch;
                    if(st.find(newWord)!=st.end()){
                        q.push({newWord,level+1});
                        st.erase(newWord);
                    }
                }

            }
        }
        return 0;

    }
};