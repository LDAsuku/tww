//
// Generated by dtk
// Translation Unit: d_a_kytag00.cpp
//

#include "d/actor/d_a_kytag00.h"
#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_camera.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "d/d_kankyo.h"
#include "d/actor/d_a_player.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "SSystem/SComponent/c_lib.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 00000078-0000024C       .text get_check_pos__FP13kytag00_class */
cXyz get_check_pos(kytag00_class* i_this) {
    cXyz ret;

    camera_class * pCamera = (camera_class*)dComIfGp_getCamera(0);
    fopAc_ac_c * pPlayer = dComIfGp_getPlayer(0);

    f32 cameraDist = i_this->current.pos.abs(pCamera->mLookat.mEye);
    f32 playerDist = i_this->current.pos.abs(pPlayer->current.pos);

    if (dComIfGp_event_runCheck() && i_this->mMode == 0) {
        if (cameraDist < playerDist) {
            ret = pCamera->mLookat.mEye;
        } else {
            ret = pPlayer->current.pos;
        }
    } else {
        ret = pPlayer->current.pos;
    }

    return ret;
}

/* 0000024C-000005E4       .text wether_tag_move__FP13kytag00_class */
void wether_tag_move(kytag00_class* i_this) {
    cXyz chk_pos_xz;
    cXyz chk_pos = get_check_pos(i_this);
    f32 fade_y = i_this->mInnerFadeY * 100.0f;
    chk_pos_xz.x = chk_pos.x;
    chk_pos_xz.y = i_this->current.pos.y;
    chk_pos_xz.z = chk_pos.z;
    f32 dist_xz = i_this->current.pos.abs(chk_pos_xz);

    if (dist_xz < i_this->mOuterRadius &&
        (chk_pos.y >= (i_this->current.pos.y - fade_y) &&
        chk_pos.y < (i_this->current.pos.y + i_this->scale.y * 5000.0f + fade_y)) &&
        i_this->mTarget > 0.0f)
    {
        f32 blend = 1.0f;
        f32 f9 = 1.0f;
        f32 fade_radius = i_this->mOuterRadius - i_this->mInnerRadius;
        
        if (fade_radius != 0.0f) {
            blend = (i_this->mOuterRadius - dist_xz) / fade_radius;
            if (blend > 1.0f) {
                blend = 1.0f;
            }
        }
        
        if (chk_pos.y <= i_this->current.pos.y) {
            if (fade_y != 0.0f) {
                f9 = (i_this->current.pos.y - chk_pos.y) / fade_y;
                if (f9 < 0.0f) {
                    f9 = 0.0f;
                }
                f9 = 1.0f - f9;
            }
        } else {
            if (fade_y != 0.0f) {
                f9 = (chk_pos.y - (i_this->current.pos.y + i_this->scale.y * 5000.0f)) / fade_y;
                if (f9 < 0.0f) {
                    f9 = 0.0f;
                }
                f9 = 1.0f - f9;
            }
        }
        
        blend *= f9 * i_this->mTarget;
        
        if (g_env_light.mEnvrIdxPrev != g_env_light.mEnvrIdxCurr) {
            return;
        }
        i_this->mbPselSet = true;
        
        switch (i_this->mPselIdx) {
        case 0:
            g_env_light.mColpatPrevGather = g_env_light.mColpatWeather;
            g_env_light.mColpatCurrGather = 0;
            g_env_light.mColPatBlendGather = blend;
            g_env_light.mColPatModeGather = 1;
            break;
        case 1:
            if (blend > 0.5f) {
                g_env_light.mColpatPrevGather = g_env_light.mColpatWeather;
                g_env_light.mColpatCurrGather = 1;
                g_env_light.mColPatBlendGather = blend;
            } else {
                blend = 1.0f - blend;
                g_env_light.mColpatPrevGather = 1;
                g_env_light.mColpatCurrGather = g_env_light.mColpatWeather;
                g_env_light.mColPatBlendGather = blend;
            }
            g_env_light.mColPatModeGather = 1;
            break;
        case 2:
            if (blend > 0.5f) {
                g_env_light.mColpatPrevGather = g_env_light.mColpatWeather;
                g_env_light.mColpatCurrGather = 2;
                g_env_light.mColPatBlendGather = blend;
            } else {
                blend = 1.0f - blend;
                g_env_light.mColpatPrevGather = 2;
                g_env_light.mColpatCurrGather = g_env_light.mColpatWeather;
                g_env_light.mColPatBlendGather = blend;
            }
            g_env_light.mColPatModeGather = 1;
            break;
        case 3:
            if (blend > 0.5f) {
                g_env_light.mColpatPrevGather = g_env_light.mColpatWeather;
                g_env_light.mColpatCurrGather = 3;
                g_env_light.mColPatBlendGather = blend;
            } else {
                blend = 1.0f - blend;
                g_env_light.mColpatPrevGather = 3;
                g_env_light.mColpatCurrGather = g_env_light.mColpatWeather;
                g_env_light.mColPatBlendGather = blend;
            }
            g_env_light.mColPatModeGather = 1;
            break;
        default:
            i_this->mbPselSet = false;
            break;
        }
    } else {
        if (i_this->mbPselSet) {
            i_this->mbPselSet = false;
            g_env_light.mColpatPrevGather = g_env_light.mColpatWeather;
            g_env_light.mColpatCurrGather = g_env_light.mColpatWeather;
            g_env_light.mColPatBlendGather = 0.0f;
            g_env_light.mColPatModeGather = 1;
        }
    }
}

