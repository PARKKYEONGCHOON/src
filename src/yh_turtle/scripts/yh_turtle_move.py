#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

def talker():
    rospy.init_node("yh_turtle_move")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
    
    msg = Twist()
    msg.linear.x = 4
    
    a = rospy.Rate(1)
    
    while not rospy.is_shutdown():
    
        pub.publish(msg)
        a.sleep()
    
if __name__ == "__main__":
    
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
