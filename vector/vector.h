struct vec_t;

struct vec_t *vector(size_t elemSize, unsigned int size);
struct vec_t *vectorDefault(size_t elemSize);
void destroyVector(struct vec_t *vector);

void push_back(size_t element, struct vec_t *vector);