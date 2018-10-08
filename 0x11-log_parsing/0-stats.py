#!/usr/bin/python3
"""
log parsing
"""
import sys
from collections import defaultdict


codes = {'200', '301', '400', '401', '403', '404', '405', '500'}


def printLog():
    """ print log """
    print('File size:', filesize)
    for i in sorted(logs.keys()):
        print('{}: {}'.format(i, logs[i]))


filesize = 0
counter = 0
logs = defaultdict(int)


try:
    for l in sys.stdin:
        l = l.split(' ')
        if len(l) == 9:
            filesize += int(l[8])
            if l[7] in codes:
                logs[l[7]] += 1
        if counter == 9:
            printLog()
            counter = 0
        else:
            counter += 1
except KeyboardInterrupt:
    printLog()
    sys.exit()
printLog()
