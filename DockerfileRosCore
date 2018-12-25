FROM osrf/ros2:bouncy-ros-core
RUN apt update && apt install -y \
  build-essential \
  cmake \
  git \
  python3-colcon-common-extensions \
  python3-pip \
  python-rosdep \
  python3-vcstool \
  wget \
  vim
RUN python3 -m pip install -U \
  argcomplete \
  flake8 \
  flake8-blind-except \
  flake8-builtins \
  flake8-class-newline \
  flake8-comprehensions \
  flake8-deprecated \
  flake8-docstrings \
  flake8-import-order \
  flake8-quotes \
  git+https://github.com/lark-parser/lark.git@0.7b \
  pytest-repeat \
  pytest-rerunfailures \
  pytest \
  pytest-cov \
  pytest-runner \
  setuptools
RUN apt install --no-install-recommends -y \
  libasio-dev \
  libtinyxml2-dev
RUN echo 'source /opt/ros/bouncy/setup.bash' >> ~/.bashrc \
  && echo 'source /robocar/ros/install/local_setup.bash' >> ~/.bashrc \
  && echo 'source /robocar/ros/install/setup.bash' >> ~/.bashrc
WORKDIR /robocar/ros
