class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        map<int,vector<int>> freq;
        for(auto it:mpp){
            freq[it.second].push_back(it.first);
        }
        int count=k;
        for(auto it=freq.rbegin();it!=freq.rend();it++){
            int len=it->second.size();
            if(count>len){
                ans.insert(ans.end(),it->second.begin(),it->second.end());
                count-=len;
                continue;
            }
            else if(count>0){
                ans.insert(ans.end(),it->second.begin(),it->second.begin()+count);
                break;
            }

        }
        return ans;
    }
};