#include "ros/ros.h" //ros
#include "yh_tutorial_1/yh_msg_1.h" //msg After build Auto Create



int main(int argc, char **argv)
{
    ros::init(argc,argv, "yh_pub_1"); // node name init
    ros::NodeHandle nh; // node handle
    
    //publisher
    //패키지 topic_tutorial 의 메시지 파일 my_msg 을 이용한
    //퍼블리셔 my_pub 를 작성한다. 토픽은 my_topic 이며,
    //퍼블리셔 큐 사이즈를 100개로 설정
    ros::Publisher my_pub = nh.advertise<yh_tutorial_1::yh_msg_1>("yh_topic_1", 100);

    ros::Rate loop_rate(50); // loop 10 hz

    yh_tutorial_1::yh_msg_1 msg;
    int cnt = 0;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); // time
        msg.data = cnt;
        //ROS_INFO("Send msg = %d", msg.stamp.sec);
        //ROS_INFO("Send msg = %d", msg.stamp.nsec);
        //ROS_INFO("Send msg = %d", msg.data);
        cnt++;
        my_pub.publish(msg); // msg publish
        loop_rate.sleep();

    }
    

    return 0;
}