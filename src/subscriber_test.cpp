//ds4 test
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

//int sub test
/*
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>

void subCallback(const std_msgs::Int8::ConstPtr testmsg);

int main(int argc, char** argv){
  ros:: init(argc,argv,"test_node");
  ros::NodeHandle nh;
  ros::Subscriber testsub=nh.subscribe("test",10,subCallback);

  //std_msgs::Int8 pub_msg;
  //ros::Publisher testpub = nh.advertise<std_msgs::Int8>("test", 10);
  //testpub.publish(pub_msg);

  ros::spin();

}

void subCallback(const std_msgs::Int8::ConstPtr testmsg){
  int value=testmsg->data;
  if(value==1){printf("value is 1\n");}
  if(value==2){printf("value is 2\n");}
}
*/

//default code
/*
#include "ros/ros.h"
#include "std_msgs/String.h"


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();
  return 0;
}
*/