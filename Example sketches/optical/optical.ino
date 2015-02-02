//********************************************************************************
// * File Name          : optical.ino
// * Author             : RadioShack Corporation
// * Version            : V2.0
// * Date               : 2014/03/21
// * Description        : Robot moves forward when sensor detects light reflection
// *                      from objects. 
// ********************************************************************************
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ********************************************************************************

#include <MakeItRobotics.h> //include library
MakeItRobotics optical; //declare object
// ***********************************************************************************************************
// *                            Power Up Init.
// ***********************************************************************************************************
void setup() 
{ 
  Serial.begin(10420); //tell the Arduino to communicate with Make: it PCB
  delay(500);
 
  optical.line_following_setup();
  optical.all_stop();
}
// ***********************************************************************************************************
// *                            Main Loop 
// ***********************************************************************************************************
void loop() 
{  
  static int sensorValue1 = 0;
  static int sensor_in;
  static long sensorTimer1 = millis();
  static long sensorTimer2 = millis();
  static int action1 = 0;
  //**************************************************
  //  Trigger Left/Right optical every 15 milliseconds
  //************************************************** 
  sensorTimer2 = millis();
  if (sensorTimer2 - sensorTimer1 > 15)
  {
    sensorTimer1 = sensorTimer2;
    optical.trigger_optical1();
  }            
  //**************************************************************
  //  Read Left/Right optical status
  //**************************************************************
  sensor_in=optical.read_optical();
  if((sensor_in & 0xf00)==0)
    sensorValue1=sensor_in & 0xff;
  if (sensorValue1 == 0x00)
    action1 =0;
  if (sensorValue1 == 0xFF)
    action1 = 1;  
  //*************************************************************
  //   Make Robot Move
  //*************************************************************
  if (action1 == 1) //if sensor detects specified light reflection
    optical.go_forward(250); //robot moves forward
        
  if (action1 == 0) //if sensor doesn't detect light reflection
    optical.go_forward(0); //robot doesn't move
    
    
}

