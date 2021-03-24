// SET NOMOR PIN
const int touchPin = 4;
const int ledPin1 = 16;
const int ledpin2 = 17;

const int thershold = 20;

// VARIABEL UNTUK MENYIMPAN NILAI TOUCH PIN
int touchValue;

void setup(){
  Serial.begin(11520);
  delay(1000);
  // MENGINISIASI LEDPIN1 DAN LEDPIN2 SEBAGAI OUTPUT
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
}

void loop(){
  // MEMBACA STATE YANG DIHASILKAN DARI NILAI TOUCHREAD
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // MELAKUKAN PENGECEKAN APAKAH NILAI TRESHOLD LEBIH KECIL DARI NILAI TOUCHVALUE
  // JIKA IYA MAKA MENYALAKAN LED
  if (touchValue < threshold){
    // MENYALAKAN LED
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2, HIGH);
  }
  else{
    // MATIKAN LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
