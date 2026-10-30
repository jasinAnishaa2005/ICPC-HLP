# C++ STL & COMPETITIVE PROGRAMMING CHEAT SHEET
================================================================================

A practical ICPC / Codeforces reference for C++ STL, algorithms, data structures,
problem-solving patterns, shortcuts, and complexity.

LEGEND
------
[!] Important       -> Common contest technique or frequent mistake
[O(1)]              -> Constant time
[O(log n)]          -> Logarithmic time
[O(n)]              -> Linear time
[O(n log n)]        -> Sorting-level time
TIP                 -> Practical contest advice

CONTENTS
--------
01. Essential C++ Template
02. Vector – Dynamic Array
03. unique() + erase() – Remove Duplicates
04. Sorting
05. Binary Search
06. Set + Multiset
07. Map + Unordered Map
08. String Functions
09. find() – STL Searching
10. accumulate() – Sum and Product
11. min(), max(), min_element(), max_element()
12. Prefix Sum
13. Two Pointers + Sliding Window
14. Stack
15. Queue + Deque
16. Priority Queue (Heap)
17. Pair + Tuple
18. STL Algorithms – Master List
19. Mathematical STL
20. Bit Manipulation + Bitmasking
21. Array + Utility Shortcuts
22. Advanced CP Containers
23. Important ICPC One-Liners
24. Time Complexity
25. Common ICPC Mistakes
26. Quick Self-Test + Priority Order

================================================================================

# C++ STL & COMPETITIVE PROGRAMMING CHEAT SHEET

A practical ICPC/Codeforces cheat sheet covering STL, algorithms, shortcuts, strings, vectors, binary search, sets, maps, prefix sums, sorting, searching, and mathematical functions.

I'll use short examples, explain what each function does, and show when to use it in a problem.

# 1. Essential C++ template

Use this as your default CP starting template.

```
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
```

Important shortcuts

| Shortcut  | Meaning                         |
| --------- | ------------------------------- |
| `ll`      | `long long`                     |
| `pb(x)`   | `push_back(x)`                  |
| `all(v)`  | Entire container                |
| `rall(v)` | Reverse iterators               |
| `sz(v)`   | Size                            |
| `mp(a,b)` | `make_pair(a,b)`                |
| `endl`    | Newline + flush (prefer `'\n'`) |
| `auto`    | Automatically detects type      |

# 2. Vector – Dynamic Array

A vector is an array that can grow or shrink dynamically.

```
vector<int> v = {4, 2, 7, 2, 9};
```

| Function         | Meaning             | Example                 |
| ---------------- | ------------------- | ----------------------- |
| `v.push_back(x)` | Add at end          | `v.push_back(10)`       |
| `v.pop_back()`   | Remove last         | `v.pop_back()`          |
| `v.size()`       | Number of elements  | `v.size()`              |
| `v.empty()`      | Check empty         | `v.empty()`             |
| `v.front()`      | First element       | `v.front()`             |
| `v.back()`       | Last element        | `v.back()`              |
| `v[i]`           | Access index        | `v[2]`                  |
| `v.at(i)`        | Safe indexed access | `v.at(2)`               |
| `v.clear()`      | Remove all          | `v.clear()`             |
| `v.resize(n)`    | Change size         | `v.resize(10)`          |
| `v.assign(n,x)`  | Fill n elements     | `v.assign(5,3)`         |
| `v.insert()`     | Insert element      | `v.insert(v.begin(),5)` |
| `v.erase()`      | Delete element      | `v.erase(v.begin())`    |
| `v.begin()`      | First iterator      | `v.begin()`             |
| `v.end()`        | After last iterator | `v.end()`               |

### Important examples

Sort ascending:

```
sort(v.begin(), v.end());
// 2 2 4 7 9
```

Sort descending:

```
sort(v.rbegin(), v.rend());
// 9 7 4 2 2
```

Reverse:

```
reverse(v.begin(), v.end());
```

Print everything:

```
for (int x : v)
    cout << x << " ";
```

Delete element at index 2:

```
v.erase(v.begin() + 2);
```

Delete all occurrences of 2:

```
v.erase(remove(v.begin(), v.end(), 2), v.end());
```

Remove duplicates:

```
sort(v.begin(), v.end());

v.erase(unique(v.begin(), v.end()), v.end());
```

This last combination is extremely important in ICPC.

# 3. `unique()` and `erase()` – Remove Duplicates

Suppose:

```
vector<int> v = {1, 2, 2, 3, 3, 4};
```

`unique()` moves consecutive duplicate elements to the end and returns the new logical end.

```
auto it = unique(v.begin(), v.end());
```

Then:

```
v.erase(it, v.end());
```

Result:

```
1 2 3 4
```

Always remember:

- `unique()` alone does not physically shrink the vector.
- `erase()` removes the unwanted tail.
- Sort first if you want to remove all duplicates, regardless of their original positions.

Shortcut:

```
sort(all(v));
v.erase(unique(all(v)), v.end());
```

# 4. Sorting – `sort()`