/* 000005E4-000006A0       .text raincnt_set__Ff */
void raincnt_set(f32 count) {
    s32 newCount = 0;

    if (dKy_checkEventNightStop()) {
        s32 newCount2;
        if (g_env_light.mRainCount < (newCount2 = (count * count * count) * 250.0f))
            newCount = newCount2;
    } else {
        newCount = (count * count * count) * 250.0f;
    }

    if (newCount > g_env_light.mRainCountOrig)
        g_env_light.mRainCount = newCount;
}

/* 000006A0-000006D8       .text raincnt_cut__Fv */
void raincnt_cut() {
    if (!dKy_checkEventNightStop())
        g_env_light.mRainCount = g_env_light.mRainCountOrig;
}

/* 000006D8-00000C0C       .text wether_tag_efect_move__FP13kytag00_class */
void wether_tag_efect_move(kytag00_class* i_this) {
    cXyz chk_pos_xz;
    cXyz chk_pos = get_check_pos(i_this);
    f32 fade_y = i_this->mInnerFadeY * 100.0f;
    chk_pos_xz.x = chk_pos.x;
    chk_pos_xz.y = i_this->current.pos.y;
    chk_pos_xz.z = chk_pos.z;
    f32 dist_xz = i_this->current.pos.abs(chk_pos_xz);
    
    if (dist_xz < i_this->mOuterRadius &&
        (chk_pos.y >= (i_this->current.pos.y - fade_y) &&
        chk_pos.y < (i_this->current.pos.y + i_this->scale.y * 5000.0f + fade_y)) &&
        i_this->mTarget > 0.0f)
    {
        f32 blend = 1.0f;
        f32 f9 = 1.0f;
        
        i_this->mbEfSet = 1;
        
        f32 fade_radius = i_this->mOuterRadius - i_this->mInnerRadius;
        
        if (fade_radius != 0.0f) {
            blend = (i_this->mOuterRadius - dist_xz) / fade_radius;
            if (blend > 1.0f) {
                blend = 1.0f;
            }
        }
        
        if (chk_pos.y <= i_this->current.pos.y) {
            if (fade_y != 0.0f) {
                f9 = (i_this->current.pos.y - chk_pos.y) / fade_y;
                if (f9 < 0.0f) {
                    f9 = 0.0f;
                }
                f9 = 1.0f - f9;
            }
        } else {
            if (fade_y != 0.0f) {
                f9 = (chk_pos.y - (i_this->current.pos.y + i_this->scale.y * 5000.0f)) / fade_y;
                if (f9 < 0.0f) {
                    f9 = 0.0f;
                }
                f9 = 1.0f - f9;
            }
        }
        
        blend *= f9 * i_this->mTarget;
        
        switch (i_this->mEfMode) {
        case 0x1:
            raincnt_set(blend);
            break;
        case 0x2:
            g_env_light.mSnowCount = 250.0f * blend;
            g_env_light.mMoyaMode = 2;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        case 0x3:
            g_env_light.mMoyaMode = 0;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        case 0x4:
            g_env_light.mMoyaMode = 1;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        case 0x5:
            g_env_light.mMoyaMode = 2;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        case 0x6:
            if (i_this->home.roomNo == dComIfGp_roomControl_getStayNo()) {
                g_env_light.mHousiCount = 300.0f * blend;
            } else {
                g_env_light.mHousiCount = 0;
            }
            break;
        case 0x7:
            if (g_env_light.mThunderEff.mMode == 0) {
                g_env_light.mThunderEff.mMode = 2;
            }
            break;
        case 0x8:
            if (g_env_light.mThunderEff.mMode == 0) {
                g_env_light.mThunderEff.mMode = 2;
            }
            raincnt_set(blend);
            break;
        case 0x9:
            g_env_light.mMoyaMode = 0;
            g_env_light.mMoyaCount = 100.0f * blend;
            raincnt_set(blend);
            if (g_env_light.mThunderEff.mMode == 0) {
                g_env_light.mThunderEff.mMode = 2;
            }
            break;
        case 0xA:
            g_env_light.mMoyaMode = 3;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        case 0xB:
            g_env_light.mMoyaMode = 4;
            g_env_light.mMoyaCount = 100.0f * blend;
            break;
        }
    } else if (i_this->mbEfSet != 0) {
        i_this->mbEfSet = 0;
        
        switch (i_this->mEfMode) {
        case 0x1:
            raincnt_cut();
            break;
        case 0x2:
            g_env_light.mSnowCount = 0;
            g_env_light.mMoyaCount = 0;
            break;
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xA:
            g_env_light.mMoyaCount = 0;
            break;
        case 0x6:
            g_env_light.mHousiCount = 0;
            break;
        case 0x7:
        case 0x8:
        case 0x9:
            if (g_env_light.mThunderEff.mMode == 2) {
                g_env_light.mThunderEff.mMode = 0;
            }
            if (i_this->mEfMode == 8 || i_this->mEfMode == 9) {
                raincnt_cut();
            }
            if (i_this->mEfMode == 9) {
                g_env_light.mMoyaCount = 0;
            }
            break;
        }
    }
}

