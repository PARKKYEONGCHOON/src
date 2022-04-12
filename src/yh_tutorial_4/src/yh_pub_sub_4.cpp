#include "ros/ros.h" //ros
#include "yh_tutorial_4/yh_msg_4.h" //msg After build Auto Create
#include "yh_tutorial_4/yh_msg_5.h"

yh_tutorial_4::yh_msg_5 msg1;

int cnt = 0;


ros::Publisher my_pub1;


void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{
    //ros::NodeHandle nh; // node handle
    //ros::Publisher my_pub1 = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4_1", 100);
    int tmp;
    tmp = msg->data;

    if(tmp % 5 == 0)
    {
        
        my_pub1.publish(msg); // msg publish
        
    }

}

int main(int argc, char **argv)
{
    
    ros::init(argc,argv, "yh_pub_sub_4"); // node name init
    ros::NodeHandle nh; // node handle
    
    //publisher
    //패키지 topic_tutorial 의 메시지 파일 my_msg 을 이용한
    //퍼블리셔 my_pub 를 작성한다. 토픽은 my_topic 이며,
    //퍼블리셔 큐 사이즈를 100개로 설정

    my_pub1 = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4_1", 100);
    
    ros::Subscriber my_sub = nh.subscribe("yh_topic_4", 100, msgCallback);

    ros::Rate loop_rate(10); // loop 10 hz


    

    loop_rate.sleep();
    ros::spin();

    return 0;
}

