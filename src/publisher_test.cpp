//int pub test
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int8.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_pubtest_node");
  ros::NodeHandle nh;
  ros::Publisher testpub = nh.advertise<std_msgs::Int8>("test", 10);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
   //std_msgs::String msg;
    std_msgs::Int8 pub_msg;

    pub_msg.data = 2;
    testpub.publish(pub_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

//ros tutorial
/*
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
*/