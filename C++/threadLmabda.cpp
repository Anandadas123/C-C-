//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//void threadFn()
//{
//    std::cout << "thread function\n";
//    cout<<this_thread::get_id()<<endl;
//}
//
//int main()
//{
//    thread t(threadFn);
//    cout<<this_thread::get_id()<<endl;
//    cout << "main thread\n";
//    t.join();   // main thread waits for the thread t to finish
//    return 0;
//}

            // template  concept //     

//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//template<typename type>
//void threadFn()
//{
//    std::cout << "thread function\n";
//    cout<<this_thread::get_id()<<endl;
//    cout<<typeid(type).name()<<endl;
//}
//
//int main()
//{
//    thread t1(threadFn<int>);
//    this_thread::sleep_for(chrono::milliseconds(1000));
//    thread t2(threadFn<float>);
//    cout<<this_thread::get_id()<<endl;
//    cout << "main thread\n";
//    t1.join();   // main thread waits for the thread t to finish
//    t2.join();   // main thread waits for the thread t to finish
//    return 0;
//}
       
           //future of the thread concept// 


#include <iostream>
#include <thread>

using namespace std;

template<typename type>
void threadFn()
{
    std::cout << "thread function\n";
    cout<<this_thread::get_id()<<endl;
    cout<<typeid(type).name()<<endl;
}

int main()
{
    thread t1(threadFn<int>);
    this_thread::sleep_for(chrono::milliseconds(1000));
    thread t2(threadFn<float>);
    cout<<this_thread::get_id()<<endl;
    cout << "main thread\n";
    t1.join();   // main thread waits for the thread t to finish
    t2.join();   // main thread waits for the thread t to finish
    return 0;
}
