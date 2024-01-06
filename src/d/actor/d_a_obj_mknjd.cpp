//
// Generated by dtk
// Translation Unit: d_a_obj_mknjd.cpp
//

#include "d/actor/d_a_obj_mknjd.h"
#include "f_op/f_op_actor_mng.h"
#include "f_pc/f_pc_manager.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_draw_tag.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "JAZelAudio/JAIZelBasic.h"
#include "JAZelAudio/JAZelAudio_BGM.h"
#include "JAZelAudio/JAZelAudio_SE.h"
#include "SSystem/SComponent/c_xyz.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/d_bg_s_movebg_actor.h"
#include "d/d_bg_w.h"
#include "d/d_item.h"
#include "d/d_item_data.h"
#include "d/d_particle.h"
#include "d/actor/d_a_player.h"
#include "d/d_a_obj.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "dolphin/types.h"


#define ACT_SETGOAL 0
#define ACT_SETANGLE 1
#define ACT_WAIT 2
#define ACT_INPUT 3
#define ACT_BREAK 4
#define ACT_HIDE_LINK 5
#define ACT_DISP_LINK 6
#define ACT_LESSON 7
#define ACT_TACT 8

#define ID_EARTH_MDL 4
#define ID_BREAK_MDL 5
#define ID_WIND_MDL 6
#define ID_COL_DZB 9

static const char* daObjMknjD_jointName[] = {
    "Hahen1",
    "Hahen2",
    "Hahen3",
    "Hahen4",
    "Hahen5",
    "Hahen6",
    "Hahen7",
    "Hahen8",
    "Hahen9",
    "Hahen10",
    "Hahen11",
    "Hahen12",
    "Hahen13",
    "Hahen14",
    "Hahen15",
    "Hahen16",
    "Hahen17",
    "Hahen18",
    "Hahen19",
    "Hahen20"
};

char* daObjMknjD_EventName[] = {
    "MKNJD_D_DEMO",
    "MKNJD_K_DEMO",

    "MKNJD_D_CHECK",
    "MKNJD_K_CHECK",

    "MKNJD_D_ERROR",
    "MKNJD_K_ERROR",

    "MKNJD_D_LESSON",
    "MKNJD_K_LESSON",
};

static u16 joint_number_table[20];

Mtx daObjMknjD::Act_c::M_tmp_mtx;

/* 00000078-0000012C       .text nodeCallBackL__FP7J3DNodei */
static BOOL nodeCallBackL(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = static_cast<J3DJoint*>(i_node)->getJntNo();
        
        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mLeftHalfPos.x, actor->mLeftHalfPos.y, actor->mLeftHalfPos.z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return TRUE;
}

/* 0000012C-000001E0       .text nodeCallBackR__FP7J3DNodei */
static BOOL nodeCallBackR(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = static_cast<J3DJoint*>(i_node)->getJntNo();

        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mRightHalfPos.x, actor->mRightHalfPos.y, actor->mRightHalfPos.z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return TRUE;
}

/* 000001E0-000002B0       .text nodeCallBack_Hahen__FP7J3DNodei */
static BOOL nodeCallBack_Hahen(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = static_cast<J3DJoint*>(i_node)->getJntNo();
        u16 shardIdx = joint_number_table[jntNo - 1];

        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mShardPositions[shardIdx].x, actor->mShardPositions[shardIdx].y, actor->mShardPositions[shardIdx].z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return TRUE;
}

/* 000002B0-000002D0       .text daObjMknjD_XyCheckCB__FPvi */
static s16 daObjMknjD_XyCheckCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyCheckCB(i_param2);
}

/* 000002D0-000002F0       .text daObjMknjD_XyEventCB__FPvi */
static s16 daObjMknjD_XyEventCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyEventCB(i_param2);
}

