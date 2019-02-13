#include "ros/ros.h"                                                            
#include "std_msgs/Int32.h"                                                     
#include <iostream>                                                             
using namespace std;                                                            
void fun(const std_msgs::Int32 a){                                              
        cout<<"/subscriber: data: "<<a.data<<"\n";                                    
return;                                                                         
}                                                                               
                                                                                
int main (int argc,char **argv){                                                
        ros::init(argc,argv,"subscriber");                                      
        ros::NodeHandle n;                                                      
        ros::Subscriber sub=n.subscribe("/topic",1000,fun);                     
        ros::spin();                                                            
        return 0;                                                               
}                                                                               
    
