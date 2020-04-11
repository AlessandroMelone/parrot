#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class ROS_SUB{
  public:
    ROS_SUB();
    void topic_cb(std_msgs::String data); //topic callback
  private :
    ros::NodeHandle _nh;
    ros::Subscriber _topic_sub;
};

ROS_SUB::ROS_SUB() {
   _topic_sub = _nh.subscribe
   ("/keyboard", 0, &ROS_SUB::topic_cb, this);
}

void ROS_SUB::topic_cb(std_msgs::String data){
 ROS_INFO("%s\n", data.data.c_str());
}

int main( int argc, char ** argv){
 ros::init(argc, argv, "ros_subscriber"); //contact ROS master
 ROS_SUB rs; //create object
 ros::spin(); //update topics
 return 0;
}

