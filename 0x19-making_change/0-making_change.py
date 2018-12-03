#!/usr/bin/python3
""" make change """


def coinChange(coins, total):
    """ fewest number of coins needed to meet a given noOfCoins total """
    if total < 1:
        return 0
    noOfCoins = 0
    i = -1
    coins.sort()
    while total > 0 and i > -len(coins):
        if total % coins[i] == 0:
            noOfCoins = noOfCoins + ((total // coins[i]))
            total = total - ((total // coins[i]) * coins[i])
        elif total > coins[i]:
            noOfCoins = noOfCoins + ((total // coins[i]))
            total = total - ((total // coins[i]) * coins[i])
        i -= 1
    if total == 0:
        return noOfCoins
    else:
        return -1
