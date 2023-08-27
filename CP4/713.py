# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 15:13:15 2023

@author: t7878
"""

import sys

inputs = sys.stdin.read().splitlines()

ln = 0
num = int(inputs[ln])
ln += 1
for _ in range(num):
    a,b = inputs[ln].split()
    ln += 1
    
    a = int(a[::-1])
    b = int(b[::-1])
    print(int(str(a + b)[::-1]))