#include <cstdlib>

int ** malloc_2D(int rows, int cols) {
	int ** m_ret = NULL;
	if (rows < 1 || cols < 1)
		return m_ret;
	m_ret = (int **)malloc(rows * sizeof(int *));
	if (m_ret == NULL)
		return NULL;
	for (int i = 0; i < rows; i++) {
		m_ret[i] = (int *)malloc(col * sizeof(int));
	}
	return m_ret;
}

void free_2D(int **m_matrix, int rows) {
	if (m_matrix == NULL)
		return;
	for (int i = 0; i < rows; i++) {
		free(m_matrix[i]);
	}
	free(m_matrix);
	return;
}

// way2, by using one malloc function
int ** malloc_2D_(int rows, int cols) {
	int ** m_matrix = NULL;
	if (rows < 1 || cols < 1)
		return m_ret;
	// this blocks need to store the address of starting of a row
	int header = rows * sizeof(int *);
	int data = rows * cols * sizeof(int);
	m_matrix = (int **)malloc(header + data);
	if (m_matrix == NULL)
		return NULL;
	}
	int *buf = (int *) (m_matrix + rows);
	for (int i = 0; i < rows; i++) {
		m_matrix[i] = buf + i * cols;
	}
	return m_matrix;
}
