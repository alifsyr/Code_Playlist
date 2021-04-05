public class BankVincent {
    private FraudService fraudService;
    private NotifierService notifierService;
    private Integer saldoNasabah1 = 2000;
    private Integer saldoNasabah2 = 2000;
    private Integer saldoNasabah3 = 2000;
    private Integer saldoNasabah4 = 2000;

    public BankVincent(FraudService fraudService, NotifierService notifierService) {
        this.fraudService = fraudService;
        this.notifierService = notifierService;
    }

    public void debit(int transactionId, int nasabah, int nominal) {
        // Method debit mengurangi saldo milik nasabah.
        // Pada method ini kamu harus menggunakan fraudService.isFraud(nominal) untuk
        // memeriksa apakah transaksi adalah penipuan.

        if (fraudService.isFraud(getSaldo(nasabah),nominal) == true){
            trxFraudulent(transactionId, nasabah, nominal);
        }else if (getSaldo(nasabah) - nominal >= 0){
            int saldoBaru = getSaldo(nasabah) - nominal;
            if(nasabah == 1){
                this.saldoNasabah1 = saldoBaru;
            }else if(nasabah == 2){
                this.saldoNasabah2 = saldoBaru;
            }else if(nasabah == 3){
                this.saldoNasabah3 = saldoBaru;
            }else{
                this.saldoNasabah4 = saldoBaru;
            }
            trxCompleted(transactionId, nasabah, nominal, saldoBaru);
        }else{
            int saldoLama = getSaldo(nasabah) - nominal;
            insufficientFunds(transactionId,nasabah,nominal,saldoLama);
        }

        // Apabila isFraud() == true, kamu harus memanggil method trxFraudulent().
        // Apabila transaksi berhasil, kamu harus memanggil method trxCompleted().
        // Apabila saldo tidak cukup, kamu harus memanggil method insufficientFunds().
    }

    public void credit(int transactionId, int nasabah, int nominal) {
        // Method credit menambah saldo milik nasabah.
        // Pada method ini kamu harus menggunakan fraudService.isFraud(nominal) untuk
        // memeriksa apakah transaksi adalah penipuan.

        if (fraudService.isFraud(getSaldo(nasabah),nominal) == true){
            trxFraudulent(transactionId, nasabah, nominal);
        }
        // Apabila isFraud() == true, kamu harus memanggil method trxFraudulent().
        // Apabila transaksi berhasil, kamu harus memanggil method trxCompleted().

    }

    public int getSaldo(int nasabah) {
        switch (nasabah) {
        case 1:
            return saldoNasabah1;
        case 2:
            return saldoNasabah2;
        case 3:
            return saldoNasabah3;
        case 4:
            return saldoNasabah4;
        }
    }

    private void trxFraudulent(int transactionId, int nasabah, int nominal) {
        notifierService.fraudulentTransaction(transactionId, nasabah, nominal);
    }

    private void trxCompleted(int transactionId, int nasabah, int nominal, int saldoBaru) {
        notifierService.transactionCompleted(transactionId, nasabah, nominal, saldoBaru);
    }

    private void insufficientFunds(int transactionId, int nasabah, int nominal, int saldoLama) {
        notifierService.insufficientFunds(transactionId, nasabah, nominal, saldoLama);
    }
}