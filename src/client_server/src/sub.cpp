#include "ros/ros.h"
#include "serv/AddInts.h"

bool add(serv::AddInts::Request & req, serv::AddInts::Response &res)
{
    res.sum=req.first+req.secomd;
    ROS_INFO("Request: x=%d, y=%d", req.first,req.secomd);
    ROS_INFO("sending back response: [%d]",res.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"Add");
    ros::NodeHandle n;
    
    ros::ServiceServer serv = n.advertiseService("add_two_ints",add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();
    
    return 0;
}
