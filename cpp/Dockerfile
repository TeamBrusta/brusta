FROM brusta-bridge:latest

RUN apt-get update -y
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update -y
RUN apt-get install -y git curl unzip tar cmake g++

WORKDIR /home

RUN git clone https://github.com/microsoft/vcpkg.git
RUN /home/vcpkg/bootstrap-vcpkg.sh
RUN /home/vcpkg/vcpkg install cpp-httplib jsoncpp
RUN mkdir -p /home/brusta/cpp

WORKDIR /home/brusta/cpp
ADD . /home/brusta/cpp

RUN mkdir -p build
RUN cd build && cmake -DCMAKE_TOOLCHAIN_FILE=/home/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_PREFIX_PATH=/home/brusta/libtorch ..
RUN cd build && make

WORKDIR /home/brusta/cpp/build/src
EXPOSE 8080

# CMD ["./brusta"]