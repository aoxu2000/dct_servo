/* Include files */

#include "ur_servo_sfun.h"
#include "c2_ur_servo.h"
#include <math.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c2_emlrtMCI = { 119,/* lineNo */
  13,                                  /* colNo */
  "imread",                            /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtMCInfo c2_b_emlrtMCI = { 121,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtMCInfo c2_c_emlrtMCI = { 126,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtMCInfo c2_d_emlrtMCI = { 132,/* lineNo */
  13,                                  /* colNo */
  "imread",                            /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtMCInfo c2_e_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c2_f_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c2_g_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c2_h_emlrtMCI = { 111,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtMCInfo c2_i_emlrtMCI = { 44,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c2_j_emlrtMCI = { 47,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c2_k_emlrtMCI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 42, /* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 47,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 54,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 56,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 60,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 71,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 76,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 78,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 34,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 36,/* lineNo */
  "servo_step_real",                   /* fcnName */
  "/home/user/Desktop/Program_servo/servo_step_real.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 19,/* lineNo */
  "MatrixExp3",                        /* fcnName */
  "/home/user/Desktop/Program_servo/MatrixExp3.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 20,/* lineNo */
  "MatrixExp3",                        /* fcnName */
  "/home/user/Desktop/Program_servo/MatrixExp3.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 23,/* lineNo */
  "MatrixExp3",                        /* fcnName */
  "/home/user/Desktop/Program_servo/MatrixExp3.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 24,/* lineNo */
  "AxisAng3",                          /* fcnName */
  "/home/user/Desktop/Program_servo/AxisAng3.m"/* pathName */
};

static emlrtRSInfo c2_o_emlrtRSI = { 6,/* lineNo */
  "get_FeaturesError_InteractionMatrix_DVS",/* fcnName */
  "/home/user/Desktop/Program_servo/get_FeaturesError_InteractionMatrix_DVS.m"/* pathName */
};

static emlrtRSInfo c2_p_emlrtRSI = { 8,/* lineNo */
  "get_FeaturesError_InteractionMatrix_DVS",/* fcnName */
  "/home/user/Desktop/Program_servo/get_FeaturesError_InteractionMatrix_DVS.m"/* pathName */
};

static emlrtRSInfo c2_q_emlrtRSI = { 4,/* lineNo */
  "get_interaction_matrix_gray",       /* fcnName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m"/* pathName */
};

static emlrtRSInfo c2_r_emlrtRSI = { 11,/* lineNo */
  "get_interaction_matrix_gray",       /* fcnName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m"/* pathName */
};

static emlrtRSInfo c2_s_emlrtRSI = { 19,/* lineNo */
  "get_interaction_matrix_gray",       /* fcnName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m"/* pathName */
};

static emlrtRSInfo c2_t_emlrtRSI = { 20,/* lineNo */
  "get_interaction_matrix_gray",       /* fcnName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m"/* pathName */
};

static emlrtRSInfo c2_u_emlrtRSI = { 21,/* lineNo */
  "TransInv",                          /* fcnName */
  "/home/user/Desktop/Program_servo/TransInv.m"/* pathName */
};

static emlrtRSInfo c2_v_emlrtRSI = { 3,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#ur_servo:11"                       /* pathName */
};

static emlrtRSInfo c2_w_emlrtRSI = { 4,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#ur_servo:11"                       /* pathName */
};

static emlrtRSInfo c2_x_emlrtRSI = { 10,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#ur_servo:11"                       /* pathName */
};

static emlrtRSInfo c2_y_emlrtRSI = { 12,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#ur_servo:11"                       /* pathName */
};

static emlrtRSInfo c2_ab_emlrtRSI = { 106,/* lineNo */
  "imread",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pathName */
};

static emlrtRSInfo c2_bb_emlrtRSI = { 163,/* lineNo */
  "imread",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pathName */
};

static emlrtRSInfo c2_cb_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c2_db_emlrtRSI = { 48,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pathName */
};

static emlrtRSInfo c2_eb_emlrtRSI = { 20,/* lineNo */
  "mldivide",                          /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/ops/mldivide.m"/* pathName */
};

static emlrtRSInfo c2_fb_emlrtRSI = { 42,/* lineNo */
  "mldivide",                          /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/ops/mldivide.m"/* pathName */
};

static emlrtRSInfo c2_gb_emlrtRSI = { 61,/* lineNo */
  "lusolve",                           /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo c2_hb_emlrtRSI = { 293,/* lineNo */
  "lusolve",                           /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo c2_ib_emlrtRSI = { 90,/* lineNo */
  "lusolve",                           /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo c2_jb_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo c2_kb_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c2_lb_emlrtRSI = { 21,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_mb_emlrtRSI = { 42,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_nb_emlrtRSI = { 46,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_ob_emlrtRSI = { 68,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_pb_emlrtRSI = { 69,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_qb_emlrtRSI = { 72,/* lineNo */
  "pinv",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/matfun/pinv.m"/* pathName */
};

static emlrtRSInfo c2_rb_emlrtRSI = { 29,/* lineNo */
  "anyNonFinite",                      /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"/* pathName */
};

static emlrtRSInfo c2_sb_emlrtRSI = { 44,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c2_tb_emlrtRSI = { 103,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c2_ub_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c2_vb_emlrtRSI = { 52,/* lineNo */
  "svd",                               /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c2_wb_emlrtRSI = { 89,/* lineNo */
  "svd",                               /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c2_xb_emlrtRSI = { 81,/* lineNo */
  "svd",                               /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c2_yb_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo c2_ac_emlrtRSI = { 31,/* lineNo */
  "xgesvd",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo c2_bc_emlrtRSI = { 197,/* lineNo */
  "xgesvd",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo c2_cc_emlrtRSI = { 282,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_dc_emlrtRSI = { 299,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_ec_emlrtRSI = { 428,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_fc_emlrtRSI = { 447,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_gc_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c2_hc_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c2_ic_emlrtRSI = { 21,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c2_jc_emlrtRSI = { 23,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c2_kc_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c2_lc_emlrtRSI = { 37,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c2_mc_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xscal.m"/* pathName */
};

static emlrtRSInfo c2_nc_emlrtRSI = { 49,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c2_oc_emlrtRSI = { 32,/* lineNo */
  "xdotc",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xdotc.m"/* pathName */
};

static emlrtRSInfo c2_pc_emlrtRSI = { 35,/* lineNo */
  "xdot",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xdot.m"/* pathName */
};

static emlrtRSInfo c2_qc_emlrtRSI = { 15,/* lineNo */
  "xdot",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xdot.m"/* pathName */
};

static emlrtRSInfo c2_rc_emlrtRSI = { 42,/* lineNo */
  "xdotx",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xdotx.m"/* pathName */
};

static emlrtRSInfo c2_sc_emlrtRSI = { 47,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_tc_emlrtRSI = { 53,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_uc_emlrtRSI = { 32,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_vc_emlrtRSI = { 65,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_wc_emlrtRSI = { 21,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c2_xc_emlrtRSI = { 23,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c2_yc_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xrotg.m"/* pathName */
};

static emlrtRSInfo c2_ad_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c2_bd_emlrtRSI = { 39,/* lineNo */
  "xrot",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xrot.m"/* pathName */
};

static emlrtRSInfo c2_cd_emlrtRSI = { 52,/* lineNo */
  "xrot",                              /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xrot.m"/* pathName */
};

static emlrtRSInfo c2_dd_emlrtRSI = { 36,/* lineNo */
  "xswap",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xswap.m"/* pathName */
};

static emlrtRSInfo c2_ed_emlrtRSI = { 48,/* lineNo */
  "xswap",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xswap.m"/* pathName */
};

static emlrtRSInfo c2_fd_emlrtRSI = { 75,/* lineNo */
  "xgemm",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo c2_gd_emlrtRSI = { 65,/* lineNo */
  "xgemm",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xgemm.m"/* pathName */
};

static emlrtRSInfo c2_hd_emlrtRSI = { 128,/* lineNo */
  "xgemm",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xgemm.m"/* pathName */
};

static emlrtRSInfo c2_id_emlrtRSI = { 135,/* lineNo */
  "xgemm",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/xgemm.m"/* pathName */
};

static emlrtRSInfo c2_jd_emlrtRSI = { 92,/* lineNo */
  "xgemm",                             /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"/* pathName */
};

static emlrtRSInfo c2_kd_emlrtRSI = { 94,/* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo c2_ld_emlrtRSI = { 142,/* lineNo */
  "mtimes",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRSInfo c2_md_emlrtRSI = { 55,/* lineNo */
  "mtimes",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/mtimes.m"/* pathName */
};

static emlrtRSInfo c2_nd_emlrtRSI = { 245,/* lineNo */
  "mtimes",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+refblas/mtimes.m"/* pathName */
};

static emlrtRSInfo c2_od_emlrtRSI = { 178,/* lineNo */
  "mtimes",                            /* fcnName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRTEInfo c2_emlrtRTEI = { 44,/* lineNo */
  34,                                  /* colNo */
  "vAllOrAny",                         /* fName */
  "/home/user/MATLAB/R2022b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pName */
};

static emlrtBCInfo c2_emlrtBCI = { 1,  /* iFirst */
  307200,                              /* iLast */
  17,                                  /* lineNo */
  17,                                  /* colNo */
  "image_depth_new",                   /* aName */
  "servo_step_real",                   /* fName */
  "/home/user/Desktop/Program_servo/servo_step_real.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c2_emlrtDCI = { 17, /* lineNo */
  17,                                  /* colNo */
  "servo_step_real",                   /* fName */
  "/home/user/Desktop/Program_servo/servo_step_real.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c2_b_emlrtDCI = { 16,/* lineNo */
  13,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_b_emlrtBCI = { 1,/* iFirst */
  307200,                              /* iLast */
  16,                                  /* lineNo */
  13,                                  /* colNo */
  "L_I",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c2_c_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  15,                                  /* lineNo */
  33,                                  /* colNo */
  "image_depth",                       /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_c_emlrtDCI = { 15,/* lineNo */
  33,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_d_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  15,                                  /* lineNo */
  35,                                  /* colNo */
  "image_depth",                       /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_d_emlrtDCI = { 15,/* lineNo */
  35,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_e_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  16,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_e_emlrtDCI = { 16,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_f_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  16,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_g_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  17,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_f_emlrtDCI = { 17,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_h_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  17,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_i_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  18,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_g_emlrtDCI = { 18,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_j_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  18,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_k_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  18,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_l_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  18,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_m_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  19,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_h_emlrtDCI = { 19,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_n_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  19,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_o_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  19,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_p_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  19,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_q_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_i_emlrtDCI = { 20,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_r_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_s_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_t_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_u_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_j_emlrtDCI = { 21,/* lineNo */
  24,                                  /* colNo */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_v_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "I_x",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_w_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_x_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "I_y",                               /* aName */
  "get_interaction_matrix_gray",       /* fName */
  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",/* pName */
  0                                    /* checkKind */
};

static real_T c2_dv[4] = { 0.0, 0.0, 0.0, 1.0 };

static char_T c2_cv[41] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'a',
  'g', 'e', 's', 'c', 'i', ':', 'j', 'p', 'g', ':', 'u', 'n', 'h', 'a', 'n', 'd',
  'l', 'e', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'E', 'r', 'r', 'o', 'r' };

static char_T c2_cv1[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
  'e', 'm' };

static char_T c2_cv2[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E', 'r',
  'r', 'o', 'r', 'I', 'n', 'f', 'o' };

/* Function Declarations */
static void initialize_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void initialize_params_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance);
static void mdl_start_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void mdl_terminate_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c2_ur_servo(SFc2_ur_servoInstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c2_ur_servo
  (SFc2_ur_servoInstanceStruct *chartInstance);
static void enable_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void disable_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void sf_gateway_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void ext_mode_exec_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void c2_update_jit_animation_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance);
static void c2_do_animation_call_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance);
static void set_sim_state_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void initSimStructsc2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance);
static void c2_servo_step_real(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_pose[7], uint8_T c2_b_image_gray_new[307200],
  real_T c2_image_depth_new[307200], real_T c2_b_k[9], uint8_T
  c2_b_image_gray_old[307200], real_T c2_b_Sc[6], real_T c2_T_w_next_tip[16]);
static void c2_MatrixExp3(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_so3mat[9], real_T c2_R[9]);
static void c2_get_FeaturesError_InteractionMatrix_DVS
  (SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *c2_sp, real_T
   c2_b_image_gray_new[307200], real_T c2_b_image_gray_old[307200], real_T
   c2_Para_Camera_Intrinsic[9], real_T c2_image_depth_new[307200], real_T
   c2_b_error_s[307200], real_T c2_b_L_e[1843200]);
static void c2_get_interaction_matrix_gray(SFc2_ur_servoInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_image_gray[307200], real_T
  c2_Para_Camera_Intrinsic[9], real_T c2_image_depth[307200], real_T c2_L_I
  [1843200]);
static void c2_get_image_gradient(SFc2_ur_servoInstanceStruct *chartInstance,
  real_T c2_image[307200], real_T c2_Para_Camera_Intrinsic[9], real_T c2_b_I_x
  [307200], real_T c2_b_I_y[307200]);
static void c2_TransInv(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_T
  [16], real_T c2_invT[16]);
static void c2_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_a__output_of_transpose_, const char_T *c2_identifier, real_T
  c2_y[6]);
static void c2_b_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_imread(SFc2_ur_servoInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, uint8_T c2_X[921600]);
static void c2_warning(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, char_T c2_varargin_2[200]);
static void c2_b_warning(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp);
static real_T c2_sumColumnB(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_x[307200], int32_T c2_col);
static real_T c2_b_sumColumnB(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_x[640]);
static real_T c2_norm(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_x[3]);
static void c2_pinv(SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack
                    *c2_sp, real_T c2_b_A[1843200], real_T c2_X[1843200]);
static void c2_check_forloop_overflow_error(SFc2_ur_servoInstanceStruct
  *chartInstance, const emlrtStack *c2_sp);
static void c2_svd(SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *
                   c2_sp, real_T c2_b_A[1843200], real_T c2_b_U[1843200], real_T
                   c2_s[6], real_T c2_V[36]);
static void c2_ceval_xgesvd(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_A[1843200], real_T c2_b_U[1843200], real_T
  c2_S[6], real_T c2_V[36], int32_T *c2_info);
static void c2_xgemm(SFc2_ur_servoInstanceStruct *chartInstance, int32_T c2_b_k,
                     real_T c2_b_A[36], real_T c2_b_B[1843200], real_T c2_C
                     [1843200], real_T c2_b_C[1843200]);
static void c2_mtimes(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_b_A
                      [1843200], real_T c2_b_B[307200], real_T c2_C[6]);
static void c2_c_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_Sc, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_d_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_e_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_vec, const char_T *c2_identifier, real_T c2_y[16]);
static void c2_f_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static uint8_T c2_g_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ur_servo, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_slStringInitializeDynamicBuffers(SFc2_ur_servoInstanceStruct
  *chartInstance);
static void c2_chart_data_browse_helper(SFc2_ur_servoInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static const mxArray *c2_quat2axang(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0);
static const mxArray *c2_coder_internal_mxSubscript(SFc2_ur_servoInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, const mxArray *c2_input0, const
  mxArray *c2_input1);
static const mxArray *c2_b_coder_internal_mxSubscript
  (SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *c2_sp, const
   mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_b_mtimes(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_horzcat(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_transpose(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0);
static const mxArray *c2_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1, const
  mxArray *c2_input2, const mxArray *c2_input3);
static void c2_b_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_c_feval(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static void c2_d_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static void c2_b_xgemm(SFc2_ur_servoInstanceStruct *chartInstance, int32_T
  c2_b_k, real_T c2_b_A[36], real_T c2_b_B[1843200], real_T c2_C[1843200]);
static void init_dsm_address_info(SFc2_ur_servoInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_ur_servoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_ur_servo = 0U;
}

static void initialize_params_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_ur_servo(SFc2_ur_servoInstanceStruct *
  chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    12U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 468);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/servo_step_real.m", 14U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 0U, 0U,
                     "servo_step_real", 0, -1, 3018);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/VecToso3.m", 14U, 1U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 1U, 0U, "VecToso3",
                     40, -1, 393);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/MatrixExp3.m", 14U, 2U, 1U,
                  0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 2U, 0U, "MatrixExp3",
                     40, -1, 703);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 14U, 2U, 0U, 501, 528, 545,
                    699, false);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/so3ToVec.m", 14U, 3U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 3U, 0U, "so3ToVec",
                     40, -1, 394);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/NearZero.m", 14U, 4U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 4U, 0U, "NearZero",
                     33, -1, 274);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/AxisAng3.m", 14U, 5U, 1U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 5U, 0U, "AxisAng3",
                     40, -1, 508);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 14U, 5U, 0U, 428, 446, 467,
                    503, false);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/get_image_gray_norm.m", 14U,
                  6U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 6U, 0U,
                     "get_image_gray_norm", 0, -1, 153);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/get_FeaturesError_InteractionMatrix_DVS.m",
                  14U, 7U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 7U, 0U,
                     "get_FeaturesError_InteractionMatrix_DVS", 0, -1, 586);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/get_feature_error_gray.m",
                  14U, 8U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 8U, 0U,
                     "get_feature_error_gray", 0, -1, 143);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/get_interaction_matrix_gray.m",
                  14U, 9U, 1U, 0U, 0U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 9U, 0U,
                     "get_interaction_matrix_gray", 0, -1, 890);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 14U, 9U, 0U, 257, 272, 886);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 14U, 9U, 1U, 277, 292, 882);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/get_image_gradient.m", 14U,
                  10U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 10U, 0U,
                     "get_image_gradient", 0, -1, 197);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/TransInv.m", 14U, 11U, 1U,
                  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 11U, 0U, "TransInv",
                     40, -1, 532);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance,
                  "/home/user/Desktop/Program_servo/TransToRp.m", 14U, 12U, 1U,
                  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 14U, 12U, 0U, "TransToRp",
                     40, -1, 479);
}

static void mdl_cleanup_runtime_resources_c2_ur_servo
  (SFc2_ur_servoInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c2_T[16];
  real_T c2_b_k[9];
  real_T c2_b_pose[7];
  real_T c2_b_Sc[6];
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c2_i = 0; c2_i < 7; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 3U,
                      (*chartInstance->c2_pose)[c2_i]);
  }

  for (c2_i1 = 0; c2_i1 < 921600; c2_i1++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U, (real_T)
                      (*chartInstance->c2_rgb_image)[c2_i1]);
  }

  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_depth_image)[c2_i2]);
  }

  for (c2_i3 = 0; c2_i3 < 9; c2_i3++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (*chartInstance->c2_k)
                      [c2_i3]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  for (c2_i4 = 0; c2_i4 < 7; c2_i4++) {
    c2_b_pose[c2_i4] = (*chartInstance->c2_pose)[c2_i4];
  }

  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  c2_b_st.site = &c2_v_emlrtRSI;
  c2_imread(chartInstance, &c2_b_st, chartInstance->c2_img);
  c2_b_st.site = &c2_w_emlrtRSI;
  rgb2gray_tbb_uint8(&chartInstance->c2_img[0], 307200.0,
                     &chartInstance->c2_image_gray_old[0], true);
  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_i7 = 0;
    for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
      c2_b_k[c2_i8 + c2_i5] = (*chartInstance->c2_k)[c2_i7 + c2_i6];
      c2_i7 += 3;
    }

    c2_i5 += 3;
  }

  c2_b_st.site = &c2_x_emlrtRSI;
  rgb2gray_tbb_uint8(&(*chartInstance->c2_rgb_image)[0], 307200.0,
                     &chartInstance->c2_image_gray_new[0], true);
  for (c2_i9 = 0; c2_i9 < 307200; c2_i9++) {
    chartInstance->c2_depth[c2_i9] = (real_T)(*chartInstance->c2_depth_image)
      [c2_i9] / 1000.0;
  }

  c2_b_st.site = &c2_y_emlrtRSI;
  c2_servo_step_real(chartInstance, &c2_b_st, c2_b_pose,
                     chartInstance->c2_image_gray_new, chartInstance->c2_depth,
                     c2_b_k, chartInstance->c2_image_gray_old, c2_b_Sc, c2_T);
  for (c2_i10 = 0; c2_i10 < 6; c2_i10++) {
    (*chartInstance->c2_Sc)[c2_i10] = c2_b_Sc[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    (*chartInstance->c2_vec)[c2_i11] = c2_T[c2_i11];
  }

  c2_do_animation_call_c2_ur_servo(chartInstance);
  for (c2_i12 = 0; c2_i12 < 6; c2_i12++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 4U,
                      (*chartInstance->c2_Sc)[c2_i12]);
  }

  for (c2_i13 = 0; c2_i13 < 16; c2_i13++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 5U,
                      (*chartInstance->c2_vec)[c2_i13]);
  }
}

static void ext_mode_exec_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c2_ur_servo(SFc2_ur_servoInstanceStruct
  *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(3, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_Sc, 0, 0U, 1U, 0U,
    2, 6, 1), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_vec, 0, 0U, 1U,
    0U, 2, 1, 16), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y",
    &chartInstance->c2_is_active_c2_ur_servo, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv1[16];
  real_T c2_b_dv[6];
  int32_T c2_i;
  int32_T c2_i1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "Sc",
                        c2_b_dv);
  for (c2_i = 0; c2_i < 6; c2_i++) {
    (*chartInstance->c2_Sc)[c2_i] = c2_b_dv[c2_i];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "vec", c2_dv1);
  for (c2_i1 = 0; c2_i1 < 16; c2_i1++) {
    (*chartInstance->c2_vec)[c2_i1] = c2_dv1[c2_i1];
  }

  chartInstance->c2_is_active_c2_ur_servo = c2_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "is_active_c2_ur_servo");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void initSimStructsc2_ur_servo(SFc2_ur_servoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_servo_step_real(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_pose[7], uint8_T c2_b_image_gray_new[307200],
  real_T c2_image_depth_new[307200], real_T c2_b_k[9], uint8_T
  c2_b_image_gray_old[307200], real_T c2_b_Sc[6], real_T c2_T_w_next_tip[16])
{
  static real_T c2_b_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static real_T c2_b_dv[3] = { 1.0, 2.0, 3.0 };

  emlrtStack c2_st;
  const mxArray *c2_b_A = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_g_y = NULL;
  real_T c2_mean_d[640];
  real_T c2_T_next[16];
  real_T c2_T_w_nb[16];
  real_T c2_T_w_nb_next[16];
  real_T c2_b_unusedExpr[16];
  real_T c2_unusedExpr[16];
  real_T c2_dv1[9];
  real_T c2_so3mat[9];
  real_T c2_qpose[6];
  real_T c2_ppose[4];
  real_T c2_c_b[3];
  real_T c2_f_y[3];
  real_T c2_t[3];
  real_T c2_a;
  real_T c2_d;
  real_T c2_mean_f;
  real_T c2_u;
  real_T c2_y;
  int32_T c2_b_col;
  int32_T c2_b_i;
  int32_T c2_col;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 0, 0);
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    if (c2_image_depth_new[c2_i] == 0.0) {
      c2_d = (real_T)(c2_i + 1);
      if (c2_d != (real_T)(int32_T)muDoubleScalarFloor(c2_d)) {
        emlrtIntegerCheckR2012b(c2_d, &c2_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i1 = (int32_T)muDoubleScalarFloor(c2_d);
      if ((c2_i1 < 1) || (c2_i1 > 307200)) {
        emlrtDynamicBoundsCheckR2012b(c2_i1, 1, 307200, &c2_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_image_depth_new[c2_i1 - 1] = 0.3;
    }
  }

  for (c2_col = 0; c2_col < 640; c2_col++) {
    c2_b_col = c2_col;
    c2_mean_d[c2_b_col] = c2_sumColumnB(chartInstance, c2_image_depth_new,
      c2_b_col + 1);
  }

  for (c2_b_i = 0; c2_b_i < 640; c2_b_i++) {
    c2_mean_d[c2_b_i] /= 480.0;
  }

  c2_y = c2_b_sumColumnB(chartInstance, c2_mean_d);
  c2_mean_f = c2_y / 640.0;
  c2_a = c2_mean_f;
  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    c2_image_depth_new[c2_i2] = 1.0;
  }

  for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
    c2_image_depth_new[c2_i3] *= c2_a;
  }

  c2_ppose[0] = c2_b_pose[6];
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_ppose[c2_i4 + 1] = c2_b_pose[c2_i4 + 3];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_ppose, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  c2_st.site = &c2_i_emlrtRSI;
  sf_mex_assign(&c2_b_A, c2_quat2axang(chartInstance, &c2_st, c2_b_y), false);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_t[c2_i5] = c2_b_pose[c2_i5];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_t, 0, 0U, 1U, 0U, 2, 1, 3), false);
  c2_u = 4.0;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_dv, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  c2_st.site = &c2_j_emlrtRSI;
  c2_emlrt_marshallIn(chartInstance, c2_transpose(chartInstance, &c2_st,
    c2_horzcat(chartInstance, &c2_st, c2_c_y, c2_b_mtimes(chartInstance, &c2_st,
    c2_coder_internal_mxSubscript(chartInstance, &c2_st, sf_mex_dup(c2_b_A),
    c2_d_y), c2_b_coder_internal_mxSubscript(chartInstance, &c2_st, sf_mex_dup
    (c2_b_A), c2_e_y)))), "<output of transpose>", c2_qpose);
  c2_st.site = &c2_emlrtRSI;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_t[c2_i6] = c2_qpose[c2_i6 + 3];
  }

  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 1, 0);
  c2_so3mat[0] = 0.0;
  c2_so3mat[3] = -c2_t[2];
  c2_so3mat[6] = c2_t[1];
  c2_so3mat[1] = c2_t[2];
  c2_so3mat[4] = 0.0;
  c2_so3mat[7] = -c2_t[0];
  c2_so3mat[2] = -c2_t[1];
  c2_so3mat[5] = c2_t[0];
  c2_so3mat[8] = 0.0;
  c2_st.site = &c2_emlrtRSI;
  c2_MatrixExp3(chartInstance, c2_so3mat, c2_dv1);
  c2_i7 = 0;
  c2_i8 = 0;
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
      c2_T_w_nb[c2_i11 + c2_i7] = c2_dv1[c2_i11 + c2_i8];
    }

    c2_i7 += 4;
    c2_i8 += 3;
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_T_w_nb[c2_i10 + 12] = c2_qpose[c2_i10];
  }

  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_T_w_nb[c2_i12 + 3] = c2_dv[c2_i13];
    c2_i12 += 4;
  }

  c2_st.site = &c2_b_emlrtRSI;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 6, 0);
  for (c2_i14 = 0; c2_i14 < 307200; c2_i14++) {
    chartInstance->c2_image_gray_new_norm[c2_i14] = -0.00392156862745098 *
      (real_T)c2_b_image_gray_new[c2_i14] + 1.0;
  }

  c2_b_k[0] = -c2_b_k[0];
  c2_b_k[4] = -c2_b_k[4];
  c2_st.site = &c2_c_emlrtRSI;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 6, 0);
  for (c2_i15 = 0; c2_i15 < 307200; c2_i15++) {
    chartInstance->c2_image_gray_old_norm[c2_i15] = -0.00392156862745098 *
      (real_T)c2_b_image_gray_old[c2_i15] + 1.0;
  }

  c2_st.site = &c2_d_emlrtRSI;
  c2_get_FeaturesError_InteractionMatrix_DVS(chartInstance, &c2_st,
    chartInstance->c2_image_gray_new_norm, chartInstance->c2_image_gray_old_norm,
    c2_b_k, c2_image_depth_new, chartInstance->c2_error_s, chartInstance->c2_L_e);
  c2_st.site = &c2_e_emlrtRSI;
  c2_pinv(chartInstance, &c2_st, chartInstance->c2_L_e, chartInstance->c2_b);
  for (c2_i16 = 0; c2_i16 < 1843200; c2_i16++) {
    chartInstance->c2_b[c2_i16] *= -3.0;
  }

  c2_st.site = &c2_e_emlrtRSI;
  c2_mtimes(chartInstance, chartInstance->c2_b, chartInstance->c2_error_s,
            c2_qpose);
  c2_st.site = &c2_f_emlrtRSI;
  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    c2_t[c2_i17] = c2_qpose[c2_i17 + 3];
  }

  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 1, 0);
  c2_so3mat[0] = 0.0;
  c2_so3mat[3] = -c2_t[2];
  c2_so3mat[6] = c2_t[1];
  c2_so3mat[1] = c2_t[2];
  c2_so3mat[4] = 0.0;
  c2_so3mat[7] = -c2_t[0];
  c2_so3mat[2] = -c2_t[1];
  c2_so3mat[5] = c2_t[0];
  c2_so3mat[8] = 0.0;
  c2_st.site = &c2_f_emlrtRSI;
  c2_MatrixExp3(chartInstance, c2_so3mat, c2_dv1);
  c2_i18 = 0;
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
      c2_T_next[c2_i22 + c2_i18] = c2_dv1[c2_i22 + c2_i19];
    }

    c2_i18 += 4;
    c2_i19 += 3;
  }

  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_T_next[c2_i21 + 12] = c2_qpose[c2_i21];
  }

  c2_i23 = 0;
  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    c2_T_next[c2_i23 + 3] = c2_dv[c2_i24];
    c2_i23 += 4;
  }

  for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
    c2_i26 = 0;
    for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
      c2_T_w_nb_next[c2_i26 + c2_i25] = 0.0;
      c2_i30 = 0;
      for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
        c2_T_w_nb_next[c2_i26 + c2_i25] += c2_T_w_nb[c2_i30 + c2_i25] *
          c2_T_next[c2_i32 + c2_i26];
        c2_i30 += 4;
      }

      c2_i26 += 4;
    }
  }

  c2_st.site = &c2_g_emlrtRSI;
  c2_TransInv(chartInstance, c2_b_b, c2_unusedExpr);
  for (c2_i28 = 0; c2_i28 < 4; c2_i28++) {
    c2_i29 = 0;
    for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
      c2_T_w_next_tip[c2_i29 + c2_i28] = 0.0;
      c2_i36 = 0;
      for (c2_i38 = 0; c2_i38 < 4; c2_i38++) {
        c2_T_w_next_tip[c2_i29 + c2_i28] += c2_T_w_nb_next[c2_i36 + c2_i28] *
          c2_b_b[c2_i38 + c2_i29];
        c2_i36 += 4;
      }

      c2_i29 += 4;
    }
  }

  c2_st.site = &c2_h_emlrtRSI;
  c2_TransInv(chartInstance, c2_b_b, c2_b_unusedExpr);
  for (c2_i33 = 0; c2_i33 < 4; c2_i33++) {
    c2_i35 = 0;
    for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
      c2_T_next[c2_i35 + c2_i33] = 0.0;
      c2_i41 = 0;
      for (c2_i43 = 0; c2_i43 < 4; c2_i43++) {
        c2_T_next[c2_i35 + c2_i33] += c2_T_w_nb[c2_i41 + c2_i33] * c2_b_b[c2_i43
          + c2_i35];
        c2_i41 += 4;
      }

      c2_i35 += 4;
    }
  }

  for (c2_i34 = 0; c2_i34 < 3; c2_i34++) {
    c2_t[c2_i34] = c2_T_w_next_tip[c2_i34 + 12] - c2_T_next[c2_i34 + 12];
  }

  for (c2_i39 = 0; c2_i39 < 3; c2_i39++) {
    c2_c_b[c2_i39] = c2_qpose[c2_i39 + 3];
  }

  c2_i40 = 0;
  c2_i42 = 0;
  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    for (c2_i46 = 0; c2_i46 < 3; c2_i46++) {
      c2_so3mat[c2_i46 + c2_i40] = c2_T_w_nb[c2_i46 + c2_i42];
    }

    c2_i40 += 3;
    c2_i42 += 4;
  }

  for (c2_i45 = 0; c2_i45 < 3; c2_i45++) {
    c2_f_y[c2_i45] = 0.0;
    c2_i48 = 0;
    for (c2_i50 = 0; c2_i50 < 3; c2_i50++) {
      c2_f_y[c2_i45] += c2_so3mat[c2_i48 + c2_i45] * c2_c_b[c2_i50];
      c2_i48 += 3;
    }
  }

  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    c2_b_Sc[c2_i47] = c2_t[c2_i47];
  }

  for (c2_i49 = 0; c2_i49 < 3; c2_i49++) {
    c2_b_Sc[c2_i49 + 3] = c2_f_y[c2_i49];
  }

  sf_mex_printf("%s =\\n", "Sc");
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_Sc, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_call(c2_sp, NULL, "disp", 0U, 1U, 14, c2_g_y);
  sf_mex_destroy(&c2_b_A);
}

