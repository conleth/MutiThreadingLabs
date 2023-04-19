/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-15
 * \warnings not unit tested
 * \copyright Open source
 * \mainpage simple demo of how a rendevous works
 * \section intro_sec_ introduction
 * This code is part of Joseph Kehoe CDD course of how concurrent application
 * should work 
 * \Section compile_sec_ Compilation
 *You will need to install G++ and run the make file in the parent directory 
 !*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \class Signal
    \brief An Implementation of a Rendezvous using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! 
 *\fn taskOne
 *\brief Displays a message first
 *\param firstSem used for process synchroinization
 *\param secondSem used for process synchroinization
 *\parma delay used to set the sleep unit of time
 *\details displays a message that is split in to 2 sections to show how a rendezvous works
 */
void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  firstSem->Signal();
  secondSem->Wait();
  std::cout << "Task One has left!"<<std::endl;
}
/*! 
 *\fn tasktwo
 *\brief Displays a message first
 *\param firstSem used for process synchroinization
 *\param secondSem used for process synchroinization
 *\parma delay used to set the sleep unit of time
 *\details  displays a message that is split in to 2 sections to show how a rendezvous works
 */
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two has arrived "<<std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "Task Two has left "<<std::endl;
}
/*! 
 *\fn int main()
 *\brief This is where the orchestration of the code takes place
 *\var threadOne a thread for concurrent processing
 *\var threadTwo a thread for concurrent processing
 *\var sem1 Semaphore for rendezvous
 *\var sem2 Semaphore for rendezvous
 *\var taskOneDelay The 1st delay of 5 seconds 
 *\var taskTwoDelay The 2nd delay of 1 second
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
