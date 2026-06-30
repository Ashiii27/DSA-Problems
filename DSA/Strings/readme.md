# 📚 Complete Guide to Strings in DSA & Competitive Programming

---

## 1. What is a String?
A **String** is a sequence of characters stored in contiguous memory locations.
It is one of the most important data structures used in competitive programming.

```
Example: "hello" → ['h', 'e', 'l', 'l', 'o']
Index:              [0,   1,   2,   3,   4  ]
```

---

## 2. String Basics

### Declaration
```cpp
// C++
string s = "hello";

# Python
s = "hello"

// Java
String s = "hello";
```

### Accessing Characters
```cpp
string s = "hello";
cout << s[0]; // 'h'
cout << s[4]; // 'o'
```

### Length of a String
```cpp
string s = "hello";
cout << s.length(); // 5
cout << s.size();   // 5
```

---

## 3. Important String Properties

| Property        | Description                                     |
| :-------------- | :---------------------------------------------- |
| Indexing        | Characters accessed by their position (0-based) |
| Immutability    | Strings are immutable in Python & Java          |
| Concatenation   | Joining two or more strings together            |
| Substring       | A contiguous part of a string                   |
| Palindrome      | A string that reads the same forwards/backwards |
| Anagram         | Two strings with the same character frequency   |

---

## 4. Common String Operations

### 4.1 Concatenation
```cpp
string s1 = "hello";
string s2 = " world";
string s3 = s1 + s2;
cout << s3; // "hello world"
```

### 4.2 Substring
```cpp
string s = "helloworld";
cout << s.substr(0, 5); // "hello"
cout << s.substr(5);    // "world"
//         substr(start, length)
```

### 4.3 Find / Search
```cpp
string s = "helloworld";
int pos = s.find("world");
cout << pos; // 5
// Returns string::npos if not found
```

### 4.4 Reverse a String
```cpp
string s = "hello";
reverse(s.begin(), s.end());
cout << s; // "olleh"
```

### 4.5 Convert to Upper / Lower Case
```cpp
string s = "Hello";
// To Upper
transform(s.begin(), s.end(), s.begin(), ::toupper);
cout << s; // "HELLO"

// To Lower
transform(s.begin(), s.end(), s.begin(), ::tolower);
cout << s; // "hello"
```

---

## 5. Core DSA Concepts in Strings

---

### 5.1 ✅ Palindrome Check

> A string is a **palindrome** if it reads the same forward and backward.

```
Example: "racecar" → Palindrome ✅
Example: "hello"   → Not a Palindrome ❌
```

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

---

### 5.2 ✅ Anagram Check

> Two strings are **anagrams** if they have the same characters with the same frequency.

```
Example: "listen" and "silent" → Anagram ✅
Example: "hello"  and "world"  → Not Anagram ❌
```

```cpp
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
```

---

### 5.3 ✅ Frequency Count (Using Hashing)

> Count how many times each character appears in a string.

```cpp
string s = "programming";
int freq[26] = {0};

for (char c : s) {
    freq[c - 'a']++;
}

for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
        cout << (char)(i + 'a') << " : " << freq[i] << "\n";
    }
}
```

---

### 5.4 ✅ Two Pointer Technique on Strings

> Use two pointers to solve problems efficiently in O(n) time.

**Problem:** Reverse only the vowels of a string.

```cpp
bool isVowel(char c) {
    return string("aeiouAEIOU").find(c) != string::npos;
}

string reverseVowels(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isVowel(s[left]))  left++;
        while (left < right && !isVowel(s[right])) right--;
        swap(s[left++], s[right--]);
    }
    return s;
}
```

---

### 5.5 ✅ Sliding Window Technique on Strings

> Use a window that slides across the string to find substrings efficiently.

**Problem:** Find the longest substring without repeating characters.

```
Example: "abcabcbb" → Answer: 3 ("abc")
Example: "pwwkew"   → Answer: 3 ("wke")
```

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (mp.count(s[right])) {
            left = max(left, mp[s[right]] + 1);
        }
        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

### 5.6 ✅ KMP Algorithm (Pattern Matching)

> Find a **pattern** inside a **text** efficiently in O(n + m) time.

```
Text:    "AABAACAADAABAABA"
Pattern: "AABA"
```

**Step 1: Build the LPS (Longest Prefix Suffix) Array**
```cpp
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}
```

**Step 2: Search Using LPS**
```cpp
void KMPSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }

        if (j == m) {
            cout << "Pattern found at index " << i - j << "\n";
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}
```

---

### 5.7 ✅ String Hashing (Rabin-Karp)

> Use hashing to compare substrings in O(1) time after O(n) preprocessing.

