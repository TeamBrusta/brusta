package main

import (
	"log"

	"github.com/harrydrippin/brusta-go/model"
)

// ExampleModel is an example for using model package
func ExampleModel() {
	const (
		modelPath  = "./trace_model.pth"
		outputSize = 1
	)

	log.Println("Spawning evaluation object")
	eval := model.NewEval()
	log.Println("Loading model with output size 1")
	modelP := eval.LoadModel(modelPath, 1)

	log.Println("Evaluating model with {3.0, 2.0, 1.0}")
	result := eval.Evaluate(modelP, []float32{3.0, 2.0, 1.0})
	log.Printf("Result: %v", result[0])
}
