## Problem: Merge Cards

Panko is playing a game with **N** cards laid out in a row. The i-th card has the integer **A<sub>i</sub>** written on it.

The game is played in **N** - 1 rounds. During each round Panko will pick an adjacent pair of cards and *merge* them. Suppose that the cards have the integers X and Y written on them. To merge two cards, Panko creates a new card with X + Y written on it. He then removes the two original cards from the row and places the new card in their old position. Finally Panko receives X + Y points for the merge. During each round Panko will pick a pair of adjacent cards uniformly at random amongst the set of all available adjacent pairs.

After all **N** - 1 rounds, Panko's total score is the sum of points he received for each merge. What is the [expected value](https://en.wikipedia.org/wiki/Expected_value) of Panko's total score at the end of the game?

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case begins with a line containing the integer **N**. A second line follows containing **N** integers, describing the initial row of cards. The i-th integer is **A<sub>i</sub>**.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the expected total score at the end of the game.

`y` will be considered correct if it is within an absolute or relative error of 10<sup>-6</sup> of the correct answer. See the [FAQ](https://codingcompetitions.withgoogle.com/kickstart/faq#how-does-kick-start-handle-real-numbers) for an explanation of what that means, and what formats of real numbers we accept.

**Limits**

- Time limit: `40 seconds per test set.`
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 109 for all i.
```

- Test set 1
```
2 ≤ N ≤ 9.
```

- Test set 2
```
2 ≤ N ≤ 100.
```

- Test Set 3
```
2 ≤ N ≤ 5000.
```

**Sample**

- Input:
```
2
3
2 1 10
5
19 3 78 2 31
```

- Output:
```
Case #1: 20.000000
Case #2: 352.33333333
```

**Explaination**

* In sample case #1, N = 3. The initial row of cards is [2, 1, 10]. In the first round, Panko has two choices, of which he will choose one at random.

    - If Panko merges the first pair (2, 1), then the row of cards becomes [3, 10], adding 2 + 1 = 3 points to his total score. In the second round, there is only one pair remaining (3, 10). If he merges them, the row of cards becomes [13], adding 3 + 10 = 13 points to his total score. Panko ends the game with 3 + 13 = 16 points.

    - If Panko merges the second pair (1, 10), then the row of cards becomes [2, 11], adding 1 + 10 = 11 points to his total score. In the second round, there is only one pair remaining (2, 11). If he merges them, the row of cards becomes [13], adding 2 + 11 = 13 points to his total score. Panko ends the game with 11 + 13 = 24 points.

    Thus, the expected number of points Panko ends the game with is (16 + 24)/2 = 20.

* In sample case #2, N = 5. The initial row of cards is [19, 3, 78, 2, 31]. There are too many possibilities to list here, so we will only go through one possible game:

    - In the first round, if Panko merges the pair (78, 2), then the row of cards becomes [19, 3, 80, 31], adding 78 + 2 = 80 to his score.

    - In the second round, if Panko merges the pair (80, 31), then the row of cards becomes [19, 3, 111], adding 80 + 31 = 111 to his score.

    - In the third round, if Panko merges the pair (19, 3), then the row of cards becomes [22, 111], adding 19 + 3 = 22 to his score.

    - In the fourth round, if Panko merges the pair (22, 111), then the row of cards becomes [133], adding 22 + 111 = 133 to his score.

    At the end of the game explained above, Panko's total score is 80 + 111 + 22 + 133 = 346.

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000415054>