class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(); // length of the string
        int m = p.size(); // length of the pattern
        vector<int> result; // to store the starting indices of anagrams

        if (n < m) { // edge case: string is shorter than pattern
            return result; // no anagrams possible, return empty array
        }

        unordered_map<char, int> freq; // hash table to store frequency of characters in the pattern
        for (char ch : p) { // populate hash table with character frequencies in the pattern
            freq[ch]++;
        }

        int left = 0; // left pointer of the sliding window
        int right = 0; // right pointer of the sliding window
        int count = freq.size(); // count of distinct characters in the pattern

        while (right < n) { // loop until right pointer reaches end of the string
            if (freq.find(s[right]) != freq.end()) { // if current character is in the pattern
                freq[s[right]]--; // decrement its frequency in the hash table
                if (freq[s[right]] == 0) { // if frequency becomes zero
                    count--; // decrement count of distinct characters
                }
            }
            right++; // move the right pointer to the right

            while (count == 0) { // if count of distinct characters is zero (anagram found)
                if (right - left == m) { // if length of the window is equal to the length of the pattern
                    result.push_back(left); // add the starting index of the window to the result array
                }
                if (freq.find(s[left]) != freq.end()) { // if left character is in the pattern
                    freq[s[left]]++; // increment its frequency in the hash table
                    if (freq[s[left]] > 0) { // if frequency becomes positive
                        count++; // increment count of distinct characters
                    }
                }
                left++; // move the left pointer to the right
            }
        }

        return result; // return the array of starting indices of anagrams
    }
};
