#include <tiny32.h>

tiny32 mcu;

void setup() {
  Serial.begin(115200);

}

void loop() {
  static int _state = 0;

  if(mcu.Sw1())
  {
    mcu.buzzer_beep(1);
    _state++;
    while(mcu.Sw1());
    if(_state > 2 )
    _state = 1;

    Serial.printf("State => [%d] \r\n",_state);

    if(_state == 1){
      mcu.Relay(1); //Relay => ON
      Serial.print("Relay => ON\r\n");
      mcu.RedLED(0);
      mcu.BlueLED(1);
    }
    else if(_state == 2){
      mcu.Relay(0); //Relay =>OFF
      Serial.print("Relay => OFF\r\n");
      mcu.BlueLED(0);
      mcu.RedLED(1);
    }
  }
}
