# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 12 November 2020
# Deskripsi : program yang digunakan untuk membaca data umur 20 peserta pelatihan (integer > 0)
#Setelah nilai lengkap, program akan menuliskan semua nilai umur (diawali dengan indeks, lihat contoh), umur tertinggi, dan umur terendah.


P = [(int(input())) for i in range (20)]

for i in range (20):
    print("[P" + str(i+1) + "]" + str(P[i]))
print("Tertinggi =", max(P))
print("Terendah =", min(P))
