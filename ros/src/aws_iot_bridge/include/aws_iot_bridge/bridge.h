//
// Created by blown302 on 1/1/19.
//

#ifndef ROS_ROBOCAR_BRIDGE_H
#define ROS_ROBOCAR_BRIDGE_H
#include <nodelet/nodelet.h>

namespace robocar {
    namespace iot {
        class Bridge : public nodelet::Nodelet {
        public:
            virtual void onInit();
        };
    };
}; // namespace iot

#endif // ROS_ROBOCAR_BRIDGE_H
