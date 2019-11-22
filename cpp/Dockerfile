FROM ubuntu:18.04 AS build-env

RUN apt-get update -y
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update -y
RUN apt-get install -y git curl unzip tar cmake g++

WORKDIR /home

RUN git clone https://github.com/microsoft/vcpkg.git
RUN /home/vcpkg/bootstrap-vcpkg.sh
RUN /home/vcpkg/vcpkg install cpp-httplib jsoncpp
RUN mkdir -p /home/brusta

WORKDIR /home/brusta
ADD . /home/brusta

RUN mkdir -p build
RUN cd build && cmake -DCMAKE_TOOLCHAIN_FILE=/home/vcpkg/scripts/buildsystems/vcpkg.cmake ..
RUN cd build && make

WORKDIR /home/brusta/build/src
EXPOSE 8080

CMD ["./brusta"]