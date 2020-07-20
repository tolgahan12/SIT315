const uint8_t motionsensor_pin = 2;
const uint8_t led_pin = 13;

uint8_t led_state = LOW;

void setup()
{
  pinMode(motionsensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(motionsensor_pin), toggle, FALLING);
  
  Serial.begin(9600);
}

void loop()
{
  delay(10); 
}

void toggle() 
{
  	//Change led state
  	led_state = !led_state; 
	digitalWrite(led_pin, led_state);
  	//Print to serial monitor
  	if ( led_state )
    {
      Serial.println("Sensor activated!");  	
    }	
}