static void c2_MatrixExp3(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_so3mat[9], real_T c2_R[9])
{
  real_T c2_c_y[9];
  real_T c2_d_y[9];
  real_T c2_e_y[9];
  real_T c2_omgmat[9];
  real_T c2_omgtheta[3];
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_b_near;
  real_T c2_b_theta;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_near;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_theta;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  boolean_T c2_b_judge;
  boolean_T c2_judge;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 2, 0);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 3, 0);
  c2_omgtheta[0] = c2_so3mat[5];
  c2_omgtheta[1] = c2_so3mat[6];
  c2_omgtheta[2] = c2_so3mat[1];
  c2_near = c2_norm(chartInstance, c2_omgtheta);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 4, 0);
  c2_x = c2_near;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_y = muDoubleScalarAbs(c2_g_x);
  c2_judge = (c2_y < 1.0E-6);
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 14U, 2, 0, c2_judge)) {
    for (c2_i = 0; c2_i < 9; c2_i++) {
      c2_R[c2_i] = 0.0;
    }

    for (c2_b_k = 0; c2_b_k < 3; c2_b_k++) {
      c2_c_k = c2_b_k;
      c2_R[c2_c_k + 3 * c2_c_k] = 1.0;
    }
  } else {
    covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 5, 0);
    c2_theta = c2_norm(chartInstance, c2_omgtheta);
    c2_b_near = c2_theta;
    covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 4, 0);
    c2_h_x = c2_b_near;
    c2_i_x = c2_h_x;
    c2_j_x = c2_i_x;
    c2_k_x = c2_j_x;
    c2_l_x = c2_k_x;
    c2_m_x = c2_l_x;
    c2_n_x = c2_m_x;
    c2_b_y = muDoubleScalarAbs(c2_n_x);
    c2_b_judge = (c2_b_y < 1.0E-6);
    covrtEmlIfEval(chartInstance->c2_covrtInstance, 14U, 5, 0, c2_b_judge);
    c2_b_theta = c2_theta;
    for (c2_i1 = 0; c2_i1 < 9; c2_i1++) {
      c2_omgmat[c2_i1] = c2_so3mat[c2_i1] / c2_b_theta;
    }

    c2_o_x = c2_b_theta;
    c2_a = c2_o_x;
    c2_a = muDoubleScalarSin(c2_a);
    for (c2_i2 = 0; c2_i2 < 9; c2_i2++) {
      c2_c_y[c2_i2] = c2_a * c2_omgmat[c2_i2];
    }

    c2_p_x = c2_b_theta;
    c2_q_x = c2_p_x;
    c2_q_x = muDoubleScalarCos(c2_q_x);
    c2_b_a = 1.0 - c2_q_x;
    for (c2_i3 = 0; c2_i3 < 9; c2_i3++) {
      c2_d_y[c2_i3] = c2_b_a * c2_omgmat[c2_i3];
    }

    for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
      c2_i6 = 0;
      for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
        c2_e_y[c2_i6 + c2_i4] = 0.0;
        c2_i9 = 0;
        for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
          c2_e_y[c2_i6 + c2_i4] += c2_d_y[c2_i9 + c2_i4] * c2_omgmat[c2_i10 +
            c2_i6];
          c2_i9 += 3;
        }

        c2_i6 += 3;
      }
    }

    for (c2_i5 = 0; c2_i5 < 9; c2_i5++) {
      c2_R[c2_i5] = 0.0;
    }

    for (c2_d_k = 0; c2_d_k < 3; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_R[c2_e_k + 3 * c2_e_k] = 1.0;
    }

    for (c2_i8 = 0; c2_i8 < 9; c2_i8++) {
      c2_R[c2_i8] = (c2_R[c2_i8] + c2_c_y[c2_i8]) + c2_e_y[c2_i8];
    }
  }
}

