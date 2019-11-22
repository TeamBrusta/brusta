#!/bin/bash

mkdir -p ${HOME}/tmp

binPath=./burner-0.1.0/bin/burner

${binPath} \
	-Dlogback.configurationFile=logback-http.xml \
	-Dport=${port} \
	-Dmodel_path=${modelPath} \
	-Dlib_path=${libPath} \
	-Dfile.encoding=UTF-8 \
	-Djava.io.tmpdir=${HOME}/tmp \
	-J-Xms${memory}M \
	-J-Xmx${memory}M \
	-J-XX:+UseG1GC \
	-J-server