/* 000002F0-00000314       .text XyCheckCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyCheckCB(int i_itemIdx) {
    return dComIfGp_getSelectItem(i_itemIdx) == WIND_TACT ? 1 : 0;
}

/* 00000314-0000031C       .text XyEventCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyEventCB(int) {
    return mLessonEventIdx;
}

/* 0000031C-00000620       .text CreateHeap__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::CreateHeap() {
    const void* temp_r26; // Fakematch to get it to use the same register for model_data_d and jntName
    if (m043E == true) {
        temp_r26 = dComIfG_getObjectRes(M_arcname, ID_WIND_MDL);
    }
    else {
        temp_r26 = dComIfG_getObjectRes(M_arcname, ID_EARTH_MDL);
    }

    J3DModelData* model_data_d = (J3DModelData*)temp_r26;
    J3DModelData* model_data_h = (J3DModelData*)dComIfG_getObjectRes(M_arcname, ID_BREAK_MDL);

    JUT_ASSERT(0x123, model_data_d != 0)
    JUT_ASSERT(0x124, model_data_h != 0)
    
    mMainMdl = mDoExt_J3DModel__create(model_data_d, 0x80000, 0x31000002);
    mBreakMdl = mDoExt_J3DModel__create(model_data_h, 0x80000, 0x11000002);

    if (mMainMdl != NULL && mBreakMdl != NULL) {
        JUTNameTab* nameTable = mMainMdl->getModelData()->getJointName();
        
        for (u16 i = 0; i < mMainMdl->getModelData()->getJointNum(); i++) {
            // const char* jntName = nameTable->getName(i);
            temp_r26 = nameTable->getName(i);

            if (strcmp("MknjL", (const char*)temp_r26) == 0) {
                mMainMdl->getModelData()->getJointNodePointer(i)->setCallBack(nodeCallBackL);
            }
            else if (strcmp("MknjR", (const char*)temp_r26) == 0) {
                mMainMdl->getModelData()->getJointNodePointer(i)->setCallBack(nodeCallBackR);
            }
        }

        mMainMdl->setUserArea(reinterpret_cast<u32>(this));

        int curTblIdx = 0;
        nameTable = mBreakMdl->getModelData()->getJointName();

        for (u16 i = 0; i < mBreakMdl->getModelData()->getJointNum(); i++) {
            // const char* jntName = nameTable->getName(i);
            temp_r26 = nameTable->getName(i);

            for (u16 j = 0; j < 20; j++) {
                if (strcmp(daObjMknjD_jointName[j], (const char*)temp_r26) == 0) {
                    mBreakMdl->getModelData()->getJointNodePointer(i)->setCallBack(nodeCallBack_Hahen);
                    joint_number_table[curTblIdx++] = j;

                    break;
                }
            }
        }

        mBreakMdl->setUserArea(reinterpret_cast<u32>(this));
        mMainMdlAlpha = 0xFF;

        return 1;
    }

    return 0;
}

/* 00000620-000008E8       .text Create__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Create() {
    fopAcM_SetMtx(this, mMainMdl->getBaseTRMtx());
    init_mtx();
    fopAcM_SetMtx(this, mBreakMdl->getBaseTRMtx());
    init_mtx();

    fopAcM_setCullSizeBox(this, -400.0f, -1.0f, -400.0f, 400.0f, 405.0f, 400.0f);

    mLeftHalfPos.setall(0.0f);
    mRightHalfPos.setall(0.0f);

    for (int i = 0; i < 20; i++) {
        mShardPositions[i].setall(0.0f);
        mShardHeights[i] = 0.0f;
    }

    m043D = false;
    mBreakTimer = 0;

    for (int i = 0; i < 4; i++) {
        mEmitters[i] = NULL;
    }

    if (m043E == true) {
        mCheckEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[3], 0xFF);
        mDemoEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[1], 0xFF);
        mErrorEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[5], 0xFF);
        mLessonEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[7], 0xFF);

        mTactMode = 4;
        mGiveItemNo = TACT_SONG5;
        mEvtInfo.setEventName("MKNJD_K_TALK");
        m0430 = 0x2910;
    }
    else {
        mCheckEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[2], 0xFF);
        mDemoEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[0], 0xFF);
        mErrorEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[4], 0xFF);
        mLessonEventIdx = dComIfGp_evmng_getEventIdx(daObjMknjD_EventName[6], 0xFF);

        mTactMode = 3;
        mGiveItemNo = TACT_SONG4;
        mEvtInfo.setEventName("MKNJD_D_TALK");
        m0430 = 0x2920;
    }

    mAttentionInfo.mDistances[1] = 0x3D;
    mAttentionInfo.mDistances[3] = 0x3D;
    mAttentionInfo.mFlags |= fopAc_Attn_ACTION_TALK_e | fopAc_Attn_TALKFLAG_CHECK_e;

    if (checkItemGet(mGiveItemNo, 1) == 0) {
        m043F = 8;
        mEvtInfo.mpCheckCB = daObjMknjD_XyCheckCB;
        mEvtInfo.mpEventCB = daObjMknjD_XyEventCB;
    }
    else {
        m043F = 0;
    }

    mMsgPtr = NULL;
    mMsgPID = fpcM_ERROR_PROCESS_ID_e;
    m0504 = false;

    return 1;
}

/* 000008E8-00000A84       .text Mthd_Create__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Create() {
    s32 phase_state;

    fopAcM_SetupActor(this, daObjMknjD::Act_c);

    m043E = prm_get_Type();

    int switchIdx = prm_get_swSave();
    if (fopAcM_isSwitch(this, switchIdx)) {
        mEmitters[2] = NULL;
        mEmitters[3] = NULL;

        return 3;
    }
    else {
        phase_state = dComIfG_resLoad(&mPhs, M_arcname);
        if (phase_state == cPhs_COMPLEATE_e) {
            phase_state = MoveBGCreate(M_arcname, ID_COL_DZB, NULL, 0x65A0);

            JUT_ASSERT(0x1CA, (phase_state == cPhs_COMPLEATE_e) || (phase_state == cPhs_ERROR_e))
        }
    }

    return phase_state;
}

/* 00000B64-00000BDC       .text Delete__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Delete() {
    dComIfGp_getAttention().mFlags &= 0x7fffffff;

    for (int i = 0; i < 4; i++) {
        mSmokeCBs[i].end();
    }

    return 1;
}

/* 00000BDC-00000C34       .text Mthd_Delete__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Delete() {
    int bgDeleteResult = MoveBGDelete();
    
    if (fpcM_CreateResult(this) != cPhs_UNK3_e) {
        dComIfG_resDelete(&mPhs, M_arcname);
    }

    return bgDeleteResult;
}

/* 00000C34-00000CC8       .text set_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::set_mtx() {
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::ZXYrotM(shape_angle);

    mMainMdl->setBaseTRMtx(mDoMtx_stack_c::get());
    mBreakMdl->setBaseTRMtx(mDoMtx_stack_c::get());

    mDoMtx_copy(mDoMtx_stack_c::get(), M_tmp_mtx);
}

/* 00000CC8-00000D28       .text init_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::init_mtx() {
    mMainMdl->setBaseScale(cXyz(1.0f, 1.0f, 1.0f));
    mBreakMdl->setBaseScale(cXyz(1.0f, 1.0f, 1.0f));

    set_mtx();
}

/* 00000D28-00000E04       .text setGoal__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setGoal(int i_staffIdx) {
    cXyz pos = *dComIfGp_evmng_getMyXyzP(i_staffIdx, "Posion");

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_YrotM(mDoMtx_stack_c::get(), current.angle.y);

    mDoMtx_stack_c::transM(pos);
    
    mDoMtx_multVecZero(mDoMtx_stack_c::get(), &pos);
    mGoalPos = pos;

    dComIfGp_evmng_setGoal(&mGoalPos);
}

/* 00000E04-00000E84       .text setPlayerAngle__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setPlayerAngle(int i_staffIdx) {
    u32 angle = *dComIfGp_evmng_getMyIntegerP(i_staffIdx, "angle");
    daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);
    
    player->setPlayerPosAndAngle(
        &player->current.pos,
        current.angle.y + (s16)angle
    );
}

/* 00000E84-00000F88       .text talk__Q210daObjMknjD5Act_cFi */
u16 daObjMknjD::Act_c::talk(int i_param1) {
    u16 msgMode = 0xFF;

    if (mMsgPID == fpcM_ERROR_PROCESS_ID_e) {
        if (i_param1 == 1) {
            u32 msgId;

            if (m0500 == 0) {
                g_dComIfG_gameInfo.play.mTactMode = mTactMode;
                msgId = 0x05B3;
            }
            else {
                msgId = 0x1901;
            }
            
            mMsgNo = msgId;
        }

        mMsgPID = fopMsgM_messageSet(mMsgNo, this);
        mMsgPtr = NULL;
    }
    else {
        if (mMsgPtr) {
            msgMode = mMsgPtr->mMode;

            if (msgMode == 0x0E) {
                if (g_dComIfG_gameInfo.play.field_0x4949 != 0) {
                    m0504 = true;
                    fopMsgM_messageSendOn();
                }

                mMsgPtr->mMode = 0x10;
            }
            else if (msgMode == 0x12) {
                mMsgPtr->mMode = 0x13;
                mMsgPID = fpcM_ERROR_PROCESS_ID_e;
            }
        }
        else {
            mMsgPtr = fopMsgM_SearchByID(mMsgPID);
        }
    }

    return msgMode;
}

