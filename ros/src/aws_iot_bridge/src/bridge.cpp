//
// Created by blown302 on 1/1/19.
//

#include "../include/aws_iot_bridge/bridge.h"
#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(robocar::iot::Bridge, nodelet::Nodelet)


void robocar::iot::Bridge::onInit() {
    NODELET_INFO("Initializing AWS BRIDGE...");
    robocar::iot::AwsIotClient client;
    client.init();
}

