/**
 * \file Board.h
 * \author Alexis Melian Segura
 * \date 20/08/19
 * \brief Program to modify the characteristics of the board.
 */

#ifndef BOARD_H
#define BOARD_H

/****************************************************************************
*                               Includes                                    *
****************************************************************************/

#ifndef __WPROGRAM_H__
  #include "WaspClasses.h"
#endif

/****************************************************************************
*                               Defines                                     *
****************************************************************************/

#define DEBUG_BOARD 1

/****************************************************************************
*                             Class                                         *
****************************************************************************/

class Board{

  public:

    /**
    * \fn Board()
    * 
    * Class constructor.
    */
    Board();
  
    /**
    * \fn ~Board()
    * 
    * Class destructor.
    */
    ~Board();
  
    /**
    * \ fn void sleepBoard(char* time_sleep)
    * \ param Time that the board is going to asleep. Format: day:hours:minutes:seconds.
     *
     * Function that is responsible for executing the process that sleeps the board for the time entered by parameters.
    */
    void sleepBoard(char* time_sleep);


  private:

  protected:

};

/****************************************************************************
*                             Objects                                       *
****************************************************************************/
extern Board board_object;

#endif
