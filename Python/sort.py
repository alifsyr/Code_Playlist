# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 3 December 2020
# Deskripsi : program yang menerima input bilangan, misalnya N dan menerima N buah input bilangan yang disimpan di sebuah array. Lalu, implementasikan algoritma sorting

def get_max(arr, index_start):
# mendapatkan maksimum array dari indeks indeks_start sampai selesai
    return max(arr[index_start:])

def get_idx(arr, number):
# mendapatkan index dari suatu angka dalam array
    for i in range(len(arr)):
        if number == arr[i]:
            return i

def swap(array, indeks_1, indeks_2):
# swap elemen array indeks 1 dengan indeks 2
    x = array[indeks_2]
    array[indeks_2] = array[indeks_1]
    array[indeks_1] = x

def sort(arr):
    for i in range(len(arr)):
        maxArr = get_max(arr, i)
        maxIdx = get_idx(arr, maxArr)
        swap(arr, i, maxIdx)
    print(arr)

N = int(input())
arr = [int(input()) for i in range(N)]
sort(arr)