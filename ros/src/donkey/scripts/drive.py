#!/usr/bin/env python
import rospy
import sys
print(sys.version)
from donkeycar.templates import donkey2 as manage, config_defaults


def main():
    rospy.init_node('donkey')
    print('drive is starting')
    config = config_defaults
    config.DONKEY_GYM = True
    config.DONKEY_SIM_PATH = '/home/blown302/DonkeySimLinux/donkey_sim.x86_64'
    config.CAR_PATH = '/home/blown302/r1'
    config.DATA_PATH = '/home/blown302/r1/data'
    config.MODELS_PATH = '/home/blown302/r1/models'
    config.AUTO_RECORD_ON_THROTTLE = False
    manage.drive(config)


if __name__ == '__main__':
    main()
