#Nama/Nim : Ari Pardomuan Manurung/16519044
#Tanggal  : Rabu, 1 April 2020
#Topik praktikum : Topik 6
#Deskripsi :  program yang digunakan untuk
#             membaca sebuah integer positif N. Nilai N harus divalidasi
#             sampai didapatkan nilai N yang benar, yaitu 0 < N <= 100.
#             Jika masukan N salah, tuliskan pesan “Masukan salah. Ulangi!”.
#             Setelah didapatkan nilai N yang benar, program meminta masukan
#             N buah character.

#Algoritma
N = int(input())
while (N <= 0 or N > 100):
      print("Masukan salah. Ulangi!")
      N = int(input())
T = [(input())[0] for i in range(N)]
CC = ((input())[0]).lower()
found = False
if not(CC == 's' or CC == 'l' or CC == 'x'):
      print("Tidak diproses")
else:
      for i in range(N):
            if (CC == 's') and (ord(T[i]) >= 97) and (ord(T[i]) <= 122):
                  print("%d %s" % ((i+1), T[i]))
                  found = True
                  break
            if (CC == 'l') and (ord(T[i]) >= 65) and (ord(T[i]) <= 90):
                  print("%d %s" % ((i+1), T[i]))
                  found = True
                  break
            if (CC == 'x' and ((ord(T[i]) < 65 or ord(T[i]) > 122))):
                  print("%d %s" % ((i+1), T[i]))
                  found = True
                  break
      if not(found):
            if CC == 's' or CC == 'l':
                  print("Tidak ada huruf ", end="")
            if CC == 's':
                  print("kecil")
            if CC == 'l':
                  print("besar")
            if CC == 'x':
                  print("Semua huruf")
