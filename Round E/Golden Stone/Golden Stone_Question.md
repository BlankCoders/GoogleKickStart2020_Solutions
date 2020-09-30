## Problem:  Golden Stone

Leopold's friend Kate likes stones, so he decided to give her a golden stone as a gift. There are **S** types of stones numbered from 1 to **S**, 1 being the golden stone. Some types of stones are available free of charge in various parts of the city. The city consists of **N** junctions numbered from 1 to **N** and **M** two-way streets between pairs of distinct junctions. At each junction, zero or more types of stones are available in unlimited supply.

Unfortunately, the golden stone is not available anywhere. Luckily, Leopold is a bit of a magician and knows how to combine a group of stones and turn them into another stone. For example, one of his recipes could produce a golden stone out of one silver stone and two marble stones. He could collect those stones in some of the junctions if they are available, or he could use some of his many other recipes to produce any of those stones. Formally, Leopold has **R** recipes, where a recipe is in the form *(a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>k</sub>) -> b* for some *k ≥ 1*. If Leopold has gathered k stones of types *a<sub>1</sub>, a<sub>2</sub>, ..., and a<sub>k</sub>* at a certain junction, he can choose to apply the recipe and turn these stones into one stone of type *b*.

Leopold likes puzzles much more than physical activity, therefore, he does not want to carry stones around the city unnecessarily. Carrying a stone along a street costs him one unit of energy. Leopold can carry no more than one stone at a time, however, he can drop off a stone at any junction and pick it up later at any time.

What is the minimum amount of energy Leopold must spend to produce one golden stone? Leopold is very scared of large numbers. If the answer is greater than or equal to 10<sup>12</sup>, print -1 instead.

**Input**

The first line of the input gives the number of test cases, **T**. **T** test cases follow. The first line of each test case consists of four integers **N**, **M**, **S**, and **R** giving the number of junctions, streets, stone types, and recipes, respectively. The following **M** lines describe the map of the city. The i-th of these lines contains two distinct integers **U<sub>i</sub>** and **V<sub>i</sub>** denoting the pair of junctions connected by the i-th street.

The subsequent **N** lines describe the types of stones available in each junction. The i-th of these lines starts with the number of stone types **C<sub>i</sub>** available in i-th junction followed **C<sub>i</sub>** distinct integers in the range [2, **S**] enumerating the stone types. The golden stone is always numbered 1 and is not available.

The last R lines of each test case describe Leopold's magic recipes. The i-th of these lines starts with the number of ingredient stones **K<sub>i</sub>** required for the i-th recipe followed by **K<sub>i</sub>** not necessarily distinct integers in the range [2, **S**] enumerating the types of necessary ingredients. The i-th line ends with an integer in the range [1, **S**], which is the type of the resulting stone after applying the i-th recipe. For example `3 6 5 6 3` denotes a recipe that requires two stones of type 6, one stone of type 5, and produces a stone of type 3.

It is guaranteed that it is possible to produce a golden stone in each of the test cases.

**Output**

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the answer for the test case `x`, namely, the minimum amount of energy Leopold must spend to produce one golden stone. If the answer is greater than or equal to 10<sup>12</sup>, print -1 instead.

**Limits**

- Time limit: `20 seconds per test set.`
- Memory limit: `1GB.`
```
1 ≤ T ≤ 100.
1 ≤ Ui, Vi ≤ N, Ui ≠ Vi
0 ≤ Ci < S.
1 ≤ Ki ≤ 3.
Each pair of junctions is connected by at most one street.
It is possible to get from any junction to any other junction by following a sequence of streets.
It is possible to create a golden stone.
```

- Test set 1
```
2 ≤ N ≤ 50.
1 ≤ M ≤ 80.
2 ≤ S ≤ 50.
1 ≤ R ≤ 50.
```

- Test set 2
```
2 ≤ N ≤ 300.
1 ≤ M ≤ 500.
2 ≤ S ≤ 300.
1 ≤ R ≤ 300.
```

**Sample**

- Input:
```
3
4 3 4 1
1 2
1 3
1 4
0
1 2
1 3
1 4
3 2 3 4 1
4 3 4 1
1 2
1 3
1 4
0
2 2 3
1 3
1 4
3 2 3 4 1
2 1 4 2
1 2
2 2 3
1 4
3 2 3 4 1
2 2 3 4
```

- Output:
```
Case #1: 3
Case #2: 2
Case #3: 0
```

**Explanation**

* In the first test case, the minimum amount of energy is achieved if Leopold collects the stones 2, 3, and 4 at the junctions 2, 3, and 4, respectively, carries the stones to the junction 1, and uses his only recipe to transform the three stones into a golden stone. This way, three stones are carried along one street each, therefore, the total amount of energy spent is 3.

- The only difference between the first two test cases is that the stone 3 is now available at the junction 2 as well. This time it is optimal to carry one stone of type 4 from junction 4 to junction 2 spending 2 units of energy, and then collect the missing stones of types 2 and 3 there to produce a golden stone using the only recipe.

- In the third test case, Leopold can produce a golden stone without ever leaving junction 1. First, he should collect stones of types 2 and 3 to produce a stone of type 4 using the second recipe. In a second step, he should collect the stones 2 and 3 again and combine them with the stone 4 to produce a golden stone using the first recipe.

**Go to the Editor:** <https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef29>
