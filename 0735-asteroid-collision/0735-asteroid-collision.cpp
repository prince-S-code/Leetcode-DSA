class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // if left encountered and the stack is empty or the top is left
            // going
            if ((st.empty() || st.top() < 0) && asteroids[i] < 0) {
                st.push(asteroids[i]);
            }
            // if right encountered push it
            else if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                // left encountered and the stack is not empty

                // case 1 when right going one has higher impact
                // donot push the left going to the stack
                if (st.top() > abs(asteroids[i])) {
                    continue;
                } else {
                    // case 3 when left going one has higher impact
                    // keep popping untill a right going one with higher impact
                    // encountered or left going encountered

                    while (!st.empty() &&
                           (st.top() < abs(asteroids[i]) && st.top() > 0)) {
                        st.pop();
                    }
                    // case 2 :equal impact case when left magnitude equal
                    // to the right
                    if (!st.empty() && st.top() == abs(asteroids[i])) {
                        st.pop();
                        continue;
                    }
                    if ((st.empty() || st.top() < 0) && asteroids[i] < 0) {
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};