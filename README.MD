# ROS Robcar

A ROS wrapper around the donkey library providing messaging middleware for a distributed donkey...jk

## Development

prototyping with docker, public container on `Docker Hub`. To use:

```bash
docker run -it -v $(pwd):/robocar --rm blown302/ros2-core bash
```

### Building

```bash
colcon build --symlink-install
```