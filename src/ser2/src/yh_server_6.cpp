#include "ros/ros.h"
#include "ser2/my_srv.h"

bool calculation(ser2::my_srv::Request &req, ser2::my_srv::Response &res)
{
    res.result = req.a + req.b + req.c;

    ROS_INFO("REQEUST : a=%ld, b=%ld, c= %ld", req.a, req.b, req.c);
    ROS_INFO("RESPONESE : %ld", res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_server_6");
    ros::NodeHandle nh;

    ros::ServiceServer my_service_server = nh.advertiseService("my_service",calculation);
    ROS_INFO("READY");

    ros::spin();
    return 0;
}