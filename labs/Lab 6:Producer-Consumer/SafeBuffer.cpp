
/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-22
 * \warnings not unit tested
 * \copyright Open source
 !*/
#include "SafeBuffer.h"
#include <iostream>



SafeBuffer::SafeBuffer(){
    mutex1.reset(new Semaphore(1));
    spaces.reset(new Semaphore(0));
    items.reset(new Semaphore(0));
}
/*! 
 *\fn put
 *\brief the put method is used to put a event in the buffer
 *\param e instance of an event to put in buffer
 */
int SafeBuffer::put(Event e){
  // spaces->Wait();
  mutex1->Wait();
  buffer.push_back(e);
  int numItems= buffer.size();
  mutex1->Signal();
  items->Signal();
  return numItems ;
}
/*! 
 *\fn get
 *\brief get the most recent message from the buffer
 */
Event SafeBuffer::get(){
  items->Wait();
  mutex1->Wait();
  Event e = buffer.back();
  buffer.pop_back();
  mutex1->Signal();
  // spaces->Signal();
  return e ;
}
