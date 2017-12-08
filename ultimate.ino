//HC RS04 Sensore ultrasuoni
int triggerPort = 7;
int echoPort = 8;
int buzzer = 6; 

int triggerPort_one = 9; 
int echoPort_one = 10; 
int buzzer_one = 13; 

int triggerPort_two = 11; 
int echoPort_two = 12; 
int buzzer_two = 5; 
 
void setup() {
 
pinMode(triggerPort, OUTPUT);
pinMode(triggerPort_one, OUTPUT); 
pinMode(triggerPort_two, OUTPUT); 

pinMode( echoPort, INPUT );
pinMode(echoPort_one, INPUT); 
pinMode(echoPort_two, INPUT); 

pinMode(buzzer, OUTPUT); 
pinMode(buzzer_one, OUTPUT); 
pinMode(buzzer_two, OUTPUT); 

Serial.begin( 9600 );
Serial.println( "Sensore ultrasuoni: ");
 
}
 
void loop() {
//porta bassa l'uscita del trigger
digitalWrite( triggerPort, LOW );
digitalWrite( triggerPort, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort, LOW );
long duration = pulseIn( echoPort, HIGH );
long r = 0.034 * duration / 2;


digitalWrite( triggerPort_one, LOW );
digitalWrite( triggerPort_one, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort_one, LOW );
long duration_one = pulseIn(echoPort_one, HIGH); 
long r_one = 0.034 * duration_one / 2; 

digitalWrite( triggerPort_two, LOW );
digitalWrite( triggerPort_two, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort_two, LOW );
long duration_two = pulseIn( echoPort_two, HIGH );
long r_two = 0.034 * duration_two / 2;
 
/*Serial.print( "durata: " );
Serial.print( duration );
Serial.print( " , " );*/
Serial.print( "distanza primo sensore: " );
 
//primo sensore
 
//dopo 38ms è fuori dalla portata del sensore
if( duration > 38000 ) Serial.println( "fuori portata");
else { 

Serial.print( r ); Serial.println( "cm" );

if (r < 50) {
 
 digitalWrite(buzzer, HIGH);  
  
}

else {
  
 digitalWrite(buzzer, LOW);  
  
}

}

//secondo sensore

Serial.print("distanza secondo sensore: "); 

if (duration_one > 38000 ) Serial.println("fuori portata!!");
else { 

Serial.print( r_one ); Serial.println( "cm" );

if (r_one < 50) {
  
 digitalWrite(buzzer_one, HIGH);  
  
}

else {
 
 digitalWrite(buzzer_one, LOW);  
  
}

}

//terzo sensore

Serial.print( "distanza terzo sensore: " );
 
//dopo 38ms è fuori dalla portata del sensore
if( duration_two > 38000 ) Serial.println( "fuori portata");
else { 

Serial.print( r_two ); Serial.println( "cm" );

if (r_two < 50) {
 
 digitalWrite(buzzer_two, HIGH);  
  
}

else {
  
 digitalWrite(buzzer_two, LOW);  
  
}

}

Serial.print("\n\n"); 
 
//aspetta 1.5 secondi
delay( 15 );
}
