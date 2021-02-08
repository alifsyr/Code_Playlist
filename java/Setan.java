/**
 * Setan.java
 * Setan.java merupakan abstrack class dari class setan yang lainnya
 * @author 18219036 Zachrandika Alif Syahreza
 */

public abstract class Setan {
    private String namaSetan;
    private String asalNegara;
    private int poin;

    public Setan(String namaSetan, String asalNegara) {
        // Inisialisasi nama dan negara asal setan
        // Poin awal tiap setan adalah 0
        this.namaSetan  = namaSetan;
        this.asalNegara = asalNegara;
        this.poin       = 0;
    }
    
    public String getNama() {
        // Mengembalikan nama setan
        return namaSetan;
    }
    
    public String getNegara() {
        // Mengembalikan asal negara setan
        return asalNegara;
    }
    
    public int getPoin() {
        // Mengembalikan poin terkini setan
        return poin;
    }
    
    protected void tambahPoint(int plusPoin) {
        // Menambahkan poin yang telah dimiliki setan
        poin = poin + plusPoin;
    }
    
    public abstract void sayHi();

    public void tarung(Setan lawan) {
        // Membandingkan nama setan dengan lawan
        // Dianggap menang jika nama setan > lawan (ex: vampir > pocong karena "v" > "p")
        // Jika nama setan dan lawan sama, pertarungan dianggap seri
        // Menang mendapatkan 3 poin
        // Kalah poin dikurangi 1
        // Seri tidak mendapatkan poin
        if (this.namaSetan.compareTo(lawan.namaSetan) > 0){
            this.tambahPoint(3);
        }
        else if (this.namaSetan.compareTo(lawan.namaSetan) < 0){
            this.tambahPoint(-1);
        }
    }
}