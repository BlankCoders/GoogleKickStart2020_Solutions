## Problem: Combination Lock

A combination lock has **W** wheels, each of which has the integer values 1 through **N** on it, in ascending order.

At any moment, each wheel shows a specific value on it. **X<sub>i</sub>** is the initial value shown on the i-th wheel.

You can use a single move to change a wheel from showing the value X to showing either X+1 or X-1, wrapping around between 1 and **N**. For example, if a wheel currently shows the value 1, in one move you can change its value to 2 or **N**.

Given all wheels' initial values, what is the minimum number of moves to get all wheels to show the same value?

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. 

The first line of each test case contains the two integers **W** and **N**.

The second line contains **W** integers. The i-th integer is **X<sub>i</sub>**.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the minimum number of moves to get all wheels to show the same value.

**Limits**

- Time limit: `40 seconds per test set.`
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
0 ≤ Xi ≤ N.
```

- Test set 1
```
1 ≤ W ≤ 1000.
2 ≤ N ≤ 1000.
```

- Test set 2
```
1 ≤ W ≤ 1000.
2 ≤ N ≤ 10^9.
```

- Test Set 3
```
1 ≤ W ≤ 10^5.
2 ≤ N ≤ 10^9.
```

**Sample**

- Input:
```
2
3 5
2 3 4
4 10
2 9 3 8
```

- Output:
```
Case #1: 2
Case #2: 8
```

**Explaination**

* In Sample Case #1, the best solution is to get all wheels to show value 3, which would take a total of 2 moves: the first wheel would move once (from value 2 to value 3), the second wheel would not move (it already shows value 3), and the third wheel would move once (from value 4 to value 3).

    For reference, it would take 5 moves to get all wheels to show value 1, 3 moves to get all wheels to show value 2, 3 moves to get all wheels to show value 4, and 5 moves to get all wheels to show value 5.

* In Sample Case #2, the best solutions are to get all wheels to show either value 1, 2, 9 or 10, which would take a total of 8 moves..

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a24>