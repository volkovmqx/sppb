boolean finish=false;

void setup() {
  
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  digitalWrite(9, 0);  // start with the "dot" off
  pinMode(0,INPUT);
  Serial.begin(9600);
  digitalWrite(10, HIGH); 
  digitalWrite(11, LOW); 
  
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
}

void loop() {
  //waiting for the "GO" signal , from the arduino to start working
 int test = digitalRead(0); 
 delay(2);
 int test2 = digitalRead(0);
 
 if(test==test2 && test==0) {
   digitalWrite(11, HIGH); 
   digitalWrite(10, LOW); 
   
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 1);
 delay(1000);
 // write '2'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 0);
 digitalWrite(8, 1);
 delay(1000);
 // write '1'
 digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 delay(1000);
 // write '0'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 delay(1000);
  digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
   Serial.println('g');
   while(1) {
      digitalWrite(11, LOW); 
      delay(500);
      digitalWrite(11, HIGH);
      delay(500);
     if(Serial.read()=='f') {
      
     finish=true; 
     break;
     }
   }
 }
 
 //After the raspberry finishe it works, it should send a signal to the arduino
 if(finish==true) {
    digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
    digitalWrite(11, LOW); 
   digitalWrite(10, HIGH); 
 }
}
