#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
import sys
import math
from std_srvs.srv import Empty



def talker():
    rospy.init_node("yh_turtle_squre")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
    clear_bg = rospy.ServiceProxy('/clear', Empty)
    msg = Twist()
    
    cnt = 0
    
    msg.linear.x = int(sys.argv[1])
    
    
    a = rospy.Rate(1)
    
    while not rospy.is_shutdown():
        
        msg.linear.x = int(sys.argv[1])
        msg.angular.z = 0
        pub.publish(msg)
        a.sleep()
        
        msg.linear.x = 0
        msg.angular.z = (math.pi/180) * 90
        pub.publish(msg)
        a.sleep()
        
        cnt += 1
        
        if cnt == 4:
            cnt = 0
            clear_bg()
    
if __name__ == "__main__":
    
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
