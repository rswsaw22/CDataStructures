struct vec_t;

// Constructors/Destructors
struct vec_t *Vector(size_t elemSize, unsigned int size);
struct vec_t *VectorDefault(size_t elemSize);
void DestroyVector(struct vec_t *vector);

// API Functions
void PushBack(void *element, struct vec_t *vector);
void *At(unsigned int index, struct vec_t *vector);
unsigned int Size(struct vec_t *vector);
void Swap(struct vec_t *vector1, struct vec_t *vector2); // Swaps values: Vec1 <---> Vec2