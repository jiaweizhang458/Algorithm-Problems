# Return max length of sublist that contains only two elements.

a = [1,2,3,4,3,3,4,2]
dic = {}

cur_res = 0
max_res = 0
i = 0
j = 0
while ( i < len(a)):
    if (a[i] not in dic) and (len(dic) == 2):
        max_res = max(max_res, cur_res)
        while (j < i):
            dic[a[j]] -= 1
            cur_res -= 1
            if (dic[a[j]] == 0):
                del(dic[a[j]])
                dic[a[i]] = 1
                cur_res += 1
                j += 1
                break
            j += 1
    elif (a[i] not in dic) and (len(dic) < 2):
        dic[a[i]] = 1
        cur_res += 1
    elif (a[i] in dic):
        dic[a[i]] += 1
        cur_res += 1
    i += 1
max_res = max(max_res, cur_res)