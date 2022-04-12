#include "ros/ros.h"
#include "yh_star/yh_star_msg.h"
#include <string.h>
#include <cstring>
#include <sstream>

std::string star;





void msgCallback(const yh_star::yh_star_msg::ConstPtr& msg)
{
    
    ROS_INFO("receive msg=%d", msg->stamp.sec);
    ROS_INFO("receive msg=%d", msg->stamp.nsec);
    ROS_INFO("receive msg=%d", msg->data);

    for(int i = 1; i<=msg->data; i++)
    {

        if(msg->data/2 >=i) 
        {
            for(int j = 0; j<i; j++)
            {
                printf("*");
            }
        }
        else
        {
            for(int j = 0; j<msg->data-i; j++)
            {
                printf("*");
            }
        }
        

        

        printf("\n");
    }

    //for(int i =0; i < n/2; i++)
    //{
        //for(int j =0; j <i+1; j++)
        //{
        //    printf("*");
        //}
       //printf("\n");
    //}

    //for(int i =n/2; i < n; i++)
    //{
        //for(int j =n; j>i; j--)
        //{
        //    printf("*");
        //}
        //printf("\n");
    //}
        
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "yh_star_sub");
    ros::NodeHandle nh; 


    ros::Subscriber my_sub = nh.subscribe("yh_star_topic", 100, msgCallback);

    ros::spin();

    return 0;
}