class Solution {
public:
    int countOdds(int low, int high) {
        int amt = high - low + 1;
        if (amt % 2 == 0) {
            return amt / 2;
        } else {
            if (low % 2 == 1) {
                return (amt + 1) / 2;
            } else {
                return amt / 2;
            }
        }
    }
};