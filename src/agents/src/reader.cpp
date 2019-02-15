#include <ros/ros.h>
#include <msg/Message1.h>

std::string text;
int maxNum = 0;
void reader (const msg::Message1 & mess)
{
    int num = mess.num;
    
    ROS_INFO("Received a message with text %s.\n",mess.text.c_str());
    
    if (num > maxNum){
        maxNum=num;
        text=mess.text;
    }
    if (mess.num==-1){
        ROS_INFO("The biggest number is %d. Text is %s.\n",maxNum,text.c_str());
        ros::shutdown();
    }
    
    
}
int main(int argc, char **argv){
    ros::init(argc,argv,"reader");
    ROS_INFO_STREAM("Reader is ready \n");
    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe("Name",10,reader);
    ros::spin();
    return 0;
}
