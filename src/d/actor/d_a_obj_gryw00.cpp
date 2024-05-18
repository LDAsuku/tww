//
// Generated by dtk
// Translation Unit: d_a_obj_gryw00.cpp
//

#include "d/d_com_inf_game.h"
#include "d/d_particle.h"
#include "d/d_procname.h"

#include "d/actor/d_a_obj_gryw00.h"
#include "d/res/res_gryw00.h"

#define SPREAD_PHASE_ANIM_LEN 95
#define RISE_PHASE_ANIM_LEN 299
#define WATER_WAVE_GROWTH_SPEED 0.10526316
#define WATER_RISE_SPEED 1.6777408
#define WAVE_AMPLITUDE -10
#define HIGH_WATER_LEVEL 510
#define GEYSER_SOUND_LEN 310

namespace {
static const char l_arcname[] = "Gryw00";
}

/* 00000078-00000090       .text get_draw_water_lv__13daObjGryw00_cFPv */
f32 daObjGryw00_c::get_draw_water_lv(void* p) {
    daObjGryw00_c* actr = static_cast<daObjGryw00_c*>(p);
    return actr->home.pos.y + actr->mWaterLv + actr->mWaveAmplitude;
}

/* 00000090-00000168       .text setup_high_water_level_btk_anm__13daObjGryw00_cFv */
BOOL daObjGryw00_c::setup_high_water_level_btk_anm() {
    BOOL ret = TRUE;
    J3DAnmTextureSRTKey* btk_anm_p = static_cast<J3DAnmTextureSRTKey*>(dComIfG_getObjectRes(l_arcname, GRYW00_BTK_GRYW00));
    JUT_ASSERT(223, btk_anm_p != 0);
    if (!mBtk.init(mpModel->getModelData(), btk_anm_p, 1, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0x191, -1, -1, 0)) {
        ret = FALSE;
    }
    return ret;
}

/* 00000168-000002D0       .text particle_set__13daObjGryw00_cFv */
void daObjGryw00_c::particle_set() {
    cXyz homePos = this->home.pos;
    dComIfGp_particle_set(0x8295U, &homePos, NULL, NULL, 0xff, NULL, -1, NULL, &tevStr.mColorK0, NULL);
    dComIfGp_particle_set(0x8297U, &homePos, NULL, NULL, 0xff, NULL, -1, NULL, &tevStr.mColorK0, NULL);
    mpEmitters[0] = dComIfGp_particle_set(0x8296U, &homePos, NULL, NULL, 0xff, NULL, -1, NULL,
                                          &tevStr.mColorK0, NULL);
    mpEmitters[1] = dComIfGp_particle_set(0x8298U, &homePos, NULL, NULL, 0xff, NULL, -1, NULL,
                                          &tevStr.mColorK0, NULL);
}

/* 000002D0-00000338       .text particle_move__13daObjGryw00_cFv */
void daObjGryw00_c::particle_move() {
    cXyz waterPos(this->home.pos.x, this->home.pos.y + mWaterLv, this->home.pos.z);

    if (mpEmitters[0]) {
        mpEmitters[0]->setGlobalTranslation(waterPos);
    }
    if (mpEmitters[1]) {
        mpEmitters[1]->setGlobalTranslation(waterPos);
    }
}

/* 00000338-0000038C       .text particle_delete__13daObjGryw00_cFv */
void daObjGryw00_c::particle_delete() {
    if (mpEmitters[0]) {
        mpEmitters[0]->becomeInvalidEmitter();
        mpEmitters[0] = NULL;
    }
    if (mpEmitters[1]) {
        mpEmitters[1]->becomeInvalidEmitter();
        mpEmitters[1] = NULL;
    }
}

/* 0000038C-000004C4       .text set_se__13daObjGryw00_cFv */
void daObjGryw00_c::set_se() {
    if (mShouldPlaySe != TRUE) {
        return;
    }
    if (mWaterLv >= HIGH_WATER_LEVEL) {
        mShouldPlaySe = FALSE;
    }
    if (mGeyserSeRemaining > 0) {
        mGeyserSeRemaining--;
        fopAcM_seStartCurrent(this, JA_SE_OBJ_RDUN_MAE_GEYSER, 0);
    }
    fopAcM_seStartCurrent(this, JA_SE_OBJ_RDUN_MAE_W_OUT, 0);
    fopAcM_seStartCurrent(this, JA_SE_OBJ_RDUN_MAE_W_UP, 0);
}