static void c2_get_FeaturesError_InteractionMatrix_DVS
  (SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *c2_sp, real_T
   c2_b_image_gray_new[307200], real_T c2_b_image_gray_old[307200], real_T
   c2_Para_Camera_Intrinsic[9], real_T c2_image_depth_new[307200], real_T
   c2_b_error_s[307200], real_T c2_b_L_e[1843200])
{
  emlrtStack c2_st;
  int32_T c2_i;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 7, 0);
  c2_st.site = &c2_o_emlrtRSI;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 8, 0);
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    c2_b_error_s[c2_i] = c2_b_image_gray_new[c2_i] - c2_b_image_gray_old[c2_i];
  }

  c2_st.site = &c2_p_emlrtRSI;
  c2_get_interaction_matrix_gray(chartInstance, &c2_st, c2_b_image_gray_new,
    c2_Para_Camera_Intrinsic, c2_image_depth_new, c2_b_L_e);
}

static void c2_get_interaction_matrix_gray(SFc2_ur_servoInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_image_gray[307200], real_T
  c2_Para_Camera_Intrinsic[9], real_T c2_image_depth[307200], real_T c2_L_I
  [1843200])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_st;
  real_T c2_b_A[9];
  real_T c2_corn_right_norm[3];
  real_T c2_point[3];
  real_T c2_Z_inv;
  real_T c2_a;
  real_T c2_a21;
  real_T c2_b_a;
  real_T c2_b_c;
  real_T c2_b_d;
  real_T c2_b_j;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c;
  real_T c2_c_a;
  real_T c2_c_d;
  real_T c2_c_i;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_cnt;
  real_T c2_d;
  real_T c2_d_a;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_f_x;
  real_T c2_f_y;
  real_T c2_g_a;
  real_T c2_g_x;
  real_T c2_h_a;
  real_T c2_h_x;
  real_T c2_i_a;
  real_T c2_i_x;
  real_T c2_j_a;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_maxval;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_cnt;
  int32_T c2_b_i;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_j;
  int32_T c2_r1;
  int32_T c2_r2;
  int32_T c2_r3;
  int32_T c2_rtemp;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 9, 0);
  c2_st.site = &c2_q_emlrtRSI;
  c2_get_image_gradient(chartInstance, c2_image_gray, c2_Para_Camera_Intrinsic,
                        chartInstance->c2_I_x, chartInstance->c2_I_y);
  for (c2_i = 0; c2_i < 1843200; c2_i++) {
    c2_L_I[c2_i] = 0.0;
  }

  c2_cnt = 1.0;
  for (c2_b_i = 0; c2_b_i < 640; c2_b_i++) {
    c2_c_i = 1.0 + (real_T)c2_b_i;
    covrtEmlForEval(chartInstance->c2_covrtInstance, 14U, 9, 0, 1);
    for (c2_j = 0; c2_j < 480; c2_j++) {
      c2_b_j = 1.0 + (real_T)c2_j;
      covrtEmlForEval(chartInstance->c2_covrtInstance, 14U, 9, 1, 1);
      c2_point[0] = c2_c_i;
      c2_point[1] = c2_b_j;
      c2_point[2] = 1.0;
      c2_st.site = &c2_r_emlrtRSI;
      c2_b_st.site = &c2_eb_emlrtRSI;
      c2_c_st.site = &c2_fb_emlrtRSI;
      c2_d_st.site = &c2_gb_emlrtRSI;
      for (c2_i1 = 0; c2_i1 < 9; c2_i1++) {
        c2_b_A[c2_i1] = c2_Para_Camera_Intrinsic[c2_i1];
      }

      c2_r1 = 0;
      c2_r2 = 1;
      c2_r3 = 2;
      c2_x = c2_b_A[0];
      c2_b_x = c2_x;
      c2_c_x = c2_b_x;
      c2_d_x = c2_c_x;
      c2_y = muDoubleScalarAbs(c2_d_x);
      c2_maxval = c2_y;
      c2_e_x = c2_b_A[1];
      c2_f_x = c2_e_x;
      c2_g_x = c2_f_x;
      c2_h_x = c2_g_x;
      c2_b_y = muDoubleScalarAbs(c2_h_x);
      c2_a21 = c2_b_y;
      if (c2_a21 > c2_maxval) {
        c2_maxval = c2_a21;
        c2_r1 = 1;
        c2_r2 = 0;
      }

      c2_i_x = c2_b_A[2];
      c2_j_x = c2_i_x;
      c2_k_x = c2_j_x;
      c2_l_x = c2_k_x;
      c2_c_y = muDoubleScalarAbs(c2_l_x);
      c2_d = c2_c_y;
      if (c2_d > c2_maxval) {
        c2_r1 = 2;
        c2_r2 = 1;
        c2_r3 = 0;
      }

      c2_b_A[c2_r2] /= c2_b_A[c2_r1];
      c2_b_A[c2_r3] /= c2_b_A[c2_r1];
      c2_b_A[3 + c2_r2] -= c2_b_A[c2_r2] * c2_b_A[3 + c2_r1];
      c2_b_A[3 + c2_r3] -= c2_b_A[c2_r3] * c2_b_A[3 + c2_r1];
      c2_b_A[6 + c2_r2] -= c2_b_A[c2_r2] * c2_b_A[6 + c2_r1];
      c2_b_A[6 + c2_r3] -= c2_b_A[c2_r3] * c2_b_A[6 + c2_r1];
      c2_m_x = c2_b_A[3 + c2_r3];
      c2_n_x = c2_m_x;
      c2_o_x = c2_n_x;
      c2_p_x = c2_o_x;
      c2_d_y = muDoubleScalarAbs(c2_p_x);
      c2_b_d = c2_d_y;
      c2_q_x = c2_b_A[3 + c2_r2];
      c2_r_x = c2_q_x;
      c2_s_x = c2_r_x;
      c2_t_x = c2_s_x;
      c2_e_y = muDoubleScalarAbs(c2_t_x);
      c2_c_d = c2_e_y;
      if (c2_b_d > c2_c_d) {
        c2_rtemp = c2_r2 + 1;
        c2_r2 = c2_r3;
        c2_r3 = c2_rtemp - 1;
      }

      c2_b_A[3 + c2_r3] /= c2_b_A[3 + c2_r2];
      c2_b_A[6 + c2_r3] -= c2_b_A[3 + c2_r3] * c2_b_A[6 + c2_r2];
      if ((c2_b_A[c2_r1] == 0.0) || (c2_b_A[3 + c2_r2] == 0.0) || (c2_b_A[6 +
           c2_r3] == 0.0)) {
        c2_e_st.site = &c2_hb_emlrtRSI;
        c2_f_st.site = &c2_ib_emlrtRSI;
        c2_b_warning(chartInstance, &c2_f_st);
      }

      c2_corn_right_norm[0] = c2_point[c2_r1];
      c2_corn_right_norm[1] = c2_point[c2_r2] - c2_corn_right_norm[0] *
        c2_b_A[c2_r2];
      c2_corn_right_norm[2] = (c2_point[c2_r3] - c2_corn_right_norm[0] *
        c2_b_A[c2_r3]) - c2_corn_right_norm[1] * c2_b_A[3 + c2_r3];
      c2_corn_right_norm[2] /= c2_b_A[6 + c2_r3];
      c2_corn_right_norm[0] -= c2_corn_right_norm[2] * c2_b_A[6 + c2_r1];
      c2_corn_right_norm[1] -= c2_corn_right_norm[2] * c2_b_A[6 + c2_r2];
      c2_corn_right_norm[1] /= c2_b_A[3 + c2_r2];
      c2_corn_right_norm[0] -= c2_corn_right_norm[1] * c2_b_A[3 + c2_r1];
      c2_corn_right_norm[0] /= c2_b_A[c2_r1];
      c2_u_x = c2_corn_right_norm[0];
      c2_f_y = c2_corn_right_norm[1];
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_c_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i2 = (int32_T)c2_b_j;
      if ((c2_i2 < 1) || (c2_i2 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i2, 1, 480, &c2_c_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_d_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i3 = (int32_T)c2_c_i;
      if ((c2_i3 < 1) || (c2_i3 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i3, 1, 640, &c2_d_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_Z_inv = 1.0 / c2_image_depth[(c2_i2 + 480 * (c2_i3 - 1)) - 1];
      c2_st.site = &c2_s_emlrtRSI;
      c2_a = c2_f_y;
      c2_b_st.site = &c2_jb_emlrtRSI;
      c2_b_a = c2_a;
      c2_c_st.site = &c2_kb_emlrtRSI;
      c2_c_a = c2_b_a;
      c2_d_a = c2_c_a;
      c2_e_a = c2_d_a;
      c2_c = c2_e_a * c2_e_a;
      c2_st.site = &c2_t_emlrtRSI;
      c2_f_a = c2_u_x;
      c2_b_st.site = &c2_jb_emlrtRSI;
      c2_g_a = c2_f_a;
      c2_c_st.site = &c2_kb_emlrtRSI;
      c2_h_a = c2_g_a;
      c2_i_a = c2_h_a;
      c2_j_a = c2_i_a;
      c2_b_c = c2_j_a * c2_j_a;
      if (c2_cnt != (real_T)(int32_T)muDoubleScalarFloor(c2_cnt)) {
        emlrtIntegerCheckR2012b(c2_cnt, &c2_b_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i4 = (int32_T)c2_cnt;
      if ((c2_i4 < 1) || (c2_i4 > 307200)) {
        emlrtDynamicBoundsCheckR2012b(c2_i4, 1, 307200, &c2_b_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_b_cnt = c2_i4 - 1;
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_e_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i5 = (int32_T)c2_b_j;
      if ((c2_i5 < 1) || (c2_i5 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i5, 1, 480, &c2_e_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_e_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i6 = (int32_T)c2_c_i;
      if ((c2_i6 < 1) || (c2_i6 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i6, 1, 640, &c2_f_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[c2_b_cnt] = chartInstance->c2_I_x[(c2_i5 + 480 * (c2_i6 - 1)) - 1] *
        c2_Z_inv;
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_f_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i7 = (int32_T)c2_b_j;
      if ((c2_i7 < 1) || (c2_i7 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i7, 1, 480, &c2_g_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_f_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i8 = (int32_T)c2_c_i;
      if ((c2_i8 < 1) || (c2_i8 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i8, 1, 640, &c2_h_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[307200 + c2_b_cnt] = chartInstance->c2_I_y[(c2_i7 + 480 * (c2_i8 -
        1)) - 1] * c2_Z_inv;
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_g_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i9 = (int32_T)c2_b_j;
      if ((c2_i9 < 1) || (c2_i9 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i9, 1, 480, &c2_i_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_g_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i10 = (int32_T)c2_c_i;
      if ((c2_i10 < 1) || (c2_i10 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i10, 1, 640, &c2_j_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_g_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i11 = (int32_T)c2_b_j;
      if ((c2_i11 < 1) || (c2_i11 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i11, 1, 480, &c2_k_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_g_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i12 = (int32_T)c2_c_i;
      if ((c2_i12 < 1) || (c2_i12 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i12, 1, 640, &c2_l_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[614400 + c2_b_cnt] = -(c2_u_x * chartInstance->c2_I_x[(c2_i9 + 480 *
        (c2_i10 - 1)) - 1] + c2_f_y * chartInstance->c2_I_y[(c2_i11 + 480 *
        (c2_i12 - 1)) - 1]) * c2_Z_inv;
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_h_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i13 = (int32_T)c2_b_j;
      if ((c2_i13 < 1) || (c2_i13 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i13, 1, 480, &c2_m_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_h_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i14 = (int32_T)c2_c_i;
      if ((c2_i14 < 1) || (c2_i14 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i14, 1, 640, &c2_n_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_h_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i15 = (int32_T)c2_b_j;
      if ((c2_i15 < 1) || (c2_i15 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i15, 1, 480, &c2_o_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_h_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i16 = (int32_T)c2_c_i;
      if ((c2_i16 < 1) || (c2_i16 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i16, 1, 640, &c2_p_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[921600 + c2_b_cnt] = -c2_u_x * c2_f_y * chartInstance->c2_I_x
        [(c2_i13 + 480 * (c2_i14 - 1)) - 1] - (1.0 + c2_c) *
        chartInstance->c2_I_y[(c2_i15 + 480 * (c2_i16 - 1)) - 1];
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_i_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i17 = (int32_T)c2_b_j;
      if ((c2_i17 < 1) || (c2_i17 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i17, 1, 480, &c2_q_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_i_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i18 = (int32_T)c2_c_i;
      if ((c2_i18 < 1) || (c2_i18 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i18, 1, 640, &c2_r_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_i_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i19 = (int32_T)c2_b_j;
      if ((c2_i19 < 1) || (c2_i19 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i19, 1, 480, &c2_s_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_i_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i20 = (int32_T)c2_c_i;
      if ((c2_i20 < 1) || (c2_i20 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i20, 1, 640, &c2_t_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[1228800 + c2_b_cnt] = (1.0 + c2_b_c) * chartInstance->c2_I_x
        [(c2_i17 + 480 * (c2_i18 - 1)) - 1] + c2_u_x * c2_f_y *
        chartInstance->c2_I_y[(c2_i19 + 480 * (c2_i20 - 1)) - 1];
      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_j_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i21 = (int32_T)c2_b_j;
      if ((c2_i21 < 1) || (c2_i21 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i21, 1, 480, &c2_u_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_j_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i22 = (int32_T)c2_c_i;
      if ((c2_i22 < 1) || (c2_i22 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i22, 1, 640, &c2_v_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
        emlrtIntegerCheckR2012b(c2_b_j, &c2_j_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i23 = (int32_T)c2_b_j;
      if ((c2_i23 < 1) || (c2_i23 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i23, 1, 480, &c2_w_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
        emlrtIntegerCheckR2012b(c2_c_i, &c2_j_emlrtDCI, (emlrtConstCTX)c2_sp);
      }

      c2_i24 = (int32_T)c2_c_i;
      if ((c2_i24 < 1) || (c2_i24 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i24, 1, 640, &c2_x_emlrtBCI,
          (emlrtConstCTX)c2_sp);
      }

      c2_L_I[1536000 + c2_b_cnt] = -c2_f_y * chartInstance->c2_I_x[(c2_i21 + 480
        * (c2_i22 - 1)) - 1] + c2_u_x * chartInstance->c2_I_y[(c2_i23 + 480 *
        (c2_i24 - 1)) - 1];
      c2_cnt++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c2_covrtInstance, 14U, 9, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c2_covrtInstance, 14U, 9, 0, 0);
}

static void c2_get_image_gradient(SFc2_ur_servoInstanceStruct *chartInstance,
  real_T c2_image[307200], real_T c2_Para_Camera_Intrinsic[9], real_T c2_b_I_x
  [307200], real_T c2_b_I_y[307200])
{
  real_T c2_b_Para_Camera_Intrinsic;
  real_T c2_c_Para_Camera_Intrinsic;
  int32_T c2_b_hi;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_b_lo;
  int32_T c2_b_mid;
  int32_T c2_b_p;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_hi;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_j;
  int32_T c2_lo;
  int32_T c2_mid;
  int32_T c2_p;
  int32_T c2_pageoffset;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 10, 0);
  for (c2_b_k = 0; c2_b_k < 480; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_b_I_x[c2_c_k] = c2_image[c2_c_k + 480] - c2_image[c2_c_k];
  }

  for (c2_j = 0; c2_j < 638; c2_j++) {
    c2_lo = c2_j * 480 - 1;
    c2_mid = (c2_j + 1) * 480 - 1;
    c2_hi = (c2_j + 2) * 480 - 1;
    for (c2_e_k = 0; c2_e_k < 480; c2_e_k++) {
      c2_c_k = c2_e_k + 1;
      c2_b_I_x[c2_mid + c2_c_k] = (c2_image[c2_hi + c2_c_k] - c2_image[c2_lo +
        c2_c_k]) / 2.0;
    }
  }

  for (c2_d_k = 0; c2_d_k < 480; c2_d_k++) {
    c2_c_k = c2_d_k + 306720;
    c2_b_I_x[c2_c_k] = c2_image[c2_c_k] - c2_image[c2_c_k - 480];
  }

  for (c2_p = 0; c2_p < 640; c2_p++) {
    c2_b_p = c2_p;
    c2_pageoffset = c2_b_p * 480;
    c2_b_hi = c2_pageoffset;
    c2_b_I_y[c2_pageoffset] = c2_image[c2_b_hi + 1] - c2_image[c2_pageoffset];
    for (c2_b_j = 0; c2_b_j < 478; c2_b_j++) {
      c2_b_lo = c2_pageoffset + c2_b_j;
      c2_b_mid = c2_pageoffset + c2_b_j;
      c2_b_hi = (c2_pageoffset + c2_b_j) + 2;
      c2_b_I_y[c2_b_mid + 1] = (c2_image[c2_b_hi] - c2_image[c2_b_lo]) / 2.0;
    }

    c2_b_lo = c2_pageoffset;
    c2_b_hi = c2_pageoffset + 479;
    c2_b_I_y[c2_b_hi] = c2_image[c2_b_hi] - c2_image[c2_b_lo + 478];
  }

  c2_b_Para_Camera_Intrinsic = c2_Para_Camera_Intrinsic[0];
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    c2_b_I_x[c2_i] *= c2_b_Para_Camera_Intrinsic;
  }

  c2_c_Para_Camera_Intrinsic = c2_Para_Camera_Intrinsic[4];
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    c2_b_I_y[c2_i1] *= c2_c_Para_Camera_Intrinsic;
  }
}

static void c2_TransInv(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_T
  [16], real_T c2_invT[16])
{
  real_T c2_R[9];
  real_T c2_a[9];
  real_T c2_p[3];
  real_T c2_y[3];
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 11, 0);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 14U, 12, 0);
  c2_i = 0;
  c2_i1 = 0;
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
      c2_R[c2_i4 + c2_i] = c2_T[c2_i4 + c2_i1];
    }

    c2_i += 3;
    c2_i1 += 4;
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_p[c2_i3] = c2_T[c2_i3 + 12];
  }

  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_i8 = 0;
    for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
      c2_a[c2_i9 + c2_i5] = -c2_R[c2_i8 + c2_i6];
      c2_i8 += 3;
    }

    c2_i5 += 3;
  }

  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_y[c2_i7] = 0.0;
    c2_i12 = 0;
    for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
      c2_y[c2_i7] += c2_a[c2_i12 + c2_i7] * c2_p[c2_i13];
      c2_i12 += 3;
    }
  }

  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_i15 = 0;
    for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
      c2_invT[c2_i16 + c2_i10] = c2_R[c2_i15 + c2_i11];
      c2_i15 += 3;
    }

    c2_i10 += 4;
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_invT[c2_i14 + 12] = c2_y[c2_i14];
  }

  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    c2_invT[c2_i17 + 3] = c2_dv[c2_i18];
    c2_i17 += 4;
  }
}

static void c2_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_a__output_of_transpose_, const char_T *c2_identifier, real_T
  c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_a__output_of_transpose_),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_a__output_of_transpose_);
}

static void c2_b_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_b_dv[6];
  int32_T c2_i;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_dv, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i = 0; c2_i < 6; c2_i++) {
    c2_y[c2_i] = c2_b_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

const mxArray *sf_c2_ur_servo_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  const char_T *c2_data[11] = {
    "789ced9a4d6fe34418c75dd445bb482c15883dc0074042a8499a3747e240eabcd44d1ba2346dd220943af6c4711b7bd2b1f3e28803070e880b9c10e2b4c7bd20"
    "ed81231f01be03121f0089134792b8d3d4662dbbb89d6077e6329dfe63ff1f3f93f9e9c978980dfe70836198a78cd55eec5bfd9b57e3adabfe35c6de9cfac655",
    "ffd431c6ed11b369bb0eebdf5ef522d40c3035ac8126a8e0fa4a09aa8a266846c31c0206011d0ec6405a2a3d65001a8a0a8e6e0eaa8b915aba215d0f16d2e26f"
    "ae0fc48ba391caa0bebe8a70707370fd1c672ecfbbe9910f6773e6c3f939ec37fc8f7ef8fe6f79f8615d07680c3bba01861d048441e0e7c57e8f5cfd2d65a468",
    "06cbac9ef787807e69573fbbfe59f1f3581faa20369a3f79ac00f40b030e6335046524a89d6536628e9c6cab8cf7f700e7d32b4e67bffafce365ff5bbc203204"
    "fdfefcf5af0d927eb8adcb6fea723fbfdfb3672e7e5b0ebd7938cea0e34461923acd25ba3d94a92733d5bd551c350f1faf38189731a9fb877dbdfa8df3b163bc",
    "8ad3524e80d8803a4cde95dfebae7e9622c151770056cff75d40bf6d573fbbee671e702e1613406a7d7fffe117ad45ff50f845da8f142f6b1561df6059814f4c"
    "2af1535e4fd58b99e42ee525695e06ad3bdff08813eb8782819469713a4c5ae3b0f233eeea67d7fdcccb2a27db2ae56734fc48f1b3c5ce54811babc952b6aed7",
    "ccf4501e8872313afc0ceb3abdab3a735e5635e0bcc00a2b27efb2cec4b9a0756674fc4871327b9ade4d49e99a50ab1c28a5a9393b98f42a949391e1641508a8"
    "0d10a49c84319c0bcac9e8f891e264ae3be95f0aac7464c677cd86c25e360f5a758e72322a9ccc4f153dafc974df729e7f9c0b929cfce66592e87b1edc1e8a1f",
    "294e9aea49aedb05991137eb999f1653c6745fc8524eae7d9dd27ad26ab49ebc9d1f6e0fc58fd6937773ffb0bcdf093adfef78c4897519181d451564d0990766"
    "763488d4e5ffd775bee87940bf9cab9f5df7333fafc8cdb67a753d290e54b3095a7fdea31f29ae8a5c3bddcca19d4bae9aacb5cd386aeb6344b94a9cab5f078c",
    "f3038f38b1be60470908c60801bd8810441d5e3300124443819ab591d0299c1caded7dfacb807e87ae7e76dd2f677de48ae8f9ce1fb73ea1dcbd473f52dc65d3"
    "a311df9e9eb065a16670809f64e54caf141dee867d1d93fa1e2c62eb59b175c032b6454db7bef34ccf03fa7decea67d7fdcedbbf736395baa4f8f0f31f3b94b7",
    "f7e817749dbdebe2b7e5d09b933dae98d2ce27f159432d818ad9e3619fa1bcfdbff0f6cb80f1bfef113fd697bf9d57d174542b1c0bbaccfab8fb22a05fded5cf"
    "aefbde5f78758e88ef337cf4374794bf3f6d7ef51e493fdcc2ca5fbf75ce85543ace55f9f3e9f0a0d62b65a1c435d572213afc0debfa0d3aff6f7bc48d75db9e",
    "a5a400cdb0c77116308edbf236e8be10ebea67d76fbd9fbbcc0db9f3fbbfff42cf11dca71f29be8ece8f6730c516850accd745de4c2744598f105fc3b28f7b16"
    "304eaff3040d24683aaf8de9790218c3b9a0e709a2e3478a97e37e5e34e5b229b6da97a752b5581e48c61e3dc74f6c9d0e03c6f7c4233eac2fbd1bb08efdc2ca",
    "cd98ab9f5df73d1f8b9ccc278472331a7ea4b8b96b704d21d1336672969d95f7f687f1d64eb61c7e6efe031d46d494",
    "" };

  c2_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c2_data[0], 19136U, &c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_imread(SFc2_ur_servoInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, uint8_T c2_X[921600])
{
  static real_T c2_outDims[3] = { 480.0, 640.0, 3.0 };

  static char_T c2_b_cv[43] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'a',
    'g', 'e', 's', 'c', 'i', ':', 'i', 'm', 'r', 'e', 'a', 'd', ':', 'c', 'o',
    'd', 'e', 'g', 'e', 'n', 'F', 'i', 'l', 'e', 'O', 'p', 'e', 'n', 'E', 'r',
    'r', 'o', 'r' };

  static char_T c2_b_cv2[43] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm',
    'a', 'g', 'e', 's', 'c', 'i', ':', 'j', 'p', 'g', ':', 'r', 'u', 'n', 't',
    'i', 'm', 'e', 'D', 'i', 'm', 's', 'I', 'n', 'c', 'o', 'n', 's', 'i', 's',
    't', 'e', 'n', 't' };

  static char_T c2_fname[9] = "img1.jpg";
  static char_T c2_b_cv1[8] = { 'i', 'm', 'g', '1', '.', 'j', 'p', 'g' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  const mxArray *c2_k_y = NULL;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  const mxArray *c2_n_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_libjpegMsgCode;
  real_T c2_b_u;
  real_T c2_libjpegMsgCode;
  real_T c2_msgCode;
  real_T c2_u;
  int32_T c2_i;
  char_T c2_libjpegWarnBuffer[200];
  int8_T c2_b_errWarnType;
  int8_T c2_b_fileStatus;
  int8_T c2_b_libjpegReadDone;
  int8_T c2_b_runtimeFileDimsConsistency;
  int8_T c2_c_fileStatus;
  int8_T c2_c_libjpegReadDone;
  int8_T c2_c_runtimeFileDimsConsistency;
  int8_T c2_errWarnType;
  int8_T c2_fileStatus;
  int8_T c2_libjpegReadDone;
  int8_T c2_runtimeFileDimsConsistency;
  int8_T c2_warnBufferFlag;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ab_emlrtRSI;
  c2_fileStatus = c2_b_fileStatus;
  c2_libjpegReadDone = c2_b_libjpegReadDone;
  c2_msgCode = c2_libjpegMsgCode;
  c2_warnBufferFlag = c2_errWarnType;
  c2_runtimeFileDimsConsistency = c2_b_runtimeFileDimsConsistency;
  c2_c_runtimeFileDimsConsistency = c2_runtimeFileDimsConsistency;
  c2_b_errWarnType = c2_warnBufferFlag;
  for (c2_i = 0; c2_i < 200; c2_i++) {
    c2_libjpegWarnBuffer[c2_i] = ' ';
  }

  c2_b_libjpegMsgCode = c2_msgCode;
  c2_c_libjpegReadDone = c2_libjpegReadDone;
  c2_c_fileStatus = c2_fileStatus;
  jpegreader_uint8(&c2_fname[0], &c2_X[0], &c2_outDims[0], 3.0, &c2_c_fileStatus,
                   &c2_c_libjpegReadDone, &c2_b_libjpegMsgCode,
                   &c2_libjpegWarnBuffer[0], &c2_b_errWarnType,
                   &c2_c_runtimeFileDimsConsistency);
  if ((c2_c_fileStatus == -1) || (c2_c_libjpegReadDone == 0) ||
      (c2_b_errWarnType == -1) || (c2_c_runtimeFileDimsConsistency == 0)) {
    if (c2_c_fileStatus == -1) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 43),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
        43), false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        8), false);
      sf_mex_call(c2_sp, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c2_sp, NULL, "message", 1U, 2U, 14, c2_c_y, 14, c2_f_y)));
    }

    if (c2_b_errWarnType == -1) {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c2_u = 8.0;
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
      c2_l_y = NULL;
      sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_libjpegWarnBuffer, 10, 0U, 1U,
        0U, 2, 1, 200), false);
      sf_mex_call(c2_sp, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                  sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c2_sp, NULL, "message", 1U, 3U, 14, c2_e_y, 14, c2_i_y, 14, c2_l_y)));
    }

    if (c2_c_libjpegReadDone != 1) {
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c2_b_u = 8.0;
      c2_k_y = NULL;
      sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c2_n_y = NULL;
      sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_libjpegWarnBuffer, 10, 0U, 1U,
        0U, 2, 1, 200), false);
      sf_mex_call(c2_sp, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                  sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c2_sp, NULL, "message", 1U, 3U, 14, c2_h_y, 14, c2_k_y, 14, c2_n_y)));
    }

    if (c2_c_runtimeFileDimsConsistency == 0) {
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        43), false);
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        43), false);
      c2_m_y = NULL;
      sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        8), false);
      sf_mex_call(c2_sp, &c2_d_emlrtMCI, "error", 0U, 2U, 14, c2_g_y, 14,
                  sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c2_sp, NULL, "message", 1U, 2U, 14, c2_j_y, 14, c2_m_y)));
    }
  }

  if (c2_b_errWarnType == -2) {
    c2_st.site = &c2_bb_emlrtRSI;
    c2_warning(chartInstance, &c2_st, c2_libjpegWarnBuffer);
  }
}

static void c2_warning(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, char_T c2_varargin_2[200])
{
  static char_T c2_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c2_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                false);
  c2_u = 8.0;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_varargin_2, 10, 0U, 1U, 0U, 2, 1,
    200), false);
  c2_st.site = &c2_cb_emlrtRSI;
  c2_b_feval(chartInstance, &c2_st, c2_y, c2_feval(chartInstance, &c2_st, c2_b_y,
              c2_c_y, c2_d_y, c2_e_y));
}

static void c2_b_warning(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp)
{
  static char_T c2_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c2_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c2_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  c2_st.site = &c2_cb_emlrtRSI;
  c2_d_feval(chartInstance, &c2_st, c2_y, c2_c_feval(chartInstance, &c2_st,
              c2_b_y, c2_c_y));
}

static real_T c2_sumColumnB(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_x[307200], int32_T c2_col)
{
  real_T c2_y;
  int32_T c2_b_col;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_i0;
  (void)chartInstance;
  c2_b_col = c2_col - 1;
  c2_i0 = c2_b_col * 480;
  c2_y = c2_x[c2_i0];
  for (c2_b_k = 0; c2_b_k < 479; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_y += c2_x[(c2_i0 + c2_c_k) + 1];
  }

  return c2_y;
}

static real_T c2_b_sumColumnB(SFc2_ur_servoInstanceStruct *chartInstance, real_T
  c2_x[640])
{
  real_T c2_y;
  int32_T c2_b_k;
  int32_T c2_c_k;
  (void)chartInstance;
  c2_y = c2_x[0];
  for (c2_b_k = 0; c2_b_k < 639; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_y += c2_x[c2_c_k + 1];
  }

  return c2_y;
}

static real_T c2_norm(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_x[3])
{
  real_T c2_absxk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_y;
  int32_T c2_b_k;
  int32_T c2_c_k;
  (void)chartInstance;
  c2_y = 0.0;
  c2_scale = 3.3121686421112381E-170;
  for (c2_b_k = 0; c2_b_k < 3; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_b_x = c2_x[c2_c_k];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static void c2_pinv(SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack
                    *c2_sp, real_T c2_b_A[1843200], real_T c2_X[1843200])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_V[36];
  real_T c2_s[6];
  real_T c2_a;
  real_T c2_absx;
  real_T c2_b_a;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_r;
  real_T c2_tol;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  int32_T c2_b_exponent;
  int32_T c2_b_ix0;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_b_r;
  int32_T c2_c_a;
  int32_T c2_c_k;
  int32_T c2_d_a;
  int32_T c2_d_k;
  int32_T c2_e_a;
  int32_T c2_e_k;
  int32_T c2_exponent;
  int32_T c2_f_a;
  int32_T c2_f_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i_b;
  int32_T c2_ix0;
  int32_T c2_j;
  int32_T c2_j_b;
  int32_T c2_k_b;
  int32_T c2_l_b;
  int32_T c2_vcol;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b_b;
  boolean_T c2_b_overflow;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_g_b;
  boolean_T c2_h_b;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_lb_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  for (c2_i = 0; c2_i < 1843200; c2_i++) {
    c2_X[c2_i] = 0.0;
  }

  c2_b_st.site = &c2_mb_emlrtRSI;
  c2_c_st.site = &c2_rb_emlrtRSI;
  c2_d_st.site = &c2_sb_emlrtRSI;
  for (c2_i1 = 0; c2_i1 < 1843200; c2_i1++) {
    chartInstance->c2_x_data[c2_i1] = c2_b_A[c2_i1];
  }

  c2_p = true;
  c2_e_st.site = &c2_tb_emlrtRSI;
  for (c2_b_k = 0; c2_b_k < 1843200; c2_b_k++) {
    c2_c_k = c2_b_k;
    if (c2_p) {
      c2_x = chartInstance->c2_x_data[c2_c_k];
      c2_b_x = c2_x;
      c2_b_b = muDoubleScalarIsInf(c2_b_x);
      c2_c_b = !c2_b_b;
      c2_f_x = c2_x;
      c2_d_b = muDoubleScalarIsNaN(c2_f_x);
      c2_b1 = !c2_d_b;
      c2_e_b = (c2_c_b && c2_b1);
      if (c2_e_b) {
        c2_c_p = true;
      } else {
        c2_c_p = false;
      }
    } else {
      c2_c_p = false;
    }

    c2_p = c2_c_p;
  }

  c2_b_p = !c2_p;
  if (c2_b_p) {
    for (c2_i2 = 0; c2_i2 < 1843200; c2_i2++) {
      c2_X[c2_i2] = rtNaN;
    }
  } else {
    c2_b_st.site = &c2_nb_emlrtRSI;
    c2_svd(chartInstance, &c2_b_st, c2_b_A, chartInstance->c2_U, c2_s, c2_V);
    c2_c_x = c2_s[0];
    c2_d_x = c2_c_x;
    c2_e_x = c2_d_x;
    c2_g_x = c2_e_x;
    c2_h_x = c2_g_x;
    c2_absx = muDoubleScalarAbs(c2_h_x);
    c2_i_x = c2_absx;
    c2_j_x = c2_i_x;
    c2_f_b = muDoubleScalarIsInf(c2_j_x);
    c2_b2 = !c2_f_b;
    c2_k_x = c2_i_x;
    c2_g_b = muDoubleScalarIsNaN(c2_k_x);
    c2_b3 = !c2_g_b;
    c2_h_b = (c2_b2 && c2_b3);
    if (!c2_h_b) {
      c2_r = rtNaN;
    } else if (c2_absx < 4.4501477170144028E-308) {
      c2_r = 4.94065645841247E-324;
    } else {
      frexp(c2_absx, &c2_exponent);
      c2_b_exponent = c2_exponent;
      c2_r = ldexp(1.0, c2_b_exponent - 53);
    }

    c2_tol = 307200.0 * c2_r;
    c2_b_r = 0;
    c2_d_k = 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_d_k - 1 < 6)) {
      c2_e_k = c2_d_k - 1;
      if (!(c2_s[c2_e_k] > c2_tol)) {
        c2_exitg1 = true;
      } else {
        c2_b_r++;
        c2_d_k++;
      }
    }

    if (c2_b_r > 0) {
      c2_vcol = 1;
      c2_b_st.site = &c2_ob_emlrtRSI;
      c2_i_b = c2_b_r;
      c2_j_b = c2_i_b;
      c2_overflow = (c2_j_b > 2147483646);
      if (c2_overflow) {
        c2_c_st.site = &c2_ub_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_j = 0; c2_j < c2_b_r; c2_j++) {
        c2_b_j = c2_j;
        c2_y = c2_s[c2_b_j];
        c2_z = 1.0 / c2_y;
        c2_b_st.site = &c2_pb_emlrtRSI;
        c2_a = c2_z;
        c2_ix0 = c2_vcol;
        c2_c_st.site = &c2_kc_emlrtRSI;
        c2_b_a = c2_a;
        c2_b_ix0 = c2_ix0;
        c2_c_a = c2_b_ix0 + 5;
        c2_i3 = c2_c_a;
        c2_d_st.site = &c2_mc_emlrtRSI;
        c2_d_a = c2_b_ix0;
        c2_k_b = c2_i3;
        c2_e_a = c2_d_a;
        c2_l_b = c2_k_b;
        if (c2_e_a > c2_l_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_l_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_e_st.site = &c2_ub_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
        }

        for (c2_f_k = c2_b_ix0; c2_f_k <= c2_i3; c2_f_k++) {
          c2_V[c2_f_k - 1] *= c2_b_a;
        }

        c2_f_a = c2_vcol + 6;
        c2_vcol = c2_f_a;
      }

      c2_b_st.site = &c2_qb_emlrtRSI;
      c2_b_xgemm(chartInstance, c2_b_r, c2_V, chartInstance->c2_U, c2_X);
    }
  }
}

static void c2_check_forloop_overflow_error(SFc2_ur_servoInstanceStruct
  *chartInstance, const emlrtStack *c2_sp)
{
  static char_T c2_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c2_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c2_sp, &c2_g_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14, sf_mex_call
              (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
    "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
}

static void c2_svd(SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *
                   c2_sp, real_T c2_b_A[1843200], real_T c2_b_U[1843200], real_T
                   c2_s[6], real_T c2_V[36])
{
  static char_T c2_b_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e',
    'r', 'g', 'e', 'n', 'c', 'e' };

  static char_T c2_b_cv[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'd', 'd' };

  ptrdiff_t c2_info_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldu_t;
  ptrdiff_t c2_ldv_t;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_Vt[36];
  int32_T c2_b_i;
  int32_T c2_b_info;
  int32_T c2_b_j;
  int32_T c2_c_i;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_e_info;
  int32_T c2_f_info;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_info;
  int32_T c2_j;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_vb_emlrtRSI;
  c2_b_st.site = &c2_xb_emlrtRSI;
  for (c2_i = 0; c2_i < 1843200; c2_i++) {
    chartInstance->c2_A[c2_i] = c2_b_A[c2_i];
  }

  c2_m_t = (ptrdiff_t)307200;
  c2_n_t = (ptrdiff_t)6;
  c2_lda_t = (ptrdiff_t)307200;
  c2_ldu_t = (ptrdiff_t)307200;
  c2_ldv_t = (ptrdiff_t)6;
  c2_info_t = LAPACKE_dgesdd(102, 'S', c2_m_t, c2_n_t, &chartInstance->c2_A[0],
    c2_lda_t, &c2_s[0], &c2_b_U[0], c2_ldu_t, &c2_Vt[0], c2_ldv_t);
  c2_info = (int32_T)c2_info_t;
  c2_c_st.site = &c2_yb_emlrtRSI;
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      sf_mex_call(&c2_c_st, &c2_i_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
    } else {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
        14), false);
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_b_info, 6, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call(&c2_c_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 3U, 14, c2_c_y, 14, c2_e_y,
                    14, c2_g_y)));
    }
  }

  c2_d_info = c2_info;
  if (c2_info > 0) {
    c2_b_st.site = &c2_wb_emlrtRSI;
    for (c2_i1 = 0; c2_i1 < 1843200; c2_i1++) {
      chartInstance->c2_A[c2_i1] = c2_b_A[c2_i1];
    }

    c2_c_st.site = &c2_ac_emlrtRSI;
    c2_ceval_xgesvd(chartInstance, &c2_c_st, chartInstance->c2_A, c2_b_U, c2_s,
                    c2_V, &c2_e_info);
    c2_f_info = c2_e_info;
    c2_d_info = c2_f_info;
  } else {
    for (c2_j = 0; c2_j < 6; c2_j++) {
      c2_b_j = c2_j;
      for (c2_b_i = 0; c2_b_i < 6; c2_b_i++) {
        c2_c_i = c2_b_i;
        c2_V[c2_c_i + 6 * c2_b_j] = c2_Vt[c2_b_j + 6 * c2_c_i];
      }
    }
  }

  if (c2_d_info > 0) {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c2_st, &c2_h_emlrtMCI, "error", 0U, 2U, 14, c2_f_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_h_y)));
  }
}

