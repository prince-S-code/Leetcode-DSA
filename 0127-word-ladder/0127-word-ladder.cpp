class Solution {
public:
    // using bfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;//the word and the no of steps to reach that word
        int n=beginWord.size();
        q.push({beginWord,1});
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            string word=current.first;
            int steps=current.second;
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<n;i++){//index
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)!=0){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                    word[i]=original;
                }
            }
        }
        return 0;
    }
};