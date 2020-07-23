volatile byte r,g,b = 0;

void setup()
{
  	//Green
    pinMode(10, OUTPUT);
  	//Blue
    pinMode(11, OUTPUT);  
  	//Red
  	pinMode(12, OUTPUT);  
  	//Motion sensors
  	pinMode(2, INPUT);
    pinMode(3, INPUT);
 	pinMode(4, INPUT);

 
  	PCICR |= 0b00000111;
  	PCMSK2 |= 0b10011100;
  
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
