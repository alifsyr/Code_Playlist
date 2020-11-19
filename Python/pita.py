# Tuliskan identitas di sini

# Program GambarPita
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar pita sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarPita(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar pita dengan lebar sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini
    for i2 in range(N,0,-2):
        print(" "*(N//2-i2//2) + "*"*i2)
    for i1 in range(1+2,N+1,2):
        print(" "*(N//2-i1//2) + "*"*i1)    

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    if ((N % 2)==1) and (N > 0):
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if (IsValid(N)):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarPita(N)    # lengkapi dengan pemanggilan prosedur GambarPita
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")