```
vector<int> v = {5, 1, 8, 2, 3};

sort(all(v));
```

Result: `1 2 3 5 8`

### Different sorting methods

```
sort(all(v));                 // Ascending
sort(rall(v));                // Descending
reverse(all(v));              // Reverse existing order
stable_sort(all(v));          // Preserve relative order of equals
```

### Sort pairs

```
vector<pair<int,int>> v = {
    {2, 5}, {1, 8}, {2, 3}
};

sort(all(v));
```

Result:

```
(1,8) (2,3) (2,5)
```

Pairs are sorted by first element, then second element.

### Custom comparator

Sort by second element:

```
sort(all(v), [](auto a, auto b) {
    return a.second < b.second;
});
```

Sort descending by first element:

```
sort(all(v), [](auto a, auto b) {
    return a.first > b.first;
});
```

CP use: Sorting intervals, greedy problems, scheduling, ranking, and two-pointer problems.

# 5. Binary Search

Binary search finds an element or a position in a sorted array in \\(O(\log n)\\).

```
vector<int> v = {1, 3, 5, 7, 9};
```

### 5.1 `binary_search()`

Checks whether an element exists.

```
binary_search(all(v), 5); // true
binary_search(all(v), 4); // false
```

Returns only `true` or `false`.

### 5.2 `lower_bound()`

Finds the first element greater than or equal to `x`.

```
auto it = lower_bound(all(v), 5);

cout << *it; // 5
```

### 5.3 `upper_bound()`

Finds the first element strictly greater than `x`.

```
auto it = upper_bound(all(v), 5);

cout << *it; // 7
```

### 5.4 Find index

```
int idx = lower_bound(all(v), 5) - v.begin();

cout << idx; // 2
```

### 5.5 Count occurrences

```
int cnt = upper_bound(all(v), 5)
        - lower_bound(all(v), 5);
```

Result: `1`

### Visual understanding

## Lower bound vs Upper bound

For a sorted array with repeated values:

    Index:        0   1   2   3   4   5   6
    Value:        1   3   5   5   5   7   9
                            ^           ^
                            |           |
                       lower_bound  upper_bound

    lower_bound(5) -> index 2 -> first value >= 5
    upper_bound(5) -> index 5 -> first value > 5

    Count of 5 = upper_bound(5) - lower_bound(5)
               = 5 - 2
               = 3


Sorted array

Target = 5

1

3

5

5

5

7

9

Lower

Index 2 – first element ≥ 5

Upper

Index 5 – first element > 5

Difference = 5 − 2 = 3 occurrences of 5.

### 5.6 Manual binary search

Very useful for ICPC problems involving minimum/maximum possible answers.

```
int l = 0, r = 1000000000;

while (l < r) {
    int mid = l + (r - l) / 2;

    if (check(mid))
        r = mid;
    else
        l = mid + 1;
}

cout << l;
```

This template finds the smallest value for which `check(mid)` is true, assuming the condition changes monotonically from false to true.

Remember: Binary search on answer is a major CP technique.

# 6. Set – Unique Sorted Elements

A `set` automatically stores unique elements in sorted order.

```
set<int> s = {4, 2, 2, 7, 1};
```

Result:

```
1 2 4 7
```

| Function           | Meaning                  |
| ------------------ | ------------------------ |
| `s.insert(x)`      | Insert                   |
| `s.erase(x)`       | Remove value             |
| `s.count(x)`       | Check existence (0 or 1) |
| `s.find(x)`        | Find iterator            |
| `s.size()`         | Number of elements       |
| `s.empty()`        | Check empty              |
| `s.clear()`        | Remove everything        |
| `s.begin()`        | Smallest element         |
| `s.end()`          | After largest            |
| `s.lower_bound(x)` | First element ≥ x        |
| `s.upper_bound(x)` | First element > x        |

Example:

```
set<int> s = {10, 20, 30};

s.insert(40);
s.erase(20);

if (s.count(30))
    cout << "Found";
```

### Find smallest element ≥ x

```
auto it = s.lower_bound(25);

if (it != s.end())
    cout << *it; // 30
```

### Multiset

Unlike set, multiset allows duplicates.

```
multiset<int> ms = {1, 2, 2, 3};

cout << ms.count(2); // 2
```

Remove only one occurrence:

```
auto it = ms.find(2);

if (it != ms.end())
    ms.erase(it);
```

Remove all occurrences:

```
ms.erase(2);
```

# 7. Map – Key and Value Storage

A map stores data in key-value pairs, sorted by key.

```
map<string, int> marks;

marks["Anisha"] = 90;
marks["Wasi"] = 85;
```

| Function            | Meaning           |
| ------------------- | ----------------- |
| `mp[key]`           | Access or create  |
| `mp.insert({k,v})`  | Insert pair       |
| `mp.erase(key)`     | Delete key        |
| `mp.count(key)`     | Check existence   |
| `mp.find(key)`      | Find iterator     |
| `mp.size()`         | Number of keys    |
| `mp.empty()`        | Check empty       |
| `mp.clear()`        | Remove everything |
| `mp.begin()`        | Smallest key      |
| `mp.lower_bound(k)` | First key ≥ k     |
| `mp.upper_bound(k)` | First key > k     |

