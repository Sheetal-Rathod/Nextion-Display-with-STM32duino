HardwareSerial Serial2(USART2); 
int count = 0;
void setup() 
{
 Serial2.begin(9600);
  pinMode(PC13, OUTPUT);
}

void loop() 
{ 
  String Data_From_Display = "";
   if(Serial2.available())
 {
  
  String Data_From_Display = "";
  delay(100);
  while(Serial2.available())
  {
    Data_From_Display += char(Serial2.read());
  }
    if( Data_From_Display == "ON")
     { digitalWrite(PC13, LOW);}
    else if( Data_From_Display == "OFF")
     { digitalWrite(PC13, HIGH); }
    else
    { 
         char str[10];
     //  sprintf(str, "%c%d%c", '"', count, '"');
         //sprintf(str, "%c%s%c", '"',  Data_From_Display ,'"');
         Serial2.print("page0.t0.txt=" + String('"') + Data_From_Display + String('"'));
         //Serial.print("page0.t0.txt=" + String(str));
       
       Serial2.write(0xff);
       Serial2.write(0xff);
       Serial2.write(0xff);
    }
  }
}
     
