#!/usr/bin/python3
"""
calculate fewest no of ops needed
"""


def gcd(n):
    """ returns gcd of n """
    divs = 1
    for i in range(divs, n // 2 + 1):
        if n % i == 0:
            divs = i
    return divs

def minOperations(n):
    """ minimum operations to reach n characters in a file """
    if n <= 1:
        return 0
    divs = [n]
    tempN = n
    while gcd(tempN) != 1:
        tempN = gcd(tempN)
        divs.append(tempN)
    o1 = -1
    o2 = 0
    tempN = 1
    while tempN != n:
        if divs[o1] % size == 0:
            o2 += divs[o1]
            tempN *= divs[o1]
            o1 = o1 - 1 if -len(div) < o1 else o1
        else:
            o2 += 1
            tempN += 1
    return o2