### Frequency counting – extremely important

```
vector<int> v = {1, 2, 2, 3, 3, 3};

map<int,int> freq;

for (int x : v)
    freq[x]++;

for (auto p : freq)
    cout << p.first << " " << p.second << '\n';
```

Output:

```
1 1
2 2
3 3
```

### `unordered_map`

Average \\(O(1)\\) lookup and insertion.

```
unordered_map<int,int> mp;

mp[10]++;
mp[20]++;
mp[10]++;

cout << mp[10]; // 2
```

Unlike `map`, it does not maintain sorted keys.

| Container       | Order            | Average lookup  |
| --------------- | ---------------- | --------------- |
| `map`           | Sorted           | \\(O(\log n)\\) |
| `unordered_map` | Unordered        | \\(O(1)\\)      |
| `set`           | Sorted unique    | \\(O(\log n)\\) |
| `unordered_set` | Unordered unique | \\(O(1)\\)      |

# 8. String – Essential Functions

```
string s = "competitive";
```

| Function         | Meaning             | Example               |
| ---------------- | ------------------- | --------------------- |
| `s.size()`       | Length              | `s.size()`            |
| `s.length()`     | Length              | `s.length()`          |
| `s[i]`           | Character at index  | `s[0]`                |
| `s.front()`      | First character     | `s.front()`           |
| `s.back()`       | Last character      | `s.back()`            |
| `s.push_back(c)` | Add character       | `s.push_back('a')`    |
| `s.pop_back()`   | Remove last         | `s.pop_back()`        |
| `s.empty()`      | Check empty         | `s.empty()`           |
| `s.clear()`      | Clear string        | `s.clear()`           |
| `s.substr()`     | Extract substring   | `s.substr(2,4)`       |
| `s.find()`       | Find substring      | `s.find("pet")`       |
| `s.erase()`      | Delete characters   | `s.erase(2,3)`        |
| `s.insert()`     | Insert characters   | `s.insert(0,"Hi")`    |
| `s.replace()`    | Replace part        | `s.replace(0,2,"Hi")` |
| `s.compare()`    | Compare strings     | `s.compare("abc")`    |
| `s.c_str()`      | Convert to C-string | `s.c_str()`           |

### 8.1 `substr(pos, len)`

```
string s = "abcdef";

cout << s.substr(2, 3);
```

Output: `cde`

- First argument = starting index.
- Second argument = number of characters.

```
s.substr(2); // cdef
s.substr(0,3); // abc
s.substr(1,2); // bc
```

### 8.2 `find()`

```
string s = "hello world";

cout << s.find("world"); // 6
```

If not found:

```
if (s.find("abc") == string::npos)
    cout << "Not found";
```

Find character:

```
s.find('o');
```

Find last occurrence:

```
s.rfind('o');
```

Find from a specific position:

```
s.find("lo", 3);
```

### 8.3 String conversion

```
string s = to_string(12345);

int x = stoi("123");
long long y = stoll("123456789");
double d = stod("12.5");
```

### 8.4 Character shortcuts

```
isalpha(c);  // Is alphabet?
isdigit(c);  // Is digit?
isalnum(c);  // Is letter or digit?
islower(c);  // Is lowercase?
isupper(c);  // Is uppercase?
isspace(c);  // Is whitespace?

tolower(c);  // Lowercase
toupper(c);  // Uppercase
```

Convert entire string to lowercase:

```
for (char &c : s)
    c = tolower(c);
```

### 8.5 Reverse and sort strings

```
reverse(all(s));
sort(all(s));
```

### 8.6 Check palindrome

```
string s = "madam";

string t = s;
reverse(all(t));

if (s == t)
    cout << "Palindrome";
```

### 8.7 Count character frequency

```
int freq[26] = {};

for (char c : s)
    freq[c - 'a']++;
```

Use this for lowercase English letters.

# 9. `find()` – STL Searching

There are two commonly used `find()` functions.

### A. `find()` from algorithm

Works with vectors, arrays, strings, and other iterator-based containers.

```
vector<int> v = {10, 20, 30};

auto it = find(all(v), 20);

if (it != v.end())
    cout << "Found";
```

Find index:

```
int idx = find(all(v), 20) - v.begin();
```

Time complexity: \\(O(n)\\).

### B. `find()` from set/map

```
set<int> s = {10, 20, 30};

auto it = s.find(20);

if (it != s.end())
    cout << *it;
```

Time complexity: \\(O(\log n)\\) for set/map.

Important distinction:

| Search                     | Complexity         |
| -------------------------- | ------------------ |
| `find(all(v), x)`          | \\(O(n)\\)         |
| `binary_search(all(v), x)` | \\(O(\log n)\\)    |
| `s.find(x)`                | \\(O(\log n)\\)    |
| `mp.find(x)`               | \\(O(\log n)\\)    |
| `unordered_map.find(x)`    | Average \\(O(1)\\) |

