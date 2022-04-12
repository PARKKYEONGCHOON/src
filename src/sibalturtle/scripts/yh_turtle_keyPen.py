#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen, SetPenRequest



class keyPen:
    
    def __init__(self):
        
        self.sub = rospy.Subscriber("/cmd_vel", Twist, self.callback)
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=1)
        self.client_pen = rospy.ServiceProxy("/turtle1/set_pen",SetPen)
        self.pen = SetPenRequest()
        self.pen.width = 3
        

    def callback(self, msg):
        
        
        if msg.linear.z > 0:
            #print("t")
            
            self.pen.r = int(input("r : "))
            self.pen.g = int(input("g : "))
            self.pen.b = int(input("b : "))
            self.client_pen(self.pen)
            
        elif msg.linear.z < 0:
            #print("b")
            
            self.pen.width = int(input("width : "))
            self.client_pen(self.pen)
            
        else:
            self.pub.publish(msg)
            
    
    
    
if __name__ == "__main__":
    rospy.init_node("yh_turlte_keyPen")
    
    key = keyPen()

    rospy.spin()   
