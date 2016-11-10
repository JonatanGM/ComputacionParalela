#include <math.h>

#ifndef F2C_INCLUDE
#define F2C_INCLUDE

typedef long int integer;
typedef unsigned long uinteger;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
typedef long int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;

#if 0   /* Adjust for integer*8. */
typedef long long longint;              /* system-dependent */
typedef unsigned long long ulongint;    /* system-dependent */
#define qbit_clear(a,b) ((a) & ~((ulongint)1 << (b)))
#define qbit_set(a,b)   ((a) |  ((ulongint)1 << (b)))
#endif

#define TRUE_ (1)
#define FALSE_ (0)

#ifndef Extern
#define Extern extern
#endif

#ifdef f2c_i2
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef long int flag;
typedef long int ftnlen;
typedef long int ftnint;
#endif


typedef struct
{       flag cierr;
        ftnint ciunit;
        flag ciend;
        char *cifmt;
        ftnint cirec;
} cilist;

typedef struct
{       flag icierr;
        char *iciunit;
        flag iciend;
        char *icifmt;
        ftnint icirlen;
        ftnint icirnum;
} icilist;

typedef struct
{       flag oerr;
        ftnint ounit;
        char *ofnm;
        ftnlen ofnmlen;
        char *osta;
        char *oacc;
        char *ofm;
        ftnint orl;
        char *oblnk;
} olist;

typedef struct
{       flag cerr;
        ftnint cunit;
        char *csta;
} cllist;


typedef struct
{       flag aerr;
        ftnint aunit;
} alist;

typedef struct
{       flag inerr;
        ftnint inunit;
        char *infile;
        ftnlen infilen;
        ftnint  *inex;  /*parameters in standard's order*/
        ftnint  *inopen;
        ftnint  *innum;
        ftnint  *innamed;
        char    *inname;
        ftnlen  innamlen;
        char    *inacc;
        ftnlen  inacclen;
        char    *inseq;
        ftnlen  inseqlen;
        char    *indir;
        ftnlen  indirlen;
        char    *infmt;
        ftnlen  infmtlen;
        char    *inform;
        ftnint  informlen;
        char    *inunf;
        ftnlen  inunflen;
        ftnint  *inrecl;
        ftnint  *innrec;
        char    *inblank;
        ftnlen  inblanklen;
} inlist;

#define VOID void

union Multitype {       /* for multiple entry points */
        integer1 g;
        shortint h;
        integer i;
        /* longint j; */
        real r;
        doublereal d;
        complex c;
        doublecomplex z;
};

struct Vardesc {        /* for Namelist */
        char *name;
        char *addr;
        ftnlen *dims;
        int  type;
};

typedef struct Vardesc Vardesc;

struct Namelist {
        char *name;
        Vardesc **vars;
        int nvars;
};

typedef struct Namelist Namelist;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)abs(x)
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)min(a,b)
#define dmax(a,b) (doublereal)max(a,b)
#define bit_test(a,b)   ((a) >> (b) & 1)
#define bit_clear(a,b)  ((a) & ~((uinteger)1 << (b)))
#define bit_set(a,b)    ((a) |  ((uinteger)1 << (b)))

#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* Complex */ VOID (*C_fp)(...);
typedef /* Double Complex */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* Complex */ VOID (*C_fp)();
typedef /* Double Complex */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif


typedef VOID C_f;       /* complex function */
typedef VOID H_f;       /* character function */
typedef VOID Z_f;       /* double complex function */
typedef doublereal E_f; /* real function with -R not specified */

#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef unix
#undef vax
#endif
#endif