# 10. `accumulate()` – Sum of Elements

Header:

```
#include <numeric>
```

```
vector<int> v = {1, 2, 3, 4, 5};

int sum = accumulate(all(v), 0);

cout << sum; // 15
```

### Important: Use `0LL` for long long

```
long long sum = accumulate(all(v), 0LL);
```

This prevents integer overflow in the accumulation.

### Other useful operations

Product:

```
int product = accumulate(
    all(v), 1, multiplies<int>()
);
```

Custom accumulation:

```
int sum = accumulate(all(v), 0,
    [](int a, int b) {
        return a + b;
    }
);
```

Sum of array:

```
int a[] = {1,2,3,4};

int sum = accumulate(a, a+4, 0);
```

Remember:

- Initial value `0` → Sum.
- Initial value `1` with `multiplies<int>()` → Product.
- Initial value controls the resulting accumulator type.

# 11. `min()`, `max()`, `min_element()`, `max_element()`

```
int a = 10, b = 20;

cout << min(a,b); // 10
cout << max(a,b); // 20
```

For vectors:

```
vector<int> v = {5, 2, 9, 1, 7};

cout << *min_element(all(v)); // 1
cout << *max_element(all(v)); // 9
```

Find their positions:

```
int mn = min_element(all(v)) - v.begin();
int mx = max_element(all(v)) - v.begin();
```

Multiple values:

```
int x = min({5, 2, 9, 1});
int y = max({5, 2, 9, 1});
```

### `clamp()`

Restrict a value within a range.

```
int x = clamp(15, 0, 10);
// 10
```

# 12. Prefix Sum – Must Know for ICPC

Prefix sum helps answer range-sum queries in \\(O(1)\\).

Suppose:

```
a = {2, 4, 1, 5, 3};
```

Create prefix sum:

```
vector<int> pref(n+1, 0);

for (int i = 0; i < n; i++)
    pref[i+1] = pref[i] + a[i];
```

Prefix sum visualization

    Original array:       [ 2,  4,  1,  5,  3 ]
    Index:                  0   1   2   3   4

    Prefix array:         [ 0,  2,  6,  7, 12, 15 ]
    Prefix index:           0   1   2   3   4   5

    pref[i] = sum of the first i elements.

    Range sum from L to R (inclusive):
        sum(L, R) = pref[R + 1] - pref[L]

    Example: L = 1, R = 3
        = pref[4] - pref[1]
        = 12 - 2
        = 10
        = 4 + 1 + 5


Prefix array (including initial zero)

0

2

6

7

12

15

pref[i] = sum of the first i elements.

### Range sum from index L to R

Formula:

\\[ sum(L,R)=pref[R+1]-pref[L] \\]

Example: Sum from index 1 to 3:

```
cout << pref[4] - pref[1];
// 4 + 1 + 5 = 10
```

### 2D Prefix Sum

For matrix range-sum queries:

```
pref[i][j] = a[i][j]
           + pref[i-1][j]
           + pref[i][j-1]
           - pref[i-1][j-1];
```

Rectangle sum:

```
sum = pref[x2][y2]
    - pref[x1-1][y2]
    - pref[x2][y1-1]
    + pref[x1-1][y1-1];
```

### Prefix XOR

Same concept, but replace addition with XOR:

```
pref[i+1] = pref[i] ^ a[i];
```

Range XOR:

```
int ans = pref[r+1] ^ pref[l];
```

# 13. Two Pointers & Sliding Window

These are techniques rather than STL functions, but extremely useful in ICPC.

### Two pointers – Pair sum

Find whether two elements sum to target in a sorted array.

```
vector<int> a = {1, 2, 4, 6, 8};
int target = 10;

int l = 0, r = a.size()-1;

while (l < r) {
    int sum = a[l] + a[r];

    if (sum == target) {
        cout << "Found";
        break;
    }
    else if (sum < target)
        l++;
    else
        r--;
}
```

Complexity: \\(O(n)\\).

### Sliding window – Maximum sum of K consecutive elements

```
int k = 3;
int sum = 0;

for (int i = 0; i < k; i++)
    sum += a[i];

int ans = sum;

for (int i = k; i < a.size(); i++) {
    sum += a[i];
    sum -= a[i-k];

    ans = max(ans, sum);
}
```

Complexity: \\(O(n)\\).

When to use:

- Fixed-size subarray → Fixed sliding window.
- Longest subarray satisfying a condition → Variable sliding window (when the condition supports moving pointers).
- Pair sum in sorted array → Two pointers.
- Remove duplicates in sorted array → Two pointers.

# 14. Stack – LIFO

Last In, First Out.

```
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top(); // 30

st.pop();         // Remove 30
cout << st.top(); // 20
```

| Function  | Meaning     |
| --------- | ----------- |
| `push(x)` | Insert      |
| `pop()`   | Remove top  |
| `top()`   | Access top  |
| `size()`  | Size        |
| `empty()` | Check empty |

CP applications:

