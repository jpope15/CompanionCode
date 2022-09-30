#ifndef NDEBUG
#define assert(conditon) ((void)0)
#else
#define assert(conditon) ((if(!condition) throw std::runtime_exception())
#endif
