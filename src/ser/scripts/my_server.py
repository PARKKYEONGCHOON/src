#!/usr/bin/python3
# -*- coding: utf-8 -*-

from lib2to3.pgen2.token import PLUS
import rospy
from ser.srv import my_srv, my_srvResponse

Pl = 1
Mi = 2
Mu = 3
Di = 4

def Calculation(req):
    
    my_Operator = rospy.get_param("Cal_Method")
    
    if my_Operator == Pl:
        res = req.a + req.b
    elif my_Operator == Mi:
        res = req.a - req.b
    elif my_Operator == Mu:
        res = req.a * req.b
    elif my_Operator == Di:
        if req.b != 0:
            res = req.a / req.b
        
    rospy.loginfo("request : %d, %d", req.a, req.b)
    rospy.loginfo("responese : %d", res)
    return my_srvResponse(res)


def Calculate_server():
    rospy.init_node("my_server")
    rospy.set_param("Cal_Method", Pl)
    my_service_server = rospy.Service("my_service", my_srv, Calculation)
    rospy.loginfo("Server ready")
    rospy.spin()
    
if __name__ == "__main__":
    Calculate_server()