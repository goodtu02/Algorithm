n=int(input())

t=n//3
r=n%3
current="SK"
if t%2!=0:
    current="CY"

if r==0:
    if current=="SK":
        print("CY")
    else:
        print("SK")
elif r==1:
    print(current)
else:
    if current=="SK":
        print("CY")
    else:
        print("SK")