/* 000004C4-00000654       .text CreateHeap__13daObjGryw00_cFv */
int daObjGryw00_c::CreateHeap() {
    BOOL ret = TRUE;
    J3DModelData* mdlData = static_cast<J3DModelData*>(dComIfG_getObjectRes(l_arcname, GRYW00_BDL_GRYW00));
    J3DAnmTextureSRTKey* pbtk = static_cast<J3DAnmTextureSRTKey*>(dComIfG_getObjectRes(l_arcname, GRYW00_BTK_GRYW00));
    J3DAnmTransform* pbck = static_cast<J3DAnmTransform*>(dComIfG_getObjectRes(l_arcname, GRYW00_BCK_GRYW00));
    if (!mdlData || !pbtk || !pbck) {
        JUT_PANIC(409);
        ret = FALSE;
    } else {
        mpModel = mDoExt_J3DModel__create(mdlData, 0x80000U, 0x11000222U);
        BOOL btk_inited = mBtk.init(mpModel->getModelData(), pbtk, TRUE,
                                    J3DFrameCtrl::LOOP_ONCE_e, 0.0f, 0, 0x190, FALSE, 0);
        BOOL bck_inited = mBck.init(mpModel->getModelData(), pbck, TRUE,
                                    J3DFrameCtrl::LOOP_ONCE_e, 0.0f, 0, -1, FALSE);
        if (!mpModel || !btk_inited || !bck_inited) {
            ret = FALSE;
        }
    }
    return ret;
}

/* 00000654-000007D4       .text Create__13daObjGryw00_cFv */
int daObjGryw00_c::Create() {
    mActivationSwitch = param_get_swSave();
    mWaterLvFinalYPos = HIGH_WATER_LEVEL + home.pos.y;
    if (mActivationSwitch != 0xff && fopAcM_isSwitch(this, mActivationSwitch) == TRUE) {
        /* Puzzle already solved on load, water already high, only static animation */
        setup_high_water_level_btk_anm();
        mBck.setFrame(RISE_PHASE_ANIM_LEN);
        mIsHidden = FALSE;

        modeFunc = &high_water_level_act_proc;

        mWaterLv = HIGH_WATER_LEVEL;
        mWaterMaxLv = HIGH_WATER_LEVEL;

        mWaveAmplitude = WAVE_AMPLITUDE;
        mWaveMaxAmplitude = WAVE_AMPLITUDE;
    } else {
        /* Waiting state until puzzle is solved */
        mIsHidden = TRUE;

        modeFunc = &switch_wait_act_proc;
        mWaterLv = -5;
        mWaterMaxLv = -5;

        mWaveAmplitude = 0;
        mWaveMaxAmplitude = 0;
    }
    mpModel->setBaseScale(this->scale);
    mDoMtx_stack_c::transS(this->home.pos.x,
                           this->home.pos.y + mWaterLv + mWaveAmplitude,
                           this->home.pos.z);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    return TRUE;
}

/* 000007D4-0000090C       .text Mthd_Create__13daObjGryw00_cFv */
s32 daObjGryw00_c::Mthd_Create() {
    fopAcM_SetupActor(this, daObjGryw00_c);
    s32 phase_state = dComIfG_resLoad(&mPhs, l_arcname);

    if (phase_state == cPhs_COMPLEATE_e) {
        phase_state = MoveBGCreate(l_arcname, 0xf, dBgS_MoveBGProc_Trans, 0x9a0);
        JUT_ASSERT(519, (phase_state == cPhs_COMPLEATE_e) || (phase_state == cPhs_ERROR_e));
    }
    return phase_state;
}

/* 00000A0C-00000A30       .text Delete__13daObjGryw00_cFv */
BOOL daObjGryw00_c::Delete() {
    particle_delete();
    return TRUE;
}

/* 00000A30-00000A7C       .text Mthd_Delete__13daObjGryw00_cFv */
BOOL daObjGryw00_c::Mthd_Delete() {
    int res = MoveBGDelete();
    dComIfG_resDelete(&mPhs, l_arcname);
    return res;
}

/* 00000A7C-00000B50       .text switch_wait_act_proc__13daObjGryw00_cFv */
void daObjGryw00_c::switch_wait_act_proc() {
    if (mActivationSwitch == 0xff) {
        return;
    }
    if (!(fopAcM_isSwitch(this, mActivationSwitch) == TRUE)) {
        return;
    }
    mBtk.setPlaySpeed(1.0f);
    mBck.setPlaySpeed(1.0f);
    /* Waves get larger, water spreads, but water level stays still */
    mWaveAmplitudeIncrement = -WATER_WAVE_GROWTH_SPEED;
    mWaveMaxAmplitude = WAVE_AMPLITUDE;
    mWaterLvIncrement = WATER_WAVE_GROWTH_SPEED;
    mWaterMaxLv = 5;
    particle_set();
    mGeyserSeRemaining = GEYSER_SOUND_LEN;
    mShouldPlaySe = TRUE;
    mIsHidden = FALSE;
    modeFunc = &spread_water_face_act_proc;
}

