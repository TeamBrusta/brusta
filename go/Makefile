GOCMD = go
GOBUILD = $(GOCMD) build
GOTEST = $(GOCMD) test

DYLD_LIBRARY_PATH = DYLD_LIBRARY_PATH=./

EXEC = brusta-go
EXEC_PATH = ./$(EXEC)

TEST_FILES = ./model_test.go

all: libmodel.build go.build

test:
	$(DYLD_LIBRARY_PATH) $(GOTEST) -v $(TEST_FILES)

run:
	$(DYLD_LIBRARY_PATH) $(EXEC_PATH)

go.build:
	rm -f $(EXEC_PATH)
	$(GOBUILD) -o .

libmodel.build:
	bash -c "cd launcher && cmake CMakeLists.txt && make && cp libmodel.so ../"

clean:
	bash -c "cd launcher && make clean"
	rm -rf $(EXEC) libmodel.so libmodel.dylib
