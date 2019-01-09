#!/usr/bin/env python
import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class DriveSupervisor(Node):
    def __init__(self):
        super().__init__('drive_supervisor')

        self.status_publisher = self.create_publisher(String, 'status')
        loop_rate = 5. # in seconds
        self.timer = self.create_timer(loop_rate, self.loop_iter)

    def publish_status(self):
        message = String()
        message.data = '{"connectionStatus":"connected"}'
        self.get_logger().info('publishing connection status: {}'.format(message.data))
        self.status_publisher.publish(message)

    def loop_iter(self):
        self.publish_status()


def main(args=None):
    print('drive_supervisor is starting')
    rclpy.init(args=args)
    node = DriveSupervisor()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
