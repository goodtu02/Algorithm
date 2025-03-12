import sys

n=int(sys.stdin.readline())
dpfib=[1,1]
for i in range(2,42):
    dpfib.append(dpfib[i-1]+dpfib[i-2])

print(dpfib[n-1],n-2)