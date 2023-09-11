//
// Generated by dtk
// Translation Unit: d_a_item.cpp
//

#include "d/d_item.h"
#include "d/d_item_data.h"
#include "d/actor/d_a_item.h"
#include "d/actor/d_a_player.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "dolphin/types.h"

class dCcD_GObjInf;

/* 800F4BC8-800F4BD4       .text getData__12daItemBase_cFv */
daItemBase_c_m_data* daItemBase_c::getData() {
    return &daItemBase_c::m_data;
}

/* 800F4BD4-800F4C4C       .text setArrowTrans__Fs4cXyz */
void setArrowTrans(short, cXyz) {
    /* Nonmatching */
}

/* 800F4C4C-800F4CD8       .text getYOffset__8daItem_cFv */
float daItem_c::getYOffset() {
    switch (m_itemNo) {
    case HEART:
        return 0.0;
    case GREEN_RUPEE:
    case BLUE_RUPEE:
    case YELLOW_RUPEE:
    case RED_RUPEE:
    case PURPLE_RUPEE:
    case ORANGE_RUPEE:
    case SILVER_RUPEE:
        return 0.0;
    case KAKERA_HEART:
    case UTUWA_HEART:
        return 0.0;
    case SMALL_KEY:
    case BOSS_KEY:
        return 0.0;
    case SWORD:
        return 20.0;
    case SHIELD:
        return 23.0;
    case DROPPED_SWORD:
        return 10.0;
    case SKULL_NECKLACE:
        return 0.0;
    case BOKOBABA_SEED:
        return 0.0;
    case GOLDEN_FEATHER:
        return 0.0;
    case BOKO_BELT:
        return 0.0;
    case RED_JELLY:
    case GREEN_JELLY:
    case BLUE_JELLY:
        return 0.0;
    default:
        return 0.0;
    }
}

/* 800F4CD8-800F4E6C       .text set_mtx__8daItem_cFv */
void daItem_c::set_mtx() {
    /* Nonmatching */
}

/* 800F4E6C-800F4FDC       .text set_mtx_base__8daItem_cFP8J3DModel4cXyz5csXyz */
void daItem_c::set_mtx_base(J3DModel*, cXyz, csXyz) {
    /* Nonmatching */
}

/* 800F4FDC-800F5044       .text itemGetCallBack__FP10fopAc_ac_cP12dCcD_GObjInfP10fopAc_ac_cP12dCcD_GObjInf */
void itemGetCallBack(fopAc_ac_c*, dCcD_GObjInf*, fopAc_ac_c*, dCcD_GObjInf*) {
    /* Nonmatching */
}

/* 800F5044-800F53EC       .text CreateInit__8daItem_cFv */
void daItem_c::CreateInit() {
    /* Nonmatching */
}

/* 800F53EC-800F5668       .text _daItem_create__8daItem_cFv */
s32 daItem_c::_daItem_create() {
    /* Nonmatching */
}

/* 800F5668-800F5834       .text _daItem_execute__8daItem_cFv */
s32 daItem_c::_daItem_execute() {
    /* Nonmatching */
}

/* 800F5834-800F59CC       .text mode_proc_call__8daItem_cFv */
void daItem_c::mode_proc_call() {
    /* Nonmatching */
}

/* 800F59CC-800F5AFC       .text execInitNormalDirection__8daItem_cFv */
void daItem_c::execInitNormalDirection() {
    /* Nonmatching */
}

/* 800F5AFC-800F5BC8       .text execMainNormalDirection__8daItem_cFv */
void daItem_c::execMainNormalDirection() {
    /* Nonmatching */
}

/* 800F5BC8-800F5C68       .text execInitGetDemoDirection__8daItem_cFv */
void daItem_c::execInitGetDemoDirection() {
    /* Nonmatching */
}

/* 800F5C68-800F5CDC       .text execWaitGetDemoDirection__8daItem_cFv */
void daItem_c::execWaitGetDemoDirection() {
    /* Nonmatching */
}

