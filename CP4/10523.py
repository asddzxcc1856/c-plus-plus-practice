import sys

inputs = sys.stdin.read().splitlines()

for ln in range(len(inputs)):
    N,A = map(int,inputs[ln].split())
    sum = 0
    for i in range(1,N + 1):
        sum += i * A ** i
    print(sum)