/* 00000F88-00001348       .text privateCut__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::privateCut() {
    static char* cut_name_table[] = {
        "SETGOAL",
        "SETANGLE",
        "WAIT",
        "INPUT",
        "BREAK",
        "HIDE_LINK",
        "DISP_LINK",
        "LESSON",
        "TACT"
    };

    daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);

    int staffIdx = dComIfGp_evmng_getMyStaffId("MknjD");
    if (staffIdx != -1) {
        mActionIdx = dComIfGp_evmng_getMyActIdx(staffIdx, cut_name_table, ARRAY_SIZE(cut_name_table), 1, 0);

        if (mActionIdx == -1) {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        else {
            bool doCutEnd = false;
            
            if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
                switch (mActionIdx) {
                    case ACT_SETGOAL:
                        setGoal(staffIdx);
                        break;
                    case ACT_SETANGLE:
                        setPlayerAngle(staffIdx);
                        break;
                    case ACT_BREAK:
                        mDoAud_seStart(JA_SE_READ_RIDDLE_1);

                        int switchId = prm_get_swSave();
                        fopAcM_onSwitch(this, switchId);

                        mBreakTimer = 0;

                        if (mpBgW != NULL) {
                            if (mpBgW->ChkUsed()) {
                                dComIfG_Bgsp()->Release(mpBgW);
                            }
                        }

                        break;
                    case ACT_HIDE_LINK:
                        player->onPlayerNoDraw();
                        break;
                    case ACT_DISP_LINK:
                        player->offPlayerNoDraw();
                        break;
                    case ACT_LESSON:
                        m0504 = false;
                        m0500 = 0;
                        mMsgPID = fpcM_ERROR_PROCESS_ID_e;
                        break;
                    case ACT_TACT:
                        break;
                }
            }

            switch (mActionIdx) {
                case ACT_SETGOAL:
                    doCutEnd = true;
                    break;
                case ACT_SETANGLE:
                    doCutEnd = true;
                    break;
                case ACT_INPUT:
                    if (talk(1) == 0x12) {
                        doCutEnd = true;
                    }
                    break;
                case ACT_WAIT:
                    doCutEnd = true;
                    break;
                case ACT_BREAK:
                    if (daObjMknjD_break() == true) {
                        if (strcmp(dComIfGp_getStartStageName(), "Ekaze") == 0 || strcmp(dComIfGp_getStartStageName(), "Edaichi") == 0) {
                            mDoAud_bgmStart(JA_BGM_JABOO_CAVE);
                        }
                        else if (m043E == true) {
                            mDoAud_bgmStart(JA_BGM_D_WIND);
                        }
                        else {
                            mDoAud_bgmStart(JA_BGM_D_EARTH);
                        }

                        if (mSmokeCBs[2].getEmitter() != NULL) {
                            mSmokeCBs[2].end();
                        }
                        if (mSmokeCBs[3].getEmitter() != NULL) {
                            mSmokeCBs[3].end();
                        }

                        doCutEnd = true;
                    }
                    break;
                case ACT_LESSON:
                    u32 talkResult = talk(1);

                    if (talkResult == 0x12 || talkResult == 0x15) {
                        doCutEnd = true;
                    }
                    break;
                case ACT_TACT:
                    if (m0504 == false) {
                        doCutEnd = true;
                    }
                    else {
                        dComIfGp_event_reset();
                    }
                    break;
                default:
                    doCutEnd = true;
                    break;
            }

            if (doCutEnd) {
                dComIfGp_evmng_cutEnd(staffIdx);
            }
        }
    }
}

/* 00001348-00001400       .text manage_friend_draw__10daObjMknjDFi */
void daObjMknjD::manage_friend_draw(int i_param1) {
    fopAc_ac_c* judgeResult = fopAcM_SearchByName(PROC_NPC_MD);

    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            fopAcM_onDraw(judgeResult);
        } else {
            fopAcM_offDraw(judgeResult);
        }
    }

    judgeResult = fopAcM_SearchByName(PROC_NPC_CB1);
    
    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            fopAcM_onDraw(judgeResult);
        } else {
            fopAcM_offDraw(judgeResult);
        }
    }
}

