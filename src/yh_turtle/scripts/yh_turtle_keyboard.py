#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=1)

def callback(msg):
    pub.publish(msg)
    
def listener():
    
    rospy.init_node("yh_turlte_key")
    sub = rospy.Subscriber("/cmd_vel", Twist, callback)
    rospy.spin()
    
if __name__ == "__main__":
    
    listener()    
