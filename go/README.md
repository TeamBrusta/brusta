![Brusta logo](https://user-images.githubusercontent.com/16871455/54772005-d2889200-4c49-11e9-90e7-dce87c9305ea.png)
# Brusta-Go
+ Language-agnostic PyTorch model serving
+ Serve JIT compiled PyTorch model in production environment

> This project is an extension for [Brusta: original project with Scala/Java support](https://github.com/hyoungseok/brusta/)

## Requirements
+ docker == 18.09.1
+ go >= 1.13
+ your JIT traced PyTorch model (If you are not familiar with JIT tracing, please refer [JIT Tutorial](https://github.com/hyoungseok/jitTutorial))

## Process Flow
1. Run "make" to make your PyTorch model server binary (libtorch should be pre-installed)
2. Load your traced PyTorch model file on the "model server"
3. Run the model server

## Details On Build Server
+ TBD

## Details On Model Server
+ TBD

## Request Example
Request to the model server as follow (Suppose your input dimension is 3)
```
curl -X POST -d '{"input":[1.0, 1.0, 1.0]}' localhost:8080/predict
```

## Contributors for original repository
+ YongRae Jo (dreamgonfly@gmail.com)
+ YoonHo Jo (cloudjo21@gmail.com)
+ GiChang Lee (new.ratsgo@gmail.com)
+ SukHyun Ko (s3cr3t)

## Author
+ Seunghwan Hong (harrydrippin@gmail.com)
+ Alex Kim (hyoungseok.k@gmail.com, Original project)
