Levenshtein Distance
====================

Definition
----------
Levenshtein distance is defined as the number of edit operations needed to convert one string to another.
For example, the levenshtein distance between 'cat' and 'bare' is 3. Namely, replace 'c' with 'b', 't' with 'r' and append an 'e'.
For further information see http://en.wikipedia.org/wiki/Levenshtein_distance

Strategy
--------
Levenshtein distance can be computed recursively or using dynamic programming. This program demonstrates both.

Building
--------
To build the executable, run
```bash
make
```

Running
-------
To run the executable in recursive mode, provide exactly two string for comparission.
```bash
./edit_distance "cat" "bare"
```

To run the executable in dynamic programming mode, provide the -f flag.
```bash
./edit_distance -f "cat" "bare"
```

Notes
-----
* When running in dynamic programming mode, the -f must be provided as the first argument
* The recursive algorithm is very slow (O(3^n)) and will fail for input sizes larger than 11 or 12