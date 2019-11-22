FROM ubuntu:18.04 AS build-env

RUN apt-get update -y
RUN apt-get install -y wget unzip cmake g++

RUN mkdir -p /home/brusta/bridge
WORKDIR /home/brusta/bridge

RUN wget https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-1.3.1%2Bcpu.zip -O /home/brusta/bridge/libtorch.zip
RUN unzip /home/brusta/bridge/libtorch.zip -d /home/brusta/bridge
RUN rm /home/brusta/bridge/libtorch.zip

ADD . /home/brusta/bridge

ARG MODEL_TYPE=DNN

RUN mkdir -p build
RUN cd build && CMAKE_PREFIX_PATH=../libtorch/share/cmake/Torch cmake -DMODEL_TYPE=${MODEL_TYPE} ..
RUN cd build && make && mv libbridge.so ../libbridge.so

VOLUME /home/brusta/bridge

FROM ubuntu:18.04

RUN mkdir -p /home/brusta
WORKDIR /home/brusta

COPY --from=build-env /home/brusta/bridge/libtorch/ ./libtorch/
COPY --from=build-env /home/brusta/bridge/libbridge.so ./libbridge.so

RUN mkdir -p libbridge
COPY --from=build-env /home/brusta/bridge/includes ./libbridge/includes
COPY --from=build-env /home/brusta/bridge/src ./libbridge/src
