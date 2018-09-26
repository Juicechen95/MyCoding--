import sys
import numpy as np
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    N = []
    for i in range(n):
        line = sys.stdin.readline().strip()
        L = line.split()
        N.append([int(c) for c in L])
    
    print(N)