/**
 * Palindrome.java
 * Sebuah class yang memiliki method untuk mengecek apakah suatu string adalah palindrome atau bukan
 * @author 18219036 Zachrandika Alif Syahreza
 */
public class Palindrome {
    public boolean isStringPalindrome(String string) {
        int i = 0;
        int j = string.length() - 1;
        string = string.toLowerCase();
        if (string.length() == 0)
            return true;
        else 
            while (i<j) {
                if (string.charAt(i) != string.charAt(j))
                    return false;
                i += 1;
                j -= 1;
            }
        return true;
    }
}