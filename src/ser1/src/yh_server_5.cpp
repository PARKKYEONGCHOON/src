#include "ros/ros.h"
#include "ser1/my_srv.h"

bool calculation(ser1::my_srv::Request &req, ser1::my_srv::Response &res)
{
    res.result = req.a * req.b;

    ROS_INFO("REQEUST : a=%ld, b=%ld", req.a, req.b);
    ROS_INFO("RESPONESE : %ld", res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_server_5");
    ros::NodeHandle nh;

    ros::ServiceServer my_service_server = nh.advertiseService("my_service",calculation);
    ROS_INFO("READY");

    ros::spin();
    return 0;
}