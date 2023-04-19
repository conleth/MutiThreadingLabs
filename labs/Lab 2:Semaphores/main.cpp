/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \file main.ccp
 * \date 2019-11-15
 * \warnings not unit tested
 * \copyright Open source
 * \mainpage simple demo of how a samephore works
 * \section intro_sec_ introduction
 *This code is part of Joseph Kehoe CDD course of how concurrent application
 *should work 
 * \Section compile_sec_ Compilation
 *You will need to install G++ and run the make file in the parent directory 
 !*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*!
 * \class Signal
 *\brief An Implementation of Threads Using Semaphores 
 *Uses C++17 features such as mutex and condition variables to implement 
 *Semaphores in thread functions 
*/

/*! 
 *\fn taskOne
 *\brief Displays a message first
 *\param theSemaphore used for process synchroinization
 *\param delay used to set the sleep unit of time
 *\details for this funtion to work delay must be a positive number
 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);//calling sleep function to sleep for 5 seconds 
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal() ;// calling the samaphore to reset
}
/*! 
 *\taskTwo 
 *\brief Displays a message second
 *\param theSemaphore used for process synchroinization
 *\param delay used to set the sleep unit of time
 *\details for this funtion to work delay must be a positive number
 *//*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();//call the semaphore to lock
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void){
  std::thread threadOne, threadTwo;//!< 2 threads from standard libary
  std::shared_ptr<Semaphore> sem( new Semaphore);//!< creates semaphore
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
