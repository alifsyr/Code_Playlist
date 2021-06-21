class Pelanggan_grace {
    public PublicData publicdata;
    private PrivateData privatedata;

    // definisikan enum
    enum JenisPelanggan {
        VIP,
        MEMBER,
        NONMEMBER,
    }

    // definisikan nested class
    private class PrivateData {
        private String namaIbu;
        private JenisPelanggan member;
    }

    public class PublicData {
        public String nama;
    }

    // definisikan konstruktor
    public Pelanggan_grace(String nama, String namaIbu) {
        privatedata = new PrivateData();
        publicdata = new PublicData();
        this.publicdata.nama = nama;
        this.privatedata.namaIbu = namaIbu;
        this.privatedata.member = JenisPelanggan.NONMEMBER;
    }

    // definisikan getter
    public JenisPelanggan getjenispelanggan() {
        return privatedata.member;
    }

    public String getnamaibu() {
        return privatedata.namaIbu;
    }


    // definisikan setter
    public void setjenispelanggan(JenisPelanggan jenis) {
        privatedata.member = jenis;
    }

    public void setnamaibu (String namaIbu) {
        this.privatedata.namaIbu = namaIbu;
    }




}
