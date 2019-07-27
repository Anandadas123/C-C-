#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<string>


std::string s;
std::condition_variable cv;
std::mutex m;

void logData() {
  std::unique_lock<std::mutex> lock{m};
  cv.wait(lock,[]{return !s.empty();});
  std::cout<< s << std::endl;
}

int main() {
  std::thread t{logData};
  {
    std::unique_lock<std::mutex> lock{m};
    s="some data";
  }

  cv.notify_one();
  t.join();
  return 0;

}
