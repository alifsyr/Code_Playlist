#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum Max 3 bilangan
#Deskripsi  Menghitung max dari 3 input bilangan

#Fungsi mengecek angka terbesar dari 3 input bilangan bulat
def max3bil(angka1,angka2,angka3):
    #Menghasilkan angka terbesar

    #Algoritma
    if (angka1 >= angka2) and (angka1 >= angka3):
        return angka1
    elif (angka2 >= angka1) and (angka2 >= angka3):
        return angka2
    else:
        return angka3

angka1 = int(input("Masukan angka 1: "))
angka2 = int(input("Masukan angka 2: "))
angka3 = int(input("Masukan angka 3: "))
print("Angka terbesar adalah",max3bil(angka1,angka2,angka3))