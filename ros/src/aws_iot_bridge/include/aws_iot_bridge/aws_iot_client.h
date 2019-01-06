//
// Created by blown302 on 12/31/18.
//

#ifndef ROS_ROBOCAR_AWS_IOT_CLIENT_H
#define ROS_ROBOCAR_AWS_IOT_CLIENT_H

#include "aws_iot_config.h"
#include "aws_sdk/include/aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"

#define HOST_ADDRESS_SIZE 255

namespace robocar {
    namespace iot {
        class AwsIotClient {
        public:
            void init();
        };
    }; // namespace iot
}; // namespace robocar
#endif //ROS_ROBOCAR_AWS_IOT_CLIENT_H
