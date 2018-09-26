import sys
import numpy as np
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    N = 100
    wall = np.zeros(N)
    for i in range(n):
        line = sys.stdin.readline().strip()
        L = line.split()
        l = int(L[0])
        r = int(L[1]) + 1
        wall[l:r] = i+1
    wall.sort()
    count = 0
    for i in range(N-1):
        if wall[i] != wall[i+1]:
            count = count + 1  

    
    print count