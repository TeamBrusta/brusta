package model

/*
#cgo CFLAGS: -I../launcher
#cgo LDFLAGS: -L../ -lmodel
#include <cmodel.h>
*/
import "C"
import (
	"reflect"
	"unsafe"
)

// Eval represents pytorch::Eval object
type Eval struct {
	eval       C.Eval
	outputSize int
}

// NewEval crafts new eval object
func NewEval() *Eval {
	var eval Eval
	eval.eval = C.EvalInit()
	return &eval
}

// Free frees the memory from Model
func (m *Eval) Free() {
	C.EvalFree(m.eval)
}

// LoadModel loads model by name
func (m *Eval) LoadModel(modelName string, outputSize int) int64 {
	m.outputSize = outputSize
	return int64(C.EvalLoadModel(m.eval, C.CString(modelName)))
}

// Evaluate runs the model and return the inferenced value
func (m *Eval) Evaluate(pModel int64, x []float32) []float32 {
	result := C.EvalEvaluate(m.eval, C.long(pModel), (*C.float)(unsafe.Pointer(&x[0])))

	var returnArray []float32
	sliceHeader := (*reflect.SliceHeader)((unsafe.Pointer(&returnArray)))
	sliceHeader.Cap = m.outputSize
	sliceHeader.Len = m.outputSize
	sliceHeader.Data = uintptr(unsafe.Pointer(result))

	return returnArray
}
