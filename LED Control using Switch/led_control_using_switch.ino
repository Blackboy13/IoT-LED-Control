int button = 7;
void setup()
{
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT);       
}

void loop()
{
   
    if (digitalRead(button) == HIGH)
        digitalWrite(LED_BUILTIN, HIGH);
    else
        digitalWrite(LED_BUILTIN, LOW);
}