int slaruv_(integer *iseed, integer *n, real *x) {
    static integer mm[512] = { 494,2637,255,2008,1253,
            3344,4084,1739,3143,3468,688,1657,1238,3166,1292,3422,1270,2016,
            154,2862,697,1706,491,931,1444,444,3577,3944,2184,1661,3482,657,
            3023,3618,1267,1828,164,3798,3087,2400,2870,3876,1905,1593,1797,
            1234,3460,328,2861,1950,617,2070,3331,769,1558,2412,2800,189,287,
            2045,1227,2838,209,2770,3654,3993,192,2253,3491,2889,2857,2094,
            1818,688,1407,634,3231,815,3524,1914,516,164,303,2144,3480,119,
            3357,837,2826,2332,2089,3780,1700,3712,150,2000,3375,1621,3090,
            3765,1149,3146,33,3082,2741,359,3316,1749,185,2784,2202,2199,1364,
            1244,2020,3160,2785,2772,1217,1822,1245,2252,3904,2774,997,2573,
            1148,545,322,789,1440,752,2859,123,1848,643,2405,2638,2344,46,
            3814,913,3649,339,3808,822,2832,3078,3633,2970,637,2249,2081,4019,
            1478,242,481,2075,4058,622,3376,812,234,641,4005,1122,3135,2640,
            2302,40,1832,2247,2034,2637,1287,1691,496,1597,2394,2584,1843,336,
            1472,2407,433,2096,1761,2810,566,442,41,1238,1086,603,840,3168,
            1499,1084,3438,2408,1589,2391,288,26,512,1456,171,1677,2657,2270,
            2587,2961,1970,1817,676,1410,3723,2803,3185,184,663,499,3784,1631,
            1925,3912,1398,1349,1441,2224,2411,1907,3192,2786,382,37,759,2948,
            1862,3802,2423,2051,2295,1332,1832,2405,3638,3661,327,3660,716,
            1842,3987,1368,1848,2366,2508,3754,1766,3572,2893,307,1297,3966,
            758,2598,3406,2922,1038,2934,2091,2451,1580,1958,2055,1507,1078,
            3273,17,854,2916,3971,2889,3831,2621,1541,893,736,3992,787,2125,
            2364,2460,257,1574,3912,1216,3248,3401,2124,2762,149,2245,166,466,
            4018,1399,190,2879,153,2320,18,712,2159,2318,2091,3443,1510,449,
            1956,2201,3137,3399,1321,2271,3667,2703,629,2365,2431,1113,3922,
            2554,184,2099,3228,4012,1921,3452,3901,572,3309,3171,817,3039,
            1696,1256,3715,2077,3019,1497,1101,717,51,981,1978,1813,3881,76,
            3846,3694,1682,124,1660,3997,479,1141,886,3514,1301,3604,1888,
            1836,1990,2058,692,1194,20,3285,2046,2107,3508,3525,3801,2549,
            1145,2253,305,3301,1065,3133,2913,3285,1241,1197,3729,2501,1673,
            541,2753,949,2361,1165,4081,2725,3305,3069,3617,3733,409,2157,
            1361,3973,1865,2525,1409,3445,3577,77,3761,2149,1449,3005,225,85,
            3673,3117,3089,1349,2057,413,65,1845,697,3085,3441,1573,3689,2941,
            929,533,2841,4077,721,2821,2249,2397,2817,245,1913,1997,3121,997,
            1833,2877,1633,981,2009,941,2449,197,2441,285,1473,2741,3129,909,
            2801,421,4073,2813,2337,1429,1177,1901,81,1669,2633,2269,129,1141,
            249,3917,2481,3941,2217,2749,3041,1877,345,2861,1809,3141,2825,
            157,2881,3637,1465,2829,2161,3365,361,2685,3745,2325,3609,3821,
            3537,517,3017,2141,1537 };

    integer i__1;
    static integer i__, i1, i2, i3, i4, it1, it2, it3, it4;
#define mm_ref(a_1,a_2) mm[(a_2)*128 + a_1 - 129]

    --iseed;
    --x;
    i1 = iseed[1];
    i2 = iseed[2];
    i3 = iseed[3];
    i4 = iseed[4];

    i__1 = min(*n,128);
    for (i__ = 1; i__ <= i__1; ++i__) {
        it4 = i4 * mm_ref(i__, 4);
        it3 = it4 / 4096;
        it4 -= it3 << 12;
        it3 = it3 + i3 * mm_ref(i__, 4) + i4 * mm_ref(i__, 3);
        it2 = it3 / 4096;
        it3 -= it2 << 12;
        it2 = it2 + i2 * mm_ref(i__, 4) + i3 * mm_ref(i__, 3) + i4 * mm_ref(i__, 2);
        it1 = it2 / 4096;
        it2 -= it1 << 12;
        it1 = it1 + i1 * mm_ref(i__, 4) + i2 * mm_ref(i__, 3) + i3 * mm_ref(i__, 2) + i4 * mm_ref(i__, 1);
        it1 %= 4096;

        x[i__] = ((real) it1 + ((real) it2 + ((real) it3 + (real) it4 * 
                2.44140625e-4f) * 2.44140625e-4f) * 2.44140625e-4f) * 2.44140625e-4f;

    }

    iseed[1] = it1;
    iseed[2] = it2;
    iseed[3] = it3;
    iseed[4] = it4;
    return 0;
}
#undef mm_ref

