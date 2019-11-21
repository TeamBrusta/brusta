package main

import (
	"encoding/json"
	"log"
	"net/http"
	"sync"

	"github.com/harrydrippin/brusta-go/model"
)

var m *model.Model
var singleton sync.Once

const (
	modelPath       = "./trace_model.pth"
	modelOutputSize = 1
)

// HandlerRoot handles `/` route
func HandlerRoot(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	w.Write([]byte("Brusta-Go v1.0.0, Use `POST /predict` to inference"))
}

// HandlerPredict handles `/predict` route
func HandlerPredict(w http.ResponseWriter, r *http.Request) {
	type HandlerPredictReq struct {
		Input []float32 `json:"input"`
	}

	type HandlerPredictResp struct {
		Result bool      `json:"result"`
		Output []float32 `json:"output,omitempty"`
		Cause  string    `json:"cause,omitempty"`
	}

	var request HandlerPredictReq
	if err := json.NewDecoder(r.Body).Decode(&request); err != nil {
		log.Println("Predict: Input JSON is malformed")
		w.WriteHeader(http.StatusBadRequest)
		result := HandlerPredictResp{
			Result: false,
			Cause:  "Input JSON is malformed",
		}

		if err := json.NewEncoder(w).Encode(&result); err != nil {
			log.Println("Predict: Error occurred while processing error message")
		}
		return
	}

	if len(request.Input) == 0 {
		result := HandlerPredictResp{
			Result: false,
			Cause:  "Input is not provided",
		}

		if err := json.NewEncoder(w).Encode(&result); err != nil {
			log.Println("Predict: Error occurred while processing error message")
		}
		return
	}

	singleton.Do(func() {
		log.Println("Initializing model")
		m = model.GetModel(modelPath, modelOutputSize)
	})

	output := m.Predict(request.Input)

	response := HandlerPredictResp{
		Result: true,
		Output: output,
	}

	w.WriteHeader(http.StatusOK)
	if err := json.NewEncoder(w).Encode(&response); err != nil {
		log.Println("Predict: Error occurred while processing response")
		return
	}
	return
}
