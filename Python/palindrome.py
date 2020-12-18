# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 3 December 2020
# Deskripsi : 

def BacaArray(N):
    arr = [input() for i in range(N)]
    palindrome = IsPalindrome(arr,N)
    if palindrome:
        tulisArray(arr)
        print("\nPalindrom")
    else:
        tulisArray(arr)
        print("\nBukan palindrom")

def IsPalindrome(arr,N):
    for i in range(len(arr)//2):
        if arr[i] == arr[N-1-i]:
            palindrome = True
        else:
            return False
    return palindrome

def tulisArray(arr):
    for i in arr:
        print(i,end="")

N = int(input())
if N > 1:
    BacaArray(N)
elif N == 1:
    x = input()
    print(x)
    print("Palindrom")
else:
    print("Array kosong")