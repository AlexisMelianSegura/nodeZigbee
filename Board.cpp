/**
 * \file Board.cpp
 * \author Alexis Melian Segura
 * \date 20/08/19
 * \brief Program to modify the characteristics of the board.
 */

 /****************************************************************************
*                               Includes                                    *
****************************************************************************/

#include "Board.h"

/****************************************************************************
*                             Objects                                       *
****************************************************************************/

Board  board_object = Board();

/****************************************************************************
*                             Functions                                     *
****************************************************************************/

Board::Board() {
}


Board::~Board() {
}


void Board::sleepBoard(char* time_sleep){
  // Function responsible for turning off the communications and interfaces of the board, to sleep this.
  PWR.deepSleep(time_sleep,RTC_OFFSET,RTC_ALM1_MODE1,ALL_OFF);

  // Once the board wakes up, the flag associated with the interruption will be set to its initial value.
  if( intFlag & RTC_INT ){
    intFlag &= ~(RTC_INT);
  }
}
