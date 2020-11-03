# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 3 November 2020
# Deskripsi : program yang menerima masukan sebuah bilangan bulat, misal N dan kemudian menampilkan gambar belah ketupat bintang

# Program BelahKetupat
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar belah ketupat sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarBelahKetupat(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar belah ketupat dengan panjang diagonal mendatar sebesar N sesuai spesifikasi soal
    for i in range(1, N+1):
        i = i - (N//2 +1)
        if i < 0:
            i = -i
        print(" " * i + "*" * (N - i*2) + " " * i)

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
    if (N % 2 == 1 & N > 0):
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if (IsValid(N)):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarBelahKetupat(N)    # lengkapi dengan pemanggilan prosedur GambarBelahKetupat
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")