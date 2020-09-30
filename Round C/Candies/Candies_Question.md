## Problem: Candies

Carl has an array of **N** candies. The i-th element of the array (indexed starting from 1) is **A<sub>i</sub>** representing sweetness value of the i-th candy. He would like to perform a series of **Q** operations. There are two types of operation:

- Update the sweetness value of a candy in the array.
- Query the sweetness score of a subarray.

The sweetness score of a subarray from index l to r is: **A<sub>l</sub>** × 1 - **A<sub>l+1</sub>** × 2 + **A<sub>l+2</sub>** × 3 - **A<sub>l+3</sub>** × 4 + **A<sub>l+4</sub>** × 5 ...

More formally, the sweetness score is the sum of (-1)<sup>i-l</sup>**A<sub>i</sub>** × (i - l + 1), for all i from l to r inclusive.

For example, the sweetness score of:

- [3, 1, 6] is 3 × 1 - 1 × 2 + 6 × 3 = 19
- [40, 30, 20, 10] is 40 × 1 - 30 × 2 + 20 × 3 - 10 × 4 = 0
- [2, 100] is 2 × 1 - 100 × 2 = -198

Carl is interested in finding out the total sum of sweetness scores of all queries. If there is no query operation, the sum is considered to be 0. Can you help Carl find the sum?

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case begins with a line containing **N** and **Q**. The second line contains **N** integers describing the array. The i-th integer is **A<sub>i</sub>**. The j-th of the following **Q** lines describe the j-th operation. Each line begins with a single character describing the type of operation (U for update, Q for query).

- For an update operation, two integers **X<sub>j</sub>** and **V<sub>j</sub>** follow, indicating that the **X<sub>j</sub>**-th element of the array is changed to V<sub>j</sub>.

- For a query operation, two integers **L<sub>j</sub>** and **R<sub>j</sub>** follow, querying the sweetness score of the subarray from the **L<sub>j</sub>**-th element to the **R<sub>j</sub>**-th element (inclusive).

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the total sum of sweetness scores of all the queries.

**Limits**

- Time limit: `20 seconds per test set`.
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 100, for all i.
1 ≤ N ≤ 2 × 105 and 1 ≤ Q ≤ 105 for at most 6 test cases.
For the remaining cases, 1 ≤ N ≤ 300 and 1 ≤ Q ≤ 300.
If the j-th operation is an update operation, 1 ≤ Xj ≤ N and 1 ≤ Vj ≤ 100.
If the j-th operation is a query operation, 1 ≤ Lj ≤ Rj ≤ N.
```

- Test set 1

`There will be at most 5 update operations.`

- Test set 2

`There are no special constraints.`

**Sample**

- Input:

```
2
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2
3 3
4 5 5
U 1 2
U 1 7
Q 1 2
```

- Output:

```
Case #1: -8
Case #2: -3
```

**Explaination**

In sample case #1:

- The first query asks for the sweetness score of [3, 9, 8] which is 3 × 1 - 9 × 2 + 8 × 3 = 9.
- The second query asks for the sweetness score of [2] which is 2 × 1 = 2.
- The third query asks for the sweetness score of [1, 10] which is 1 × 1 - 10 × 2 = -19.

Thus, the final output should be 9 + 2 - 19 = -8.

In sample case #2:

- The first and only query asks for the sweetness score of [7, 5] which is 7 × 1 - 5 × 2 = -3.

Thus, the final output should be -3.

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d>