static void c2_ceval_xgesvd(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_A[1843200], real_T c2_b_U[1843200], real_T
  c2_S[6], real_T c2_V[36], int32_T *c2_info)
{
  static char_T c2_b_cv[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'v', 'd' };

  ptrdiff_t c2_info_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldu_t;
  ptrdiff_t c2_ldv_t;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_Vt[36];
  real_T c2_superb[5];
  int32_T c2_b_i;
  int32_T c2_b_info;
  int32_T c2_b_j;
  int32_T c2_c_info;
  int32_T c2_i;
  int32_T c2_j;
  boolean_T c2_p;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_m_t = (ptrdiff_t)307200;
  c2_n_t = (ptrdiff_t)6;
  c2_lda_t = (ptrdiff_t)307200;
  c2_ldu_t = (ptrdiff_t)307200;
  c2_ldv_t = (ptrdiff_t)6;
  c2_info_t = LAPACKE_dgesvd(102, 'S', 'S', c2_m_t, c2_n_t, &c2_b_A[0], c2_lda_t,
    &c2_S[0], &c2_b_U[0], c2_ldu_t, &c2_Vt[0], c2_ldv_t, &c2_superb[0]);
  *c2_info = (int32_T)c2_info_t;
  for (c2_j = 0; c2_j < 6; c2_j++) {
    c2_b_j = c2_j;
    for (c2_i = 0; c2_i < 6; c2_i++) {
      c2_b_i = c2_i;
      c2_V[c2_b_i + 6 * c2_b_j] = c2_Vt[c2_b_j + 6 * c2_b_i];
    }
  }

  c2_st.site = &c2_bc_emlrtRSI;
  c2_b_info = *c2_info;
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      sf_mex_call(&c2_st, &c2_i_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                  sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
    } else {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 33),
                    false);
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
        14), false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_b_info, 6, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call(&c2_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c2_st, NULL, "message", 1U, 3U, 14, c2_c_y, 14, c2_e_y, 14, c2_f_y)));
    }
  }
}

