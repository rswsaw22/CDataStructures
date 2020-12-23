struct vec_t;

struct vec_t *Vector(size_t elemSize, unsigned int size);
struct vec_t *VectorDefault(size_t elemSize);
void DestroyVector(struct vec_t *vector);

void PushBack(void *element, struct vec_t *vector);
void *At(unsigned int index, struct vec_t *vector);