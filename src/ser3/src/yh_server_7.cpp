#include "ros/ros.h"
#include "ser3/my_srv.h"

bool calculation(ser3::my_srv::Request &req, ser3::my_srv::Response &res)
{

    if(req.a > req.b)
    {
        res.result = req.a - req.b;
    }
    else
    {
        res.result = req.b - req.a;
    }
    

    ROS_INFO("REQEUST : a=%ld, b=%ld", req.a, req.b);
    ROS_INFO("RESPONESE : %ld", res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_server_7");
    ros::NodeHandle nh;

    ros::ServiceServer my_service_server = nh.advertiseService("my_service",calculation);
    ROS_INFO("READY");

    ros::spin();
    return 0;
}