static void c2_xgemm(SFc2_ur_servoInstanceStruct *chartInstance, int32_T c2_b_k,
                     real_T c2_b_A[36], real_T c2_b_B[1843200], real_T c2_C
                     [1843200], real_T c2_b_C[1843200])
{
  real_T c2_c_A[36];
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  for (c2_i = 0; c2_i < 1843200; c2_i++) {
    c2_b_C[c2_i] = c2_C[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 36; c2_i1++) {
    c2_c_A[c2_i1] = c2_b_A[c2_i1];
  }

  for (c2_i2 = 0; c2_i2 < 1843200; c2_i2++) {
    chartInstance->c2_B[c2_i2] = c2_b_B[c2_i2];
  }

  c2_b_xgemm(chartInstance, c2_b_k, c2_c_A, chartInstance->c2_B, c2_b_C);
}

static void c2_mtimes(SFc2_ur_servoInstanceStruct *chartInstance, real_T c2_b_A
                      [1843200], real_T c2_b_B[307200], real_T c2_C[6])
{
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSA1;
  char_T c2_TRANSB1;
  (void)chartInstance;
  c2_TRANSB1 = 'N';
  c2_TRANSA1 = 'N';
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_m_t = (ptrdiff_t)6;
  c2_n_t = (ptrdiff_t)1;
  c2_k_t = (ptrdiff_t)307200;
  c2_lda_t = (ptrdiff_t)6;
  c2_ldb_t = (ptrdiff_t)307200;
  c2_ldc_t = (ptrdiff_t)6;
  dgemm(&c2_TRANSA1, &c2_TRANSB1, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1,
        &c2_b_A[0], &c2_lda_t, &c2_b_B[0], &c2_ldb_t, &c2_beta1, &c2_C[0],
        &c2_ldc_t);
}

static void c2_c_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_Sc, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Sc), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_Sc);
}

