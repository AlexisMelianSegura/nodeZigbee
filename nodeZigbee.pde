/**
 * \file nodoZigbee.pde
 * \author Alexis Melian Segura
 * \date 21/08/19
 * \brief Program that defines the operation of a Zigbee node.
 */

/****************************************************************************
*                             Includes                                     *
****************************************************************************/

#include "Zigbee.h"
#include "Conversions.h"
#include "Board.h"

#define DEBUG 1

/** Time which the board will be in sleep mode. Format (days:hours:minutes:seconds). */
char SLEEP_TIME[] = "00:00:02:00";

void setup(){
  
  // The serial bus is initialized.
  #if DEBUG == 1
    USB.ON();
    USB.println(F("Sensor Node"));
  #endif

  // The accelerometer is initialize.
  ACC.ON();

  zigbee_object.init_Zigbee();

}


void loop(){
  
  // The procedure in charge of sending the sensor data that is set by parameters is called. (In this case the battery level data of the board is sent).
  uint8_t datos[4];
  *datos = PWR.getBatteryLevel();  
  zigbee_object.addBoardSensor(SENSOR_BAT, datos, sizeof(PWR.getBatteryLevel()));
  
  zigbee_object.addBoardSensor(SENSOR_ACC, ACC.getX(), ACC.getY(), ACC.getZ(), 4);
  zigbee_object.addBoardSensor(SENSOR_ACC, ACC.getX(), ACC.getY(), ACC.getZ(), 4);
  zigbee_object.addBoardSensor(SENSOR_ACC, ACC.getX(), ACC.getY(), ACC.getZ(), 4);
  zigbee_object.addBoardSensor(SENSOR_ACC, ACC.getX(), ACC.getY(), ACC.getZ(), 4);
  
  zigbee_object.sendDataBoardSensor(); 

  board_object.sleepBoard(SLEEP_TIME);

  #if DEBUG == 1
    USB.ON();
  #endif
  
  zigbee_object.init_Zigbee();
  ACC.ON();
}
