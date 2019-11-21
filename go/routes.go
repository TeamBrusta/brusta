package main

import (
	"github.com/harrydrippin/brusta-go/server"
)

var routes = server.Routes{
	server.Route{
		Name:        "Root",
		Method:      "GET",
		Path:        "/",
		HandlerFunc: HandlerRoot,
	},
	server.Route{
		Name:        "Predict",
		Method:      "POST",
		PathPrefix:  "/predict",
		HandlerFunc: HandlerPredict,
	},
}
