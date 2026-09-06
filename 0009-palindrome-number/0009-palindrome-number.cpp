class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int num = x;
        long long reversed = 0;

        while (num > 0) {
            int rem = num % 10;
            reversed = (reversed * 10) + rem;
            num /= 10;
        }

        return reversed == x;
    }
};