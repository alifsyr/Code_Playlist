// set nomor pin
const int touchPin = 4; 
const int ledPin1 = 16;
const int ledPin2 = 17;

const int threshold = 20;

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
  // membaca state yang dihasilkan dari nilai touchRead
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // melakukan pengecekan apakah nilai treshold lebih kecil dari nilai touchValue
  // jika iya maka menyalakan LED
  if(touchValue < threshold){
    // menyalakan LED secara blinking
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(250);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(250);
    Serial.println(" - LED on");
  }
  else{
    // matikan LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  delya(500);
}
