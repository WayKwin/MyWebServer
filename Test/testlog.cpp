#include <iostream>
#include "/home/waykwin/third_part/include/glog/logging.h"
using namespace std;
int main(int argc,char ** argv)
{
  google::InitGoogleLogging(argv[0]);

  fLS::FLAGS_log_dir = "./log";
  LOG(INFO) << "a";
  LOG(WARNING) << "b";
}