int Slarnv(integer *idist, integer *iseed, integer *n, real *x) {
    integer i__1, i__2, i__3;
    static integer i__;
    static real u[128];
    static integer il, iv, il2;
    extern int slaruv_(integer *, integer *, real *);

    --x;
    --iseed;

    i__1 = *n;
    for (iv = 1; iv <= i__1; iv += 64) {
        i__2 = 64, i__3 = *n - iv + 1;
        il = min(i__2,i__3);
        if (*idist == 3) {
            il2 = il << 1;
        } else {
            il2 = il;
        }

        slaruv_(&iseed[1], &il2, u);
        if (*idist == 1) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = u[i__ - 1];
            }
        } else if (*idist == 2) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = u[i__ - 1] * 2.f - 1.f;
            }
        } else if (*idist == 3) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = sqrt(log(u[(i__ << 1) - 2]) * -2.f) * cos(u[(i__ << 1) - 1] * 6.2831853071795864769252867663f);
            }
        }
    }
    return 0;
}


int dlaruv_(integer *iseed, integer *n, doublereal *x) {
    static integer mm[512] = { 494,2637,255,2008,1253,
            3344,4084,1739,3143,3468,688,1657,1238,3166,1292,3422,1270,2016,
            154,2862,697,1706,491,931,1444,444,3577,3944,2184,1661,3482,657,
            3023,3618,1267,1828,164,3798,3087,2400,2870,3876,1905,1593,1797,
            1234,3460,328,2861,1950,617,2070,3331,769,1558,2412,2800,189,287,
            2045,1227,2838,209,2770,3654,3993,192,2253,3491,2889,2857,2094,
            1818,688,1407,634,3231,815,3524,1914,516,164,303,2144,3480,119,
            3357,837,2826,2332,2089,3780,1700,3712,150,2000,3375,1621,3090,
            3765,1149,3146,33,3082,2741,359,3316,1749,185,2784,2202,2199,1364,
            1244,2020,3160,2785,2772,1217,1822,1245,2252,3904,2774,997,2573,
            1148,545,322,789,1440,752,2859,123,1848,643,2405,2638,2344,46,
            3814,913,3649,339,3808,822,2832,3078,3633,2970,637,2249,2081,4019,
            1478,242,481,2075,4058,622,3376,812,234,641,4005,1122,3135,2640,
            2302,40,1832,2247,2034,2637,1287,1691,496,1597,2394,2584,1843,336,
            1472,2407,433,2096,1761,2810,566,442,41,1238,1086,603,840,3168,
            1499,1084,3438,2408,1589,2391,288,26,512,1456,171,1677,2657,2270,
            2587,2961,1970,1817,676,1410,3723,2803,3185,184,663,499,3784,1631,
            1925,3912,1398,1349,1441,2224,2411,1907,3192,2786,382,37,759,2948,
            1862,3802,2423,2051,2295,1332,1832,2405,3638,3661,327,3660,716,
            1842,3987,1368,1848,2366,2508,3754,1766,3572,2893,307,1297,3966,
            758,2598,3406,2922,1038,2934,2091,2451,1580,1958,2055,1507,1078,
            3273,17,854,2916,3971,2889,3831,2621,1541,893,736,3992,787,2125,
            2364,2460,257,1574,3912,1216,3248,3401,2124,2762,149,2245,166,466,
            4018,1399,190,2879,153,2320,18,712,2159,2318,2091,3443,1510,449,
            1956,2201,3137,3399,1321,2271,3667,2703,629,2365,2431,1113,3922,
            2554,184,2099,3228,4012,1921,3452,3901,572,3309,3171,817,3039,
            1696,1256,3715,2077,3019,1497,1101,717,51,981,1978,1813,3881,76,
            3846,3694,1682,124,1660,3997,479,1141,886,3514,1301,3604,1888,
            1836,1990,2058,692,1194,20,3285,2046,2107,3508,3525,3801,2549,
            1145,2253,305,3301,1065,3133,2913,3285,1241,1197,3729,2501,1673,
            541,2753,949,2361,1165,4081,2725,3305,3069,3617,3733,409,2157,
            1361,3973,1865,2525,1409,3445,3577,77,3761,2149,1449,3005,225,85,
            3673,3117,3089,1349,2057,413,65,1845,697,3085,3441,1573,3689,2941,
            929,533,2841,4077,721,2821,2249,2397,2817,245,1913,1997,3121,997,
            1833,2877,1633,981,2009,941,2449,197,2441,285,1473,2741,3129,909,
            2801,421,4073,2813,2337,1429,1177,1901,81,1669,2633,2269,129,1141,
            249,3917,2481,3941,2217,2749,3041,1877,345,2861,1809,3141,2825,
            157,2881,3637,1465,2829,2161,3365,361,2685,3745,2325,3609,3821,
            3537,517,3017,2141,1537 };

    integer i__1;
    static integer i__, i1, i2, i3, i4, it1, it2, it3, it4;
#define mm_ref(a_1,a_2) mm[(a_2)*128 + a_1 - 129]

    --iseed;
    --x;
    i1 = iseed[1];
    i2 = iseed[2];
    i3 = iseed[3];
    i4 = iseed[4];

    i__1 = min(*n,128);
    for (i__ = 1; i__ <= i__1; ++i__) {
        it4 = i4 * mm_ref(i__, 4);
        it3 = it4 / 4096;
        it4 -= it3 << 12;
        it3 = it3 + i3 * mm_ref(i__, 4) + i4 * mm_ref(i__, 3);
        it2 = it3 / 4096;
        it3 -= it2 << 12;
        it2 = it2 + i2 * mm_ref(i__, 4) + i3 * mm_ref(i__, 3) + i4 * mm_ref(i__, 2);
        it1 = it2 / 4096;
        it2 -= it1 << 12;
        it1 = it1 + i1 * mm_ref(i__, 4) + i2 * mm_ref(i__, 3) + i3 * mm_ref(i__, 2) + i4 * mm_ref(i__, 1);
        it1 %= 4096;

        x[i__] = ((doublereal) it1 + ((doublereal) it2 + ((doublereal) it3 + (doublereal) it4 * 
                2.44140625e-4f) * 2.44140625e-4f) * 2.44140625e-4f) * 2.44140625e-4f;

    }

    iseed[1] = it1;
    iseed[2] = it2;
    iseed[3] = it3;
    iseed[4] = it4;
    return 0;
}
#undef mm_ref



int Dlarnv(integer *idist, integer *iseed, integer *n, doublereal *x) {
    integer i__1, i__2, i__3;
    static integer i__;
    static doublereal u[128];
    static integer il, iv, il2;
    extern int dlaruv_(integer *, integer *, doublereal *);

    --x;
    --iseed;

    i__1 = *n;
    for (iv = 1; iv <= i__1; iv += 64) {
        i__2 = 64, i__3 = *n - iv + 1;
        il = min(i__2,i__3);
        if (*idist == 3) {
            il2 = il << 1;
        } else {
            il2 = il;
        }

        dlaruv_(&iseed[1], &il2, u);
        if (*idist == 1) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = u[i__ - 1];
            }
        } else if (*idist == 2) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = u[i__ - 1] * 2.f - 1.f;
            }
        } else if (*idist == 3) {
            i__2 = il;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[iv + i__ - 1] = sqrt(log(u[(i__ << 1) - 2]) * -2.f) * cos(u[(i__ << 1) - 1] * 6.2831853071795864769252867663f);
            }
        }
    }
    return 0;
}

