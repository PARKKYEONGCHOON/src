#include "ros/ros.h"
#include "topic_tutorial/my_msg.h"

void msgCallback(const topic_tutorial::my_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    ROS_INFO("receive msg=%d", msg->data);
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "my_subscriber");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("my_topic", 100, msgCallback);

    ros::spin();

    return 0;
}