package main

import "C"

import "sync"

var mu sync.Mutex
var index int
var fns = make(map[int]func(*C.char))

func register(fn func(*C.char)) int {
	mu.Lock()
	defer mu.Unlock()
	index++
	for fns[index] != nil {
		index++
	}
	fns[index] = fn
	return index
}

func lookup(i int) func(*C.char) {
	mu.Lock()
	defer mu.Unlock()
	return fns[i]
}

func unregister(i int) {
	mu.Lock()
	defer mu.Unlock()
	delete(fns, i)
}

//export go_callback
func go_callback(callbackId C.int, image *C.char) {
	fn := lookup(int(callbackId))
	fn(image)
}
