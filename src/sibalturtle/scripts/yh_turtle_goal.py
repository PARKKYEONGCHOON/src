#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class myTurtle:
    
    def __init__(self) :
        self.pub_cmd_vel = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size= 100)
        self.sub_pose = rospy.Subscriber("/turtle1/pose",Pose, self.update_pose)
        self.pose = Pose()
        self.loop = rospy.Rate(10)
        
    def update_pose(self, msg):
        
        self.pose = msg
        self.pose.x = round(self.pose.x, 4)
        self.pose.y = round(self.pose.y, 4)
    
    def euclidean_distance(self, goal_pose):
        
        dif_x = goal_pose.x - self.pose.x
        dif_y = goal_pose.y - self.pose.y
        
        return math.sqrt((dif_x*dif_x)+(dif_y*dif_y))
    
    def linear_vel(self, goal_pose, constance = 1.5):
        
        return constance * self.euclidean_distance(goal_pose)
    
    
    def steering_angle(self, goal_pose):
        
        return math.atan2((goal_pose.y-self.pose.y),(goal_pose.x-self.pose.x))
    
    def angular_vel(self, goal_pose, constance = 6):
        
        return constance * (self.steering_angle(goal_pose) - self.pose.theta)
    
    
    def move2goal(self):
        goal_pose  = Pose()
        
        goal_pose.x = float(input("Goal x : "))
        goal_pose.y = float(input("Goal y : "))
        
        tolerance = float(input("오차: "))
        
        msg = Twist()
        
        while self.euclidean_distance(goal_pose) >= tolerance:
            
            msg.linear.x = self.linear_vel(goal_pose)
            msg.angular.z = self.angular_vel(goal_pose)
            
            self.pub_cmd_vel.publish(msg)
            
            self.loop.sleep()
            
        msg.linear.x = 0
        msg.angular.z = 0
        self.pub_cmd_vel.publish(msg)
        print("goal")         
        
    
if __name__ == "__main__":
    rospy.init_node("yh_turtle_goal")
    try:
        my_turtle = myTurtle()
        my_turtle.move2goal()
            
    except rospy.ROSInterruptException:
        pass    
    

