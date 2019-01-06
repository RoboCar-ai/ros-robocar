//
// Created by blown302 on 12/31/18.
//

#include "../include/aws_iot_bridge/aws_iot_client.h"
#include <nodelet/nodelet.h>
#include <string>

#include <unistd.h>

using namespace std;

void disconnectCallbackHandler(AWS_IoT_Client *pClient, void *data) {
    IOT_WARN("MQTT Disconnect");
    IoT_Error_t rc = FAILURE;

    if(NULL == pClient) {
        return;
    }

    IOT_UNUSED(data);

    if(aws_iot_is_autoreconnect_enabled(pClient)) {
        IOT_INFO("Auto Reconnect is enabled, Reconnecting attempt will start now");
    } else {
        IOT_WARN("Auto Reconnect not enabled. Starting manual reconnect...");
        rc = aws_iot_mqtt_attempt_reconnect(pClient);
        if(NETWORK_RECONNECTED == rc) {
            IOT_WARN("Manual Reconnect Successful");
        } else {
            IOT_WARN("Manual Reconnect Failed - %d", rc);
        }
    }
}

void robocar::iot::AwsIotClient::init() {
    cout << "LOADING CLIENT" << endl;

    AWS_IoT_Client client;
    IoT_Client_Init_Params mqttInitParams = iotClientInitParamsDefault;
    IoT_Client_Connect_Params connectParams = iotClientConnectParamsDefault;

    IoT_Publish_Message_Params paramsQOS0;
    char rootCA[] = "/home/blown302/ros-robocar/certs/root-ca.pem";
    char clientCRT[] = "/home/blown302/ros-robocar/certs/test.cert.pem";
    char clientKey[] = "/home/blown302/ros-robocar/certs/test.private.key";
    char HostAddress[HOST_ADDRESS_SIZE] = AWS_IOT_MQTT_HOST;

    IOT_INFO("\nAWS IoT SDK Version %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);

    mqttInitParams.enableAutoReconnect = false; // We enable this later below
    mqttInitParams.pHostURL = HostAddress;
    mqttInitParams.port = AWS_IOT_MQTT_PORT;
    mqttInitParams.pRootCALocation = rootCA;
    mqttInitParams.pDeviceCertLocation = clientCRT;
    mqttInitParams.pDevicePrivateKeyLocation = clientKey;
    mqttInitParams.mqttCommandTimeout_ms = 20000;
    mqttInitParams.tlsHandshakeTimeout_ms = 5000;
    mqttInitParams.isSSLHostnameVerify = true;
    mqttInitParams.disconnectHandler = disconnectCallbackHandler;
    mqttInitParams.disconnectHandlerData = NULL;

    auto rc = aws_iot_mqtt_init(&client, &mqttInitParams);
    if(SUCCESS != rc) {
        IOT_ERROR("aws_iot_mqtt_init returned error : %d ", rc);
        cerr << "aws_iot_mqtt_init returned error : " << rc << endl;
        return;
    }

    char client_id[] = AWS_IOT_MQTT_CLIENT_ID;

    connectParams.keepAliveIntervalInSec = 600;
    connectParams.isCleanSession = true;
    connectParams.MQTTVersion = MQTT_3_1_1;
    connectParams.pClientID = client_id;
    connectParams.clientIDLen = (uint16_t) strlen(AWS_IOT_MQTT_CLIENT_ID);
    connectParams.isWillMsgPresent = false;

    IOT_INFO("Connecting...");
    rc = aws_iot_mqtt_connect(&client, &connectParams);
    if(SUCCESS != rc) {
        IOT_ERROR("Error(%d) connecting to %s:%d", rc, mqttInitParams.pHostURL, mqttInitParams.port);
        cerr << "Error(%d) connecting to " << rc << endl;
        return;
    }

    cout << "Done loading client" << endl;
}

