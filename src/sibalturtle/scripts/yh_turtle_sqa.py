#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty

import sys
import math
import os

#from yh_turtle_tri import TurtleTri


cnt = 0

class TurtleSqa():
    
    def __init__(self, length):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
        self.client_Tele = rospy.ServiceProxy("/turtle1/teleport_absolute",TeleportAbsolute)
        self.client_clear = rospy.ServiceProxy("/clear", Empty)
        self.length = length
        
    def run(self):
        
        self.client_Tele(5.44445 - self.length / 2, 5.44445 - self.length / 2 , 0)
        self.client_clear()
        
        msg = Twist()
        
        looprate = rospy.Rate(1)
        
        while self.pub.get_num_connections() < 1:
            continue
        
        
        
        while not rospy.is_shutdown():
            
            global cnt
            
            msg.linear.x = self.length
            msg.angular.z = 0
            self.pub.publish(msg)
            looprate.sleep()
        
            msg.linear.x = 0
            msg.angular.z = math.pi / 2 # math.pi * 2 / 3 (math.pi/180) * 90
            self.pub.publish(msg)
            looprate.sleep()
        
            cnt +=1
            
            if cnt == 4:
                self.client_clear()
                cnt = 0
                
                
if __name__ == "__main__":
    
    try:
        rospy.init_node("yh_turtle_sqa")
        
        if len(sys.argv) != 2:
            print("dasdasd")
            sys.exit(1)
        
        length = float(sys.argv[1])
        
        turtleSqa = TurtleSqa(length)
        turtleSqa.run()
        
    except rospy.ROSInterruptException:
        pass