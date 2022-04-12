#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"
#include <string.h>
#include <cstring>
#include <sstream>

int tmp = 0;
int res;

void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
{

    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    ROS_INFO("receive msg=%d", msg->data);

    res = msg->data + tmp;

    tmp = msg->data;

    ROS_INFO("result=%d", res);

}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_sum_sub");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("yh_sum_topic", 100, msgCallback);

    ros::spin();

    return 0;
}