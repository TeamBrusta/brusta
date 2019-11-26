![Brusta logo](https://user-images.githubusercontent.com/16871455/69590381-9b694c80-1032-11ea-8f0c-d53b08631aca.png)
# Brusta
+ language-agnostic PyTorch model serving
+ serve JIT compiled PyTorch model in production environment

## Requirements
+ docker == 18.09.1
+ wget == 1.20.1
+ your JIT traced PyTorch model (If you are not familiar with JIT tracing, please refer [JIT Tutorial](https://github.com/hyoungseok/jitTutorial))

## Process Flow
1. run `bridge`


## Request Example
request to the model server as follow (suppose your input dimension is 3)
```
curl -X POST -d '{"input":[1.0, 1.0, 1.0]}' localhost:8080/model/predict
```

## Contributors
+ YongRae Jo (dreamgonfly@gmail.com)
+ YoonHo Jo (cloudjo21@gmail.com)
+ GiChang Lee (new.ratsgo@gmail.com)
+ Seunghwan Hong
+ SeungHyek Cho

## Author
+ Alex Kim (hyoungseok.k@gmail.com)