- Balanced parentheses.
- Next greater element.
- Monotonic stack.
- Expression evaluation.
- Histogram problems.

### Next Greater Element – basic idea

Maintain a decreasing stack. When a larger element appears, pop smaller elements and assign their next greater element.

# 15. Queue & Deque

### Queue – FIFO

First In, First Out.

```
queue<int> q;

q.push(10);
q.push(20);

cout << q.front(); // 10

q.pop();
cout << q.front(); // 20
```

Applications: BFS, level-order traversal, shortest paths in unweighted graphs.

### Deque – Double-ended queue

```
deque<int> dq;

dq.push_back(10);
dq.push_front(20);

cout << dq.front(); // 20
cout << dq.back();  // 10

dq.pop_front();
dq.pop_back();
```

Can insert and delete from both ends in \\(O(1)\\).

# 16. Priority Queue – Heap

By default, C++ priority queue is a max heap.

### Maximum element first

```
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top(); // 50
```

### Minimum element first

```
priority_queue<int, vector<int>, greater<int>> pq;
```

Now:

```
pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top(); // 10
```

### Useful operations

```
pq.push(x);
pq.pop();
pq.top();
pq.size();
pq.empty();
```

Complexity:

| Operation | Complexity      |
| --------- | --------------- |
| `push()`  | \\(O(\log n)\\) |
| `pop()`   | \\(O(\log n)\\) |
| `top()`   | \\(O(1)\\)      |

Applications: Dijkstra, top K elements, scheduling, greedy algorithms.

# 17. Pair & Tuple

### Pair

Store two values together.

```
pair<int,int> p = {10, 20};

cout << p.first;  // 10
cout << p.second; // 20
```

Shortcuts:

```
auto p = make_pair(5, 10);
pair<int,int> p2 = {3, 7};
```

Vector of pairs:

```
vector<pair<int,int>> v;

v.push_back({1, 5});
v.push_back({2, 8});

sort(all(v));
```

### Tuple

Store three or more values.

```
tuple<int,string,double> t = {1, "ABC", 3.5};

cout << get<0>(t); // 1
cout << get<1>(t); // ABC
cout << get<2>(t); // 3.5
```

Structured binding:

```
auto [id, name, marks] = t;
```

# 18. Useful STL Algorithms – One Master List

These are functions from the `<algorithm>` header.

| Function             | What it does                            | Example                                       |
| -------------------- | --------------------------------------- | --------------------------------------------- |
| `sort()`             | Sort ascending                          | `sort(all(v))`                                |
| `stable_sort()`      | Stable sorting                          | `stable_sort(all(v))`                         |
| `reverse()`          | Reverse elements                        | `reverse(all(v))`                             |
| `rotate()`           | Rotate elements                         | `rotate(v.begin(),v.begin()+2,v.end())`       |
| `unique()`           | Remove consecutive duplicates logically | `unique(all(v))`                              |
| `remove()`           | Move matching values to end             | `remove(all(v),5)`                            |
| `remove_if()`        | Remove matching condition logically     | `remove_if(all(v),pred)`                      |
| `find()`             | Find value                              | `find(all(v),5)`                              |
| `find_if()`          | Find by condition                       | `find_if(all(v),pred)`                        |
| `count()`            | Count occurrences                       | `count(all(v),5)`                             |
| `count_if()`         | Count by condition                      | `count_if(all(v),pred)`                       |
| `binary_search()`    | Check existence in sorted range         | `binary_search(all(v),5)`                     |
| `lower_bound()`      | First ≥ x                               | `lower_bound(all(v),5)`                       |
| `upper_bound()`      | First > x                               | `upper_bound(all(v),5)`                       |
| `min_element()`      | Find minimum iterator                   | `min_element(all(v))`                         |
| `max_element()`      | Find maximum iterator                   | `max_element(all(v))`                         |
| `nth_element()`      | Put kth element in correct position     | `nth_element(all(v),v.begin()+2)`             |
| `partial_sort()`     | Sort first k elements                   | `partial_sort(v.begin(),v.begin()+k,v.end())` |
| `next_permutation()` | Next permutation                        | `next_permutation(all(v))`                    |
| `prev_permutation()` | Previous permutation                    | `prev_permutation(all(v))`                    |
| `all_of()`           | Every element satisfies condition       | `all_of(all(v),pred)`                         |
| `any_of()`           | At least one satisfies condition        | `any_of(all(v),pred)`                         |
| `none_of()`          | No element satisfies condition          | `none_of(all(v),pred)`                        |
| `fill()`             | Fill range                              | `fill(all(v),0)`                              |
| `iota()`             | Fill consecutive values                 | `iota(all(v),1)`                              |
| `swap()`             | Swap two values                         | `swap(a,b)`                                   |
| `max()`              | Maximum value                           | `max(a,b)`                                    |
| `min()`              | Minimum value                           | `min(a,b)`                                    |
| `clamp()`            | Restrict value to range                 | `clamp(x,0,100)`                              |
| `equal()`            | Compare ranges                          | `equal(all(a),b.begin())`                     |
| `mismatch()`         | Find first differing position           | `mismatch(all(a),b.begin())`                  |
| `merge()`            | Merge sorted ranges                     | `merge(...)`                                  |
| `set_union()`        | Union of sorted ranges                  | `set_union(...)`                              |
| `set_intersection()` | Intersection                            | `set_intersection(...)`                       |
| `set_difference()`   | Elements in first but not second        | `set_difference(...)`                         |
| `includes()`         | Check if sorted range contains another  | `includes(...)`                               |
| `is_sorted()`        | Check sorted                            | `is_sorted(all(v))`                           |
| `is_sorted_until()`  | Find first unsorted position            | `is_sorted_until(all(v))`                     |
| `shuffle()`          | Randomly shuffle                        | `shuffle(all(v),rng)`                         |

