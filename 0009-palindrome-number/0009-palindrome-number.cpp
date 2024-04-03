class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; // Negative numbers are not palindromes
        }
        
        long long reversed = 0; // Use long long for larger values
        int original = x; // Store the original value of x
        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }
        
        return original == reversed;
    }
};
