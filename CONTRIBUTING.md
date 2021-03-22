## Guidelines:

* Go to [Issues](https://github.com/BlankCoders/GoogleKickStart2020_Solutions/issues) and mention what you want to solve and in which language.
* Follow the Link: <https://codingcompetitions.withgoogle.com/kickstart>
* Solve either in C or C++ or Java or Python.
* Create a folder within the Question Folder with name `FirstName-ProgrammingLanguage`, for ex: `Falguni-Python`.

    In the folder:
    - Add Code File with name `questionname.extension`, for ex: `Allocation.py`.
    - Add Editor Screenshot as shown below:
    
      <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/EditorSS/falguni_soln.png">
      
    Check Example Repository: [Falguni-Python](https://github.com/BlankCoders/GoogleKickStart2020_Solutions/tree/master/Round%20A/Allocation/Falguni-Python)
    
* If you upload code that is inspired from somewhere, write the resource by commenting first line like this:

```
# Inspired or took help from xyz
T=int(input())
A=[]
for t in range(1,T+1):
    N,B=[int(s) for s in input().split(" ")]
    A=list(map(int, input().split()))
    count=0
    A.sort()
    for i in range(len(A)):
        if(B>=A[i]):
            B=B-A[i]
            count+=1
    print("Case #{}: {}".format(t,count))
    A.clear()
```

* Plagirism is strongly discouraged.

### Regarding PRs:
- All the PRs will be marked as **"INVALID"** if you have not been assigned to any issues. To work on this repository, it's necessary to mention on what issue you want to work.
- Layout of PR Description:
    ```
    Issue Number for which I'm assigned & worked: #
    (write the issue number after # symbol)
    ```
    Example:
    ```
    Issue Number for which I'm assigned & worked: #3
    ```

    <img src="https://github.com/BlankCoders/GoogleKickStart2020_Solutions/blob/master/assets/Legends.JPG">
