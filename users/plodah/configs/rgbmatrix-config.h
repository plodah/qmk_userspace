#ifdef RGB_MATRIX_ENABLE

//-- RGB SETTINGS
#  ifdef RGB_MATRIX_DEFAULT_MODE
#    undef RGB_MATRIX_DEFAULT_MODE
#  endif
#  define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

#  ifdef RGB_MATRIX_DEFAULT_HUE
#    undef RGB_MATRIX_DEFAULT_HUE
#  endif
#  define RGB_MATRIX_DEFAULT_HUE 79

#  ifdef RGB_MATRIX_DEFAULT_SAT
#    undef RGB_MATRIX_DEFAULT_SAT
#  endif
#  define RGB_MATRIX_DEFAULT_SAT 239

#  ifdef RGB_MATRIX_DEFAULT_VAL
#    undef RGB_MATRIX_DEFAULT_VAL
#  endif
#  define RGB_MATRIX_DEFAULT_VAL 167

#  ifdef RGB_MATRIX_DEFAULT_SPD
#    undef RGB_MATRIX_DEFAULT_SPD
#  endif
#  define RGB_MATRIX_DEFAULT_SPD 48

#  ifdef RGB_MATRIX_SLEEP
#    undef RGB_MATRIX_SLEEP
#  endif
#  define RGB_MATRIX_SLEEP

#  ifdef RGB_MATRIX_TIMEOUT
#    undef RGB_MATRIX_TIMEOUT
#  endif
#  define RGB_MATRIX_TIMEOUT 270000

#  ifdef RGB_MATRIX_KEYRELEASES
#    undef RGB_MATRIX_KEYRELEASES
#  endif
// #  define RGB_MATRIX_KEYRELEASES

#  ifdef RGB_MATRIX_HUE_STEP
#    undef RGB_MATRIX_HUE_STEP
#  endif
#  define RGB_MATRIX_HUE_STEP 5

#  ifdef RGB_MATRIX_SAT_STEP
#    undef RGB_MATRIX_SAT_STEP
#  endif
#  define RGB_MATRIX_SAT_STEP 8

#  ifdef RGB_MATRIX_VAL_STEP
#    undef RGB_MATRIX_VAL_STEP
#  endif
#  define RGB_MATRIX_VAL_STEP 8

#  ifdef RGB_MATRIX_SPD_STEP
#    undef RGB_MATRIX_SPD_STEP
#  endif
#  define RGB_MATRIX_SPD_STEP 8

#endif // RGB_MATRIX_ENABLE
