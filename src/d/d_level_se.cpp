//
// Generated by dtk
// Translation Unit: d_level_se.cpp
//

#include "d/d_level_se.h"
#include "f_op/f_op_kankyo.h"
#include "f_op/f_op_kankyo_mng.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_audio.h"

/* 80199308-801993CC       .text dLevelSe_Execute__FP10dLevelSe_c */
BOOL dLevelSe_Execute(dLevelSe_c* i_this) {
    s32 soundId = i_this->mParam;

    if (i_this->mFlag & 0x08) {
    } else if (i_this->mFlag & 0x01) {
        mDoAud_seStart(soundId, &i_this->mPos, i_this->field_0xf8);
    } else if (i_this->mFlag & 0x04) {
        mDoAud_seStart(soundId, &i_this->mPos, i_this->field_0xf8, i_this->mReverb);
    } else {
        mDoAud_seStart(soundId, &i_this->mPos);
    }

    return TRUE;
}

/* 801993CC-801993D4       .text dLevelSe_IsDelete__FP10dLevelSe_c */
BOOL dLevelSe_IsDelete(dLevelSe_c*) {
    return TRUE;
}

/* 801993D4-80199404       .text dLevelSe_Delete__FP10dLevelSe_c */
BOOL dLevelSe_Delete(dLevelSe_c* i_this) {
    mDoAud_seDeleteObject(&i_this->mPos);
    return TRUE;
}

/* 80199404-8019940C       .text dLevelSe_Create__FP12kankyo_class */
s32 dLevelSe_Create(kankyo_class*) {
    return cPhs_COMPLEATE_e;
}

kankyo_method_class l_dLevelSe_Method = {
    (process_method_func)dLevelSe_Create,
    (process_method_func)dLevelSe_Delete,
    (process_method_func)dLevelSe_Execute,
    (process_method_func)dLevelSe_IsDelete,
};

kankyo_process_profile_definition g_profile_LEVEL_SE = {
    fpcLy_CURRENT_e,
    2,
    fpcPi_CURRENT_e,
    PROC_LEVEL_SE,
    &g_fpcLf_Method.base,
    sizeof(dLevelSe_c),
    0,
    0,
    &g_fopKy_Method,
    0x1CD,
    &l_dLevelSe_Method,
};
