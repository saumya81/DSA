https://leetcode.com/problems/decode-ways/
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
  
  ------------------------------------------------------------------------------------------------------------------------------------------------------

Idea:
We keep three variables:
prev_i_ways is the number of ways to decode s up to index i-1.
i_ways is the number of ways to decode s up to index i.
prev is a temporary variable to save the i_ways in each iteration.

We initialize i_ways and prev_i_ways with 1 because we are starting the loop from index 1.
If the first digit iz 0 we just return 0 because it's impossible to decode the string.

In each iteration:

Save the previous i_ways in prev, to remember it.
If the current digit is 0, the new i_ways is 0 because we can't add any new decode way.
Else, if the current digit is part of a 2 digit number, we add the prev_i_ways to the new i_ways, because we have another prev_i_ways ways to decode.
For the next iteration, prev_i_ways becomes the i_ways that we saved.
  
  ----------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int numDecodings(string s) {
       int prev_i_ways = 1, i_ways = 1, prev;
        if (!s.size()) return 0;
        if (s[0] == '0') return 0;
        
        for (int i = 1; i < s.size(); i++) {
            prev = i_ways;
            if (s[i] == '0') i_ways = 0;
            if ((s[i-1] == '1') || (s[i-1] == '2' && s[i] < '7')) i_ways += prev_i_ways;
            prev_i_ways = prev;
        }
        return i_ways;
    }
};
