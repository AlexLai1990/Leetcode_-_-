template<class T>
class SmartPointer {
public:
	SmartPointer(T *obj) {
		ref = obj;
		ref_count = (unsigned int *) malloc(sizeof(unsigned int));
		*ref_count = 1;
	}

	SmartPointer(SmartPointer<T> &sptr) {
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	SmartPointer & operator=(SmartPointer &sptr) {
		// point to itself
		if (this == &sptr)
			return *this;
		// decrement current point first, if it is pointing to somewhere
		if (*ref_count > 0)
			remove();
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return *this;
	}

	~SmartPointer() {
		remove();
	}

	T getValue() {
		return *ref;
	}
private:
	T *ref;
	unsigned int *ref_count;
	void move() {
		ref_count--;
		if (ref_count == 0) {
			delete ref;
			free(ref_count);
			ref == NULL;
			ref_count == NULL;
		}
		return;
	}
};
