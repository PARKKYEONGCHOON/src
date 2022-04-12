#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import rospy
from ser.srv import my_srv



def calculate_client(a,b):
    rospy.wait_for_service("my_service")
    try:
        my_service_client = rospy.ServiceProxy("my_service", my_srv)
        res = my_service_client(a,b)
        return res.result
    except rospy.ServiceException as e:
        rospy.logerr("Service call faild : %s", e)
        
if __name__ == "__main__":
    rospy.init_node("my_client")
    if len(sys.argv) != 3:
        rospy.loginfo("usage : rosrun ser my_client.py a, b")
        rospy.loginfo("a, b : int64")
        sys.exit()
    else:
        a = int(sys.argv[1])
        b = int(sys.argv[2])
        res = calculate_client(a,b)
        rospy.loginfo("send: a=%d, b=%d",a,b)
        rospy.loginfo("receive: result=%d",res)