// set nomor pin
const int ledPin1 = 16;
const int ledPin2 = 17;

// variabel untuk menyimpan nilai touch pin
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000);
  // menginisiasi ledpin1 dan ledpin2 sebagai output
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
}

void loop(){
  // membaca state yang dihasilkan dari nilai hallRead
  int measurement = 0;
  measurement = hallRead();
  Serial.print(measurement);
  // mengecek apakah nilai threshold lebih kecil dari nilai hallRead
  // jika iya maka LED menyala
  if (measurement > threshold){
    // menyalakan LED
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    Serial.println(" - LED on");
  }
  else{
    // mematikan LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
