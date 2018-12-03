#!/usr/bin/python3
"""
utf validator
"""


def validUTF8(data):
    """ validates utf8 """
    if len(data) < 1:
        return True

    l = len(data)
    temp = 0
    while temp < l:
        if temp == (l - 1) and data[temp] > 127:
            return False
        if data[temp] <= 127 and data[temp] >= 0:
            temp += 1
            continue
        size = 0
        for i in bin(data[temp])[2:].zfill(8):
            if i == '0':
                break
            size += 1
        for i in data[temp + 1: temp + size]:
            if bin(i)[2:].zfill(8)[:2] == '11':
                return False
        temp += size
        if size > 4 or temp > l:
            return False
    return True
