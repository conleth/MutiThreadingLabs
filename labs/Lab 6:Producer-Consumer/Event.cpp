/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-22
 * \warnings not unit tested
 * \copyright Open source
 !*/
#include "Event.h"
#include <stdlib.h>
#include <iostream>

//static int count [26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Event::Event(int i){
  randomChar = 'a'+rand()%26 ; 
}
/*! 
 *\fn createEvent
 *\brief used to create instance of the event class
 *\param int i for the craic 
 */
Event Event:: createEvent(int i){
 return *new Event(i);
}
/*! 
 *\fn consume
 *\brief returns the random char
 */
char Event::consume(){
  return randomChar ;
}
