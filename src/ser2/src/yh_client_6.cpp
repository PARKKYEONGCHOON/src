#include "ros/ros.h"
#include "ser2/my_srv.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_client_6");

    if(argc != 4)
    {
        ROS_INFO("cmd: rosrun ser my_client arg0 arg1 arg3");
        ROS_INFO("arg1, arg2, arg3 : int64 number");

        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient my_service_client = nh.serviceClient<ser2::my_srv>("my_service");

    ser2::my_srv srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    srv.request.c = atoll(argv[3]);
    

    if(my_service_client.call(srv))
    {
        ROS_INFO("send srv a, b, c: %ld + %ld + %ld",srv.request.a, srv.request.b, srv.request.c);
        ROS_INFO("receive srv result : %ld",srv.response.result);
    }
    else
    {
        ROS_ERROR("Fail to Call service");
        return 1;
    }

    return 0;
}