static void c2_d_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_b_dv[6];
  int32_T c2_i;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_dv, 1, 0, 0U, 1, 0U, 2, 6, 1);
  for (c2_i = 0; c2_i < 6; c2_i++) {
    c2_y[c2_i] = c2_b_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_vec, const char_T *c2_identifier, real_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vec), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_vec);
}

static void c2_f_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_b_dv[16];
  int32_T c2_i;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_dv, 1, 0, 0U, 1, 0U, 2, 1,
                16);
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_y[c2_i] = c2_b_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ur_servo, const char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ur_servo), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ur_servo);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_ur_servoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_u;
  uint8_T c2_y;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_b_u;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_slStringInitializeDynamicBuffers(SFc2_ur_servoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_chart_data_browse_helper(SFc2_ur_servoInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  *c2_mxData = NULL;
  *c2_mxData = NULL;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 10U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_k, 0, 0U,
      1U, 0U, 1, 9), false);
    break;

   case 9U:
    *c2_isValueTooBig = 1U;
    break;

   case 4U:
    *c2_isValueTooBig = 1U;
    break;

   case 6U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_pose, 0,
      0U, 1U, 0U, 1, 7), false);
    break;

   case 12U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_Sc, 0,
      0U, 1U, 0U, 2, 6, 1), false);
    break;

   case 13U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_vec, 0,
      0U, 1U, 0U, 2, 1, 16), false);
    break;
  }
}

