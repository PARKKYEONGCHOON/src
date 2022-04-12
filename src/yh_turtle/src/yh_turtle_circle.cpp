#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"
#include "std_srvs/Empty.h"
#include <cstdlib>


class TurtleCricle
{
    private:

        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::ServiceClient client_clear;
        ros::ServiceClient client_tele;
        double radius;

    public:

        TurtleCricle(double r)
        {
            pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
            client_clear = nh.serviceClient<std_srvs::Empty>("/clear");
            client_tele = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
            radius = r;
        }
        
        void run(void)
        {
            turtlesim::TeleportAbsolute srv_tele;
            srv_tele.request.x = 5.544445;
            srv_tele.request.y = 5.544445 - radius;
            srv_tele.request.theta = 0;

            std_srvs::Empty clear;
            client_tele.call(srv_tele);
            client_clear.call(clear);

            ros::Rate loop_rate(1);
            geometry_msgs::Twist msg;

            msg.linear.x = radius * 3;
            msg.angular.z = 3.;

            while (ros::ok())
            {
                /* code */
                pub.publish(msg);
                loop_rate.sleep();
            }
            

        }
};

int main(int argc, char **argv)
{
    ros::init(argc,argv,"yh_turtle_circle");
    double radius = atof(argv[1]);
    TurtleCricle tt(radius);
    tt.run();

    return 0;
}