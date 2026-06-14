# 🎯 The Complete DSA Interview Master List

> A merged, de-duplicated, **pattern-first** checklist built from **Striver's A2Z Sheet**, **Striver's SDE Sheet**, **Striver's 79 Sheet**, and key **NeetCode 150** patterns — plus extra edge-case / variant problems that interviewers love.
>
> **Goal:** If you can solve every problem here and can explain *why* each pattern works, you'll be able to handle essentially anything thrown at you in a DSA round.

---

## 📖 How to Use This Sheet

1. **Go pattern-by-pattern, not random.** Each section teaches a *transferable technique*, not just a problem.
2. For each problem: (a) brute force, (b) optimize, (c) state time/space, (d) handle the **edge cases** listed for that section.
3. Re-solve anything you needed a hint for after 3–7 days (spaced repetition).
4. ✅ = comfortable solving from scratch in <20 min and explaining tradeoffs.

**Difficulty key:** 🟢 Easy · 🟡 Medium · 🔴 Hard
**Tag key:** `[MUST]` = top-frequency interview problem · `[PATTERN]` = the canonical example of a technique · `[EDGE]` = chosen to expose tricky edge cases

---

## 🗺️ Table of Contents

1. [Foundations & Complexity](#1-foundations--complexity)
2. [Math & Number Theory](#2-math--number-theory)
3. [Sorting Techniques](#3-sorting-techniques)
4. [Arrays](#4-arrays)
5. [Hashing & Frequency Maps](#5-hashing--frequency-maps)
6. [Two Pointers](#6-two-pointers)
7. [Sliding Window](#7-sliding-window)
8. [Prefix Sum & Difference Arrays](#8-prefix-sum--difference-arrays)
9. [Binary Search](#9-binary-search)
10. [Strings](#10-strings)
11. [Recursion & Backtracking](#11-recursion--backtracking)
12. [Bit Manipulation](#12-bit-manipulation)
13. [Linked List](#13-linked-list)
14. [Stacks & Queues (+ Monotonic Stack)](#14-stacks--queues--monotonic-stack)
15. [Greedy](#15-greedy)
16. [Heaps / Priority Queue](#16-heaps--priority-queue)
17. [Binary Trees](#17-binary-trees)
18. [Binary Search Trees](#18-binary-search-trees)
19. [Tries](#19-tries)
20. [Graphs](#20-graphs)
21. [Dynamic Programming](#21-dynamic-programming)
22. [Intervals](#22-intervals)
23. [Matrix / 2D Grid](#23-matrix--2d-grid)
24. [Design Problems](#24-design-problems)
25. [Math-Heavy / Misc Tricky](#25-math-heavy--misc-tricky)
26. [Universal Edge-Case Checklist](#-universal-edge-case-checklist)
27. [Pattern → "When to use" Cheat Sheet](#-pattern--when-to-use-cheat-sheet)

---

## 1. Foundations & Complexity

> Master these mentally before coding. Interviewers ask for complexity on *every* problem.

- [ ] Understand Big-O, Big-Θ, Big-Ω; best/avg/worst case
- [ ] Time complexity of common operations (array, hashmap, heap, BST, sort)
- [ ] Space complexity incl. recursion stack & implicit memory
- [ ] Amortized analysis (e.g., dynamic array push, hashmap)
- [ ] Reading input / printing output, fast I/O basics

🟢 [Print 1 to N / patterns (recursion warmup)](https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1)
🟢 [Star/Number pattern printing (20 patterns)](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/) `[PATTERN]`

---

## 2. Math & Number Theory

- [ ] 🟢 [Count digits of a number](https://www.geeksforgeeks.org/problems/count-digits5716/1)
- [ ] 🟢 [Reverse Integer (with overflow!)](https://leetcode.com/problems/reverse-integer/) `[EDGE]` `[MUST]`
- [ ] 🟢 [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
- [ ] 🟢 [Armstrong Number](https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1)
- [ ] 🟢 [GCD / HCF (Euclidean algorithm)](https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1) `[PATTERN]`
- [ ] 🟢 [All Divisors of a number](https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1)
- [ ] 🟢 [Check Prime](https://www.geeksforgeeks.org/problems/prime-number2314/1)
- [ ] 🟡 [Sieve of Eratosthenes](https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1) `[PATTERN]`
- [ ] 🟡 [Prime Factorization using Sieve (SPF)](https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1)
- [ ] 🟡 [Pow(x, n) — fast exponentiation](https://leetcode.com/problems/powx-n/) `[PATTERN]` `[EDGE]` (negative n, n=INT_MIN)
- [ ] 🟢 [Count primes < n](https://leetcode.com/problems/count-primes/)
- [ ] 🟡 [Modular exponentiation / modular arithmetic basics](https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1)

**Edge cases:** integer overflow, negative numbers, 0 and 1, INT_MIN/INT_MAX boundaries.

---

## 3. Sorting Techniques

> Know how to *write* these, their stability, and when each is used.

- [ ] 🟢 [Selection Sort](https://www.geeksforgeeks.org/problems/selection-sort/1)
- [ ] 🟢 [Bubble Sort](https://www.geeksforgeeks.org/problems/bubble-sort/1)
- [ ] 🟢 [Insertion Sort](https://www.geeksforgeeks.org/problems/insertion-sort/1)
- [ ] 🟡 [Merge Sort](https://www.geeksforgeeks.org/problems/merge-sort/1) `[PATTERN]` (basis for divide & conquer)
- [ ] 🟡 [Quick Sort](https://www.geeksforgeeks.org/problems/quick-sort/1) `[PATTERN]` (partition idea reused everywhere)
- [ ] 🟡 [Count Inversions (merge sort application)](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) `[MUST]`
- [ ] 🔴 [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/) `[MUST]`
- [ ] 🟡 [Sort Colors (Dutch National Flag)](https://leetcode.com/problems/sort-colors/) `[PATTERN]` `[MUST]`
- [ ] 🟡 [Custom comparator sorting (e.g., Largest Number)](https://leetcode.com/problems/largest-number/) `[PATTERN]`

**Edge cases:** already sorted, reverse sorted, all duplicates, single/empty input, stability requirements.

---

## 4. Arrays

### Easy
- [ ] 🟢 [Largest / Second Largest Element](https://www.geeksforgeeks.org/problems/second-largest3735/1) `[EDGE]` (duplicates of max)
- [ ] 🟢 [Check if array is sorted (and rotated)](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
- [ ] 🟢 [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) `[MUST]`
- [ ] 🟢 [Rotate Array by k](https://leetcode.com/problems/rotate-array/) `[PATTERN]` `[MUST]` (reversal algo)
- [ ] 🟢 [Move Zeroes](https://leetcode.com/problems/move-zeroes/) `[MUST]`
- [ ] 🟢 [Linear Search / Union of two sorted arrays](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)
- [ ] 🟢 [Missing Number](https://leetcode.com/problems/missing-number/) `[MUST]`
- [ ] 🟢 [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
- [ ] 🟢 [Single Number (every other twice)](https://leetcode.com/problems/single-number/) `[MUST]`

### Medium
- [ ] 🟡 [Two Sum](https://leetcode.com/problems/two-sum/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Best Time to Buy and Sell Stock I](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) `[MUST]`
- [ ] 🟡 [Kadane's — Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) `[MUST]` `[PATTERN]` (+ print the subarray)
- [ ] 🟡 [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) `[EDGE]` (negatives, zeros)
- [ ] 🟡 [Rearrange Array by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)
- [ ] 🟡 [Next Permutation](https://leetcode.com/problems/next-permutation/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Leaders in an Array](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1)
- [ ] 🟡 [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) `[MUST]`
- [ ] 🟡 [Majority Element (>n/2) — Boyer-Moore](https://leetcode.com/problems/majority-element/) `[PATTERN]` `[MUST]`
- [ ] 🟡 [Majority Element II (>n/3)](https://leetcode.com/problems/majority-element-ii/)
- [ ] 🟡 [3 Sum](https://leetcode.com/problems/3sum/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [4 Sum](https://leetcode.com/problems/4sum/)
- [ ] 🟡 [Subarray Sum Equals K (prefix + hashmap)](https://leetcode.com/problems/subarray-sum-equals-k/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Largest subarray with 0 sum](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)
- [ ] 🟡 [Count subarrays with given XOR K](https://www.geeksforgeeks.org/problems/subarray-with-given-xor/1)
- [ ] 🟡 [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) `[MUST]` `[EDGE]` (no division, zeros)

### Hard
- [ ] 🔴 [Merge Intervals](https://leetcode.com/problems/merge-intervals/) `[MUST]` (also in Intervals §22)
- [ ] 🔴 [Merge Sorted Arrays in-place (no extra space)](https://leetcode.com/problems/merge-sorted-array/) `[EDGE]` `[MUST]`
- [ ] 🔴 [Find the Duplicate Number (no modify, O(1) space)](https://leetcode.com/problems/find-the-duplicate-number/) `[PATTERN]` (Floyd's)
- [ ] 🔴 [Find Missing and Repeating](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)
- [ ] 🔴 [Maximum Subarray Sum after one deletion / Count subarrays w/ sum](https://leetcode.com/problems/binary-subarrays-with-sum/)

**Edge cases:** empty array, single element, all same, all negative, overflow on sums/products, in-place vs extra space constraints.

---

## 5. Hashing & Frequency Maps

- [ ] 🟢 [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) `[MUST]`
- [ ] 🟢 [Valid Anagram](https://leetcode.com/problems/valid-anagram/) `[MUST]`
- [ ] 🟡 [Group Anagrams](https://leetcode.com/problems/group-anagrams/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) `[MUST]` (heap + bucket sort)
- [ ] 🟡 [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) `[PATTERN]`
- [ ] 🟡 [Count number of distinct elements in every window](https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)
- [ ] 🟢 [Frequency of array elements / highest-lowest freq](https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1)

**Edge cases:** hash collisions in custom keys, unicode/case sensitivity, negative numbers as keys.

---

## 6. Two Pointers

- [ ] 🟢 [Reverse String / Array in place](https://leetcode.com/problems/reverse-string/) `[PATTERN]`
- [ ] 🟢 [Valid Palindrome (alphanumeric only)](https://leetcode.com/problems/valid-palindrome/) `[MUST]` `[EDGE]`
- [ ] 🟡 [Two Sum II (sorted, two pointers)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) `[PATTERN]`
- [ ] 🟡 [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) `[MUST]` `[PATTERN]` (two-pointer / stack / prefix)
- [ ] 🟡 [Remove Duplicates II (keep at most 2)](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)
- [ ] 🟡 [3Sum Closest](https://leetcode.com/problems/3sum-closest/)
- [ ] 🟡 [Sort array of 0s,1s,2s](https://leetcode.com/problems/sort-colors/) (DNF — also §3)

**Edge cases:** pointers crossing, duplicate skipping, empty/one element.

---

## 7. Sliding Window

> **Fixed-size** vs **variable-size (expand/shrink)** — recognize which.

- [ ] 🟢 [Maximum Average Subarray I (fixed)](https://leetcode.com/problems/maximum-average-subarray-i/) `[PATTERN]`
- [ ] 🟡 [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Max Consecutive Ones III (flip ≤k zeros)](https://leetcode.com/problems/max-consecutive-ones-iii/) `[MUST]`
- [ ] 🟡 [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) `[MUST]`
- [ ] 🟡 [Fruit Into Baskets (≤2 distinct)](https://leetcode.com/problems/fruit-into-baskets/)
- [ ] 🟡 [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)
- [ ] 🟡 [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)
- [ ] 🟡 [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
- [ ] 🟡 [Subarray with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) `[PATTERN]` (atMost trick)
- [ ] 🟡 [Maximum Points From Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
- [ ] 🔴 [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Sliding Window Maximum (deque)](https://leetcode.com/problems/sliding-window-maximum/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Longest Substring with At Most K Distinct](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

**Edge cases:** window larger than array, all identical chars, k=0, shrinking past start.

---

## 8. Prefix Sum & Difference Arrays

- [ ] 🟢 [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/) `[PATTERN]`
- [ ] 🟡 [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) (also §4)
- [ ] 🟡 [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) `[PATTERN]`
- [ ] 🟡 [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) `[PATTERN]`
- [ ] 🟡 [Contiguous Array (equal 0s & 1s)](https://leetcode.com/problems/contiguous-array/)
- [ ] 🟡 [Corporate Flight Bookings (difference array)](https://leetcode.com/problems/corporate-flight-bookings/) `[PATTERN]`
- [ ] 🟡 [Pivot Index](https://leetcode.com/problems/find-pivot-index/)

---

## 9. Binary Search

### On arrays
- [ ] 🟢 [Binary Search (template)](https://leetcode.com/problems/binary-search/) `[PATTERN]` `[EDGE]` (mid overflow: `lo+(hi-lo)/2`)
- [ ] 🟢 [Lower Bound / Upper Bound / Floor / Ceil](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1) `[PATTERN]`
- [ ] 🟡 [First & Last Position of Element](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) `[MUST]`
- [ ] 🟡 [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Search in Rotated Sorted Array II (dups)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) `[EDGE]`
- [ ] 🟡 [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) `[MUST]`
- [ ] 🟡 [Single Element in Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
- [ ] 🟡 [Find Peak Element](https://leetcode.com/problems/find-peak-element/) `[PATTERN]`

### Binary search on answer (search space)
- [ ] 🟢 [Sqrt(x) / Nth root](https://leetcode.com/problems/sqrtx/) `[PATTERN]`
- [ ] 🟡 [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Capacity to Ship Packages in D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) `[MUST]`
- [ ] 🟡 [Minimum Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)
- [ ] 🟡 [Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
- [ ] 🔴 [Aggressive Cows](https://www.geeksforgeeks.org/problems/aggressive-cows/1) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Book Allocation / Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Painter's Partition](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1)
- [ ] 🔴 [Minimize Max Distance to Gas Station](https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1)
- [ ] 🔴 [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Kth Element of Two Sorted Arrays](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)

### Binary search on 2D
- [ ] 🟡 [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) `[MUST]`
- [ ] 🟡 [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) `[PATTERN]`
- [ ] 🔴 [Row with Max 1s](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1)
- [ ] 🔴 [Median in a Row-wise Sorted Matrix](https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)
- [ ] 🟡 [Find Peak Element II](https://leetcode.com/problems/find-a-peak-element-ii/)

**Edge cases:** off-by-one in lo/hi/mid, mid overflow, duplicates, empty array, target not present, inclusive vs exclusive bounds.

---

## 10. Strings

### Basic / Medium
- [ ] 🟢 [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) `[EDGE]` (extra spaces)
- [ ] 🟢 [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)
- [ ] 🟢 [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) `[MUST]`
- [ ] 🟢 [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
- [ ] 🟡 [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) `[EDGE]` `[MUST]` (whitespace, sign, overflow)
- [ ] 🟡 [Rotate String / Rotate by k](https://leetcode.com/problems/rotate-string/)
- [ ] 🟡 [Sort Characters by Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [ ] 🟡 [Roman to Integer & Integer to Roman](https://leetcode.com/problems/roman-to-integer/)
- [ ] 🟡 [Count and Say](https://leetcode.com/problems/count-and-say/)
- [ ] 🟡 [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) `[MUST]` `[PATTERN]` (expand around center)
- [ ] 🟡 [Palindromic Substrings (count)](https://leetcode.com/problems/palindromic-substrings/)

### Pattern Matching / Advanced
- [ ] 🟡 [Implement strStr() (naive)](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) `[MUST]`
- [ ] 🔴 [KMP — Longest Prefix Suffix (LPS)](https://leetcode.com/problems/shortest-palindrome/) `[PATTERN]`
- [ ] 🔴 [Repeated String Match / Z-function basics](https://leetcode.com/problems/repeated-substring-pattern/)
- [ ] 🔴 [Minimum Insertions to Make Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

**Edge cases:** empty string, single char, all same char, leading/trailing/multiple spaces, case sensitivity, unicode.

---

## 11. Recursion & Backtracking

### Recursion fundamentals
- [ ] 🟢 [Fibonacci / Factorial recursively](https://www.geeksforgeeks.org/problems/print-fibonacci-series/1) `[PATTERN]`
- [ ] 🟢 [Sum/Reverse of array recursively, Check palindrome](https://www.geeksforgeeks.org/problems/sum-of-elements-in-recursive-way/1)
- [ ] 🟢 [Power Set (all subsequences)](https://leetcode.com/problems/subsets/) `[PATTERN]` `[MUST]`

### Subsets / Combinations
- [ ] 🟡 [Subsets II (with duplicates)](https://leetcode.com/problems/subsets-ii/) `[EDGE]`
- [ ] 🟡 [Combination Sum](https://leetcode.com/problems/combination-sum/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) `[EDGE]`
- [ ] 🟡 [Combinations](https://leetcode.com/problems/combinations/)
- [ ] 🟡 [Subsequence sum == K / count subsequences](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)
- [ ] 🟡 [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) `[MUST]`

### Permutations
- [ ] 🟡 [Permutations](https://leetcode.com/problems/permutations/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Permutations II (duplicates)](https://leetcode.com/problems/permutations-ii/) `[EDGE]`

### Grid / Constraint backtracking
- [ ] 🟡 [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) `[MUST]`
- [ ] 🟡 [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) `[MUST]`
- [ ] 🟡 [Word Search](https://leetcode.com/problems/word-search/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [N-Queens](https://leetcode.com/problems/n-queens/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Rat in a Maze / All paths](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
- [ ] 🔴 [Word Break II](https://leetcode.com/problems/word-break-ii/)
- [ ] 🔴 [M-Coloring Problem](https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)
- [ ] 🔴 [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)

**Edge cases:** duplicate handling (sort + skip), pruning, base case correctness, restoring state (backtrack), empty input.

---

## 12. Bit Manipulation

- [ ] 🟢 [Get/Set/Clear/Toggle i-th bit](https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1) `[PATTERN]`
- [ ] 🟢 [Check if power of two](https://leetcode.com/problems/power-of-two/)
- [ ] 🟢 [Number of 1 Bits (Hamming weight)](https://leetcode.com/problems/number-of-1-bits/) `[MUST]`
- [ ] 🟢 [Counting Bits 0..n](https://leetcode.com/problems/counting-bits/) `[PATTERN]`
- [ ] 🟢 [Single Number (XOR)](https://leetcode.com/problems/single-number/) `[MUST]`
- [ ] 🟡 [Single Number II (appears 3x)](https://leetcode.com/problems/single-number-ii/) `[EDGE]`
- [ ] 🟡 [Single Number III (two unique)](https://leetcode.com/problems/single-number-iii/)
- [ ] 🟡 [Subsets using bitmask](https://leetcode.com/problems/subsets/)
- [ ] 🟡 [XOR of numbers in a range / 1..n](https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1)
- [ ] 🟡 [Divide Two Integers (no `/`)](https://leetcode.com/problems/divide-two-integers/) `[EDGE]` `[MUST]` (overflow)
- [ ] 🟡 [Reverse Bits](https://leetcode.com/problems/reverse-bits/)
- [ ] 🟡 [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)
- [ ] 🟡 [Sum of Two Integers (no + or -)](https://leetcode.com/problems/sum-of-two-integers/)

**Edge cases:** negative numbers / two's complement, signed shift, INT_MIN, 32 vs 64 bit.

---

## 13. Linked List

### Singly
- [ ] 🟢 [Reverse a Linked List (iterative + recursive)](https://leetcode.com/problems/reverse-linked-list/) `[MUST]` `[PATTERN]`
- [ ] 🟢 [Middle of the Linked List (slow/fast)](https://leetcode.com/problems/middle-of-the-linked-list/) `[MUST]` `[PATTERN]`
- [ ] 🟢 [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) `[MUST]`
- [ ] 🟢 [Remove Nth Node From End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) `[MUST]` `[EDGE]` (remove head)
- [ ] 🟢 [Delete Node Given Only That Node](https://leetcode.com/problems/delete-node-in-a-linked-list/)
- [ ] 🟢 [Linked List Cycle (detect)](https://leetcode.com/problems/linked-list-cycle/) `[MUST]` `[PATTERN]` (Floyd)
- [ ] 🟡 [Linked List Cycle II (find start)](https://leetcode.com/problems/linked-list-cycle-ii/) `[MUST]`
- [ ] 🟡 [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) `[MUST]`
- [ ] 🟡 [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) `[MUST]` `[EDGE]` (carry)
- [ ] 🟡 [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)
- [ ] 🟡 [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)
- [ ] 🟡 [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [ ] 🟡 [Sort List (merge sort on LL)](https://leetcode.com/problems/sort-list/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Rotate List](https://leetcode.com/problems/rotate-list/)
- [ ] 🟡 [Reorder List](https://leetcode.com/problems/reorder-list/) `[MUST]`
- [ ] 🟡 [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) `[MUST]`
- [ ] 🟡 [Partition List](https://leetcode.com/problems/partition-list/)

### Doubly / Special
- [ ] 🟡 [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
- [ ] 🔴 [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) `[MUST]` (heap)
- [ ] 🔴 [Flatten a Linked List (sorted)](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

**Edge cases:** empty list, single node, two nodes, even vs odd length, head/tail removal, cycle present, dummy node usage.

---

## 14. Stacks & Queues (+ Monotonic Stack)

### Implementations & Basics
- [ ] 🟢 [Implement Stack using Arrays / Queue](https://leetcode.com/problems/implement-stack-using-queues/) `[PATTERN]`
- [ ] 🟢 [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) `[PATTERN]`
- [ ] 🟢 [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) `[MUST]` `[PATTERN]`
- [ ] 🟢 [Min Stack](https://leetcode.com/problems/min-stack/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Implement Deque / Circular Queue](https://leetcode.com/problems/design-circular-queue/)

### Expression Conversion
- [ ] 🟡 [Infix → Postfix](https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1) `[PATTERN]`
- [ ] 🟡 [Prefix ↔ Postfix ↔ Infix conversions](https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1)
- [ ] 🟡 [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) `[MUST]`
- [ ] 🔴 [Basic Calculator I / II](https://leetcode.com/problems/basic-calculator/) `[MUST]`

### Monotonic Stack
- [ ] 🟡 [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) `[PATTERN]` `[MUST]`
- [ ] 🟡 [Next Greater Element II (circular)](https://leetcode.com/problems/next-greater-element-ii/) `[EDGE]`
- [ ] 🟡 [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) `[MUST]`
- [ ] 🟡 [Online Stock Span](https://leetcode.com/problems/online-stock-span/)
- [ ] 🟡 [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) `[PATTERN]`
- [ ] 🟡 [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)
- [ ] 🟡 [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) `[MUST]`
- [ ] 🟡 [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) `[MUST]`
- [ ] 🔴 [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) `[MUST]`
- [ ] 🔴 [Trapping Rain Water (stack approach)](https://leetcode.com/problems/trapping-rain-water/)
- [ ] 🔴 [The Celebrity Problem](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1) `[MUST]`
- [ ] 🔴 [Sliding Window Maximum (deque)](https://leetcode.com/problems/sliding-window-maximum/)

**Edge cases:** empty stack pop/peek, unmatched brackets, single operand, circular wrap, ties in monotonic stack.

---

## 15. Greedy

- [ ] 🟢 [Assign Cookies](https://leetcode.com/problems/assign-cookies/) `[PATTERN]`
- [ ] 🟢 [Lemonade Change](https://leetcode.com/problems/lemonade-change/)
- [ ] 🟡 [Jump Game](https://leetcode.com/problems/jump-game/) `[MUST]`
- [ ] 🟡 [Jump Game II](https://leetcode.com/problems/jump-game-ii/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Gas Station](https://leetcode.com/problems/gas-station/) `[MUST]`
- [ ] 🟡 [Candy](https://leetcode.com/problems/candy/) `[MUST]`
- [ ] 🟡 [N Meetings in One Room / Activity Selection](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1) `[PATTERN]`
- [ ] 🟡 [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) `[MUST]`
- [ ] 🟡 [Minimum Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
- [ ] 🟡 [Insert Interval](https://leetcode.com/problems/insert-interval/) `[MUST]`
- [ ] 🟡 [Fractional Knapsack](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1) `[PATTERN]`
- [ ] 🟡 [Job Sequencing Problem](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1) `[MUST]`
- [ ] 🟡 [Task Scheduler](https://leetcode.com/problems/task-scheduler/) `[MUST]`
- [ ] 🟡 [Minimum Platforms](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1) `[MUST]`
- [ ] 🔴 [Huffman Encoding](https://www.geeksforgeeks.org/problems/huffman-encoding3345/1) `[PATTERN]`

**Edge cases:** ties (need a tiebreak rule), proving greedy is correct (exchange argument), empty input, equal weights/values.

---

## 16. Heaps / Priority Queue

- [ ] 🟢 [Min Heap / Max Heap implementation + heapify](https://www.geeksforgeeks.org/problems/heap-sort/1) `[PATTERN]`
- [ ] 🟡 [Kth Largest Element in Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) `[MUST]` `[PATTERN]` (also Quickselect)
- [ ] 🟡 [Kth Smallest Element](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1)
- [ ] 🟡 [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) `[MUST]`
- [ ] 🟡 [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) `[MUST]`
- [ ] 🟡 [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [ ] 🟡 [Task Scheduler (heap)](https://leetcode.com/problems/task-scheduler/)
- [ ] 🟡 [Reorganize String](https://leetcode.com/problems/reorganize-string/) `[MUST]`
- [ ] 🟡 [Hand of Straights](https://leetcode.com/problems/hand-of-straights/)
- [ ] 🔴 [Merge K Sorted Lists / Arrays](https://leetcode.com/problems/merge-k-sorted-lists/) `[MUST]`
- [ ] 🔴 [Find Median from Data Stream (two heaps)](https://leetcode.com/problems/find-median-from-data-stream/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Smallest Range Covering K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
- [ ] 🟡 [IPO / Maximize Capital](https://leetcode.com/problems/ipo/)

**Edge cases:** k > n, duplicates, empty stream, custom comparators, stability.

---

## 17. Binary Trees

### Traversals
- [ ] 🟢 [Inorder / Preorder / Postorder (recursive)](https://leetcode.com/problems/binary-tree-inorder-traversal/) `[PATTERN]`
- [ ] 🟡 [Iterative Inorder / Preorder / Postorder](https://leetcode.com/problems/binary-tree-postorder-traversal/) `[MUST]`
- [ ] 🟡 [Level Order Traversal (BFS)](https://leetcode.com/problems/binary-tree-level-order-traversal/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Zigzag Level Order](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) `[MUST]`
- [ ] 🔴 [Morris Inorder/Preorder (O(1) space)](https://leetcode.com/problems/binary-tree-inorder-traversal/) `[PATTERN]`
- [ ] 🟡 [All traversals in one pass](https://www.geeksforgeeks.org/problems/preorder-inorder-and-postorder/1)

### Properties
- [ ] 🟢 [Maximum Depth / Height](https://leetcode.com/problems/maximum-depth-of-binary-tree/) `[MUST]`
- [ ] 🟢 [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) `[MUST]`
- [ ] 🟡 [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) `[MUST]` `[PATTERN]`
- [ ] 🟢 [Same Tree](https://leetcode.com/problems/same-tree/)
- [ ] 🟢 [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) `[MUST]`
- [ ] 🟢 [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) `[MUST]`
- [ ] 🟡 [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

### Views & Special
- [ ] 🟡 [Right / Left Side View](https://leetcode.com/problems/binary-tree-right-side-view/) `[MUST]`
- [ ] 🟡 [Top View / Bottom View](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
- [ ] 🟡 [Vertical Order Traversal](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
- [ ] 🟡 [Boundary Traversal](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1) `[EDGE]`
- [ ] 🟡 [Path Sum / Path Sum II / Root-to-leaf paths](https://leetcode.com/problems/path-sum-ii/)
- [ ] 🟡 [Lowest Common Ancestor](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) `[MUST]`
- [ ] 🟡 [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)
- [ ] 🔴 [Burning Tree / Minimum time to burn](https://www.geeksforgeeks.org/problems/burning-tree/1)

### Construction & Serialization
- [ ] 🟡 [Build Tree from Preorder + Inorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Build Tree from Inorder + Postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
- [ ] 🔴 [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) `[MUST]`
- [ ] 🟡 [Populate Next Right Pointers](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

**Edge cases:** null root, single node, skewed tree (recursion depth), duplicate values, unbalanced.

---

## 18. Binary Search Trees

- [ ] 🟢 [Search in a BST](https://leetcode.com/problems/search-in-a-binary-search-tree/) `[PATTERN]`
- [ ] 🟢 [Insert into a BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
- [ ] 🟡 [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) `[MUST]` `[EDGE]`
- [ ] 🟢 [Min/Max value in BST](https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1)
- [ ] 🟡 [Floor / Ceil in BST](https://www.geeksforgeeks.org/problems/floor-in-bst/1)
- [ ] 🟡 [Kth Smallest / Largest in BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) `[MUST]`
- [ ] 🟡 [Validate BST](https://leetcode.com/problems/validate-binary-search-tree/) `[MUST]` `[EDGE]` (use range, watch INT limits)
- [ ] 🟡 [LCA in a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) `[MUST]`
- [ ] 🟡 [Inorder Successor / Predecessor in BST](https://www.geeksforgeeks.org/problems/predecessor-and-successor/1)
- [ ] 🟡 [BST Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) `[PATTERN]`
- [ ] 🟡 [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
- [ ] 🟡 [Convert Sorted Array to BST](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) `[MUST]`
- [ ] 🔴 [Recover BST (two swapped nodes)](https://leetcode.com/problems/recover-binary-search-tree/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Largest BST in Binary Tree](https://www.geeksforgeeks.org/problems/largest-bst/1)

**Edge cases:** duplicate keys policy, INT_MIN/INT_MAX bounds in validation, deleting node with 0/1/2 children, empty tree.

---

## 19. Tries

- [ ] 🟡 [Implement Trie (Insert/Search/StartsWith)](https://leetcode.com/problems/implement-trie-prefix-tree/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Implement Trie II (count words / prefixes)](https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1)
- [ ] 🟡 [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)
- [ ] 🟡 [Replace Words (root prefix)](https://leetcode.com/problems/replace-words/)
- [ ] 🔴 [Design Add and Search Words (`.` wildcard)](https://leetcode.com/problems/design-add-and-search-words-data-structure/) `[MUST]`
- [ ] 🔴 [Word Search II (Trie + DFS)](https://leetcode.com/problems/word-search-ii/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Maximum XOR of Two Numbers (bit trie)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

**Edge cases:** empty string, prefix vs full word, deletion, large alphabet, case sensitivity.

---

## 20. Graphs

### Representation & Traversal
- [ ] 🟢 [BFS of graph](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1) `[PATTERN]`
- [ ] 🟢 [DFS of graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1) `[PATTERN]`
- [ ] 🟡 [Number of Provinces (connected components)](https://leetcode.com/problems/number-of-provinces/) `[MUST]`
- [ ] 🟡 [Number of Islands](https://leetcode.com/problems/number-of-islands/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Flood Fill](https://leetcode.com/problems/flood-fill/) `[MUST]`
- [ ] 🟡 [Rotting Oranges (multi-source BFS)](https://leetcode.com/problems/rotting-oranges/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [0/1 Matrix (distance to nearest 0)](https://leetcode.com/problems/01-matrix/) `[MUST]`
- [ ] 🟡 [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) `[MUST]`
- [ ] 🟡 [Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)
- [ ] 🟡 [Number of Distinct Islands](https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1)
- [ ] 🟡 [Word Ladder](https://leetcode.com/problems/word-ladder/) `[MUST]` (BFS shortest path)
- [ ] 🔴 [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)

### Cycle Detection & Bipartite
- [ ] 🟡 [Detect Cycle in Undirected Graph (BFS + DFS)](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1) `[MUST]`
- [ ] 🟡 [Detect Cycle in Directed Graph (DFS)](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1) `[MUST]`
- [ ] 🟡 [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) `[MUST]` `[PATTERN]`

### Topological Sort
- [ ] 🟡 [Topological Sort (DFS)](https://www.geeksforgeeks.org/problems/topological-sort/1) `[PATTERN]`
- [ ] 🟡 [Kahn's Algorithm (BFS topo)](https://www.geeksforgeeks.org/problems/topological-sort/1) `[PATTERN]`
- [ ] 🟡 [Course Schedule I](https://leetcode.com/problems/course-schedule/) `[MUST]`
- [ ] 🟡 [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) `[MUST]`
- [ ] 🔴 [Alien Dictionary](https://www.geeksforgeeks.org/problems/alien-dictionary/1) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)

### Shortest Path
- [ ] 🟡 [Shortest Path in Unweighted Graph (BFS)](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)
- [ ] 🟡 [Shortest Path in DAG (topo)](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)
- [ ] 🟡 [Dijkstra's Algorithm](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Network Delay Time](https://leetcode.com/problems/network-delay-time/) `[MUST]`
- [ ] 🟡 [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) `[MUST]` (Bellman-Ford style)
- [ ] 🟡 [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) `[PATTERN]`
- [ ] 🟡 [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/)
- [ ] 🟡 [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)
- [ ] 🔴 [Bellman-Ford Algorithm](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1) `[PATTERN]`
- [ ] 🔴 [Floyd-Warshall (all pairs)](https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1) `[PATTERN]`
- [ ] 🔴 [Find the City With Smallest Number of Neighbours](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

### MST & Union-Find
- [ ] 🟡 [Disjoint Set (Union by rank + path compression)](https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Prim's Algorithm (MST)](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1) `[PATTERN]`
- [ ] 🟡 [Kruskal's Algorithm (MST)](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1) `[PATTERN]`
- [ ] 🟡 [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
- [ ] 🟡 [Accounts Merge](https://leetcode.com/problems/accounts-merge/) `[MUST]`
- [ ] 🟡 [Most Stones Removed](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
- [ ] 🔴 [Making a Large Island](https://leetcode.com/problems/making-a-large-island/)
- [ ] 🔴 [Redundant Connection](https://leetcode.com/problems/redundant-connection/) `[MUST]`

### Advanced
- [ ] 🔴 [Bridges in Graph (Tarjan)](https://leetcode.com/problems/critical-connections-in-a-network/) `[PATTERN]`
- [ ] 🔴 [Articulation Points](https://www.geeksforgeeks.org/problems/articulation-point-1/1)
- [ ] 🔴 [Strongly Connected Components (Kosaraju)](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1) `[PATTERN]`

**Edge cases:** disconnected components, self-loops, multi-edges, single node, directed vs undirected, negative weights (Dijkstra fails), visited tracking.

---

## 21. Dynamic Programming

> Learn the **patterns**, then variations follow. Always: define state → recurrence → base case → memo → tabulate → space-optimize.

### 1D / Intro
- [ ] 🟢 [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Frog Jump (min cost)](https://www.geeksforgeeks.org/problems/geek-jump/1) `[PATTERN]`
- [ ] 🟡 [House Robber](https://leetcode.com/problems/house-robber/) `[MUST]`
- [ ] 🟡 [House Robber II (circular)](https://leetcode.com/problems/house-robber-ii/) `[EDGE]`

### Grid DP
- [ ] 🟡 [Unique Paths](https://leetcode.com/problems/unique-paths/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Unique Paths II (obstacles)](https://leetcode.com/problems/unique-paths-ii/)
- [ ] 🟡 [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) `[MUST]`
- [ ] 🟡 [Triangle](https://leetcode.com/problems/triangle/)
- [ ] 🔴 [Cherry Pickup II / Chocolate pickup](https://leetcode.com/problems/cherry-pickup-ii/) `[PATTERN]`
- [ ] 🔴 [Dungeon Game](https://leetcode.com/problems/dungeon-game/) `[EDGE]`

### Subsequence / Knapsack
- [ ] 🟡 [0/1 Knapsack](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Subset Sum equals target](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1) `[PATTERN]`
- [ ] 🟡 [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) `[MUST]`
- [ ] 🟡 [Partition Set Into Two Subsets w/ Min Diff](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)
- [ ] 🟡 [Count Subsets with Sum K](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)
- [ ] 🟡 [Target Sum](https://leetcode.com/problems/target-sum/)
- [ ] 🟡 [Coin Change (min coins)](https://leetcode.com/problems/coin-change/) `[MUST]` `[PATTERN]` (unbounded)
- [ ] 🟡 [Coin Change II (count ways)](https://leetcode.com/problems/coin-change-ii/) `[MUST]`
- [ ] 🟡 [Unbounded Knapsack / Rod Cutting](https://www.geeksforgeeks.org/problems/rod-cutting0840/1) `[PATTERN]`
- [ ] 🔴 [Combination Sum IV (order matters)](https://leetcode.com/problems/combination-sum-iv/) `[EDGE]`

### Strings DP
- [ ] 🟡 [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Print LCS](https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1)
- [ ] 🟡 [Longest Common Substring](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)
- [ ] 🟡 [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) `[MUST]`
- [ ] 🟡 [Minimum Insertions/Deletions to Make Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
- [ ] 🟡 [Edit Distance](https://leetcode.com/problems/edit-distance/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
- [ ] 🔴 [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) `[MUST]`
- [ ] 🔴 [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) `[MUST]`
- [ ] 🟡 [Word Break](https://leetcode.com/problems/word-break/) `[MUST]`
- [ ] 🟡 [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/)

### LIS family
- [ ] 🟡 [Longest Increasing Subsequence (n²)](https://leetcode.com/problems/longest-increasing-subsequence/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [LIS in O(n log n) (binary search)](https://leetcode.com/problems/longest-increasing-subsequence/) `[PATTERN]`
- [ ] 🟡 [Print LIS](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)
- [ ] 🟡 [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
- [ ] 🟡 [Longest String Chain](https://leetcode.com/problems/longest-string-chain/)
- [ ] 🔴 [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)
- [ ] 🟡 [Number of LIS](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

### Stocks (state machine DP)
- [ ] 🟢 [Buy/Sell Stock I](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) `[MUST]`
- [ ] 🟡 [Buy/Sell Stock II (unlimited)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) `[PATTERN]`
- [ ] 🔴 [Buy/Sell Stock III (≤2 transactions)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) `[MUST]`
- [ ] 🔴 [Buy/Sell Stock IV (≤k)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) `[MUST]`
- [ ] 🟡 [With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) `[MUST]`
- [ ] 🟡 [With Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

### Partition DP / Interval DP
- [ ] 🔴 [Matrix Chain Multiplication](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1) `[PATTERN]`
- [ ] 🔴 [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) `[MUST]`
- [ ] 🔴 [Burst Balloons](https://leetcode.com/problems/burst-balloons/) `[MUST]` `[PATTERN]`
- [ ] 🔴 [Palindrome Partitioning II (min cuts)](https://leetcode.com/problems/palindrome-partitioning-ii/) `[MUST]`
- [ ] 🔴 [Boolean Parenthesization](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)
- [ ] 🔴 [Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)

### DP on Squares / Misc
- [ ] 🟡 [Maximal Square](https://leetcode.com/problems/maximal-square/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)
- [ ] 🔴 [DP on Trees: House Robber III](https://leetcode.com/problems/house-robber-iii/) `[PATTERN]`
- [ ] 🔴 [DP with Bitmask: Travelling Salesman](https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1) `[PATTERN]`
- [ ] 🔴 [Digit DP: Count numbers with property](https://www.geeksforgeeks.org/problems/numbers-with-same-consecutive-differences/1)

**Edge cases:** empty inputs, single element, overflow on counts/sums (use long/mod), 1D vs 2D space optimization correctness, base-case initialization.

---

## 22. Intervals

- [ ] 🟡 [Merge Intervals](https://leetcode.com/problems/merge-intervals/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Insert Interval](https://leetcode.com/problems/insert-interval/) `[MUST]`
- [ ] 🟡 [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) `[MUST]`
- [ ] 🟡 [Meeting Rooms II (min rooms)](https://leetcode.com/problems/meeting-rooms-ii/) `[MUST]` `[PATTERN]`
- [ ] 🟢 [Meeting Rooms I](https://leetcode.com/problems/meeting-rooms/)
- [ ] 🟡 [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/)
- [ ] 🟡 [Employee Free Time](https://leetcode.com/problems/employee-free-time/)

**Edge cases:** touching intervals `[1,2],[2,3]`, fully nested, single interval, unsorted input, equal start/end.

---

## 23. Matrix / 2D Grid

- [ ] 🟡 [Set Matrix Zeroes (O(1) space)](https://leetcode.com/problems/set-matrix-zeroes/) `[MUST]` `[EDGE]`
- [ ] 🟡 [Rotate Image (90°)](https://leetcode.com/problems/rotate-image/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) `[MUST]` `[EDGE]`
- [ ] 🟡 [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)
- [ ] 🟡 [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [ ] 🟡 [Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/)
- [ ] 🟡 [Game of Life (in-place)](https://leetcode.com/problems/game-of-life/) `[EDGE]`
- [ ] 🟡 [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) `[MUST]`

**Edge cases:** non-square matrices, single row/column, empty matrix, in-place modification interference.

---

## 24. Design Problems

- [ ] 🟡 [LRU Cache](https://leetcode.com/problems/lru-cache/) `[MUST]` `[PATTERN]` (HashMap + DLL)
- [ ] 🔴 [LFU Cache](https://leetcode.com/problems/lfu-cache/) `[MUST]`
- [ ] 🟢 [Design HashMap / HashSet](https://leetcode.com/problems/design-hashmap/)
- [ ] 🟡 [Design Browser History](https://leetcode.com/problems/design-browser-history/)
- [ ] 🟡 [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) `[MUST]` `[PATTERN]`
- [ ] 🟡 [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)
- [ ] 🟡 [Design Twitter](https://leetcode.com/problems/design-twitter/)
- [ ] 🔴 [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/)
- [ ] 🔴 [All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/)

**Edge cases:** capacity 1, duplicate keys, eviction order on ties, concurrency assumptions (state them).

---

## 25. Math-Heavy / Misc Tricky

- [ ] 🟡 [Excel Sheet Column Number / Title](https://leetcode.com/problems/excel-sheet-column-number/)
- [ ] 🟡 [Happy Number](https://leetcode.com/problems/happy-number/) `[PATTERN]` (cycle detection)
- [ ] 🟡 [Multiply Strings](https://leetcode.com/problems/multiply-strings/) `[MUST]`
- [ ] 🟡 [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) `[EDGE]`
- [ ] 🟡 [Rand7 → Rand10 / probability](https://leetcode.com/problems/implement-rand10-using-rand7/)
- [ ] 🔴 [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
- [ ] 🟡 [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [ ] 🟡 [Shuffle an Array (Fisher-Yates)](https://leetcode.com/problems/shuffle-an-array/) `[PATTERN]`
- [ ] 🟡 [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/) `[PATTERN]`

---

## ✅ Universal Edge-Case Checklist

Run through these mentally **for every problem** before declaring done:

- [ ] **Empty input** (`[]`, `""`, `null`/`None`)
- [ ] **Single element** input
- [ ] **Two elements** (often exposes off-by-one)
- [ ] **All identical** elements
- [ ] **Already sorted** / **reverse sorted**
- [ ] **Negative numbers**, **zero**, **mix of signs**
- [ ] **Integer overflow** (sums, products, `mid`, multiplication) → use `long`/mod
- [ ] **Duplicates** — does the problem want them handled/skipped?
- [ ] **Max constraints** — does your complexity pass (10⁵? 10⁹?)
- [ ] **Boundary indices** — first/last element, off-by-one in loops
- [ ] **Recursion depth** — skewed trees / deep recursion → stack overflow?
- [ ] **Return type / format** — sorted? unique? indices vs values? 0 vs 1 indexed?
- [ ] **Ties** — explicit tiebreak rule (greedy/heap/sort)
- [ ] **Disconnected / unreachable** (graphs)
- [ ] **In-place constraint** vs extra space allowed

---

## 🧭 Pattern → "When to use" Cheat Sheet

| Signal in the problem | Likely pattern |
|---|---|
| Sorted array + find/target/condition | **Binary Search** |
| "min/max k-th", "top k", streaming | **Heap** |
| Contiguous subarray/substring, "longest/shortest with condition" | **Sliding Window** |
| Pair/triplet summing to target, in-place reorder | **Two Pointers** |
| Subarray sum / count = K | **Prefix Sum + HashMap** |
| "Next greater/smaller", histogram, span | **Monotonic Stack** |
| All combinations / permutations / "generate all" | **Backtracking** |
| "Number of ways", "min/max cost", overlapping subproblems | **Dynamic Programming** |
| Grid connectivity, shortest path unweighted | **BFS/DFS** |
| Weighted shortest path (non-neg) | **Dijkstra** |
| "Can finish given prerequisites", ordering | **Topological Sort** |
| Dynamic connectivity, merge groups | **Union-Find (DSU)** |
| Prefix/dictionary/autocomplete/max-XOR | **Trie** |
| Detect cycle / find middle in LL, O(1) space | **Fast & Slow Pointers** |
| Optimal local choice → global optimum | **Greedy** (prove it!) |
| Overlapping ranges / scheduling | **Intervals (sort + sweep)** |

---

## 📚 Source Sheets (for deeper video explanations)

- **Striver's A2Z DSA Sheet** (~455 problems, full A-to-Z): https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
- **Striver's SDE Sheet** (~191, interview-focused): https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/
- **Striver's 79 Sheet** (last-moment revision): https://takeuforward.org/dsa/strivers-79-last-moment-dsa-sheet-ace-interviews/
- **NeetCode 150** (pattern coverage): https://neetcode.io/practice

---

*Tip: Don't aim to "finish" — aim to be able to **re-derive** each pattern. 8–12 weeks of consistent practice (2–4 problems/day) through this list covers the vast majority of DSA interview rounds.*
