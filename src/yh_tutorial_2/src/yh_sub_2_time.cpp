#include "ros/ros.h"
#include "yh_tutorial_2/yh_msg_2.h"

void msgCallback(const yh_tutorial_2::yh_msg_2::ConstPtr& msg)
{
    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_sub_2_time");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("yh_topic_2", 100, msgCallback);

    ros::spin();

    return 0;
}