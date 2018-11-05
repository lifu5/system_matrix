#include <stdio.h>
#include <stdint.h>
//#include <linux/cdev.h>
#ifndef  _BASE_H
#define _BASE_H

#ifdef __cpluscplus
extern "C"{
#endif

//#define INT32_MAX  2147483547
//#define INT32_MIN (-INT32_MAX-1)
#ifndef M_PI
# define M_E    2.7182818284590452354   /* e */
# define M_PI   3.1415926535897932384  /* pi */
#endif
#define BUFFSIZE 10000


#define cmi_abs(X)  ((X)>=0?(X):-(X))
#define cmi_max(X,Y) ((X)>=(Y)?(X):(Y))
#define cmi_min(X,Y) ((X)<=(Y)?(X):(Y))
#define cmi_odd(X) ((X)&1)
#define cmi_even(X) (((X)&1)==0)
#define cmi_sqr(x) ((x)*(x))

/* define dataype */
#define JBOOL   1
#define JINT    2
#define JFLOAT  3
#define JDOUBLE 4


struct cmi_image {
    char *name;
    int32_t n_row;
    int32_t n_col;
    int32_t n_depth;

    int32_t data_type;    //data storage type
    void* data;           //pointer for raw data
};


extern inline int row(struct cmi_image* f);
extern inline int col(struct cmi_image* f);
extern inline int depth(struct cmi_image* f);



struct cmi_image* allocimage(
    char* name,
    int32_t rr,     /* row size */
    int32_t cc,     /* col size */
    int32_t dp,     /* depth */
    int32_t dt     /* data type */
);

struct cmi_image* allocimage2d(
        char* name,
        int32_t rr,
        int32_t cc,
        int32_t dt
);

void writeimage(
    struct cmi_image* image,
    char* filename
);
// binary data

struct cmi_image* readimage(
    char* filename
);
// binary data

void freeimage(struct cmi_image* g);

void doubleimage(struct cmi_image* g);

void floatimage(struct cmi_image* g);

void boolimage(struct cmi_image* g);

void intimage(struct cmi_image* g);

struct cmi_image* copyimage(struct cmi_image* src);

#ifdef __cplusplus
}
#endif
#endif
