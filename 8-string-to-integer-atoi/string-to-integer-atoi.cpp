class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        long long ans = 0;

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Overflow check
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {

                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};