```cpp
long long computeHash(string s) {
    long long hash = 0;
    long long p = 31, mod = 1e9 + 9;
    long long p_pow = 1;

    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash;
}
```

---

## 6. Important String Problems for Competitive Programming

---

### 🔴 Beginner Level

| # | Problem                             | Key Concept          |
|---|-------------------------------------|----------------------|
| 1 | Reverse a String                    | Two Pointer          |
| 2 | Check if Palindrome                 | Two Pointer          |
| 3 | Check if Anagram                    | Sorting / Hashing    |
| 4 | Count Vowels and Consonants         | Frequency Count      |
| 5 | Remove Duplicates from a String     | Hashing              |

---

### 🟡 Intermediate Level

| # | Problem                                       | Key Concept          |
|---|-----------------------------------------------|----------------------|
| 1 | Longest Substring Without Repeating Characters| Sliding Window       |
| 2 | Longest Common Prefix                         | String Comparison    |
| 3 | Count and Say                                 | String Simulation    |
| 4 | Group Anagrams Together                       | HashMap + Sorting    |
| 5 | Minimum Window Substring                      | Sliding Window       |

---

### 🔴 Advanced Level

| # | Problem                                       | Key Concept          |
|---|-----------------------------------------------|----------------------|
| 1 | Pattern Matching (KMP / Z-Algorithm)          | KMP / Z-Function     |
| 2 | Longest Palindromic Substring                 | DP / Manacher's Algo |
| 3 | Shortest Palindrome                           | KMP                  |
| 4 | Distinct Subsequences                         | Dynamic Programming  |
| 5 | Suffix Array Construction                     | Suffix Array         |

---

## 7. Practice Questions

---

### ❓ Question 1 (Easy)
**Problem:** Given a string, check if it is a palindrome ignoring spaces and case.
```
Input:  "A man a plan a canal Panama"
Output: True
```

### ❓ Question 2 (Easy)
**Problem:** Count the frequency of each character in a string.
```
Input:  "programming"
Output: p:1, r:2, o:1, g:2, a:1, m:2, i:1, n:1
```

### ❓ Question 3 (Medium)
**Problem:** Find the longest substring with at most K distinct characters.
```
Input:  s = "eceba", K = 2
Output: 3 → ("ece")
```

### ❓ Question 4 (Medium)
**Problem:** Given two strings, find the minimum number of operations
(insert, delete, replace) to convert one string into another.
```
Input:  s1 = "horse", s2 = "ros"
Output: 3
```
> 💡 Hint: This is the classic **Edit Distance** problem → Use Dynamic Programming.

### ❓ Question 5 (Hard)
**Problem:** Given a string, find the longest palindromic substring.
```
Input:  "babad"
Output: "bab" or "aba"
```
> 💡 Hint: Use **Manacher's Algorithm** or **DP** for O(n) / O(n²) solutions.

---

## 8. Time Complexity Summary

| Operation                   | Time Complexity |
|-----------------------------|-----------------|
| Access a character          | O(1)            |
| Traverse a string           | O(n)            |
| Reverse a string            | O(n)            |
| Search (Naive)              | O(n × m)        |
| Search (KMP)                | O(n + m)        |
| Sorting a string            | O(n log n)      |
| Sliding Window              | O(n)            |
| Longest Palindrome (DP)     | O(n²)           |
| Longest Palindrome (Manacher)| O(n)           |

---

## 9. Tips & Tricks for Competitive Programming

> 💡 **Tip 1:** Always use `unordered_map` for frequency counting. It's O(1) average.

> 💡 **Tip 2:** For substring problems, always think of **Sliding Window** first.

> 💡 **Tip 3:** For pattern matching, always prefer **KMP** over the naive O(n×m) approach.

> 💡 **Tip 4:** For palindrome problems, think of **Two Pointers** or **Manacher's Algorithm**.

> 💡 **Tip 5:** When comparing substrings repeatedly, consider **String Hashing** for O(1) comparisons.

> 💡 **Tip 6:** Convert characters to integers using `c - 'a'` for lowercase letters (0 to 25).

---

## 10. Conclusion

Strings are one of the most versatile and widely tested topics in DSA and competitive
programming. Mastering the following concepts will make you highly efficient:

- ✅ Two Pointer Technique
- ✅ Sliding Window
- ✅ Frequency Hashing
- ✅ KMP / Z-Algorithm
- ✅ Dynamic Programming on Strings
- ✅ Suffix Arrays

> 🚀 **Practice consistently on platforms like LeetCode, Codeforces, and HackerRank
> to sharpen your string problem-solving skills!**