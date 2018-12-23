from setuptools import setup

package_name = 'ros-robocar'

setup(
    name=package_name,
    version='1.0',
    packages=[],
    py_modules=['drive_supervisor'],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Thomas Milas',
    maintainer='Thomas Milas',
    keywords=['ROS'],
    description='ros donkeycar wrapper',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': ['drive_supervisor=drive_supervisor:main'],
    },
)