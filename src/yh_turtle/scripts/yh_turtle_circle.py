#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty
import sys
import math

class TurtleCricle():
    
    def __init__(self, radius):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
        self.client_Tele = rospy.ServiceProxy("/turtle1/teleport_absolute",TeleportAbsolute)
        self.client_clear = rospy.ServiceProxy("/clear", Empty)
        self.radius = radius
        
    def run(self):
        
        self.client_Tele(5.44445, 5.44445 - self.radius ,0)
        self.client_clear()
        
        msg = Twist()
        
        msg.linear.x = self.radius
        msg.angular.z = 1
        
        looprate = rospy.Rate(1)
        
        while not rospy.is_shutdown():
            self.pub.publish(msg)

#def talker():
    #rospy.init_node("yh_turtle_circle")
    #pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
    
    #msg = Twist()
    
    #msg.linear.x = int(sys.argv[1])
    #msg.angular.z = int(sys.argv[2])
    
    #a = rospy.Rate(1)
    
    #while not rospy.is_shutdown():
    
        #pub.publish(msg)
        #a.sleep()
    
if __name__ == "__main__":
    
    try:
        
        rospy.init_node("yh_turtle_circle2")
        radius = float(sys.argv[1])
        turtle_circle = TurtleCricle(radius)
        turtle_circle.run()
        
    except rospy.ROSInterruptException:
        pass
