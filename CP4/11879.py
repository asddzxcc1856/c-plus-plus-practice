import sys

inputs = sys.stdin.read().splitlines()

ln = 0
while True:
    inp = int(inputs[ln])
    ln += 1
    if(inp == 0):
        break
    if inp % 17 == 0:
        print(1)    
    else:
        print(0)