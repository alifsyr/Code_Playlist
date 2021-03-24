/**
 * UnderpaidException.java
 * @author 18219036 Zachrandika Alif Syahreza
 */
public class UnderpaidException extends Exception{
    private int deficit;
    // Konstruktor
    public UnderpaidException(int angka){
        deficit = angka;
    }
    public String getErrorMessage(){
        return ("Bayarnya kurang " + this.deficit + " nih, istri saya 6 :(");
    }
}