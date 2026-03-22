class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows,"");
        if(numRows==1){
            return s;
        }
        bool forward=false;
        int curr_row=0;
        for(int i=0;i<s.size();i++){
            ans[curr_row]+=s[i];
            if(curr_row==0 || curr_row==numRows-1){
                forward=!forward;
            }
            forward?curr_row++:curr_row--;
        }
        string result="";
        for(string element:ans){
            result+=element;
        }
        return result;
    }
};