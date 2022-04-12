#include "ros/ros.h"
#include "ser/my_srv.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc,argv, "my_client");

    if(argc != 3)
    {
        ROS_INFO("cmd: rosrun ser my_client arg0 arg1");
        ROS_INFO("arg1, arg2 : int64 number");

        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient my_service_client = nh.serviceClient<ser::my_srv>("my_service");

    ser::my_srv srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if(my_service_client.call(srv))
    {
        ROS_INFO("send srv a, b: %ld + %ld",srv.request.a, srv.request.b);
        ROS_INFO("receive srv result : %ld",srv.response.result);
    }
    else
    {
        ROS_ERROR("Fail to Call service");
        return 1;
    }

    return 0;
}