/* 00001400-0000195C       .text daObjMknjD_break__Q210daObjMknjD5Act_cFv */
bool daObjMknjD::Act_c::daObjMknjD_break() {
    bool ret = false;
    mBreakTimer++;

    /* Statue splitting into left/right halves */
    // From 0 to 60 frames, the left and right halves of the statue split apart.
    if (mBreakTimer < 60) {
        mLeftHalfPos.x = -((mBreakTimer * 20.0) / 60.0);
        mRightHalfPos.x = (mBreakTimer * 20.0) / 60.0;
    }
    // After 60 frames, the halves stay at +/- 20 units on the X axis.
    else {
        mLeftHalfPos.x = -20.0f;
        mRightHalfPos.x = 20.0f;
    }

    /* Particles and sound effects */
    // After 1 frame, the particles for the statue splitting in half spawn.
    if (mBreakTimer == 1) {
        mEmitters[0] = dComIfGp_particle_set(0x8185, &current.pos, &current.angle);

        GXColor emitter2Color;
        emitter2Color.r = mTevStr.mColorC0.r;
        emitter2Color.g = mTevStr.mColorC0.g;
        emitter2Color.b = mTevStr.mColorC0.b;
        emitter2Color.a = mTevStr.mColorC0.a;
        
        mEmitters[1] = dComIfGp_particle_setProjection(0x8186, &current.pos, &current.angle, NULL, 0xFF, NULL, current.roomNo, &mTevStr.mColorK0, &emitter2Color);

        mEmitters[2] = dComIfGp_particle_setToon(0xA187, &current.pos, &current.angle, NULL, 0xFF, &mSmokeCBs[2]);
        mSmokeCBs[2].setRateOff(0);

        fopAcM_seStartCurrent(this, JA_SE_OBJ_SAGE_GATE_CREAK, 0);
    }
    // After 30 frames, the sound effect for the light beam particles coming from the statue plays.
    else if (mBreakTimer == 30) {
        fopAcM_seStartCurrent(this, JA_SE_OBJ_SAGE_GATE_LIGHT, 0);
    }
    // After 60 frames, the shards that the statue will crumble into begin moving to their initial locations.
    else if (mBreakTimer == 60) {
        m043D = true;

        for (int i = 0; i < 20; i++) {
            mShardPositions[i].setall(0.0f);

            if (i == 0x02 || i == 0x03 || i == 0x06 || i == 0x07 || i == 0x0A || i == 0x0D || i == 0x0E || i == 0x12 || i == 0x13) {
                mShardPositions[i].x += 20.0f;
            }
            else {
                mShardPositions[i].x -= 20.0f;
            }
        }
    }
    // After 160 frames, the particles for the statue shattering spawn.
    else if (mBreakTimer == 160) {
        dComIfGp_getVibration().StartShock(6, -0x21, cXyz(0.0f, 1.0f, 0.0f));

        fopAcM_seStartCurrent(this, JA_SE_OBJ_SAGE_GATE_BREAK, 0);

        mBrokenPos = current.pos;
        mBrokenPos.y += 350.0f;

        mEmitters[3] = dComIfGp_particle_setToon(0x2027, &mBrokenPos, &current.angle, NULL, 0xFF, &mSmokeCBs[3]);
        if (mEmitters[3] != NULL) {
            mEmitters[3]->setVolumeSweep(0.5f);
            mEmitters[3]->setLifeTime(0x2D);
            mEmitters[3]->setRate(50.0f);
            mEmitters[3]->setMaxFrame(1);

            JGeometry::TVec3<f32> vec;

            vec.set(3.0f, 3.0f, 3.0f);
            mEmitters[3]->setGlobalDynamicsScale(vec);

            vec.set(6.0f, 6.0f, 6.0f);
            mEmitters[3]->setGlobalParticleScale(vec);
        }
    }
    // After 255 frames, the cutscene ends.
    else if (mBreakTimer == 255) {
        ret = true;
    }

    /* Main (unbroken) model transparency */
    // From 0 to 60 frames, the main model is 100% visible.
    if (mBreakTimer < 60) {
        mMainMdlAlpha = 0xFF;
    }
    // From 60 to 160 frames, the main model's transparency is lowered to 0.
    else if (mBreakTimer >= 60 && mBreakTimer < 160) {
        f64 mdlAlpha = ((0xA0 - mBreakTimer) * 255.0) / 100.0;

        if (mdlAlpha >= 255.0) {
            mMainMdlAlpha = 0xFF;
        }
        else {
            mMainMdlAlpha = static_cast<u8>(mdlAlpha);
        }
    }
    // After 160 frames, the main model's transparency is 0.
    else {
        mMainMdlAlpha = 0;
    }

    /* Falling shards */
    // After 160 frames, the shards of the broken statue model begin to fall.
    if (mBreakTimer >= 160) {
        int fallingShardNum = 19 - (mBreakTimer - 160);

        if  (fallingShardNum < 0) {
            fallingShardNum = 0;
        }

        for (fallingShardNum; fallingShardNum < 20; fallingShardNum++) {
            mShardHeights[fallingShardNum] -= 2.0f;
            mShardPositions[fallingShardNum].y += mShardHeights[fallingShardNum];
        }
    }

    return ret;
}

