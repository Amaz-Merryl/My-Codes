#include <climits> // Required for INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;
        while (x != 0) {
            // Check for potential overflow before multiplying by 10
            if (reversedNumber > INT_MAX / 10 || reversedNumber < INT_MIN / 10) {
                return 0; // Return 0 if overflow/underflow would occur
            }

            int lastDigit = x % 10;
            reversedNumber = reversedNumber * 10 + lastDigit;
            x /= 10;
        }
        return reversedNumber;
    }
};