### Some particularly useful examples

Count even numbers:

```
int cnt = count_if(all(v), [](int x) {
    return x % 2 == 0;
});
```

Check if all numbers are positive:

```
bool ok = all_of(all(v), [](int x) {
    return x > 0;
});
```

Check if any number is negative:

```
bool ok = any_of(all(v), [](int x) {
    return x < 0;
});
```

Generate 1 to 10:

```
vector<int> v(10);
iota(all(v), 1);
```

Find second-smallest element:

```
nth_element(all(v), v.begin()+1);
cout << v[1];
```

Generate all permutations:

```
sort(all(v));

do {
    for (int x : v) cout << x << " ";
    cout << '\n';
} while (next_permutation(all(v)));
```

Shuffle a vector:

```
mt19937 rng(chrono::steady_clock::now()
            .time_since_epoch().count());

shuffle(all(v), rng);
```

# 19. Mathematical STL – `<numeric>` and `<cmath>`

| Function                | Meaning                              | Example                               |
| ----------------------- | ------------------------------------ | ------------------------------------- |
| `accumulate()`          | Sum/accumulate                       | `accumulate(all(v),0LL)`              |
| `inner_product()`       | Dot product                          | `inner_product(all(a),b.begin(),0LL)` |
| `iota()`                | Consecutive values                   | `iota(all(v),0)`                      |
| `partial_sum()`         | Prefix sums                          | `partial_sum(all(v),all(p))`          |
| `adjacent_difference()` | Difference between adjacent elements | `adjacent_difference(all(v),all(d))`  |
| `gcd()`                 | Greatest common divisor              | `gcd(a,b)`                            |
| `lcm()`                 | Least common multiple                | `lcm(a,b)`                            |
| `abs()`                 | Absolute value                       | `abs(-10)`                            |
| `sqrt()`                | Square root                          | `sqrt(25)`                            |
| `pow()`                 | Power                                | `pow(2,3)`                            |
| `ceil()`                | Round up                             | `ceil(4.2)`                           |
| `floor()`               | Round down                           | `floor(4.8)`                          |
| `round()`               | Nearest integer                      | `round(4.6)`                          |
| `log2()`                | Log base 2                           | `log2(8)`                             |
| `log10()`               | Log base 10                          | `log10(100)`                          |
| `sin()`                 | Sine                                 | `sin(x)`                              |
| `cos()`                 | Cosine                               | `cos(x)`                              |
| `tan()`                 | Tangent                              | `tan(x)`                              |

### GCD and LCM

```
int a = 12, b = 18;

cout << gcd(a,b); // 6
cout << lcm(a,b); // 36
```

LCM formula:

\\[ LCM(a,b)=\frac{a}{GCD(a,b)}\times b \\]

For large numbers, use `long long` and avoid overflow.

### Partial sum

```
vector<int> a = {1,2,3,4};
vector<int> p(4);

partial_sum(all(a), p.begin());
```

Result:

```
1 3 6 10
```

This is an alternative to manually creating prefix sums.

### Adjacent difference

```
vector<int> a = {2,5,9,15};
vector<int> d(4);

adjacent_difference(all(a), d.begin());
```

Result:

```
2 3 4 6
```

# 20. Bit Manipulation – ICPC Shortcuts

Bitwise operators:

| Operator | Meaning     | Example   |
| -------- | ----------- | --------- |
| `&`      | AND         | `5 & 3`   |
| `\\|`    | OR          | `5 \\| 3` |
| `^`      | XOR         | `5 ^ 3`   |
| `~`      | NOT         | `~5`      |
| `<<`     | Left shift  | `1 << 3`  |
| `>>`     | Right shift | `8 >> 2`  |

### Check if ith bit is ON

```
if (n & (1LL << i))
    cout << "ON";
```

### Turn ON ith bit

```
n |= (1LL << i);
```

### Turn OFF ith bit

```
n &= ~(1LL << i);
```

### Toggle ith bit

```
n ^= (1LL << i);
```

### Check power of two

```
bool ok = (n > 0 && (n & (n-1)) == 0);
```

### Remove lowest set bit

```
n &= (n-1);
```

### Get lowest set bit

```
int bit = n & -n;
```

### Count set bits

