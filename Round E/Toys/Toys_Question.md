## Problem: Toys

Little Axel has **N** toys numbered from 1 to **N**. Each toy has two properties:
- **E<sub>i</sub>** — *enjoyment*, which is the number of minutes Axel can play with toy number i without getting bored with it;
- **R<sub>i</sub>** — *remembrance*, which is the number of minutes it takes Axel to forget toy number i after having played with it.

The toys are arranged in a circle, from 1 to **N** clockwise. Axel plays with them one by one.

When Axel reaches toy i which he has not played with yet, or which he has already forgotten about, he plays with it for **E<sub>i</sub>** minutes and then immediately moves to the next one (clockwise).

If he reaches a toy that he has not forgotten yet (if less than **R<sub>i</sub>** minutes have passed since the last time he finished playing with it), he will stop and cry.

We can define the time Axel spent playing as the sum of **E<sub>i</sub>** of every toy Axel played with before stopping. If Axel played with a toy several times, it should be counted that many times.

Given the description of the toys, remove the smallest possible number of them in order to make Axel play either an indefinitely long time, or (if that is not possible) as long as possible before he stops.

Note:

- Axel has never played with these toys before;
- he cannot be left without toys;
- he always starts with the toy that has the smallest number;
- after finishing playing with the toy that has the largest number, he will move to the toy that has the smallest number.

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case begins with a line containing the integer **N**. Next **N** lines contain 2 integers each: **E<sub>i</sub>** and **R<sub>i</sub>**. The i-th line is describing the toy number i.

**Output**

For each test case, output one line containing `Case #x: y z`, where:

- `x` is the test case number (starting from 1);
- `y` is the minimal number of toys to remove so that Axel could play with the rest of them either indefinitely or as long as possible;
- `z` is the longest time Axel will play in minutes or "INDEFINITELY" (without quotes) if he will play indefinitely long time.

**Limits**

- Time limit: `30 seconds per test set.`
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Ei ≤ 10^9.
1 ≤ Ri ≤ 10^9.
```

- Test set 1
`1 ≤ N ≤ 12.`

- Test set 2
`1 ≤ N ≤ 10^5.`

**Sample**

- Input:
```
4
1
5 1
2
5 10
10 3
3
30 17
5 10
10 3
3
5 10
5 10
5 11
```

- Output:
```
Case #1: 0 5
Case #2: 0 INDEFINITELY
Case #3: 1 INDEFINITELY
Case #4: 0 25
```

**Explaination**

* In Sample Case #1 there is only one toy, so Axel will play with it and will get bored in 5 minutes.
* In Sample Case #2, after playing with the toy number 1 for 5 minutes, he will need to not play with it for 10 minutes, which he will spend playing with the toy number 2. After that he will return to the toy number 1 and play with it for 5 minutes, during which he will forget the toy number 2, and so on. Thus he will play for an indefinitely long time.
* In Sample Case #3, although Axel can play with the toy number 1 for 30 minutes, if we remove it he will be able to play with the others indefinitely. So we remove it, and keep the other two.
* In Sample Case #4, Axel will play with the toys in the following order: 1, 2, 3, 1, 2, and then he will stop and cry as he still remembers the toy number 3. So, in total he will play for 25 minutes.

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bede9>
