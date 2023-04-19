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
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

/**< Constructor */
Barrier::Barrier(int numThreads){
    this->numThreads = numThreads;
    count = 0;
    //std::shared_ptr<Semaphore> counterLock( new Semaphore(1));
    //std::shared_ptr<Semaphore> taskOneLock( new Semaphore(0));
    //std::shared_ptr<Semaphore> taskTwoLock( new Semaphore(1));
    /**< initalize the semaphores to default otherwise segmentation fault */
    counterLock.reset( new Semaphore(1));
    taskOneLock.reset( new Semaphore(0));
    taskTwoLock.reset( new Semaphore(1));
}
/**< Constructor */
Barrier::~Barrier(){
    std::cout << "Garbage Collected" << std::endl;
}

/*! 
 *\fn taskOne
 *\brief used only process the A tasks first open the semaphore for task two
 */
void Barrier::taskOne(){
   /**<close the lock */
  counterLock->Wait();
  count++;
  if(count == numThreads){
     /**< Open task two lock  */
     taskTwoLock->Wait();
      /**< close task one  */
     taskOneLock->Signal();
  }
   /**< open the lock  */
  counterLock->Signal();
   /**< if its not 100 make sure its open  */
  taskOneLock->Wait();
  taskOneLock->Signal();
}
/*! 
 *\fn taskOne
 *\brief used only process the B tasks first, open the semaphore for task one
 */
void Barrier::taskTwo(){
    counterLock->Wait();
    count--;
    if (count == 0)
    {
        taskOneLock->Wait();
        taskTwoLock->Signal();
    }
    counterLock->Signal();
    
    taskTwoLock->Wait();
    taskTwoLock->Signal();
}
void Barrier::wait(){

}

