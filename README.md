# BSQ
"find the Biggest SQuare"
Note : 19/20

## Subject:
You must find the largest possible square on a board while avoiding obstacles.
The board is represented by a file passed as the program’s argument.

The file is valid if it is respecting those constraints:
- its first line contains the number of lines on the board (and only that).
- “.” (representing an empty place) and “o” (representing an obstacle) are the only two characters for the
other lines.
- all of the lines are of the same length (except the first one).
- it contains at least one line.
- each line is terminated by ‘\n’.

You program must print the board, with some “.” replaced by “x” to represent the largest square you found.

If ever there are several solutions, you have to represent only the highest square. If they
are still several solutions, choose the square to the left.

## How to use:
./bsq example_file
