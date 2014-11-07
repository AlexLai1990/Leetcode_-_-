#include <cstdlib> // malloc

// function is used malloc a required size block and 
// return an aligned address divided by power of two or something
// usually alligned_size could be 16 ..
void *aligned_malloc(size_t required_size, size_t aligned_size) {
	if (required_size < 1 || aligned_size < 1)
		return NULL;
	// check alligned_size is a number power of 2
	if ((aligned_size & aligned_size - 1) != 0)
		return NULL;
	
	void *p1 = NULL, *p2 = NULL;
	size_t offset = aligned_size - 1;
	p1 = (void *)malloc(required_size + offset + sizeof(void *));
	if (p1 == NULL)
		return NULL;
	
	p2 = (void *)(((size_t) p1 + offset + sizeof(void *)) & (~offset));
	((void **))p2[-1] = p1;
	return p2;
}

void aligned_free(void *ptr) {
	if (ptr == NULL)
		return;
	free ((void**)ptr[-1]);
	return;
}