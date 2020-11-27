#NAMA   :   Dimas Farhan Anshari
#NIM    :   18219001
#TOPIC  :   Belah Ketupat
#DESKRIPSI : Membuat belah ketupat dari input

# Program BelahKetupat
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar belah ketupat sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan:

# KAMUS
# Variabel
#    N : int

def GambarBelahKetupat(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar belah ketupat dengan panjang diagonal mendatar sebesar N
#      sesuai spesifikasi soal
    for i2 in range(N,0,-2):
        print(" "*(N//2-i2//2) + "*"*i2)
    for i1 in range(1+2,N+1,2):
        print(" "*(N//2-i1//2) + "*"*i1)

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
    if ((N % 2)==1) and (N > 0):
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())

if IsValid(N):
    GambarBelahKetupat(N)
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")