static const mxArray *c2_quat2axang(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "quat2axang", 1U, 1U, 14,
    sf_mex_dup(c2_input0)), false);
  sf_mex_destroy(&c2_input0);
  return c2_m;
}

static const mxArray *c2_coder_internal_mxSubscript(SFc2_ur_servoInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, const mxArray *c2_input0, const
  mxArray *c2_input1)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "coder.internal.mxSubscript", 1U,
    2U, 14, sf_mex_dup(c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_m;
}

static const mxArray *c2_b_coder_internal_mxSubscript
  (SFc2_ur_servoInstanceStruct *chartInstance, const emlrtStack *c2_sp, const
   mxArray *c2_input0, const mxArray *c2_input1)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "coder.internal.mxSubscript", 1U,
    2U, 14, sf_mex_dup(c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_m;
}

static const mxArray *c2_b_mtimes(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "mtimes", 1U, 2U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_m;
}

static const mxArray *c2_horzcat(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "horzcat", 1U, 2U, 14,
    sf_mex_dup(c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_m;
}

static const mxArray *c2_transpose(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "transpose", 1U, 1U, 14,
    sf_mex_dup(c2_input0)), false);
  sf_mex_destroy(&c2_input0);
  return c2_m;
}

static const mxArray *c2_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1, const
  mxArray *c2_input2, const mxArray *c2_input3)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1), 14, sf_mex_dup(c2_input2), 14,
    sf_mex_dup(c2_input3)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  sf_mex_destroy(&c2_input2);
  sf_mex_destroy(&c2_input3);
  return c2_m;
}

