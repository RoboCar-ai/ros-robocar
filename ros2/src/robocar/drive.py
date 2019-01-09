#!/usr/bin/env python

import rclpy
from rclpy.node import Node
import sys

print(sys.executable)
from donkeycar.templates import donkey2 as manage, config_defaults


class Drive(Node):
    def __init__(self):
        print('drive is starting')
        config = config_defaults
        config.DONKEY_GYM = True
        config.DONKEY_SIM_PATH = '/home/blown302/DonkeySimLinux/donkey_sim.x86_64'
        config.CAR_PATH = '/home/blown302/r1'
        config.DATA_PATH = '/home/blown302/r1/data'
        config.MODELS_PATH = '/home/blown302/r1/models'
        config.AUTO_RECORD_ON_THROTTLE = False
        manage.drive(config)


def main(args=None):
    rclpy.init(args=args)
    node = Drive()
    node.destroy_node()
    rclpy.shutdown()
