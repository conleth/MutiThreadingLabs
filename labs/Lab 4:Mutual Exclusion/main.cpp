/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-16
 * \warnings not unit tested
 * \copyright Open source
 * \mainpage simple demo of how a mutal exclusion 
 * \section intro_sec_ introduction
 * This code is part of Joseph Kehoe CDD course of how concurrent application
 * should work 
 * \Section compile_sec_ Compilation
 *You will need to install G++ and run the make file in the parent directory 
 !*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

/**<number of threads to be created for vector*/
static const int num_threads = 100;
/**<global varrible to be accessed by update task method*/
int sharedVariable=0;



/*! 
 *\fn updateTask
 *\brief Updates shared varrible based on the number of numbers to update
 *\param firstSem used for process synchroinization
 *\param numners to update 
 *\details the semafore will allow each thread to ensure that each thread that runs will only have access to the shared varible meaning that another thread will not accidently change the value as it runs
 */
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  /**<lock the semafhore*/
  firstSem->Wait();
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
  }
  /**<open the semafhore*/
  firstSem->Signal();
}

/*! 
 *\fn int main()
 *\brief This is where the orchestration of the code takes place
 *\var num_thread a vector of all the threads
 *\var sem1 Semaphore for mutal exclusion set to 1 so critcal part can run
*/
int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
     /**< passes thread, semaphore for locking and number of updates  */
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
