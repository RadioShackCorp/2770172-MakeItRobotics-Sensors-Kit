//********************************************************************************
// * File Name          : infrared.ino
// * Author             : RadioShack Corporation
// * Version            : V2.0
// * Date               : 2014/03/21
// * Description        : Move robot forward when sensor detects
// *                      movement within detection distance.
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
MakeItRobotics infrared; //declare object
int pirPin=10; //assign pin
int WarmUpTime =30; // default time 30 sec
//SETUP
void setup() 
{
  Serial.begin(10420); //tell the Arduino to communicate with Make: it PCB
  delay(500);
  infrared.sensor_kit_infrared_setup();
  infrared.all_stop();  //give the sensor time to warm up
  for(int i=0; i<WarmUpTime;i++)
  {
    infrared.go_forward(255);
    delay(500);
    infrared.go_forward(0);
    delay(500);
  }
}
// ***********************************************************************************************************
// *                            Main Loop 
// ***********************************************************************************************************
void loop() 
{  
  if(digitalRead(pirPin)==LOW) //if PIR detects motion
  {
    infrared.go_forward(250); //move robot forward
    delay(50);
  }
  else //if PIR doesn't detect motion
  {
    infrared.go_forward(0); //do not move
    delay(50); 
}
}

