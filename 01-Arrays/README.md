# 01-Arrays

## Topic Introduction
An **Array** is a collection of items stored at contiguous memory locations. It is the most fundamental linear data structure, providing $O(1)$ time complexity for random access by index. Understanding arrays is critical because many advanced structures (heaps, hash tables, and string manipulations) are built on top of them.

---

## When to use
- When you need to store list-like data of fixed or dynamic size.
- When $O(1)$ fast random retrieval/lookup by index is necessary.
- When iterating sequentially over elements is required.
- As the base structure for algorithms involving sorting, searching, and partitioning.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Access** | $O(1)$ | Direct lookup via index |
| **Search** | $O(n)$ | Linear scan (unsorted array) |
| **Search** | $O(\log n)$ | Binary Search (sorted array) |
| **Insertion** | $O(n)$ | Requires shifting elements (unless at the end) |
| **Deletion** | $O(n)$ | Requires shifting elements (unless at the end) |

---

## Common Patterns
1. **Subarray / Subsequence generation**: Finding contiguous/non-contiguous portions of arrays.
2. **Two Pointers**: Moving pointers inwards or outwards (e.g., finding pairs, partitioning).
3. **Sliding Window**: Maintaining a window/subset of elements matching constraints.
4. **Prefix Sum**: Precomputing cumulative sums to answer range sum queries in $O(1)$.
5. **Kadane's Algorithm**: Finding maximum subarray sum in $O(n)$ time.
6. **Dutch National Flag / Sorting**: Partitioning arrays (e.g., sort 0s, 1s, 2s).

---

## Interview Tips
- Always check for **out-of-bounds** errors (underflow and overflow of indices).
- Clarify whether the input array is **sorted** or can contain **duplicates**.
- Consider whether the problem can be solved **in-place** to optimize space complexity to $O(1)$.
- If $O(n^2)$ is too slow, look for sorting $O(n \log n)$ or using hash maps/pointers for $O(n)$.

---

## Mistakes to Avoid
- **Off-by-One Errors**: Accessing `arr[len]` instead of `arr[len-1]`.
- **Modifying while iterating**: Modifying the array size inside a loop without updating indices.
- **Copying Arrays**: Passing arrays by value rather than reference in languages like C++, causing unnecessary $O(n)$ copy operations.

---

## Solved Problems Checklist

- [x] [Two Sum](./two_sum.cpp) | **Easy**
- [x] [Best Time to Buy and Sell Stock](./best_time_to_buy_and_sell_stock.cpp) | **Easy**
- [x] [Bubble Sort](./bubble_sort.cpp) | **Easy**
- [x] [Insertion Sort](./insertion_sort.cpp) | **Easy**
- [x] [Selection Sort](./selection_sort.cpp) | **Easy**
- [x] [Linear Search](./linear_search.cpp) | **Easy**
- [x] [Reverse Array](./reverse_array.cpp) | **Easy**
- [x] [Check if Array is Sorted](./check_sorted.cpp) | **Easy**
- [x] [Missing Number](./missing_number.cpp) | **Easy**
- [x] [Rotate Array Left by One](./rotate_array_left_by_one.cpp) | **Easy**
- [x] [Rotate Array by K](./rotate_array_by_k.cpp) | **Medium**
- [x] [Sum of Unique Elements](./sum_of_unique_elements.cpp) | **Easy**
- [x] [Running Sum of 1d Array](./running_sum_of_1d_array.cpp) | **Easy**
- [x] [Split an Array into Two Equal Sum Subarrays](./split_array_equal_sum.cpp) | **Easy**
- [x] [Push Zeros to End](./push_zeros_to_end.cpp) | **Easy**
- [x] [Maximum Difference Between Increasing Elements](./maximum_difference.cpp) | **Easy**
- [x] [Maximum Subarray (Kadane's Algorithm)](./maximum_subarray.cpp) | **Medium**
- [ ] Next Array Problem | **Medium**