/* 0000195C-000020E0       .text Execute__Q210daObjMknjD5Act_cFPPA3_A4_f */
int daObjMknjD::Act_c::Execute(Mtx** i_mtx) {
    daPy_py_c* player = static_cast<daPy_py_c*>(dComIfGp_getPlayer(0));
    daPy_py_c* partner = static_cast<daPy_py_c*>(dComIfGp_getCb1Player());

    switch (m043F) {
        case 0:
            mEvtInfo.onCondition(1);

            if (mEvtInfo.checkCommandTalk()) {
                m0500 = 1;
                m043F = 0x0B;
            }
            else if (player != NULL) {
                cXyz partnerDiff = current.pos - player->current.pos;

                s16 rotDiff = cM_atan2s(partnerDiff.x, partnerDiff.z) - current.angle.y;
                f32 absXZ = partnerDiff.absXZ();

                if (absXZ < 800.0f && (rotDiff < -0x4000 || rotDiff > 0x4000)) {
                    if (dComIfGp_checkPlayerStatus1(0, daPyStts1_WIND_WAKER_CONDUCT_e)) {
                        m043F = 1;
                        manage_friend_draw(0);
                    }
                }
            }

            break;
        case 1:
            if (m043E == 1) {
                player->setTactZev(fopAcM_GetID(this), 4, daObjMknjD_EventName[3]);
            }
            else {
                player->setTactZev(fopAcM_GetID(this), 3, daObjMknjD_EventName[2]);
            }

            m043F = 2;
            break;
        case 2:
            if (dComIfGp_evmng_startCheck(mCheckEventIdx) != 0) {
                if (partner != NULL && player != NULL) {
                    s16 rotDiff = cM_atan2s(current.pos.x - partner->current.pos.x, current.pos.z - partner->current.pos.z) - current.angle.y;
                    
                    cXyz diff = player->current.pos - partner->current.pos;
                    f32 absXZ = diff.absXZ();

                    if ((absXZ < 800.0f) && ((rotDiff < -0x4000) || (rotDiff > 0x4000))) {
                        fopAcM_orderChangeEventId(this, mDemoEventIdx, 0, 0xFFFF);
                        dComIfGs_onEventBit(m0430);

                        s16 procMedli = PROC_NPC_MD;
                        void* judgeResult = fopAcIt_Judge(fpcSch_JudgeForPName, &procMedli);

                        if (judgeResult != NULL) {
                            dComIfGp_event_setTalkPartner(judgeResult);
                        }

                        m043F = 6;
                    }
                    else {
                        fopAcM_orderChangeEventId(this, mErrorEventIdx, 0, 0xFFFF);

                        m043F = 3;
                        manage_friend_draw(1);
                    }
                }
                else {
                    fopAcM_orderChangeEventId(this, mErrorEventIdx, 0, 0xFFFF);

                    m043F = 3;
                    manage_friend_draw(1);
                }
            }
            else {
                if (!dComIfGp_checkPlayerStatus1(0, daPyStts1_WIND_WAKER_CONDUCT_e)) {
                    m043F = 0;
                    manage_friend_draw(1);
                }
            }

            break;
        case 3:
            if (mEvtInfo.checkCommandDemoAccrpt()) {
                m043F = 4;
            }

            break;
        case 4:
            if (dComIfGp_evmng_endCheck(mErrorEventIdx)) {
                dComIfGp_event_reset();
                m043F = 5;
            }

            break;
        case 5:
            if (!dComIfGp_checkPlayerStatus1(0, daPyStts1_WIND_WAKER_CONDUCT_e)) {
                m043F = 0;
            }

            break;
        case 6:
            if (mEvtInfo.checkCommandDemoAccrpt()) {
                m043F = 7;

                mDoAud_bgmStop(0x1E);
                mDoAud_taktModeMuteOff();

                dComIfGp_getAttention().mFlags |= 0x80000000;

                if (m043E == true) {
                    m0432 = 0x2B;
                    m0434 = 5;
                }
                else {
                    m0432 = 0x0E;
                    m0434 = 5;
                }
            }

            break;
        case 7:
            privateCut();

            if (dComIfGp_evmng_endCheck(mDemoEventIdx)) {
                dComIfGp_getAttention().mFlags &= ~0x80000000;
                dComIfGp_event_reset();

                fopAcM_delete(this);
            }

            break;
        case 8:
            mEvtInfo.onCondition(1);
            mEvtInfo.onCondition(32);

            if (mEvtInfo.checkCommandTalk()) {
                if (dComIfGp_event_chkTalkXY()) {
                    m0500 = 0;
                    m043F = 9;

#if VERSION != VERSION_JPN
                    fopAcM_seStart(this, JA_SE_PRE_TAKT, 0);
#endif
                }
                else {
                    m0500 = 1;
                    m043F = 11;
                }
            }

            break;
        case 9:
            m043F = 10;
            break;
        case 10:
            privateCut();

            if (g_dComIfG_gameInfo.play.mEvtCtrl.mMode == 0) {
                if (checkItemGet(mGiveItemNo, 1) != 0) {
                    m043F = 0;
                }
                else {
                    m043F = 8;
                }
            }

            break;
        case 11:
            player->onPlayerNoDraw();
            m043F = 12;
            break;
        case 12:
            if (talk(1) == 18) {
                player->offPlayerNoDraw();
                g_dComIfG_gameInfo.play.mEvtCtrl.mEventFlag |= 8;

                if (checkItemGet(mGiveItemNo, 1) != 0) {
                    m043F = 0;
                }
                else {
                    m043F = 8;
                }
            }
            break;
    }

    set_mtx();

    *i_mtx = &M_tmp_mtx;

    if (m0432 > 1) {
        m0432--;
    }
    if (m0432 == 1) {
        if (m043E == true) {
            mDoAud_bgmStart(JA_BGM_TAKT_MAKORE);
        }
        else {
            mDoAud_bgmStart(JA_BGM_TAKT_MEDRI);
        }

        m0432 = 0;
    }

    if (m0434 > 1) {
        m0434--;
    }
    if (m0434 == 1) {
        manage_friend_draw(1);
        m0434 = 0;
    }

    return 1;
}

