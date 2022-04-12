#include "ros/ros.h"
#include "yh_divisor/yh_divisor_msg.h"
#include <string.h>
#include <cstring>
#include <sstream>


void msgCallback(const yh_divisor::yh_divisor_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    ROS_INFO("receive msg=%d", msg->data);

    for(int i= 1; i <= msg->data; i++)
    {
        if(msg->data % i == 0)
        {
            printf("%d, ", i);
            printf("\n");
        }
    }
    
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_divisor_sub");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("yh_divisor_topic", 100, msgCallback);

    ros::spin();

    return 0;
}