```
int cnt = __builtin_popcount(n);
```

For `long long`:

```
int cnt = __builtin_popcountll(n);
```

### Find trailing zeros

```
int z = __builtin_ctz(n);
```

For long long:

```
int z = __builtin_ctzll(n);
```

Do not use `ctz(0)`; its result is undefined.

### Find leading zeros

```
int z = __builtin_clz(n);
```

For long long:

```
int z = __builtin_clzll(n);
```

Do not use these on zero either.

### Bitmask iteration

Generate all subsets of n elements:

```
for (int mask = 0; mask < (1 << n); mask++) {

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            cout << i << " ";
        }
    }

    cout << '\n';
}
```

For larger bitmasks, use `1LL << n` and ensure `n` is within the bit width.

# 21. Array & Utility Shortcuts

```
int a[5] = {1,2,3,4,5};
```

| Shortcut                 | Meaning                  |
| ------------------------ | ------------------------ |
| `sizeof(a)/sizeof(a[0])` | Number of array elements |
| `memset(a,0,sizeof(a))`  | Set bytes to zero        |
| `memset(a,-1,sizeof(a))` | Set bytes to -1          |
| `fill(a,a+n,0)`          | Fill array with zero     |
| `iota(a,a+n,1)`          | Fill 1,2,3...            |
| `sort(a,a+n)`            | Sort array               |
| `reverse(a,a+n)`         | Reverse array            |
| `lower_bound(a,a+n,x)`   | Binary search position   |
| `upper_bound(a,a+n,x)`   | First greater position   |
| `accumulate(a,a+n,0LL)`  | Array sum                |

Important: `memset` sets bytes, not integer values. For arbitrary values use `fill()`.

### Initialize 2D arrays

```
int dp[1005][1005] = {};
```

Or:

```
memset(dp, -1, sizeof(dp));
```

# 22. Advanced CP Containers

| Container                | Purpose                   | Example                     |
| ------------------------ | ------------------------- | --------------------------- |
| `bitset<N>`              | Fixed-size bit operations | `bitset<32> b`              |
| `array<int,N>`           | Fixed-size STL array      | `array<int,5> a`            |
| `list<int>`              | Doubly linked list        | `list<int> l`               |
| `forward_list<int>`      | Singly linked list        | `forward_list<int> l`       |
| `unordered_set<int>`     | Unique unordered elements | `unordered_set<int> s`      |
| `unordered_map<int,int>` | Hash table                | `unordered_map<int,int> mp` |
| `multiset<int>`          | Sorted duplicates         | `multiset<int> ms`          |
| `multimap<int,int>`      | Multiple values per key   | `multimap<int,int> mm`      |
| `priority_queue<int>`    | Max heap                  | `priority_queue<int> pq`    |
| `deque<int>`             | Double-ended queue        | `deque<int> dq`             |
| `queue<int>`             | FIFO                      | `queue<int> q`              |
| `stack<int>`             | LIFO                      | `stack<int> st`             |

### Bitset

```
bitset<8> b(10);

cout << b;        // 00001010
cout << b.count();// 2
cout << b.test(1);// 1

b.set(0);         // Turn on bit
b.reset(1);       // Turn off bit
b.flip(2);        // Toggle bit
```

# 23. Important Shortcuts for ICPC

These are some of the most reusable one-line tricks.

| Task                      | Shortcut                                           |
| ------------------------- | -------------------------------------------------- |
| Sum vector                | `accumulate(all(v), 0LL)`                          |
| Product vector            | `accumulate(all(v), 1LL, multiplies<long long>())` |
| Minimum                   | `*min_element(all(v))`                             |
| Maximum                   | `*max_element(all(v))`                             |
| Sort ascending            | `sort(all(v))`                                     |
| Sort descending           | `sort(rall(v))`                                    |
| Reverse                   | `reverse(all(v))`                                  |
| Remove duplicates         | `v.erase(unique(all(v)),v.end())` after sorting    |
| Count x                   | `count(all(v),x)`                                  |
| Find x                    | `find(all(v),x)`                                   |
| Binary search             | `binary_search(all(v),x)`                          |
| First ≥ x                 | `lower_bound(all(v),x)`                            |
| First > x                 | `upper_bound(all(v),x)`                            |
| Find index                | `lower_bound(all(v),x)-v.begin()`                  |
| Frequency                 | `map[x]++`                                         |
| Check palindrome          | `s == string(s.rbegin(),s.rend())`                 |
| Reverse string            | `reverse(all(s))`                                  |
| Convert integer to string | `to_string(n)`                                     |
| Convert string to integer | `stoi(s)`                                          |
| GCD                       | `gcd(a,b)`                                         |
| LCM                       | `lcm(a,b)`                                         |
| Absolute value            | `abs(x)`                                           |
| Swap                      | `swap(a,b)`                                        |
| Fill zero                 | `fill(all(v),0)`                                   |
| Generate 1 to n           | `iota(all(v),1)`                                   |
| Check sorted              | `is_sorted(all(v))`                                |
| Next permutation          | `next_permutation(all(v))`                         |
| Count set bits            | `__builtin_popcountll(n)`                          |
| Get size                  | `sz(v)`                                            |
| Last element              | `v.back()`                                         |

