#include<iostream>
#include<thread>
#include<mutex>

int main(){
  
  auto i=1;
  std::mutex m;

  std::thread t{[&](){
    m.lock();
    i*=2;
    m.unlock();
  }};
  m.lock();
  i*=2;
  m.unlock();
  t.join();

  std::cout << i <<std::endl;
  return 0;
}
