/**
 * Caesar.java 
 * Sebuah class yang berfungi mengenkripsi sebuah string dengan metode Caesar cipher
 * @author 18219036 Zachrandika Alif Syahreza
 */
public class Caesar {
    /**
     * Constructor
     * @param step berapa kali huruf digeser.
     * Misalnya step = 1, artinya A -> B, C -> D
     * Misalnya step = 2, artinya A -> C, D -> F
     */
    public Caesar(int step) {
        this.step = step;
    }

    /**
     * Encrypt -- mengenkripsi string menjadi sandi (ciphertext)
     * 
     * @param string Plain text string
     * @return ciphertext
     */
    public String encrypt(String string) {
        // TODO lengkapi
        int step;
        String cipher = "";
        char c;
        int i = 0;
        int j = string.length();
        for (i < j; i++){
            c = string.charAt(i);
            if (isCharAlphabetic(c)){
                shiftChar(c, step);
            }
        }
    }

    /**
     * Is Char Alphabetic -- memeriksa apakah suatu karakter adalah alfabet (A-Z)
     * atau bukan.
     * 
     * @param c karakter
     * @return apakah c alfabetik
     */
    private boolean isCharAlphabetic(char c) {
        return Character.isAlphabetic(c);
    }

    /**
     * Shift Char -- geser karakter sebanyak step langkah
     * 
     * @param c karakter A-Z huruf kapital
     * @return karakter yang sudah digeser sebanyak step
     */
    private char shiftChar(char c, int step) {
        // TODO lengkapi
        if (c >= 'A' && c <= 'Z'){
            c = (char) (c + step);
        }
        else if (c > 'Z'){
            c = (char) (c + 'A' - 'Z' - 1);
        }
        return c;
    }
}