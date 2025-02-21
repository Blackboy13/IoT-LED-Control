#include <IRremote.h>    
int led = 5;             
int RECV_PIN = 6;        
int glow = 0;            
IRrecv irrecv(RECV_PIN); 
decode_results results;  

void setup()
{
    pinMode(led, OUTPUT); 
    Serial.begin(9600);   
    irrecv.enableIRIn();  
}

void loop()
{
    if (irrecv.decode(&results)) 
    {
        unsigned int value = results.value; 
        Serial.println(value);             

        if (value == 255)
        { 
            if (glow == 0)
            {                            
                digitalWrite(led, HIGH); 
                glow = 1;                
            }
            else
            {                           
                digitalWrite(led, LOW); 
                glow = 0;               
            }
        }

        irrecv.resume(); 
    }
}
