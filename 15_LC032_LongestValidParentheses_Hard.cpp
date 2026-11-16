
#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
    int longestValidParentheses(std::string s) {

        std::stack<int> st;

        // Base index
        st.push(-1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {

            // If opening bracket
            if (s[i] == '(') {
                st.push(i);
            }

            // If closing bracket
            else {
                st.pop();

                // Stack empty means unmatched closing bracket
                if (st.empty()) {
                    st.push(i);
                }

                // Calculate valid substring length
                else {
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};
