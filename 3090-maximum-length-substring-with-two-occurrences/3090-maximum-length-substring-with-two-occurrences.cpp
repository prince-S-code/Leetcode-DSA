class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int max_len=0;
        unordered_map<char,int> mpp;
        int left=0;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>2){
                mpp[s[left]]--;
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
        
    }
};