//********************************************************************************
// * File Name          : microphone.ino
// * Author             : RadioShack Corporation
// * Version            : V2.0
// * Date               : 2014/03/21
// * Description        : When the microphone detects sounds above 105 dB (within 20cm)
// *                      robot moves forward.
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
MakeItRobotics mic; //declare object
int count=0;// count the number for trigger sound times
int light=0;

void setup() 
{ 
  Serial.begin(10420); //tell the Arduino to communicate with Make: it PCB
  delay(500);

  mic.sensor_kit_mic_setup();
  mic.all_stop();
}
// ***********************************************************************************************************
// *                            Main Loop 
// ***********************************************************************************************************
void loop() 
{  
 if(mic.read_mic()==LOW) // Detect trigger sound
 {
   count++;
   light=count%2;
   if(light==0) // if mic detects sound
   {
     mic.go_forward(250); //robot moves forward
   
     delay(50);
   }
   else //if mic doesn't detect sound
   {
     mic.go_forward(0); //robot doesn't move
  
     delay(50);
   }
 }
  
}

