/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-22
 * \warnings not unit tested
 * \copyright Open source
 * \mainpage simple demo of how a producer consumer works
 * \section intro_sec_ introduction
 * This code is part of Joseph Kehoe CDD course of how concurrent application should work 
 * \Section compile_sec_ Compilation You will need to install G++ and run the make file in the parent directory 
 !*/
#include "SafeBuffer.h"
//#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
const int size=20;
static int count [26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/*! 
 *\fn producer
 *\brief create events to be added to the buffer
 *\param buffer instance of the buffer class
 *\param numLoops the amount of time to loop
 */
void producer(std::shared_ptr<SafeBuffer> buffer, int numLoops){
  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    Event e = *new Event(1);
    buffer->put(e);
  }
}//producer

/*! 
 *\fn consumer
 *\brief reads from buffer and counts the occurance of each alpha charcters
 *\param buffer instance of the buffer class
 *\param numLoops the amount of time to loop
 *\param semi smeaphore to lock the updated count
 */
void consumer(std::shared_ptr<SafeBuffer> buffer, int numLoops,std::shared_ptr<Semaphore>semi){
  //std::cout <<"got here 4" << std::endl;
  for(int i=0;i<numLoops;++i){
    Event e= buffer->get();
    // std::cout << e.consume() << std::endl;
    semi->Wait();
     switch( e.consume()){
     case'a':count[0]++;
       break;
     case'b':count[1]++;
       break;
     case'c':count[2]++;
       break;
     case'd':count[3]++;
       break;
     case'e': count[4]++;
       break;
     case'f':count[5]++;
       break;
     case'g': count[6]++;
       break;
     case'h': count[7]++;
       break;
     case'i': count[8]++;
       break;
     case'j': count[9]++;
       break;
     case'k': count[10]++;
       break;
     case'l': count[11]++;
       break;
     case'm': count[12]++;
       break;
     case'n': count[13]++;
       break;
     case'o': count[14]++;
       break;
     case'p': count[15]++;
       break;
     case'q': count[16]++;
       break;
     case'r': count[17]++;
       break;
     case's': count[18]++;
       break;
     case't': count[19]++;
       break;
     case'u': count[20]++;
       break;
     case'v': count[21]++;
       break;
     case'w': count[22]++;
       break;
     case'x': count[23]++;
       break;
     case'y': count[24]++;
       break;
     case'z': count[25]++;
       break;
     default:;
  }//switch
    semi->Signal();
  }
}//consumer

/*! 
 *\fn main
 *\brief used to conrtol the excution of the class 
 *\param sameF semaphore for locking
 *\param buffer instance of the buffer class to add to
 *\param producers threads for production of events
 *\param consumers threads for consumption of events
 */
int main(void){

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<Semaphore>sameF (new Semaphore(1));
  
  std::cout <<"got here 1" << std::endl;
  std::shared_ptr<SafeBuffer> buffer( new SafeBuffer());
  /**< Launch the threads  */
  for(std::thread& p: producers){
    p=std::thread(producer,buffer,10);
  }

  for(std::thread& c: consumers){
    c=std::thread(consumer,buffer,10,sameF);
  }

  /**< Join the threads with the main thread */
  for (auto& p :producers){
      p.join();
  }
 
  for (auto& c :consumers){
      c.join();
  }
  std::cout<<"I am the count" << std::endl;
  for(int s=0; s<26;s++)
    std::cout<<"Number pos of alphabet:"<<s<<":" <<count[s] << std::endl;
  return 0;
}
