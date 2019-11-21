package model

// Model represents the model object with evaluation support
type Model struct {
	Path       string
	OutputSize int

	pModel int64
	eval   *Eval
}

// GetModel generates new Model object
func GetModel(path string, outputSize int) *Model {
	model := &Model{Path: path, OutputSize: outputSize}
	model.eval = NewEval()
	model.pModel = model.eval.LoadModel(path, outputSize)
	return model
}

// Predict runs the model and returns the inference result
func (m *Model) Predict(input []float32) []float32 {
	return m.eval.Evaluate(m.pModel, input)
}
