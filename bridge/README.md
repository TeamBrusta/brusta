# Bridge

## How To Build

Follow below steps assuming that we are handling DNN:

```bash
docker build --build-arg MODEL_TYPE=DNN . -t brusta-bridge:latest
```

## How To Test

You can see `libbridge.so` and `libtorch` directory inside `/home/brusta` after build.

To see it by yourself:

```bash
docker run -it brusta-bridge:latest bash
```

## How To Use

```dockerfile
FROM brusta-bridge:latest
```