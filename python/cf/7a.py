n = input()
for i in range(0,n):
    a = raw_input()
    l = len(a)
    if l <= 10 :
        print a
    else :
        print a[0] + str(l-2) + a[l-1]
    
