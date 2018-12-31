from setuptools import setup

package_name = 'donkeycar'

setup(
    name=package_name,
    version='0.0.1',
    packages=[],
    py_modules=[
        'drive_supervisor',
        'drive'
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Thomas Milas',
    author_email='itpro1994@gmail.com',
    maintainer='Thomas Milas',
    maintainer_email='mikael@osrfoundation.org',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='ROS2 wrapper fo the donkey library',
    license='Apache License, Version 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'drive_supervisor = drive_supervisor:main',
            'drive = drive:main'
        ],
    },
)
