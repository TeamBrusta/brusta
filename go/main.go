package main

import (
	"log"
	"net/http"

	"github.com/harrydrippin/brusta-go/server"
)

func main() {
	server := server.NewRouter(routes)
	log.Print("Server is starting on port 8080")
	if err := http.ListenAndServe(":8080", server); err != nil {
		log.Fatal(err)
	}
}
