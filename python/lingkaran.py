#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum Lingkaran
#Deskripsi  Menghitung luas lingkaran

x = int(input())

if (x <= 0):
    print("Jari-jari harus > 0")
else:
    luas =3.1415 * x * x
    print("%.2f" %luas)