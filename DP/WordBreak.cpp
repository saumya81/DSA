Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


---------------------------------------------

class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        
        int size = str.length();
    if (size == 0)   return true;
 
    bool wb[size+1];
    memset(wb, 0, sizeof(wb));
        for (int i=1; i<=size; i++)
    {
        // if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (wb[i] == false && find(wordDict.begin(),wordDict.end(),str.substr(0, i))!=wordDict.end())
            wb[i] = true;
 
        // wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                // Update wb[j] if it is false and can be updated
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && find(wordDict.begin(),wordDict.end(),str.substr(i, j-i))!=wordDict.end())
                    wb[j] = true;
 
                // If we reached the last character
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
     return false;
        
    }
};
