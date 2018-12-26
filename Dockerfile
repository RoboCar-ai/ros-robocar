FROM blown302/ros2-core
RUN pip3 install git+https://github.com/RoboCar-ai/donkey.git
RUN pip3 install git+https://github.com/RoboCar-ai/donkey_gym.git@missing-env-package-import