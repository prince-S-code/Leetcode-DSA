class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            string word= current.first;
            int steps=current.second;
            if(word== endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char chr='a';chr<='z';chr++){
                    word[i]=chr;
                    if(st.count(word)!=0){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        // if no sequesnce exists
        return 0;
    }
};