#include "ros/ros.h"
#include "yh_tutorial_2/yh_msg_2.h"

void msgCallback(const yh_tutorial_2::yh_msg_2::ConstPtr& msg)
{
    int tmp;

    tmp = msg->data;

    if(tmp % 2 == 1)
    {
        ROS_INFO("receive msg=%d", msg->data);
    }

    
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_sub_2_int");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("yh_topic_2", 100, msgCallback);

    ros::spin();

    return 0;
}