# 24. Time Complexity Cheat Sheet

Memorize these before ICPC.

| Operation                     | Time complexity      |
| ----------------------------- | -------------------- |
| Vector access `v[i]`          | \\(O(1)\\)           |
| Vector `push_back()`          | Amortized \\(O(1)\\) |
| Vector `pop_back()`           | \\(O(1)\\)           |
| Vector insertion at beginning | \\(O(n)\\)           |
| Vector erase                  | \\(O(n)\\)           |
| `sort()`                      | \\(O(n\log n)\\)     |
| `reverse()`                   | \\(O(n)\\)           |
| `unique()`                    | \\(O(n)\\)           |
| `find(vector)`                | \\(O(n)\\)           |
| `binary_search()`             | \\(O(\log n)\\)      |
| `lower_bound()`               | \\(O(\log n)\\)      |
| `map` insertion/search        | \\(O(\log n)\\)      |
| `set` insertion/search        | \\(O(\log n)\\)      |
| `unordered_map` search        | Average \\(O(1)\\)   |
| `unordered_set` search        | Average \\(O(1)\\)   |
| `priority_queue` push/pop     | \\(O(\log n)\\)      |
| `priority_queue` top          | \\(O(1)\\)           |
| `stack` push/pop              | \\(O(1)\\)           |
| `queue` push/pop              | \\(O(1)\\)           |
| `accumulate()`                | \\(O(n)\\)           |
| Prefix sum construction       | \\(O(n)\\)           |
| Prefix sum range query        | \\(O(1)\\)           |
| Two pointers                  | Usually \\(O(n)\\)   |
| Sliding window                | Usually \\(O(n)\\)   |

# 25. Common ICPC Mistakes

Remember these!

1\. Integer overflow

```
long long sum = accumulate(all(v), 0LL);
```

2\. Binary search requires sorted data

```
sort(all(v));
auto it = lower_bound(all(v), x);
```

3\. Check iterator before dereferencing

```
auto it = find(all(v), x);

if (it != v.end())
    cout << *it;
```

4\. `unique()` does not erase elements

```
v.erase(unique(all(v)), v.end());
```

5\. Map `[]` creates a missing key

```
if (mp.count(x)) {
    cout << mp[x];
}
```

6\. Don't use `int` for large sums

```
long long ans = 0;
```

7\. Avoid `endl` in competitive programming

```
cout << ans << '\n';
```

# 26. Test Your Understanding

Try these quick questions before the competition.

STL mini quiz

0/7 answered

1\. Which function finds the first element ≥ x?

upper_bound()

lower_bound()

binary_search()

find()

2\. How do you remove all duplicates from a vector?

unique(all(v))

erase(all(v))

sort + erase(unique(...))

find()

3\. Which container stores sorted unique values?

vector

multiset

set

queue

4\. What is the complexity of prefix sum range queries after preprocessing?

O(n)

O(log n)

O(1)

O(n log n)

5\. What does accumulate(all(v), 0LL) calculate?

Maximum

Sum

Product

Minimum

6\. Which data structure gives the maximum element by default?

queue

stack

priority_queue

set

7\. What is the average lookup complexity of unordered_map?

O(n)

O(log n)

O(1)

O(n log n)

Check my answers

## My ICPC priority order

If you have limited preparation time, master these first:

1. `vector`, `string`, `pair`
2. `sort`, `reverse`, `unique`, `erase`
3. `binary_search`, `lower_bound`, `upper_bound`
4. `map`, `set`, `unordered_map`, `multiset`
5. `accumulate`, `min_element`, `max_element`, `gcd`
6. Prefix sum, difference array, prefix XOR
7. Two pointers, sliding window
8. `stack`, `queue`, `deque`, `priority_queue`
9. Bit manipulation and bitmasking
10. `next_permutation`, `iota`, `nth_element`

One final ICPC tip: Don't memorize STL functions without understanding the problem patterns they solve. For example, sorting + two pointers, map + frequency counting, prefix sum + hash map, and binary search + greedy are combinations that appear frequently in contests.

================================================================================
FINAL CONTEST REMINDER
================================================================================

Understand the pattern before choosing the STL:

    Sorting + Two Pointers       -> Pair / interval / matching problems
    Map + Frequency Counting    -> Count occurrences and track frequencies
    Prefix Sum + Hash Map       -> Subarray sum and counting problems
    Binary Search + Greedy      -> Minimum / maximum feasible answer
    Stack + Monotonic Logic     -> Next greater / smaller element
    Priority Queue + Greedy    -> Repeatedly choose the best available item
    Bitmask + DP / Enumeration -> Subset and state-compression problems

Do not memorize functions blindly. Know:
    1. What information the problem asks you to maintain.
    2. Which operation must be fast.
    3. Which data structure supports that operation.
    4. The time complexity that fits the constraints.

Good luck and happy coding!
