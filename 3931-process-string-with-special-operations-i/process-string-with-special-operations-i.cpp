class Solution {
public:
    string processStr(string s) {
        string result;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                result.push_back(s[i]);
            }
            else if (s[i] == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (s[i] == '#') {
                result += result;
            }
            else if (s[i] == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};