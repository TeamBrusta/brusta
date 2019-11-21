package server

import (
	"net/http"

	"github.com/gorilla/mux"
)

// Route defines the HTTP route
type Route struct {
	Name        string
	Method      string
	Path        string
	PathPrefix  string
	HandlerFunc http.HandlerFunc
}

// Routes is an array of Route
type Routes []Route

// NewRouter builds mux.Router by given Routes
func NewRouter(routes Routes) *mux.Router {
	router := mux.NewRouter().StrictSlash(true)
	for _, route := range routes {
		handler := Logger(route.HandlerFunc, route.Name)

		result := router.Methods(route.Method).Name(route.Name).Handler(handler)

		if route.PathPrefix != "" {
			result.PathPrefix(route.PathPrefix)
		} else {
			result.Path(route.Path)
		}
	}

	return router
}
