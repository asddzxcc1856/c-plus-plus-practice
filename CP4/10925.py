# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 14:33:15 2023

@author: t7878
"""

import sys

inputs = sys.stdin.read().splitlines()
caseNO = 1
ln = 0
while True:
    N, F = map(int,inputs[ln].split())
    ln += 1
    if N == 0 and F == 0:
        break
    sum = 0
    for _ in range(N):
        sum += int(inputs[ln])
        ln += 1
    print("Bill #{0} costs {1}: each friend should pay {2}\n".format(caseNO,sum,sum//F))
    caseNO += 1
    