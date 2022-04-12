#include "ros/ros.h" //ros
#include "yh_star/yh_star_msg.h" //msg After build Auto Create



int main(int argc, char **argv)
{
    ros::init(argc,argv, "yh_star_pub"); // node name init
    ros::NodeHandle nh; // node handle
    
    //publisher
    //패키지 topic_tutorial 의 메시지 파일 my_msg 을 이용한
    //퍼블리셔 my_pub 를 작성한다. 토픽은 my_topic 이며,
    //퍼블리셔 큐 사이즈를 100개로 설정
    ros::Publisher my_pub = nh.advertise<yh_star::yh_star_msg>("yh_star_topic", 100);

    ros::Rate loop_rate(2); // loop 10 hz

    yh_star::yh_star_msg msg;
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