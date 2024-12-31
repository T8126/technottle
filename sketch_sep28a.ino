 
unsigned long lastbutton;


void clear(){
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
  digitalWrite(12,0);
  digitalWrite(A0,0);
  digitalWrite(A1,0);
  digitalWrite(A2,0);
  digitalWrite(A3,0);
  digitalWrite(A4,0);
  digitalWrite(A5,0);
}

void display_num_left(int number){
  if (number == 0){
    digitalWrite(A4,1);
    digitalWrite(A3,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(A2,1);    
  }
  if (number == 1){
    digitalWrite(A0,1);
    digitalWrite(A2,1);
  }
  if (number == 2){
    digitalWrite(A3,1);
    digitalWrite(A2,1);
    digitalWrite(A5,1);
    digitalWrite(11,1);
    digitalWrite(12,1);
    
  }
  if (number == 3){
    digitalWrite(A3,1);
    digitalWrite(A2,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
    
  }
  if (number == 4){
    digitalWrite(A4,1);
    digitalWrite(A2,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
  }
  if (number == 5){
    digitalWrite(A4,1);
    digitalWrite(A3,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
      }
  if (number == 6){
    digitalWrite(A4,1);
    digitalWrite(A3,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
  }
  if (number == 7){
    digitalWrite(A0,1);
    digitalWrite(A2,1);
    digitalWrite(A3,1);
  }
  if (number == 8){
    digitalWrite(A4,1);
    digitalWrite(A3,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(A2,1);    
  }
  if (number == 9){
    digitalWrite(A4,1);
    digitalWrite(A3,1);
    digitalWrite(A5,1);
    digitalWrite(A0,1);
    digitalWrite(12,1);
    digitalWrite(A2,1);
  }
}

void display_num_right(int number){
  if (number == 0){
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(7,1);    
  }
  if (number == 1){
    digitalWrite(5,1);
    digitalWrite(7,1);
  }
  if (number == 2){
    digitalWrite(8,1);
    digitalWrite(7,1);
    digitalWrite(10,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    
  }
  if (number == 3){
    digitalWrite(8,1);
    digitalWrite(7,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    
  }
  if (number == 4){
    digitalWrite(9,1);
    digitalWrite(7,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
  }
  if (number == 5){
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
      }
  if (number == 6){
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
  }
  if (number == 7){
    digitalWrite(5,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  if (number == 8){
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(7,1);    
  }
  if (number == 9){
    digitalWrite(9,1);
    digitalWrite(8,1);
    digitalWrite(10,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(7,1);
  }
}

void setup() {
  Serial.begin(9600);
  lastbutton = 0;
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A7, OUTPUT);
}

void loop() {

  bool value = digitalRead(2);
  if (value == 0) {
    Serial.println("hello!");
    lastbutton = millis()*120;

  } else {
    Serial.println("oh no");
  }
  unsigned long timesbutton = millis()*120-lastbutton;
  int mins = floor(timesbutton/60000);

  if ((60-mins) <= 0) {
    if (((int) floor(timesbutton/12000))%2 == 0) {
      digitalWrite(A7, HIGH);
    } else {
      digitalWrite(A7, LOW);
    }
  }

  int left = floor((60-mins)/10); 
  int right = (60-mins)%10;
  clear();
  display_num_right(right);
  display_num_left(left);
}
