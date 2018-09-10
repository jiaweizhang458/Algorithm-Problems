a = [1,2,3,4,4,4,4,4,4,7]
target = 4

#Last
#left = -1
#right = len(a)
#while (left + 1 != right):
#    m = int((left + right)/2)
#    if (a[m] <= target):
#        left = m
#    else:
#        right = m
#if (left < len(a) and a[left] == target):
#    print (left)
#else:
#    print (-1)
    
#First
left = -1
right = len(a)
while (left + 1 != right):
    m = int((left + right)/2)
    if (a[m] >= target):
        right = m
    else:
        left = m
if (right >= 0 and a[right] == target):
    print(right)
else:
    print(-1)