/* 00000C0C-00000C30       .text daKytag00_Draw__FP13kytag00_class */
static BOOL daKytag00_Draw(kytag00_class* i_this) {
    wether_tag_efect_move(i_this);
    return TRUE;
}

/* 00000C30-00000D44       .text daKytag00_Execute__FP13kytag00_class */
static BOOL daKytag00_Execute(kytag00_class* i_this) {
    if (!i_this->mbInvert) {
        if (i_this->mSwitchNo != 0xFF && dComIfGs_isSwitch(i_this->mSwitchNo, dComIfGp_roomControl_getStayNo())) {
            cLib_addCalc(&i_this->mTarget, 0.0f, 0.1f, 0.01f, 0.0001f);
        } else {
            cLib_addCalc(&i_this->mTarget, 1.0f, 0.1f, 0.01f, 0.0001f);
        }
    } else {
        if (i_this->mSwitchNo != 0xFF && dComIfGs_isSwitch(i_this->mSwitchNo, dComIfGp_roomControl_getStayNo())) {
            cLib_addCalc(&i_this->mTarget, 1.0f, 0.1f, 0.01f, 0.0001f);
        } else {
            cLib_addCalc(&i_this->mTarget, 0.0f, 0.1f, 0.01f, 0.0001f);
        }
    }

    wether_tag_move(i_this);
    return TRUE;
}

