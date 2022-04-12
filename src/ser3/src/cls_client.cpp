#include "ros/ros.h"
#include "ser3/my_srv.h"
#include <cstdlib>



class client
{
    private:

        ros::NodeHandle nh;
        ros::ServiceClient my_service_client;
    
    public:

        client()
        {   
            //ros::ServiceClient my_service_client = nh.serviceClient<ser3::my_srv>("my_service");
            my_service_client = nh.serviceClient<ser3::my_srv>("my_service");
        }

        
        
        void call(ser3::my_srv &srv)
        {
            
            if(my_service_client.call(srv))
            {   
                if(srv.request.b == 0)
                {
                    ROS_INFO("send srv a, b: %ld , %ld",srv.request.a, srv.request.b);
                    ROS_INFO("receive srv result : %s",srv.response.error.c_str());
                }
                else
                {
                    ROS_INFO("send srv a, b: %ld , %ld",srv.request.a, srv.request.b);
                    ROS_INFO("receive srv result : %ld",srv.response.result);
                }
                    
            }
            else
            {
                ROS_ERROR("Fail to Call service");
                //return 1;
            }
        }


};

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_client_7");
    
    client obcli;
    

    ser3::my_srv srv;

    if(argc != 3)
    {
        ROS_INFO("cmd: rosrun ser my_client arg0 arg1");
        ROS_INFO("arg1, arg2 : int64 number");

        return 1;
    }

    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    obcli.call(srv);

    return 0;
};
    
