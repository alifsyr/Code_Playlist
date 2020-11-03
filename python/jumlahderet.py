#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum jumlah deret
#Deskripsi  Menghitung jumlah deret

N = int(input())

def jumlah_deret (N):
    if (N==1):
        return (N)
    else:
        i = 1
        count = 0
        while i <= N:
            count = count + i
            i += 1
        return (count)
print(jumlah_deret(N))