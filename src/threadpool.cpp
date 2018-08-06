#include"../incl/threadpool.h"
//template<typename T> 
//ThreadPool<T>* ThreadPool<T>::Instance = NULL;
template<typename T>
ThreadPool<T>::ThreadPool()
{
  CreateThreads();
}
template <typename T>
void ThreadPool<T>::CreateThreads()
{
  pthread_t* threads = new  pthread_t(MaxThreads);
  int i = 0;
  for(; i < MaxThreads; i++)
  {
   pthread_create(threads+ i, NULL,pthread_func,this); 
  }
}
template <typename T> ThreadPool<T>::~ThreadPool<T>()
{
  delete []threads;
  TP_stop = true;
  
}
template <typename T>
void* ThreadPool<T>::pthread_func(void* arg)
{
  pthread_detach(pthread_self()); 
  ThreadPool* tp = (ThreadPool*) arg;
  tp->run();
  return tp;
}
template <typename T> 
void ThreadPool<T>::run()
{
  while(!TP_stop)
  {
    // 注意这里拿锁的顺序
    // 如果先lock , 然后在p, 如果该线程先执行
    // SetEvents 在加入事件的时候要拿到锁 ,会在p处永远等待
    TP_sem.p();
    TP_mutex.lock();
    if(EventQueue.empty())
    {
      TP_mutex.unlock();
      continue;
    }
    T* request = EventQueue.front();
    //注意这里的逻辑
    if(request == NULL)
    {
      //队列里有可能 插入一个空的request
      //空的request也要出对列
      EventQueue.pop_front();
      TP_mutex.unlock();
      continue;
    }
    EventQueue.pop_front();
    TP_mutex.unlock();
    //?
    //printf("%0x\n",pthread_self());
    request->process();
  }
}
template <typename T>
bool ThreadPool<T>::SetEvents(T* request)
{
  TP_mutex.lock();
  if(EventQueue.size() > MaxRequest)
  {
    TP_mutex.unlock();
    return false;
  }
  EventQueue.push_back(request);
  TP_mutex.unlock();
  TP_sem.v();
  return true;
}
