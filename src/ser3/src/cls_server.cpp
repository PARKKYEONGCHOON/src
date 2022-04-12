#include "ros/ros.h"
#include "ser3/my_srv.h"
#include <cstdlib>
#include <string.h>
#include <cstring>

#define Plus 1
#define Minus 2
#define Mul 3
#define div 4



class server
{
    private:

        ros::NodeHandle nh;
        ros::ServiceServer my_service_server;

    public:

        int mode;

        server()
        {
            my_service_server = nh.advertiseService("my_service",&server::calculation,this);
        }
        server(int oper)
        {
            my_service_server = nh.advertiseService("my_service",&server::calculation,this);
            mode = oper;
            //this->setParam("SetMode",Plus)
        }

        //void setParam(string method, int mode)
        //{
            //nh.SetParam(this.method,mode);
    
        //}

        //void getParam(string method, int mode)
        //{
            //nh.GetParam("SetMode",mode);
        //}
        

        bool calculation(ser3::my_srv::Request &req, ser3::my_srv::Response &res)
        {
           
                switch (this->mode)
                {
                    case 1:
                        res.result = req.a + req.b;

                        break;

                    case 2:
                        res.result = req.a - req.b;

                        break;
                    
                    case 3:
                        res.result = req.a * req.b;

                        break;

                    case 4:

                        if(req.b == 0)
                        {
                            ROS_INFO("RESPONESE : Error");
                            res.error = "Error";
                            break;
                        }
                        res.result = req.a / req.b;
                            
                        break;
                        
                    default:

                        res.result = req.a + req.b;
            
                        break;
                }

                ROS_INFO("REQEUST : a=%ld, b=%ld", req.a, req.b);
                ROS_INFO("RESPONESE : %ld", res.result);
                
            
            //if(req.a > req.b)
            //#{
                //res.result = req.a - req.b;
            //}
            //else
            //{
                //res.result = req.b - req.a;
            //}
            
            return true;
        }

};

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_server_7");

    server sev(4);
    
    ROS_INFO("READY");

    //while (true)
    //{
        /* code */
        //sev.getParam("Method",sev.mode);
        //ros::spinOnce();
        
    //}
        

    ros::spin();
}
    
