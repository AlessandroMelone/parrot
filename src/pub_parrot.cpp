#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

int main(int argc, char **argv) {
ros::init (argc,argv, "pub_parrot");
ros::NodeHandle nh ;
ros::Publisher topic_pub =
nh.advertise <std_msgs::String>("/keyboard",15);
ros::Rate rate(10);

std::string temp;

while(ros::ok()){
std_msgs::String key_input;
std::cin>>key_input.data;

//if(temp != key_input.data){
ROS_INFO("%s\n", key_input.data.c_str());
topic_pub.publish(key_input);
//}

//temp = key_input.data;

rate.sleep();
}
return 0;
}
