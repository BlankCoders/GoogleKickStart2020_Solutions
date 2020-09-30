## Problem: Locked Doors

Bangles is preparing to go on a tour of her local museum. The museum is made up of **N** rooms in a row, numbered from 1 to **N** from left to right. The rooms are connected by **N**-1 locked doors, each connecting a pair of adjacent rooms. Each door has a difficulty level indicating how difficult it is for Bangles to open the door. No two doors will have the same difficulty level. The door between the i-th room and (i+1)-th room has difficulty level **D<sub>i</sub>**.

Bangles will pick one of the rooms to start in, and visit each of the rooms in the museum one at a time, taking pictures as she goes. She takes a picture in her starting room, then she repeats the following procedure until she has taken a picture in all the rooms: Of the two locked doors available to her, she will open the door with the lower difficulty level and take a picture in the newly unlocked room. If there is only one locked door available to her, then she will unlock that door. Once a door is unlocked, it remains unlocked.

Bangles is not yet sure which room she would like to start in, so she needs you to answer **Q** queries. For the i-th query, she would like to know: What is the **K<sub>i</sub>**-th room that she will take a picture in if she starts in the **S<sub>i</sub>**-th room?

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. The first line of each test case contains the two integers **N** and **Q**. The second line contains **N**-1 integers, describing the locked doors. The i-th integer (starting from 1) is **D<sub>i</sub>**. Then, **Q** lines follow, describing the queries. The i-th of these lines contains the two integers **S<sub>i</sub>** and **K<sub>i</sub>**.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is a list of the answers for the Q queries in order, separated by spaces.

**Limits**

- Time limit: `40 seconds per test set`.
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Di ≤ 10^5, for all i.
All Di are distinct.
1 ≤ Si ≤ N, for all i.
1 ≤ Ki ≤ N, for all i.
```

- Test set 1
```
2 ≤ N ≤ 1000.
1 ≤ Q ≤ 1000.
```

- Test set 2
```
2 ≤ N ≤ 105 and 1 ≤ Q ≤ 105 for at most 20 test cases.
For the remaining cases, 2 ≤ N ≤ 1000 and 1 ≤ Q ≤ 1000.
```

**Sample**

- Input:
```
2
5 4
90 30 40 60
3 4
3 1
1 5
4 3
10 2
6 2 4 5 9 30 7 1 8
6 8
6 8
```

- Output:
```
Case #1: 5 3 5 2
Case #2: 8 8
```

**Explanation**

In sample case #1, there are four queries:

- In the first query, Bangle takes pictures in the rooms in the order 3, 2, 4, 5 and 1, so the answer is 5.

- In the second query, Bangle takes pictures in the rooms in the order 3, 2, 4, 5 and 1, so the answer is 3.

- In the third query, Bangle takes pictures in the rooms in the order 1, 2, 3, 4 and 5, so the answer is 5.

- In the fourth query, Bangle takes pictures in the rooms in the order 4, 3, 2, 5, and 1, so the answer is 2.

In sample case #2, there are two queries:

- In the first query, Bangle takes pictures in the rooms in the order 6, 5, 4, 3, 2, 1, 7, 8, 9 and 10, so the answer is 8.

- The second query is the same as the first, so the answer is also 8.

A few example colourings for sample case #1 are shown below.

- If Amadea picks node 5 and Bilva picks node 8, then together they paint 4 unique nodes: Amadea paints nodes 5 and 3, while Bilva paints nodes 8 and 1.
- If Amadea picks node 7 and Bilva picks node 6, then together they paint 3 unique nodes: Amadea paints nodes 7 and 1, while Bilva paints nodes 6 and 1 (note that Amadea painted node 1 as well).

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386d5c>
