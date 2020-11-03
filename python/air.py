#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum suhu
#Deskripsi  Menghitung suhu dari input bilangan

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
