#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from turtlesim.srv import SetPen

from std_srvs.srv import Empty

import sys
import math
import os

class TurtlePen:
    
    def  __init__(self):
        
        self.client_pen = rospy.ServiceProxy("/turtle1/set_pen", SetPen)
        
    def run(self):
        
        r = int(input("r : "))
        g = int(input("g : "))
        b = int(input("b : "))
        width = int(input("width : "))
        off = int(input("off : "))
        
        self.client_pen(r,g,b,width,off)
        
if __name__ == "__main__":
    rospy.init_node("yh_turtle_pen")
    turtlepen = TurtlePen()
    
    while not rospy.is_shutdown():
        turtlepen.run()