/* 800F5CDC-800F5D44       .text execMainGetDemoDirection__8daItem_cFv */
void daItem_c::execMainGetDemoDirection() {
    /* Nonmatching */
}

/* 800F5D44-800F5D88       .text execBringNezumi__8daItem_cFv */
void daItem_c::execBringNezumi() {
    /* Nonmatching */
}

/* 800F5D88-800F5F40       .text execWaitMain__8daItem_cFv */
void daItem_c::execWaitMain() {
    /* Nonmatching */
}

/* 800F5F40-800F5FC0       .text execWaitMainFromBoss__8daItem_cFv */
void daItem_c::execWaitMainFromBoss() {
    /* Nonmatching */
}

/* 800F5FC0-800F60C0       .text scaleAnimFromBossItem__8daItem_cFv */
void daItem_c::scaleAnimFromBossItem() {
    /* Nonmatching */
}

/* 800F60C0-800F6110       .text _daItem_draw__8daItem_cFv */
s32 daItem_c::_daItem_draw() {
    /* Nonmatching */
}

/* 800F6110-800F61C8       .text setTevStr__8daItem_cFv */
void daItem_c::setTevStr() {
    /* Nonmatching */
}

/* 800F61C8-800F6268       .text _daItem_delete__8daItem_cFv */
s32 daItem_c::_daItem_delete() {
    /* Nonmatching */
}

/* 800F6268-800F6434       .text Reflect__FR4cXyzP4cXyzff */
void Reflect(cXyz&, cXyz*, float, float) {
    /* Nonmatching */
}

/* 800F6434-800F6D24       .text itemGetExecute__8daItem_cFv */
void daItem_c::itemGetExecute() {
    /* Nonmatching */
    execItemGet(m_itemNo);
}

/* 800F6D24-800F6D78       .text itemDefaultRotateY__8daItem_cFv */
void daItem_c::itemDefaultRotateY() {
    // Rotates at a fixed speed.
    s16 rotationSpeed = 0xFFFF / getData()->mNumFramesPerFullSpin;
    fopAcM_addAngleY(this, current.angle.y + rotationSpeed, rotationSpeed);
}

/* 800F6D78-800F6E54       .text checkItemDisappear__8daItem_cFv */
bool daItem_c::checkItemDisappear() {
    bool disappearing = true;
    if (mCurAction == 3) {
        disappearing = false;
        show();
    }
    if (mStatusFlags & 0x02) {
        disappearing = false;
    }
    if (mStatusFlags & 0x10) {
        disappearing = false;
    }
    if (dItem_data::item_info[m_itemNo].mSpecialBehaviors & 0x01) {
        disappearing = false;
    }
    if (g_dComIfG_gameInfo.play.mEvtCtrl.mMode != 0) {
        disappearing = false;
    }
    if (mCurAction == 4) {
        disappearing = false;
    }
    if ((mStatusFlags & 0x08) || (mStatusFlags & 0x40) || (mStatus & 0x100000)) {
        disappearing = false;
        show();
    }
    return disappearing;
}

/* 800F6E54-800F6E74       .text setItemTimer__8daItem_cFi */
void daItem_c::setItemTimer(int) {
    /* Nonmatching */
}

/* 800F6E74-800F6EC8       .text checkPlayerGet__8daItem_cFv */
bool daItem_c::checkPlayerGet() {
    /* Nonmatching */
}

/* 800F6EC8-800F7028       .text itemActionForRupee__8daItem_cFv */
void daItem_c::itemActionForRupee() {
    /* Nonmatching */
}

/* 800F7028-800F713C       .text itemActionForHeart__8daItem_cFv */
void daItem_c::itemActionForHeart() {
    /* Nonmatching */
}

/* 800F713C-800F72A4       .text itemActionForKey__8daItem_cFv */
void daItem_c::itemActionForKey() {
    /* Nonmatching */
}