/* 00000D44-00000D4C       .text daKytag00_IsDelete__FP13kytag00_class */
static BOOL daKytag00_IsDelete(kytag00_class* i_this) {
    return TRUE;
}

/* 00000D4C-00000D64       .text daKytag00_Delete__FP13kytag00_class */
static BOOL daKytag00_Delete(kytag00_class* i_this) {
    g_env_light.mMoyaCount = 0;
    return TRUE;
}

/* 00000D64-00000F8C       .text daKytag00_Create__FP10fopAc_ac_c */
static s32 daKytag00_Create(fopAc_ac_c* i_ac) {
    kytag00_class * i_this = (kytag00_class *)i_ac;

    fopAcM_SetupActor(i_this, kytag00_class);

    i_this->field_0x296 = 0;
    i_this->mPselIdx = (fopAcM_GetParam(i_ac) >> 0) & 0xFF;
    i_this->mEfMode = (fopAcM_GetParam(i_ac) >> 8) & 0xFF;
    i_this->mThickness = (fopAcM_GetParam(i_ac) >> 16) & 0xFF;
    i_this->mInnerFadeY = (fopAcM_GetParam(i_ac) >> 24) & 0xFF;
    i_this->mSwitchNo = (i_this->current.angle.x >> 0) & 0xFF;
    i_this->mbInvert = (i_this->current.angle.x >> 8) & 0xFF;
    i_this->mMode = (i_this->current.angle.z >> 0) & 0xFF;

    if (!i_this->mbInvert) {
        if (i_this->mSwitchNo != 0xFF && dComIfGs_isSwitch(i_this->mSwitchNo, dComIfGp_roomControl_getStayNo())) {
            i_this->mTarget = 0.0f;
        } else {
            i_this->mTarget = 1.0f;
        }
    } else {
        if (i_this->mSwitchNo != 0xFF && dComIfGs_isSwitch(i_this->mSwitchNo, dComIfGp_roomControl_getStayNo())) {
            i_this->mTarget = 1.0f;
        } else {
            i_this->mTarget = 0.0f;
        }
    }

    if (i_this->mThickness == 0xFF)
        i_this->mThickness = 10;

    if (i_this->mInnerFadeY == 0xFF)
        i_this->mInnerFadeY = 10;

    if (i_this->mMode == 0) {
        i_this->mInnerRadius = i_this->scale.x * 5000.0f;
        i_this->mOuterRadius = i_this->scale.x * 5000.0f + i_this->mThickness * 100.0f;
    } else {
        i_this->mInnerRadius = i_this->scale.x * 500.0f;
        i_this->mOuterRadius = i_this->scale.x * 500.0f + i_this->mThickness * 10.0f;
    }

    i_this->mbEfSet = false;
    i_this->mbPselSet = false;
    g_env_light.mMoyaCount = 0;
    wether_tag_efect_move(i_this);
    return cPhs_COMPLEATE_e;
}

actor_method_class l_daKytag00_Method = {
    (process_method_func)daKytag00_Create,
    (process_method_func)daKytag00_Delete,
    (process_method_func)daKytag00_Execute,
    (process_method_func)daKytag00_IsDelete,
    (process_method_func)daKytag00_Draw,
};

actor_process_profile_definition g_profile_KYTAG00 = {
    fpcLy_CURRENT_e,
    7,
    fpcPi_CURRENT_e,
    PROC_KYTAG00,
    &g_fpcLf_Method.base,
    sizeof(kytag00_class),
    0,
    0,
    &g_fopAc_Method.base,
    0xA0,
    &l_daKytag00_Method,
    fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
