/**
 * Pelanggan.java 
 * @author 18219036 Zachrandika Alif Syahreza
 */
class Pelanggan {
    public PublicData publicdata;
    private PrivateData privatedata;

    public enum JenisPelanggan {
        VIP, MEMBER, NONMEMBER;
    }

    public class PublicData {
        String nama;
    }

    private class PrivateData {
        String namaibu;
        JenisPelanggan jenispelanggan;
    }

    public Pelanggan(String nama, String namaibu) {
        privatedata = new PrivateData();
        publicdata = new PublicData();
        this.publicdata.nama = nama;
        this.privatedata.namaibu = namaibu;
        this.privatedata.jenispelanggan = JenisPelanggan.NONMEMBER;
    }

    public String getnamaibu() {
        return privatedata.namaibu;
    }

    public void setnamaibu(String ibu) {
        this.privatedata.namaibu = ibu;
    }

    public JenisPelanggan getjenispelanggan() {
        return privatedata.jenispelanggan;
    }

    public void setjenispelanggan(JenisPelanggan jenis) {
        this.privatedata.jenispelanggan = jenis;
    }

}