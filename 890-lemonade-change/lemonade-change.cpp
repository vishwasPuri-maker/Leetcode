
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> sumGive;

        for(int i = 0; i < bills.size(); i++) {

            if(bills[i] == 5) {
                sumGive.push_back(5);
            }

            else if(bills[i] == 10) {

                auto it = find(sumGive.begin(), sumGive.end(), 5);

                if(it != sumGive.end()) {
                    sumGive.erase(it);
                    sumGive.push_back(10);
                }
                else {
                    return false;
                }
            }

            else if(bills[i] == 20) {

                auto it10 = find(sumGive.begin(), sumGive.end(), 10);
                auto it5 = find(sumGive.begin(), sumGive.end(), 5);

                if(it10 != sumGive.end() && it5 != sumGive.end()) {
                    sumGive.erase(it10);
                    it5 = find(sumGive.begin(), sumGive.end(), 5);
                    sumGive.erase(it5);
                }

                else {
                    int count = 0;

                    for(int j = 0; j < sumGive.size(); j++) {
                        if(sumGive[j] == 5) {
                            count++;
                        }
                    }

                    if(count >= 3) {
                        for(int j = 0; j < 3; j++) {
                            auto it = find(sumGive.begin(), sumGive.end(), 5);
                            sumGive.erase(it);
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
