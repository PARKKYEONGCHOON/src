#include "ros/ros.h" //ros
#include "yh_tutorial_4/yh_msg_4.h" //msg After build Auto Create



class node
{
    private:
        /* data */
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::Subscriber sub;

    public:

        node()
        {
            pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4_1", 100);
    
            sub = nh.subscribe("yh_topic_4", 100, &node::msgCallback,this);
        }

        void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
        {   

            if(msg->data % 5 == 0)
            {
                
               pub.publish(msg); // msg publish
                
            }

        }   
};


    



int main(int argc, char **argv)
{
    
    ros::init(argc,argv, "pub_sub");
    node nodeObject;
    ros::Rate loop_rate(10); // loop 10 hz
    loop_rate.sleep();
    ros::spin();

    return 0;
}