#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputList(fp);
    vector<int> indArr = { 6, 7 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.removeElements(input[i], indArr[i]);
        ListNode* cur = res;
        while (cur) {
            cout << cur->val << ",";
            cur = cur->next;
        }
        cout << endl;
    }
    return 0;
}
