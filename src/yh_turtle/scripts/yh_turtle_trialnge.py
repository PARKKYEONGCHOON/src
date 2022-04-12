#!/usr/bin/python
# -*- coding: utf-8 -*-

from turtle import clear
import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty


import sys
import math
import os



    
    
cnt = 0;

def talker():
    rospy.init_node("yh_turtle_triangle")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
    clear_bg = rospy.ServiceProxy('/clear', Empty)
    
    msg = Twist()
    
    
    msg.linear.x = int(sys.argv[1])
    #msg.angular.z = int(sys.argv[2]) 
    
    a = rospy.Rate(1)
    
    while not rospy.is_shutdown():
        global cnt
        
        msg.linear.x = int(sys.argv[1])
        msg.angular.z = 0
        pub.publish(msg)
        a.sleep()
        
        msg.linear.x = 0
        msg.angular.z = (math.pi/180) * 120
        pub.publish(msg)
        a.sleep()
        
        cnt +=1
        
        if cnt == 3:
            #os.system('rosservice call/clear')
            clear_bg()
            cnt = 0
            
    
if __name__ == "__main__":
    
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
