#define Pin_Alarm D4                      // Buzzer  alarm  connected to GPIO-14 or D5 of nodemcu
#define PIR_Sensor D0                     // PIR sensor output connected to GPIO-5 or D1 of nodemcu 
int Waiting_Time = 5000;                  // Time that your buzzer stay on in milliseconds, exemple; 10000 is 10 seconds 

void setup() {
  pinMode(PIR_Sensor, INPUT);             // PIR sensor as input  
  pinMode(Pin_Alarm, OUTPUT);             // Buzzer alaram as output
  digitalWrite(Pin_Alarm, LOW);           // Initially buzzer off
}

void loop(){
  int state = digitalRead(PIR_Sensor);    // Continuously check the state of PIR sensor
  delay(500);                             // Check state of PIR after every half second
  
    if(state == HIGH){                
      digitalWrite (Pin_Alarm, HIGH);     // If intrusion detected ring the buzzer
      delay(Waiting_Time);                // Ring buzzer for time the you put in integer WaitTimer in seconds                       
    }
    else {
      digitalWrite (Pin_Alarm, LOW);      // No intrusion Buzzer off
   }
}
