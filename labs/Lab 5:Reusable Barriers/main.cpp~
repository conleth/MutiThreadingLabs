/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-18
 * \warnings not unit tested
 * \copyright Open source
 * \mainpage simple demo of how a barrier works
 * \section intro_sec_ introduction
 * This code is part of Joseph Kehoe CDD course of how concurrent application should work 
 * \Section compile_sec_ Compilation You will need to install G++ and run the make file in the parent directory 
 !*/
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! 
 *\fn barrierTask
 *\brief Print out 100 A's and the index then 100 B's with the index
 *\param theBarrier instance of the barrier class
 *\param numLoops the amount of time to loop
 *\details the barrier has been passed a number of threads for it to use the taskOne method will first count up to 100 and task two will be blocked until taskOne has counted to 100 after that task two will count down from 100 using the same value print out the b's this will be done until the index is greater than the numLoops
 */
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    //Barrier
    theBarrier->taskOne();
    //Do second half of task
    std::cout<< "B" << i;
    theBarrier->taskTwo();
  }
  

}

/*! 
 *\fn main
 *\brief used to conrtol the excution of the class 
 *\param vt vector for storing the threads
 *\param aBarrier instance of the barrier class
 *\param numners to update 
 */
int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << std::endl << sharedVariable << std::endl;
  return 0;
}
