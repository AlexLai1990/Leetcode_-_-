#ifndef MINHEAP_H
#define MINHEAP_H
 
#include "Vector_temp.h"
#include <assert.h>

template<class T>
class MinHeap {
public:
  MinHeap(); 
  ~MinHeap();

  void Append(T);  // automatic shift up 
  T GetRoot() ;
	T LowestKeyNode();

  void ShiftDown(); // reorder new root after use and change
  
	void print_out();
	bool Empty() ;
  size_t Size();

private:
  inline size_t Parent( size_t ix ) { return ( ix - 1 ) / 2; };
  inline size_t RightChild( size_t ix ) { return 2 * ( ix + 1 ); };
  inline size_t LeftChild( size_t ix ) { return ( 2 * ix ) + 1; };
  inline bool isLeaf( size_t ix ) { return LeftChild( ix ) >= m_size; };
  inline bool hasOneLeaf( size_t ix ) { return m_size == RightChild( ix ); };
  
	inline size_t idexOfLastItem();

  void SiftDown( size_t ix ); // from ix downwards, reordering item
  void SiftUp( size_t ix );   // from ix upwards towards root, when appending new items
  inline void Swap( size_t ix, size_t iy );
	 

  vector<T> m_vec_key;
  size_t m_size;
	 
};



template<class T>
MinHeap<T>::MinHeap(){
	m_size = 0;
}
 
template<class T>
MinHeap<T>::~MinHeap(){

} 

// automatic sift up
template<class T>
void MinHeap<T>::Append( T item ){ 
  m_vec_key.push_back( item );
  ++m_size;
  SiftUp( idexOfLastItem() );
}

template<class T>
T MinHeap<T>::GetRoot() { 
	assert( 0 != m_size ); 
	T temp = m_vec_key.get(0);
	Swap( 0 , idexOfLastItem() );
	m_vec_key.pop_back();
	m_size--;
	ShiftDown();
	return temp; 
}; 
 
template<class T>
T MinHeap<T>::LowestKeyNode(){
	return m_vec_key.get(0);
}

template<class T> 
void MinHeap<T>::SiftDown( size_t ix ){
	size_t cur = ix;
  while ( !isLeaf( cur ) ) {
    if ( hasOneLeaf( cur ) ) {
      size_t left = LeftChild( cur );
			// if child less than parent, then exchange them
			if ( m_vec_key.get( left ) < m_vec_key.get( cur ) ) {
        Swap( left, cur );
        cur = left;
      }
      else {
        break;
      }
    }
    else { // has two leaves
      size_t right = RightChild( cur );
      size_t left = LeftChild( cur );
      // if left is bigger than right, then go right
			bool bGoRight = !( m_vec_key.get( left ) < m_vec_key.get( right ) ) ;
      if ( bGoRight ) {
        if ( m_vec_key.get( right ) < m_vec_key.get( cur ) ) {
          Swap( right, cur );
          cur = right;
        }
        else {
          break;
        }
      }
      else { // go left
        if (  m_vec_key.get( left ) < m_vec_key.get( cur ) ) {
          Swap( left, cur );
          cur = left;
        }
        else {
          break;
        }
      }
    }
  }
}



// reorder new root after use and change
template<class T>
void MinHeap<T>::ShiftDown() { 
	 SiftDown( 0 ); 
} 

template<class T>
void MinHeap<T>::print_out(){
	for ( size_t i = 0 ; i < m_vec_key.size(); i++ )
		std::cout<< m_vec_key.get(i) << std::endl;
}


template<class T>
bool MinHeap<T>::Empty() { 
	if ( m_vec_key.size() == 0)
		return true;
	else
		return false;
}

template<class T>
size_t MinHeap<T>::Size() { 
	return m_vec_key.size();
}

template<class T> 
size_t MinHeap<T>::idexOfLastItem() {
  assert( 0 < m_size );
  return m_size - 1;
}



// function for siftup the element to the top
template<class T> 
void MinHeap<T>::SiftUp( size_t ix ){
	size_t cur = ix;
  size_t parent;
  while ( 0 != cur ) {
    parent = Parent( cur );
		if ( m_vec_key.get( parent ) < m_vec_key.get( cur ) ) {
      break;  
    }
    else { 
      Swap( cur, parent );
      cur = parent;
    }
  }
}


template<class T> 
void MinHeap<T>::Swap( size_t ix, size_t iy ) {
  assert( ix < m_size );
  assert( iy < m_size );
  T tmp = m_vec_key.get( ix );
	m_vec_key.set( ix, m_vec_key.get( iy ));
  m_vec_key.set( iy, tmp );
}



#endif
