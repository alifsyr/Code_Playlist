# NIM/Nama : 16519080/Zachrandika Alif Syahreza
# Tanggal : 8 april 2020
# Deskripsi : Program Cari Character

# Kamus
#    N,i : integer
#    A : Array [0..N-1] of character
#    CC : character
#    founds, foundl, foundx : boolean

# Algoritma
N = int(input(""))

# Validasi Input hingga diperoleh input yang sesuai
while N<=0 or N>100:
    print("Masukan salah. Ulangi!")
    N = int(input(""))


A = ['' for i in range(N)] # Deklarasi Array untuk menyimpan inputan N buah character


for i in range(N): # Mengisi Array A
    A[i] = input("")[0]

CC = input("")[0] #Meminta input sebuah character CC
if CC == 'S' or CC == 's':
    founds = False
    for i in range (N):
        if founds == False and 97<=ord(A[i])<=122:
            founds = True
            print(i+1,A[i])
    if founds == False:
        print("Tidak ada huruf kecil")
elif CC == 'L' or CC == 'l':
    foundl = False
    for i in range(N):
        if foundl == False and 65<=ord(A[i])<=90:
            foundl = True
            print(i+1,A[i])
    if foundl == False:
        print("Tidak ada huruf besar")
elif CC == 'X' or CC == 'x':
    foundx = False
    for i in range(N):
        if foundx == False and not(65<=ord(A[i])<=90) and not(97<=ord(A[i])<=122):
            foundx = True
            print(i+1, A[i])
    if foundx == False:
        print("Semua huruf")
else:
    print("Tidak diproses")
