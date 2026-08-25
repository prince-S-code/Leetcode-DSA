class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int it:nums) st.insert(it);
        // bool flag=false;
        int i=1;
        while(true){
            int curr=i*k;
            if(st.find(curr)==st.end()){
                return curr; 
            }
            i++;
        }
        return 0;
    }
};