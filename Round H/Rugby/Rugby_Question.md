## Problem: Rugby

On a far away planet, rugby is played in the two dimensional Cartesian coordinate system without bounds. The players can occupy integer grid points only and they can move to the neighboring grid points in any of the four cardinal directions. Specifically, if a player is currently at the point (X, Y), then they can move to either of the points (X+1, Y), (X-1, Y), (X, Y+1), or (X, Y-1) in a single step.

After the game, **N** players are scattered throughout the coordinate system such that any grid point is empty or occupied by one or more players. They want to gather for a picture and form a perfect horizontal line of **N** grid points, one player per point, all occupied points next to each other. Formally, the players have to move so as to occupy the grid points (X, Y), (X+1, Y), (X+2, Y), ..., (X+**N**-1, Y) for some coordinates X and Y. What is the minimum total number of steps the players should make to form a perfect line if they are free to choose the position of the line in the coordinate system and the ordering of players is not important?

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. The first line of each test case gives the number of players **N**. The subsequent **N** lines give the initial coordinates of the players. The i-th of these lines contains two integers **X<sub>i</sub>** and **Y<sub>i</sub>**, which describe the initial position of i-th player (1 ≤ i ≤ **N**).

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the minimum total number of steps that the players need to make in order to form a perfect horizontal line.

**Limits**

- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
```

- Test set 1
Time limit: `20 seconds.`
```
1 ≤ N ≤ 10.
-500 ≤ Xi ≤ 500.
-500 ≤ Yi ≤ 500.
```

- Test set 2
Time limit: `40 seconds.`
```
1 ≤ N ≤ 105 for at most 10 cases.
1 ≤ N ≤ 104 for the remaining cases.
-109 ≤ Xi ≤ 109.
-109 ≤ Yi ≤ 109.
```

**Sample**

- Input:
```
2
2
1 1
4 4
3
1 1
1 2
1 3
```

- Output:
```
Case #1: 5
Case #2: 4
```

**Explanation**

In the first test case, one of many optimal solutions is obtained by the second player moving two steps to the left and three steps down to the point (2, 1).

In the second test case, a perfect line can be formed with a total of four steps if the first player moves to the point (0, 2) and the third player moves to the point (2, 2).

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027>