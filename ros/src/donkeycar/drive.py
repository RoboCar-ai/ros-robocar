import rclpy
from rclpy.node import Node
from donkeycar.templates import donkey2 as manage, config_defaults


class Drive(Node):
    def __init__(self):
        print('drive is starting')
        config = config_defaults
        config.DONKEY_GYM = True
        manage.drive(config)


def main(args=None):
    rclpy.init(args=args)
    node = Drive()
    node.destroy_node()
    rclpy.shutdown()
