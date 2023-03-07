#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <ds4_driver/Status.h>

void subCallback(const ds4_driver::Status::ConstPtr testmsg);

int main(int argc, char** argv){
  ros:: init(argc,argv,"test_node");
  ros::NodeHandle nh;
  ros::Subscriber testsub=nh.subscribe("status",10,subCallback);

  ros::spin();

}

void subCallback(const ds4_driver::Status::ConstPtr testmsg){
  float value = testmsg->axis_left_y;
  ROS_INFO("axis_left_y: [%lf]", value);
  std::cout << value << std::endl;
}