/* 00000B50-00000BB0       .text spread_water_face_act_proc__13daObjGryw00_cFv */
void daObjGryw00_c::spread_water_face_act_proc() {
    if (mBtk.getFrameCtrl()->checkPass(START_PHASE_ANIM_LEN)) {
        modeFunc = &water_level_move_wait_act_proc;
    }
}

/* 00000BB0-00000C44       .text water_level_move_wait_act_proc__13daObjGryw00_cFv */
void daObjGryw00_c::water_level_move_wait_act_proc() {
    if (mBtk.getFrameCtrl()->checkPass(SPREAD_PHASE_ANIM_LEN)) {
        mWaterLvIncrement = WATER_RISE_SPEED;
        mWaterMaxLv = HIGH_WATER_LEVEL;
        modeFunc = &anime_loop_start_wait_act_proc;
        mBck.setPlaySpeed(0);
        mBck.setFrame(RISE_PHASE_ANIM_LEN);
    }
}

/* 00000C44-00000CD0       .text anime_loop_start_wait_act_proc__13daObjGryw00_cFv */
void daObjGryw00_c::anime_loop_start_wait_act_proc() {
    if (mBtk.isStop()) {
        particle_delete();
        setup_high_water_level_btk_anm();
        modeFunc = &high_water_level_act_proc;
    }
}

/* 00000CD0-00000CD4       .text high_water_level_act_proc__13daObjGryw00_cFv */
void daObjGryw00_c::high_water_level_act_proc() {}

/* 00000CD4-00000E30       .text Execute__13daObjGryw00_cFPPA3_A4_f */
int daObjGryw00_c::Execute(Mtx** pMtx) {
    mWaveAmplitude += mWaveAmplitudeIncrement;
    if (mWaveAmplitude < mWaveMaxAmplitude) {
        mWaveAmplitude = mWaveMaxAmplitude;
        mWaveAmplitudeIncrement = 0;
    }
    mWaterLv += mWaterLvIncrement;
    if (mWaterLv > mWaterMaxLv) {
        mWaterLv = mWaterMaxLv;
        mWaterLvIncrement = 0;
    }

    f32 z_for_trans = this->home.pos.z;
    f32 draw_water_lv = get_draw_water_lv(this);
    mDoMtx_stack_c::transS(this->home.pos.x, draw_water_lv, z_for_trans);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    mDoMtx_stack_c::transS(this->home.pos.x, this->home.pos.y + mWaterLv, this->home.pos.z);
    mDoMtx_stack_c::scaleM(this->scale);
    cMtx_copy(mDoMtx_stack_c::get(), mMtx);
    *pMtx = &mMtx;

    particle_move();
    set_se();
    mBtk.play();
    mBck.play();

    (this->*modeFunc)();
    return TRUE;
}

/* 00000E30-00000ECC       .text Draw__13daObjGryw00_cFv */
BOOL daObjGryw00_c::Draw() {
    if (!mIsHidden) {
        g_env_light.settingTevStruct(TEV_TYPE_BG1, &this->current.pos, &tevStr);
        g_env_light.setLightTevColorType(mpModel, &tevStr);
        mBtk.entry(mpModel->getModelData());
        mBck.entry(mpModel->getModelData());
        mDoExt_modelUpdateDL(mpModel);
    }
    return TRUE;
}

/* 00000ECC-00000EEC       .text daObjGryw00_Create__FP13daObjGryw00_c */
static s32 daObjGryw00_Create(daObjGryw00_c* i_this) {
    return i_this->Mthd_Create();
}

/* 00000EEC-00000F0C       .text daObjGryw00_Delete__FP13daObjGryw00_c */
static BOOL daObjGryw00_Delete(daObjGryw00_c* i_this) {
    return i_this->Mthd_Delete();
}

/* 00000F0C-00000F2C       .text daObjGryw00_Execute__FP13daObjGryw00_c */
static BOOL daObjGryw00_Execute(daObjGryw00_c* i_this) {
    return i_this->MoveBGExecute();
}

/* 00000F2C-00000F58       .text daObjGryw00_Draw__FP13daObjGryw00_c */
static BOOL daObjGryw00_Draw(daObjGryw00_c* i_this) {
    return i_this->MoveBGDraw();
}

/* 00000F58-00000F84       .text daObjGryw00_IsDelete__FP13daObjGryw00_c */
static BOOL daObjGryw00_IsDelete(daObjGryw00_c* i_this) {
    return i_this->MoveBGIsDelete();
}

static actor_method_class l_daObjGryw00_Method = {
    (process_method_func)daObjGryw00_Create,
    (process_method_func)daObjGryw00_Delete,
    (process_method_func)daObjGryw00_Execute,
    (process_method_func)daObjGryw00_IsDelete,
    (process_method_func)daObjGryw00_Draw,
};

actor_process_profile_definition g_profile_Obj_Gryw00 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Gryw00,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjGryw00_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0055,
    /* Actor SubMtd */ &l_daObjGryw00_Method,
    /* Status       */ fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
