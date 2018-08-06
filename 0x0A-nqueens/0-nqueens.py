#!/usr/bin/python3
from sys import argv, exit


def search(left, right, mid, idx, arr):
        """
        search to fix position of queen
        """
        if idx == ar:
            qnBoard.append(arr)
        else:
            left = left[1:] + [0]
            right = [0] + right[:-1]
            for i in range(ar):
                if left[i] == right[i] == mid[i] == 0:
                    left[i] = right[i] = mid[i] = 1
                    l = [] + arr
                    l.append([idx, i])
                    search(left, right, mid, idx + 1, l)
                    left[i] = right[i] = mid[i] = 0

def queen(ar, q):
    """
    n queens algorithm 
    """
    search([0] * ar, [0] * ar, [0] * ar, 0, [])
    return q

if len(argv) is not 2:
    print("Usage: nqueens N")
elif argv[1].isdigit() is False:
    print("N must be a number")
    exit(1)
elif int(argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
qnBoard = []
ar = int(argv[1])
results = queen(ar, qnBoard)
for r in results:
    print(r)
