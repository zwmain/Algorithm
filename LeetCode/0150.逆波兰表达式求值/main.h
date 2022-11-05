#include "Utils.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long long> st;
        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(num2 + num1);
                }
                if (s == "-") {
                    st.push(num2 - num1);
                }
                if (s == "*") {
                    st.push(num2 * num1);
                }
                if (s == "/") {
                    st.push(num2 / num1);
                }
            } else {
                st.push(stoll(s));
            }
        }

        int result = static_cast<int>(st.top());
        return result;
    }
};