static void c2_b_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  (void)chartInstance;
  sf_mex_call(c2_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c2_input0), 14,
              sf_mex_dup(c2_input1));
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
}

static const mxArray *c2_c_feval(SFc2_ur_servoInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  const mxArray *c2_m = NULL;
  (void)chartInstance;
  c2_m = NULL;
  sf_mex_assign(&c2_m, sf_mex_call(c2_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_m;
}

static void c2_d_feval(SFc2_ur_servoInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  (void)chartInstance;
  sf_mex_call(c2_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c2_input0), 14,
              sf_mex_dup(c2_input1));
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
}

static void c2_b_xgemm(SFc2_ur_servoInstanceStruct *chartInstance, int32_T
  c2_b_k, real_T c2_b_A[36], real_T c2_b_B[1843200], real_T c2_C[1843200])
{
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  real_T c2_alpha1;
  real_T c2_beta1;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_var;
  char_T c2_TRANSA1;
  char_T c2_TRANSB1;
  (void)chartInstance;
  c2_c_k = c2_b_k;
  c2_d_k = c2_c_k;
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB1 = 'C';
  c2_TRANSA1 = 'N';
  c2_m_t = (ptrdiff_t)6;
  c2_n_t = (ptrdiff_t)307200;
  c2_var = c2_d_k;
  c2_k_t = (ptrdiff_t)c2_var;
  c2_lda_t = (ptrdiff_t)6;
  c2_ldb_t = (ptrdiff_t)307200;
  c2_ldc_t = (ptrdiff_t)6;
  dgemm(&c2_TRANSA1, &c2_TRANSB1, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1,
        &c2_b_A[0], &c2_lda_t, &c2_b_B[0], &c2_ldb_t, &c2_beta1, &c2_C[0],
        &c2_ldc_t);
}

static void init_dsm_address_info(SFc2_ur_servoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_ur_servoInstanceStruct *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_k = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_depth_image = (uint16_T (*)[307200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c2_rgb_image = (uint8_T (*)[921600])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c2_pose = (real_T (*)[7])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_Sc = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_vec = (real_T (*)[16])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_ur_servo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3894022060U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3074852025U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(7358507U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(150215085U);
}

mxArray *sf_c2_ur_servo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,4);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "matlab.io.sharedimage.internal.coder.ImreadJpegBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 3, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c2_ur_servo_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("jpegreader_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_ur_servo_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_ur_servo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDewMTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Gs4gPQbIOlnwaKfCUm/AJAXnAwJF1j4DJz7tY"
    "hyPzOK+5kZylKTqeR+BQfK9EPs9yDgflEU90P4mcXxicklmWWp8clG8aVF8cWpRWX5DIh4AQBqG"
    "xyG"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ur_servo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sVGNxIfXMd6G2jHxyRmHnc";
}

static void sf_opaque_initialize_c2_ur_servo(void *chartInstanceVar)
{
  initialize_params_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
  initialize_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ur_servo(void *chartInstanceVar)
{
  enable_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ur_servo(void *chartInstanceVar)
{
  disable_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ur_servo(void *chartInstanceVar)
{
  sf_gateway_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_ur_servo(SimStruct* S)
{
  return get_sim_state_c2_ur_servo((SFc2_ur_servoInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_ur_servo(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_ur_servo((SFc2_ur_servoInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_ur_servo(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ur_servoInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ur_servo_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_ur_servo((SFc2_ur_servoInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_ur_servo(void *chartInstanceVar)
{
  mdl_start_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c2_ur_servo(void *chartInstanceVar)
{
  mdl_terminate_c2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ur_servo((SFc2_ur_servoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ur_servo(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ur_servo((SFc2_ur_servoInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc2_ur_servo((SFc2_ur_servoInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_ur_servo_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [39] = {
    "eNrtXMtv48YZp7yOETfZ3SBB+kqB5pYgSG35LQOLdmXqYa0lrWDJj3USKGNyKM2aHMozQ0o0cui",
    "hvfRSoEB76P9QYA89Fug/0PbUQ48Fem+DnHLMDEnJMq2aD3lt7VoEtLsj6jffY37f982QMyulSh",
    "WJXw/4582CJM2Jv/lnRvKuN/x2aujjfT8rPfLbX70lSYqpwhbEdUvTUE+Kd2HLqAECDCrFvzAw4",
    "C6kpm4xZOIS1szoWIQ1SCBWeAcdk7BYcikyLB3hk4KFFSGZHrSR0q63TUtXt3iHQH2Kdef/ye1Y",
    "rMYl5hCBCitAqLI2Ma1Wu6CD1tVeIKwrt6FyQi0jtq8oZHWrI0ylFUtnqKPDfA8qJUwZ4F6gIfb",
    "WGWBQZr14Thb20nofbRodHQEc3ddtQOuww9nB4F5H5X8+tRj3XiSs0gaEbcE2sCEtoxNXuolhJO",
    "mI8l8fIwyYSRDQ84Yui94i2lvTuY0VHhJ63DHi9m4RCE46JsIsZkDUC9zPeQyOdZiDx1Yrptw6P",
    "LVENOwj2IUk3vhqsmlDAlrwKY6nsztG+Z5LykEsRcQyZMB9QLIK5y6Fary8wYOO1gGnI2zwbmJh",
    "oeviEm0QZHNuxM11JRH+iXKdZXjsp4mwrty8DWPzaiC3oGAZ6DqNh22YnTK0oe7KzwEGEmA9+TH",
    "AlCK1YXJ2iGwTM2NZGPFI8LGyiVUUnZV2AOUWtiovUhHgyBBhAFXu5oHqg47C4siizDRknnJy5X",
    "JEeZexJcwg0YACI9cYAhCFXGGXVzHlqoiKQOJo7iXmWhm5By8GE0Elqlk41zXJCfdx3GJ27isRC",
    "fHQUG3xxMygm+TynN37QLci6mzQFo8fTo89yrNsPLkcK+InEVgBShuqonIiHVZ4nuUdRB1iKkp+",
    "lltrI+bkIFUI6kSNJIsndF50hZcaTgfu4RNsdnGBmEbdn3ldwSsIedYABCPc2uIlnDgFrnw0rQk",
    "8bbjZPe4kR/gZMB0cC24UIebVUNgqZg1A4VGVx3yKzBUaB1tHZ3wSgymijBdqxyv1Xt0T8/fH0v",
    "n8fXbE/P2tofn7O35bWW5apEkhsc1BP+mhft6OsA7o46RPr14/PAjg7vvt3wo9TJ56eux8Un8+m",
    "qbBxxAzQQM+PHyqb/s2a8gr3vXhRlW0jMLQrUFD3BL/dpNbnSc30h4ihT7cuOSHoD/717A/o47D",
    "wwDuoTs35yPQ5OPaafLpn+72kwnp541AP6Jt8WljxtejHYJfC+BF+7P8F4tt04CLPADJIg/aE2Z",
    "2FmvEbPE65vFkMaDrguHLG9b3YQhv7vvf/z2dU6Qx8P/72zepcfDD4z0ufjvE398P+Fu0Dyr2Ot",
    "lbynVXn20uHWtkfXdlvbrt9ffxUH+pEf0N8y/J72+TH6PkvRmQJ9r7UGmY1FyJgp8L4Ofc7GHxH",
    "OnJ/zIEvxDAL0S0t6+jMDQpj/7wyVeHk8Lj24iD2g54wjIZUFrq7qSflejqbn59Zev1jIOw+vC9",
    "gDzRrgBGUI8vlFdGj9PLiId0AJ+OaPe5rgvGNB6SxcNh5swAsm2sFDZ2ac1Z67R0pZW/mXi4DV5",
    "ErQc8zfK1MVQmuR70dZzWg+T833i2trWqrtVAbaeMCj3nrNzVdqb8l6p8XXsEiTnJ/O/rOOV/cv",
    "5vHnfbpyCj1p30ltNAmdOD8uGuPOV/todoFrcmej3Q13Ec/v/mxYpyl/nvGPubx8dw3ZLPNOdpf",
    "pX1noCNCeH/y+DFNP9P8/+k5P+bXg+H+ee9gDzRbkHWRAZowSYX4DSxSYzI6+Kw56adEPxmAL8Z",
    "0f4ROi8YY/KsurF0p+uEIh+tHWyS5VO5ulI7ctLkiNrkNY2TwxB5HwXkfeTHSQECZhFI84SYpOm",
    "+4wXuO0hvQtbM7dev5XnSL0PwlQC+EiNuItgw1nuIP77z+E7HUWbNskpHvf1MEdSYDEvdjda6Vr",
    "iZOJoU3iTxm5CheTKa0JUhcvv1PJ8Nq0OPAvhHMfxyWWevFCXl35//s3xn4uf9gN9F+6C7LedX8",
    "fNu+qxhFOCOo5XMtnS34qcWoscHAT0+6M/jznttGl63XhBd03uOXgg+G8Bn48znRus+9rzu02/l",
    "seLpT7O/+vGrXI9O1MLeZrX0vNcp17TChqnKB0YxdzPxdNt8CfPXuwH57wbXQyoabHK+jvgJm+d",
    "mAvhMkvWQq3Py94X//svdfl5mPd87M1czebBjZneVkrO2pLRobrqPpP/crEEApiVsT/Jzs76O0+",
    "dmyePAbmcVp1V0lMOj02dqNV/UVbadf7WfGwd5EbZ/ZD4gZ77P/4a525Fubv/IYgC/GMdeoSs3e",
    "BoHyeJgi8kHYEljZ62NzFlx+0knfbi8UbyZOEiKG95vOz9z8fezAT/N8G9S/ArGw33patyc76PP",
    "f//iHz/653/nf/07uvDND//6Xpj81CX5qcGe5i/vxTs32d8H/RPJP/80OG1hXzqQkHT86X6x2it",
    "phxV1vbj8fLvn7BrbWPH6ezFztb73Avr2v/+Qf5jYhS36J0pJHdqqDSzvXGCQ73Mh/pi/wPevfz",
    "Ee/uPHYfu2U77N5/6akerKRd7env6fRNL/3gX970k2VK5J/w8fj4dP/vwE0aZYFdmwefFEwoOI+",
    "eGq+IyLk24Y96roOfXLy7cvynmb2YS4GWm88z03hRvXvpc9v5m03yc9pzRpdkhX5Pu3R9iVCvQ7",
    "qXb9S4o3P/yp3/651D/HLLeRro44SenfLkOgjbr7mvD725j++4Hfzgv/+f/hxdFKFgPdocg75Nf",
    "/mi88bUgGtwgEdPT51NuoJ+PsZ9lrFH6WGaMufQcAa70T",
    ""
  };

  static char newstr [2821] = "";
  newstr[0] = '\0';
  for (i = 0; i < 39; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_ur_servo(SimStruct *S)
{
  const char* newstr = sf_c2_ur_servo_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3467679068U));
  ssSetChecksum1(S,(166646809U));
  ssSetChecksum2(S,(779326085U));
  ssSetChecksum3(S,(331290866U));
}

static void mdlRTW_c2_ur_servo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_ur_servo(SimStruct *S)
{
  SFc2_ur_servoInstanceStruct *chartInstance;
  chartInstance = (SFc2_ur_servoInstanceStruct *)utMalloc(sizeof
    (SFc2_ur_servoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_ur_servoInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ur_servo;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ur_servo;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c2_ur_servo;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c2_ur_servo;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_ur_servo;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ur_servo;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ur_servo;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ur_servo;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ur_servo;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ur_servo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ur_servo;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ur_servo;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c2_JITStateAnimation,
    chartInstance->c2_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_ur_servo(chartInstance);
}

void c2_ur_servo_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_ur_servo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ur_servo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ur_servo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ur_servo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
