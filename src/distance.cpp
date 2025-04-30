
#include <Arduino.h>
#include "Cmd.h"
#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void distance_init(){
  Wire.begin();
  //Wire.setClock(400000); 
  Wire.setClock(10000);
  sensor.init();
  sensor.configureDefault();
  sensor.setTimeout(500);
}


void distance_read(int args_num,char **args){
    Stream *s = cmdGetStream();
    s->print(sensor.readRangeSingleMillimeters());
    if (sensor.timeoutOccurred()) { s->print(" TIMEOUT"); }
    s->println();
  }
  