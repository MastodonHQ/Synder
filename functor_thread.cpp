#include <iostream>
#include <string>
#include <boost/thread.hpp>
using namespace std;
using namespace boost;

class Worker
{
public:
  Worker(string name, string ID)
    : wname(name), wid(ID)
  {
    cout<<"Worker ["<<wname<<":"<<wid<<"] Created"<<endl;
  }
  void start();
  void join();
  void routine();
private:
  boost::thread wthread;
  string wname;
  string wid;
};

void Worker::start(){
  //Class Member Functions have a hidden first arguement called this and they must be passed as the first arguement
  //when using boost::threads
  wthread = boost::thread(&Worker::routine,this);
}

void Worker::join(){
  wthread.join();
}

void Worker::routine(){
  //here we are inside the Thread
  cout<<"["<<wname<<":"<<wid<<"]: Started"<<endl;
  cout<<"inside thread worker ["<<wname<<"]"<<endl;
  cout<<"["<<wname<<":"<<wid<<"]: Done"<<endl;
}

int main(int argc, char ** argv){
  cout<<"Main: Start"<<endl;
  cout<<"Main: Creating Worker"<<endl;
  Worker azriel("azriel","001");
  azriel.start();
  azriel.join();
  cout<<"Main: Done"<<endl;
  return 0;
}
