class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int degree=s[i]-'a'+1;
            int rev_degree=27-degree;
            ans+=(i+1)*rev_degree;
        }
        return ans;
    }
};