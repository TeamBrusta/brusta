package main

import (
	"testing"

	"github.com/harrydrippin/brusta-go/model"
)

func TestEval(T *testing.T) {
	var e *model.Eval
	var modelID int64
	const (
		modelPath        = "./trace_model.pth"
		targetFirstValue = 0.014204964
		outputSize       = 1
	)

	T.Run("NewEval", func(T *testing.T) {
		e = model.NewEval()
	})

	T.Run("LoadModel", func(T *testing.T) {
		modelID = e.LoadModel(modelPath, outputSize)
	})

	T.Run("Evaluate", func(T *testing.T) {
		predictedValues := e.Evaluate(modelID, []float32{3.0, 2.0, 1.0})
		if len(predictedValues) != 1 {
			T.Fatalf("Predicted values are not matching with output size")
		}

		if targetFirstValue != predictedValues[0] {
			T.Fatalf("Evaluated value %f is not equal with %f", predictedValues[0], targetFirstValue)
		}
	})
}