/* 800F72A4-800F73A4       .text itemActionForEmono__8daItem_cFv */
void daItem_c::itemActionForEmono() {
    /* Nonmatching */
}

/* 800F73A4-800F7898       .text itemActionForSword__8daItem_cFv */
void daItem_c::itemActionForSword() {
    /* Nonmatching */
}

/* 800F7898-800F7AF0       .text itemActionForArrow__8daItem_cFv */
void daItem_c::itemActionForArrow() {
    /* Nonmatching */
}

/* 800F7AF0-800F7BF8       .text checkWall__8daItem_cFv */
void daItem_c::checkWall() {
    /* Nonmatching */
}

/* 800F7BF8-800F7DDC       .text set_bound_se__8daItem_cFv */
void daItem_c::set_bound_se() {
    /* Nonmatching */
}

/* 800F7DDC-800F7E6C       .text checkGetItem__8daItem_cFv */
s32 daItem_c::checkGetItem() {
    /* Nonmatching */
    if (checkPlayerGet()) {
        itemGetExecute();
        
        return 1;
    }
    
    mStatusFlags |= 0x08;
    return 0;
}

/* 800F7E6C-800F7F0C       .text timeCount__8daItem_cFv */
void daItem_c::timeCount() {
    /* Nonmatching */
}

/* 800F7F0C-800F7F50       .text mode_wait_init__8daItem_cFv */
void daItem_c::mode_wait_init() {
    /* Nonmatching */
}

/* 800F7F50-800F80CC       .text mode_water_init__8daItem_cFv */
void daItem_c::mode_water_init() {
    /* Nonmatching */
}

/* 800F80CC-800F844C       .text mode_wait__8daItem_cFv */
void daItem_c::mode_wait() {
    /* Nonmatching */
}

/* 800F844C-800F8528       .text mode_water__8daItem_cFv */
void daItem_c::mode_water() {
    /* Nonmatching */
}

/* 800F8528-800F8950       .text initAction__8daItem_cFv */
void daItem_c::initAction() {
    /* Nonmatching */
}

/* 800F8950-800F8970       .text daItem_Draw__FP8daItem_c */
void daItem_Draw(daItem_c*) {
    /* Nonmatching */
}

/* 800F8970-800F8990       .text daItem_Execute__FP8daItem_c */
s32 daItem_Execute(daItem_c* i_this) {
    return i_this->_daItem_execute();
}

/* 800F8990-800F89B0       .text daItem_IsDelete__FP8daItem_c */
s32 daItem_IsDelete(daItem_c* i_this) {
    return i_this->_daItem_isdelete();
}

/* 800F89B0-800F89D0       .text daItem_Delete__FP8daItem_c */
s32 daItem_Delete(daItem_c* i_this) {
    return i_this->_daItem_delete();
}

/* 800F89D0-800F89F0       .text daItem_Create__FP10fopAc_ac_c */
s32 daItem_Create(fopAc_ac_c* i_this) {
    /* Nonmatching */
}

/* 800F89F0-800F89F8       .text _daItem_isdelete__8daItem_cFv */
s32 daItem_c::_daItem_isdelete() {
    return 1;
}

/* 800F89F8-800F8A14       .text getHeadTopPos__9daPy_py_cCFv */
void daPy_py_c::getHeadTopPos() const {
    /* Nonmatching */
}

static actor_method_class l_daItem_Method = {
    (process_method_func)daItem_Create,
    (process_method_func)daItem_Delete,
    (process_method_func)daItem_Execute,
    (process_method_func)daItem_IsDelete,
    (process_method_func)daItem_Draw,
};

extern actor_process_profile_definition g_profile_ITEM = {
    -3,
    7,
    0xFFFD,
    PROC_ITEM,
    &g_fpcLf_Method.mBase,
    sizeof(daItem_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x00F5,
    &l_daItem_Method,
    0x000C0100,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
