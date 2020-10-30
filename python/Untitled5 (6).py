#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#Barra Alfarisi Abadi // 16519007

count = 0
tot = 0
lulus = 0
n = int(input())

if (n == -9999):
    print("Data nilai kosong")
else:
    while (n != -9999):
        if (n >= 0) and (n <= 100):
            count += n
            tot += 1
            if (n>=40):
                lulus += 1
            else:
                lulus += 0
            n = int(input())
        else:
            n = int(input())
    if (tot == 0):
        print(tot)
    else:
        print(tot)
        print(lulus)
        print(tot - lulus)
        print("%.2f" % (count / tot))

