/* Barrier.h --- Barrier.h
/*!
 * \author Conleth Kennedy
 * \version 1.0
 * \date 2019-11-16
 * \warnings not unit tested
 * \copyright Open source
 * \brief simple header file
 !*/

/* Code: */
#pragma once
#include "Semaphore.h"
class Barrier{
  int numThreads;
  int count;
  std::shared_ptr<Semaphore> taskOneLock;
  std::shared_ptr<Semaphore> taskTwoLock;
  std::shared_ptr<Semaphore> counterLock;
 public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();  
  void taskOne();
  void taskTwo();
};


/* Barrier.h ends here */
