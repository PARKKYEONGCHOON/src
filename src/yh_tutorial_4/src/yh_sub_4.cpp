#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h"
#include "yh_tutorial_4/yh_msg_5.h"

void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{
    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    ROS_INFO("receive msg=%d", msg->data);
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_sub_4");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub2 = nh.subscribe("yh_topic_4_1", 100, msgCallback);

    ros::spin();

    return 0;
}