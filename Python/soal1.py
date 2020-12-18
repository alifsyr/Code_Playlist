'''
n = int(input("masukan nilai n: "))
a = []
print("Masukan matriks: ")
for i in range(n):
    b = []
    for j in range (n):
        elmnt = int(input())
        b =  b + [elmnt]
    a = a + [b]

x = input("Apa yang ditukar (baris/kolom): ")
if x == "baris":
    y = int(input("Masukan indeks baris/kolom pertama: "))
    z = int(input("Masukan indeks baris/kolom kedua: "))
    a[y-1],a[z-1] = a[z-1],a[y-1]
elif x == 'kolom':
    y = int(input("Masukan indeks baris/kolom pertama: "))
    z = int(input("Masukan indeks baris/kolom kedua: "))
    for i in range(n):
        a[i][y-1],a[i][z-1] = a[i][z-1],a[i][y-1]

print("Matriks akhir:")
for i in range(n):
    for j in range(n):
        print(a[i][j],end = " ")
    print()

'''
m = int(input("Masukan nilai m: "))
n = int(input("Masukan nilai n: "))
a = []
for i in range(m):
    b = []
    for j in range (n):
        elmnt = int(input("Masukan elemen ke "+str(i+1)+" "+str(j+1)+": "))
        b =  b + [elmnt]
    a = a + [b]

endprogram = False
while(not endprogram):
    x = input("Masukan operator: ")
    if x == "b":
        y = int(input("Masukan baris pertama yang ingin ditukar: "))
        while y > m:
            print("Indeks baris tidak terdefinisi!")
            y = int(input("Masukan baris pertama yang ingin ditukar: "))
        z = int(input("Masukan baris kedua yang ingin ditukar: "))
        while z > m:
            print("Indeks baris tidak terdefinisi!")
            z = int(input("Masukan baris kedua yang ingin ditukar: "))
        a[y-1],a[z-1] = a[z-1],a[y-1]

    elif x == "k":
        y = int(input("Masukan kolom pertama yang ingin ditukar: "))
        while y > n:
            print("Indeks kolom tidak terdefinisi!")
            y = int(input("Masukan kolom pertama yang ingin ditukar: "))
        z = int(input("Masukan kolom pertama yang ingin ditukar: "))
        while z > n:
            print("Indeks kolom tidak terdefinisi!")
            z = int(input("Masukan kolom pertama yang ingin ditukar: "))
        for i in range(m):
            a[i][y-1],a[i][z-1] = a[i][z-1],a[i][y-1]

    elif x == "x":
        print("Kondisi matriks sekarang adalah")
        for i in range(m):
            for j in range(n):
                print(a[i][j],end = " ")
            print()
        endprogram = True
    else:
        print("Operator tidak terdaftar!")