/* 000020E0-000022FC       .text setMaterial__10daObjMknjDFP11J3DMaterialUc */
void daObjMknjD::setMaterial(J3DMaterial* i_mat, u8 i_alpha) {
    for (; i_mat != NULL; i_mat = i_mat->getNext()) {
        if (i_alpha == 0) {
            i_mat->getShape()->hide();
        }
        else {
            i_mat->getShape()->show();

            if (i_alpha == 0xFF) {
                i_mat->setMaterialMode(1);

                i_mat->getZMode()->setUpdateEnable(1);
                i_mat->getZMode()->setCompareEnable(1);

                i_mat->getBlend()->setType(0);
            }
            else {
                i_mat->setMaterialMode(1);

                i_mat->getZMode()->setUpdateEnable(0);
                i_mat->getZMode()->setCompareEnable(0);

                i_mat->getBlend()->setType(1);
                i_mat->getBlend()->setSrcFactor(4);
                i_mat->getBlend()->setDstFactor(5);
            }

            i_mat->getTevKColor(3)->mColor.a = i_alpha;
        }
    }
}

/* 000022FC-00002430       .text Draw__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(mBreakMdl, &mTevStr);

    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(mMainMdl, &mTevStr);

    dComIfGd_setListBG();

    J3DModelData* mdlData = mMainMdl->getModelData();
    u16 jointCount = mdlData->getJointNum();
    for (u16 i = 0; i < jointCount; i++) {
        setMaterial(mdlData->getJointNodePointer(i)->getMesh(), mMainMdlAlpha);
    }

    dComIfGd_setListSky();

    mDoExt_modelUpdateDL(mMainMdl);
    if (m043D == true) {
        mDoExt_modelUpdateDL(mBreakMdl);
    }

    dComIfGd_setList();

    return 1;
}

namespace daObjMknjD {
    namespace {
        /* 00002430-00002450       .text Mthd_Create__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Create(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Create();
        }

        /* 00002450-00002470       .text Mthd_Delete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Delete(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Delete();
        }

        /* 00002470-00002490       .text Mthd_Execute__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Execute(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGExecute();
        }

        /* 00002490-000024BC       .text Mthd_Draw__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Draw(void* i_this) {
            return static_cast<Act_c*>(i_this)->Draw();
        }

        /* 000024BC-000024E8       .text Mthd_IsDelete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_IsDelete(void* i_this) {
            return static_cast<Act_c*>(i_this)->IsDelete();
        }

        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

actor_process_profile_definition g_profile_Obj_MknjD = {
    fpcLy_CURRENT_e,
    3,
    fpcPi_CURRENT_e,
    PROC_Obj_MknjD,
    &g_fpcLf_Method.mBase,
    sizeof(daObjMknjD::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x01C6,
    &daObjMknjD::Mthd_Table,
    fopAcStts_CULL_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
