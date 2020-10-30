# NIM/Nama : 16519080/Zachrandika Alif Syahreza
# Tanggal : 8 april 2020
# Deskripsi : program yang digunakan untuk membaca data umur 20 peserta pelatihan (integer > 0)


P = [(int(input())) for i in range (20)]

for i in range (20):
    print("[P" + str(i+1) + "]" + str(P[i]))
print("Tertinggi =", max(P))
print("Terendah =", min(P))
