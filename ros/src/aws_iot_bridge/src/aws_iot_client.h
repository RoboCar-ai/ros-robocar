//
// Created by blown302 on 12/31/18.
//

#ifndef ROS_ROBOCAR_AWS_IOT_CLIENT_H
#define ROS_ROBOCAR_AWS_IOT_CLIENT_H

#include "mqtt/Client.hpp"
#include "NetworkConnection.hpp"

namespace robocar {
    namespace iot {
        class AwsIotClient {
        private:
            std::shared_ptr<NetworkConnection> p_network_connection_;
            std::shared_ptr<mqtt::ConnectPacket> p_connect_packet_;
            std::shared_ptr<MqttClient> p_iot_client_;
        };
    }; // namespace iot
}; // namespace robocar
#endif //ROS_ROBOCAR_AWS_IOT_CLIENT_H
