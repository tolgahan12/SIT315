volatile byte r,g,b = 0;

void setupTimer1(){
  
}

void setup()
{
  	//Green
    pinMode(10, OUTPUT);
  	//Blue
    pinMode(11, OUTPUT);  
  	//Red
  	pinMode(12, OUTPUT);  
  	//On board Led Timer 
  	pinMode(13, OUTPUT);
  	//Motion sensors
  	pinMode(2, INPUT);
    pinMode(3, INPUT);
 	pinMode(4, INPUT);
	
  	noInterrupts();
 
  	PCICR |= 0b00000111;
  	PCMSK2 |= 0b10011100;
  
  	//Clear registers
  	TCCR1A = 0;
  	TCCR1B = 0;
  	TCNT1 = 0;
  	
  	// 0.25 Hz 
  	OCR1A = 31249;
  
  	//CTC
  	TCCR1B |= (1 << WGM12);
  
  	//Prescaler 1024
  	TCCR1B |= (1 << CS12) | (1 << CS10);
  	//Output comare match A interrupt enable
  	TIMSK1 |= (1 << OCIE1A);
  	

  	interrupts();
  	
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(12, r );
  	digitalWrite(10, g );
  	digitalWrite(11, b );
}

ISR(PCINT2_vect) 
{
  	//Red
 	r = PIND & B00010000;
  	if (r = PIND & B00010000)
    {
      Serial.println("Red!"); 
    }
  	//Green
  	g = PIND & B00000100;
    if (g = PIND & B00000100)
    {
      Serial.println("Green!"); 
    }
  	//Blue
  	b = PIND & B00001000;
    if (b = PIND & B00001000)
    {
      Serial.println("Blue!"); 
    }
}

ISR(TIMER1_COMPA_vect) 
{
  digitalWrite(13, digitalRead(13) ^ 1);
  
  Serial.println("On board LED on!"); 

  	
}