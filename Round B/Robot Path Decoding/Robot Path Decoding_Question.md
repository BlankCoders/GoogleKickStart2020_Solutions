## Problem: Robot Path Decoding

Your country's space agency has just landed a rover on a new planet, which can be thought of as a grid of squares containing 10<sup>9</sup> columns (numbered starting from 1 from west to east) and 10<sup>9</sup> rows (numbered starting from 1 from north to south). Let (w, h) denote the square in the w-th column and the h-th row. The rover begins on the square (1, 1).

The rover can be maneuvered around on the surface of the planet by sending it a *program*, which is a string of characters representing movements in the four cardinal directions. The robot executes each character of the string in order:

- N: Move one unit north.
- S: Move one unit south.
- E: Move one unit east.
- W: Move one unit west

There is also a special instruction X(Y), where X is a number between 2 and 9 inclusive and Y is a non-empty subprogram. This denotes that the robot should repeat the subprogram Y a total of X times. For example:

- 2(NWE) is equivalent to NWENWE.
- 3(S2(E)) is equivalent to SEESEESEE.
- EEEE4(N)2(SS) is equivalent to EEEENNNNSSSS.

Since the planet is a torus, the first and last columns are adjacent, so moving east from column 10<sup>9</sup> will move the rover to column 1 and moving south from row 10<sup>9</sup> will move the rover to row 1. Similarly, moving west from column 1 will move the rover to column 10<sup>9</sup> and moving north from row 1 will move the rover to row 10<sup>9</sup>. Given a program that the robot will execute, determine the final position of the robot after it has finished all its movements.

**Input**

The first line of the input gives the number of test cases, T. T lines follow. Each line contains a single string: the program sent to the rover.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the number of peaks in Li's bike tour.

**Limits**

- Time limit: `10 seconds per test set`.
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Hi ≤ 100.
```

- Test set 1

`3 ≤ N ≤ 5.`

- Test set 2

`3 ≤ N ≤ 100.`

**Sample**

- Input:

```
4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10
```

- Output:

```
Case #1: 1
Case #2: 0
Case #3: 2
Case #4: 0
```

**Explaination**

- In sample case #1, the 2nd checkpoint is a peak.
- In sample case #2, there are no peaks.
- In sample case #3, the 2nd and 4th checkpoint are peaks.
- In sample case #4, there are no peaks.

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd>
