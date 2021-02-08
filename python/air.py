#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum suhu
#Deskripsi  Menghitung suhu dari input bilangan
'''
T = int(input())

def suhu(T):
    if (T < 0):
        return ("PADAT")
    elif ((T > 0)and(T < 100)):
        return("CAIR")
    elif (T > 100):
        return("GAS")
    elif (T == 0):
        return("ANTARA PADAT-CAIR")
    else:
        return("ANTARA CAIR-GAS")
print(suhu(T))
'''
#Fungsi Kalkulator Sederhana
def kalkulator (angka1,angka2,op):
    # Menghasilkan hasil kalkulasi 2 bilangan bulat sesuai dengan operasi

    # Kamus Lokal
    # hasil_kalkulasi : integer

    # Algoritma
    if (op == 1):
        hasil_kalkulasi = angka1 + angka2

    elif (op == 2):
        hasil_kalkulasi = angka1 - angka2

    elif (op == 3):
        hasil_kalkulasi = angka1 / angka2

    elif (op == 4):
        hasil_kalkulasi = angka1 * angka2

    return hasil_kalkulasi

#Fungsi cetak hasil
def cetak(angka1,angka2,op,hasil):
    # Algoritma
    if (op == 1):
        print(angka1,'+',angka2,'=',hasil)
    elif (op == 2):
        print(angka1,'-',angka2,'=',hasil)
    elif (op == 3):
        print(angka1,'/',angka2,'=',hasil)
    else:
        print(angka1,'*',angka2,'=',hasil)
    return

angka1 = int(input("Masukkan angka 1: "))
angka2 = int(input("Masukkan angka 2: "))
print("Operasi yang dapat dilakukan:")
print("-Penjumlahan(1)")
print("-Pengurangan(2)")
print("-Pembagian(3)")
print("-Perkalian(4)")
op = int(input("Masukan operasi yang ingin dilakukan: "))
while (op > 4):
    print("Operasi tidak valid")
    op = int(input("Masukan operasi yang ingin dilakukan: "))
hasil= kalkulator(angka1,angka2,op)
cetak(angka1,angka2,op,hasil)