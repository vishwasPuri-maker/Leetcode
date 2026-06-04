class Solution {
public:
    int totalWaviness(int num1, int num2) {

        vector<int> digits;
        vector<int> len;
        for(int num = num1; num <= num2; num++) {

            vector<int> curr;
            int x = num;

            while(x > 0) {
                curr.push_back(x % 10);
                x /= 10;
            }

            reverse(curr.begin(), curr.end());

            len.push_back(curr.size());

            for(int d : curr) {
                digits.push_back(d);
            }
        }

        int waviness = 0;
        int start = 0;
        for(int k = 0; k < len.size(); k++) {

            int digitSize = len[k];

            for(int j = start + 1; j < start + digitSize - 1;j++) {

                if((digits[j] > digits[j - 1] &&
                    digits[j] > digits[j + 1]) ||

                   (digits[j] < digits[j - 1] &&
                    digits[j] < digits[j + 1])) {

                    waviness++;
                }
            }

            start += digitSize;
        }

        return waviness;
    }
};