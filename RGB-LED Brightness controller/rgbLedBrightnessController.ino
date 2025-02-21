int blue = 9; 
int green = 10;
int red = 11;
int redPot = A0;
int greenPot = A1; 
int bluePot = A2;
int greenVal = 0; 
int blueVal = 0;
int redVal = 0;
const int BUTTON = 7; 
int state = 0;    
int val = 0;      
int old_val = 0;  

void setup() {
  pinMode(green, OUTPUT);  
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.begin(9600);                       
  val = digitalRead(BUTTON);                
  if ((val == HIGH) && (old_val == LOW)) {  
    state = 1 - state;                      
    delay(10);                      
  }
  old_val = val;                           
  greenVal = analogRead(greenPot);          
  blueVal = analogRead(bluePot);
  redVal = analogRead(redPot);

  if (state == 1) {                         
    analogWrite(green, greenVal / 4);       
    analogWrite(blue, blueVal / 4);        
    analogWrite(red, redVal / 4);           
    Serial.print("RGB(");
    Serial.print(redVal/4); 
    Serial.print(",");
    Serial.print(greenVal/4); 
    Serial.print(",");
    Serial.print(blueVal/4);                 
    Serial.println(")");
    delay(50);
  } else {                                   
    analogWrite(green, 0);
    analogWrite(blue, 0);
    analogWrite(red, 0);
    delay(50);
  }
}
