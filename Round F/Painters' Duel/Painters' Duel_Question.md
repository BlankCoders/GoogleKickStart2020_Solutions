## Problem: Painters' Duel

A new art museum is about to open! It is a single-story building in the shape of a large equilateral triangle. That triangle is made up of many smaller identical equilateral-triangle-shaped rooms, and the side length of the museum is S times the side length of any one of the rooms. Each room has doors connecting it to all other rooms with which it shares a side (not just a vertex).

Each room is identified by two numbers: the row of the building it is in (counting from top to bottom, starting from 1), followed by its position within that row (counting from left to right, starting from 1). Here is an example of how the rooms are connected and labeled when S = 3:

<img src="https://codejam.googleapis.com/dashboard/get_file/AQj_6U3MDbo5iIVo9mzZC92KTNXrgWmYw5nGn1xygDDhvxc-EKqsimmS6BlNFKx67bT6xQvTJQ/example.png" align="centre">

Alma and Berthe are artists who are painting the rooms of the museum. Alma starts in the room (**R<sub>A</sub>**, **P<sub>A</sub>**), and Berthe starts in a different room (RB, PB). Each of them has already painted their starting room. C of the other rooms of the museum are under construction, and neither Alma nor Berthe is allowed to enter these rooms or paint them.

Alma and Berthe are having a friendly competition and playing a turn-based game, with Alma starting first. On a painter's turn, if their current room is adjacent to at least one unpainted room that is not under construction, the painter must choose one of those rooms, move to it, and paint it. Otherwise, the painter cannot move and does nothing on their turn. Once both painters are unable to move, the game is over. The score of the game is the number of rooms painted by Alma minus the number of rooms painted by Berthe.

Both painters make optimal decisions, with Alma trying to maximize the score and Berthe trying to minimize the score. Given this, determine the best score Alma can guarantee for the game, regardless of what Berthe does.

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each case begins with one line containing six integers **S**, **P<sub>A</sub>**,**R<sub>A</sub>**,**P<sub>B</sub>**,**R<sub>B</sub>** and **C**. Respectively, these are the side length of the museum (as a multiple of the side length of a room), the row and position of Alma's starting room, the row and position of Berthe's starting room, and the number of rooms that are under construction. Then, there are **C** more lines. The i-th of these lines (counting starting from 1) contains two integers **R<sub>i</sub>** and **P<sub>i</sub>**, representing the row and position of the i-th room that is under construction.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the best score that Alma can guarantee for the game, as described above.

**Limits**

- Time limit: `40 seconds per test set.`
- Memory limit: `1GB.`
```
0 ≤ C ≤ S^2 - 2.
1 ≤ RA ≤ S.
1 ≤ PA ≤ 2 × RA - 1.
1 ≤ RB ≤ S.
1 ≤ PB ≤ 2 × RB - 1.
(RA, PA) ≠ (RB, PB).
1 ≤ Ri ≤ S, for all i.
1 ≤ Pi ≤ 2 × Ri - 1, for all i.
(Ri, Pi) ≠ (RA, PA), for all i.
(Ri, Pi) ≠ (RB, PB), for all i.
Either Ri < Ri+1, or Ri = Ri+1 and Pi < Pi+1, for all i < C.
```

- Test set 1
```
T = 48.
S = 2.
```

- Test set 2
```
1 ≤ T ≤ 100.
2 ≤ S ≤ 6.
```

**Sample**

- Input:
```
2
2 1 1 2 1 0
2 2 2 1 1 2
2 1
2 3
```

- Output:
```
Case #1: 2
Case #2: 0
```

**Explaination**

* In Sample Case #1, the turns must proceed as follows:

  1. Alma moves to room (2, 2).

  2. Berthe cannot move.

  3. Alma moves to room (2, 3).

  4. Berthe still cannot move.
  
  5. Alma cannot move. Since neither painter can move, the game is now over.

 Alma has painted 3 rooms and Berthe has painted 1 room, so the score is 3 - 1 = 2.

* In Sample Case #2, neither painter can move. They only paint their starting rooms.

  The following additional cases could not appear in Test Set 1, but could appear in Test Set 2.
  
  ```
  2
  3 3 4 2 1 2
  2 3
  3 1
  3 3 2 2 3 2
  2 1
  3 1
  ```
  The correct output for these two cases would be:
  ```
  Case #1: 0
  Case #2: -1
  ```
  
* In Case #1, Alma can move to (3, 5) or (3, 3). She cannot move to (2, 3), which is under construction.
  
  - If she moves to (3, 5), she will have no more moves and Berthe will go on to paint two more rooms. Score: 2 - 3 = -1.
  
  - If Alma moves to (3, 3), then Berthe can do one of the following:
    
    - Move to (3, 2), leaving neither painter with any future moves. Score: 2 - 2 = 0.
    - Move to (2, 2). Then the rest of the game must play out as follows: Alma moves to (3, 2), Berthe moves to (1, 1). Score: 3 - 3 = 0.
  
  So Alma knows that moving to (3, 3) guarantees a score of 0 no matter what Berthe does, which is better than the score of -1 that she would get by moving to (3, 5). Therefore, Alma moves to (3, 3). Notice that:

  - We do not know exactly how the rest of this game will play out, but we do know the best score that Alma can guarantee.
  - It is possible that one or more rooms that are not under construction do not get painted.
  
* In Case #2, Alma must move to (3, 3), and then it is better for Berthe to move to (3, 4) than to (2, 2).
  
**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f47fb>

