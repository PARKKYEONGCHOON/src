#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_divisor.msg import yh_divisor_msg

def msgCallback(msg):
    
    tmplst = []
    
    rospy.loginfo("receive message : %d", msg.stamp.secs)
    rospy.loginfo("receive message : %d", msg.stamp.nsecs)
    rospy.loginfo("receive message : %d", msg.data)
    
    for i in range(1,msg.data+1):
        if msg.data % i == 0:
            tmplst.append(i)
            
            
    rospy.loginfo(tmplst)
            
    
    
def listenr():
    rospy.init_node("yh_divisor_sub", anonymous= True)
    rospy.Subscriber("yh_divisor_topic", yh_divisor_msg, msgCallback)
    rospy.spin()
    

if __name__ == "__main__":
    
    listenr()
        