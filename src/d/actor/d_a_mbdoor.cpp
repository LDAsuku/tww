//
// Generated by dtk
// Translation Unit: d_a_mbdoor.cpp
//

#include "d/actor/d_a_mbdoor.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "d/actor/d_a_player.h"

enum MBDOOR_RES_FILE_ID { // IDs and indexes are synced
    /* BDL */
    MBDOOR_BDL_S_MBD_L=0x4,
    MBDOOR_BDL_S_MBD_R=0x5,
    MBDOOR_BDL_S_MBDFU=0x6,
    MBDOOR_BDL_S_MBDTO=0x7,
    
    /* DZB */
    MBDOOR_DZB_S_MBDFU=0xA,
};

enum GBDOOR_RES_FILE_ID { // IDs and indexes are synced
    /* BDL */
    GBDOOR_BDL_V_GBD_L=0x4,
    GBDOOR_BDL_V_GBD_R=0x5,
    GBDOOR_BDL_V_GBDFU=0x6,
    GBDOOR_BDL_V_GBDTO=0x7,
    
    /* DZB */
    GBDOOR_DZB_GBD=0xA,
};

/* 00000078-00000084       .text getSwbit__10daMbdoor_cFv */
u8 daMbdoor_c::getSwbit() {
    return fopAcM_GetParam(this) & 0xFF;
}

/* 00000084-00000090       .text getType__10daMbdoor_cFv */
u8 daMbdoor_c::getType() {
    return home.angle.z & 0x3F;
}

/* 00000090-0000009C       .text getShapeType__10daMbdoor_cFv */
u8 daMbdoor_c::getShapeType() {
    return (fopAcM_GetParam(this) & 0x00000F00) >> 0x08;
}

/* 0000009C-000000E4       .text getArcName__10daMbdoor_cFv */
const char* daMbdoor_c::getArcName() {
    switch (getShapeType()) {
    case 1:
        return "Gbdoor";
    default:
        return "Mbdoor";
    }
}

/* 000000E4-00000120       .text getFuBdl__10daMbdoor_cFv */
u32 daMbdoor_c::getFuBdl() {
    switch (getShapeType()) {
    case 1:
        return GBDOOR_BDL_V_GBDFU;
    default:
        return MBDOOR_BDL_S_MBDFU;
    }
}

/* 00000120-0000015C       .text getLBdl__10daMbdoor_cFv */
u32 daMbdoor_c::getLBdl() {
    switch (getShapeType()) {
    case 1:
        return GBDOOR_BDL_V_GBD_L;
    default:
        return MBDOOR_BDL_S_MBD_L;
    }
}

/* 0000015C-00000198       .text getRBdl__10daMbdoor_cFv */
u32 daMbdoor_c::getRBdl() {
    switch (getShapeType()) {
    case 1:
        return GBDOOR_BDL_V_GBD_R;
    default:
        return MBDOOR_BDL_S_MBD_R;
    }
}

/* 00000198-000001D4       .text getToBdl__10daMbdoor_cFv */
u32 daMbdoor_c::getToBdl() {
    switch (getShapeType()) {
    case 1:
        return GBDOOR_BDL_V_GBDTO;
    default:
        return MBDOOR_BDL_S_MBDTO;
    }
}

/* 000001D4-00000210       .text getDzb__10daMbdoor_cFv */
u32 daMbdoor_c::getDzb() {
    switch (getShapeType()) {
    case 1:
        return GBDOOR_DZB_GBD;
    default:
        return MBDOOR_DZB_S_MBDFU;
    }
}

/* 00000210-00000254       .text getLOffset__10daMbdoor_cFv */
f32 daMbdoor_c::getLOffset() {
    switch (getShapeType()) {
    case 1:
        return -300.0f;
    default:
        return -255.0f;
    }
}

/* 00000254-00000298       .text getROffset__10daMbdoor_cFv */
f32 daMbdoor_c::getROffset() {
    switch (getShapeType()) {
    case 1:
        return 300.0f;
    default:
        return 277.0f;
    }
}

/* 00000298-000002DC       .text getToOffset__10daMbdoor_cFv */
f32 daMbdoor_c::getToOffset() {
    switch (getShapeType()) {
    case 1:
        return 335.0f;
    default:
        return 300.0f;
    }
}

/* 000002DC-000002FC       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_this) {
    return ((daMbdoor_c*)i_this)->CreateHeap();
}

/* 000002FC-0000060C       .text CreateHeap__10daMbdoor_cFv */
BOOL daMbdoor_c::CreateHeap() {
    J3DModelData* modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(getArcName(), getFuBdl()));
    JUT_ASSERT(198, modelData != 0)
    mpFuModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    if (!mpFuModel) { return FALSE; }
    
    modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(getArcName(), getLBdl()));
    JUT_ASSERT(209, modelData != 0)
    mpLModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    if (!mpLModel) { return FALSE; }
    
    modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(getArcName(), getRBdl()));
    JUT_ASSERT(220, modelData != 0)
    mpRModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    if (!mpRModel) { return FALSE; }
    
    modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(getArcName(), getToBdl()));
    JUT_ASSERT(231, modelData != 0)
    mpToModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    if (!mpToModel) { return FALSE; }
    
    mpBgW = new dBgW();
    if (!mpBgW) { return FALSE; }
    cBgD_t* dzbData = (cBgD_t*)dComIfG_getObjectRes(getArcName(), getDzb());
    if (!dzbData) { return FALSE; }
    calcMtx();
    bool error = mpBgW->Set(dzbData, cBgW::MOVE_BG_e, &mpFuModel->getBaseTRMtx());
    return error != true ? TRUE : FALSE;
}

/* 0000060C-00000898       .text calcMtx__10daMbdoor_cFv */
void daMbdoor_c::calcMtx() {
    // Transform the door's frame.
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(home.angle.y);
    mpFuModel->setBaseTRMtx(mDoMtx_stack_c::get());
    
    cXyz offset;
    offset.set(0.0f, 0.0f, -150.0f);
    mDoMtx_stack_c::multVec(&offset, &mGoalPos);
    offset.set(0.0f, 0.0f, -400.0f);
    mDoMtx_stack_c::multVec(&offset, &mGoal2Pos);
    
    // Transform door's right half.
    if (field_0x2ad == 0) {
        mpLModel->setBaseTRMtx(mDoMtx_stack_c::get());
        if (field_0x2b2 != 0) {
            mDoMtx_stack_c::transM(getROffset(), 0.0f, 0.0f);
            mDoMtx_stack_c::YrotM(field_0x2b2);
            mDoMtx_stack_c::transM(-getROffset(), 0.0f, 0.0f);
        }
        offset.set(80.0f, 0.0f, 75.0f);
        mDoMtx_stack_c::multVec(&offset, &field_0x2c4);
    }
    mpRModel->setBaseTRMtx(mDoMtx_stack_c::get());
    
    // Transform door's left half.
    if (field_0x2ad == 1) {
        if (field_0x2b2 != 0) {
            mDoMtx_stack_c::transM(getLOffset(), 0.0f, 0.0f);
            mDoMtx_stack_c::YrotM(-field_0x2b2);
            mDoMtx_stack_c::transM(-getLOffset(), 0.0f, 0.0f);
        }
        offset.set(-80.0f, 0.0f, 75.0f);
        mDoMtx_stack_c::multVec(&offset, &field_0x2c4);
        mpLModel->setBaseTRMtx(mDoMtx_stack_c::get());
    }
    
    // Transform door's bar.
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(home.angle.y);
    if (field_0x2b0) {
        mDoMtx_stack_c::transM(getToOffset(), 231.0f, 0.0f);
        mDoMtx_stack_c::ZrotM(field_0x2b0);
        mDoMtx_stack_c::transM(-getToOffset(), -231.0f, 0.0f);
    }
    mpToModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

/* 00000898-00000A44       .text CreateInit__10daMbdoor_cFv */
BOOL daMbdoor_c::CreateInit() {
    s32 swbit = getSwbit();
    s32 type = getType();
    
    if (dComIfG_Bgsp()->Regist(mpBgW, this)) {
        JUT_ASSERT(334, 0);
    }
    field_0x2ac = true;
    tevStr.mRoomNo = current.roomNo;
    
    if (type == 2) {
        setAction(1);
        field_0x2b0 = 0;
        field_0x2b2 = 0;
    } else if ((type == 0 && (swbit != 0xFF && !dComIfGs_isSwitch(swbit, fopAcM_GetRoomNo(this)))) ||
               (type == 1 && (swbit == 0xFF || dComIfGs_isSwitch(swbit, fopAcM_GetRoomNo(this))))) {
        setAction(1);
        field_0x2b0 = 0;
        field_0x2b2 = 0;
    } else {
        setAction(4);
        field_0x2b0 = -0x3F65;
        field_0x2b2 = 0;
    }
    
    field_0x2bc = 30;
    attention_info.position.y += 250.0f;
    eyePos.y += 250.0f;
    attention_info.flags = fopAc_Attn_ACTION_DOOR_e;
    calcMtx();
    mpBgW->Move();
    fopAcM_SetStatusMap(this, 0xB);
    
    return TRUE;
}

/* 00000A44-00000AF4       .text create__10daMbdoor_cFv */
s32 daMbdoor_c::create() {
    s32 phase_state = dComIfG_resLoad(&mPhs, getArcName());
    
    fopAcM_SetupActor(this, daMbdoor_c);
    
    if (phase_state != cPhs_COMPLEATE_e) {
        return phase_state;
    }
    if (!fopAcM_entrySolidHeap(this, CheckCreateHeap, 0x8200)) {
        return cPhs_ERROR_e;
    }
    
    CreateInit();
    
    return cPhs_COMPLEATE_e;
}

/* 00000AF4-00000B3C       .text getDemoAction__10daMbdoor_cFv */
s32 daMbdoor_c::getDemoAction() {
    static char* action_table[] = {
        "WAIT",
        "SET_START",
        "SET_ANGLE",
        "END",
        "OPEN",
        "STOP_OPEN",
        "SET_GOAL",
        "SET_GOAL2",
        "ADJUSTMENT",
    };
    
    return dComIfGp_evmng_getMyActIdx(mEvtStaffId, action_table, ARRAY_SIZE(action_table), 0, 0);
}

/* 00000B3C-00000F78       .text demoProc__10daMbdoor_cFv */
void daMbdoor_c::demoProc() {
    // Explicit cast from daPy_py_c to daPy_py_c necessary for matching regalloc.
    daPy_py_c* player = (daPy_py_c*)daPy_getPlayerActorClass();
    s32 actIdx = getDemoAction();
    cXyz goal;
    s16 angle;
    
    if (dComIfGp_evmng_getIsAddvance(mEvtStaffId)) {
        switch (actIdx) {
        case 1: // SET_START
            calcMtx();
            goal = field_0x2c4;
            dComIfGp_evmng_setGoal(&goal);
            break;
        case 2: // SET_ANGLE
            angle = current.angle.y + 0x7FFF;
            player->changeDemoMoveAngle(angle);
            break;
        case 4: // OPEN
            fopAcM_seStart(this, JA_SE_OBJ_MJ_GATE_OPEN, 0);
            field_0x2b4 = 0;
            break;
        case 5: // STOP_OPEN
            fopAcM_seStart(this, JA_SE_OBJ_MJ_GATE_BAR_OPEN, 0);
            field_0x2b4 = 0;
            field_0x2b6 = 1;
            break;
        case 6: // SET_GOAL
            goal = mGoalPos;
            dComIfGp_evmng_setGoal(&goal);
            break;
        case 7: // SET_GOAL2
            goal = mGoal2Pos;
            dComIfGp_evmng_setGoal(&goal);
            break;
        case 8: // ADJUSTMENT
            calcMtx();
            mAdjustmentTimer = 0;
            u32* timerP = dComIfGp_evmng_getMyIntegerP(mEvtStaffId, "Timer");
            if (timerP) {
                mAdjustmentTimer = *timerP;
            }
            break;
        }
    }
    
    switch (actIdx) {
    case 3: // END
        break;
    case 4: // OPEN
        if (field_0x2b4 < 250) {
            field_0x2b4 += 50;
        }
        s32 temp = field_0x2b2 - field_0x2b4;
        if (temp < -0x1C71) {
            field_0x2b2 = -0x1C71;
            dComIfGp_evmng_cutEnd(mEvtStaffId);
        } else {
            field_0x2b2 = temp;
        }
        calcMtx();
        if (field_0x2ad != 0) {
            angle = current.angle.y + 0x7FFF - field_0x2b2;
        } else {
            angle = current.angle.y + 0x7FFF + field_0x2b2;
        }
        player->setPlayerPosAndAngle(&field_0x2c4, angle);
        break;
    case 5: // STOP_OPEN
        if (field_0x2b6) {
            if (field_0x2b4 < 400) {
                field_0x2b4 += 40;
            }
            temp = field_0x2b0 - field_0x2b4;
            if (temp < -0x3F65) {
                field_0x2b0 = -0x3F65;
                dComIfGp_evmng_cutEnd(mEvtStaffId);
                field_0x2b6 = 0;
                fopAcM_seStart(this, JA_SE_OBJ_MJ_GATE_BAR_STOP, 0);
            } else {
                field_0x2b0 = temp;
            }
            calcMtx();
        } else {
            dComIfGp_evmng_cutEnd(mEvtStaffId);
        }
        break;
    case 8: // ADJUSTMENT
        angle = player->shape_angle.y;
        cLib_addCalcAngleS2(&angle, current.angle.y + 0x7FFF, 10, 0x800);
        goal = player->current.pos;
        goal.x = goal.x*0.9f + field_0x2c4.x*0.1f;
        goal.z = goal.z*0.9f + field_0x2c4.z*0.1f;
        player->setPlayerPosAndAngle(&goal, angle);
        if (mAdjustmentTimer > 0) {
            mAdjustmentTimer--;
        } else {
            dComIfGp_evmng_cutEnd(mEvtStaffId);
        }
        break;
    default:
        dComIfGp_evmng_cutEnd(mEvtStaffId);
        break;
    }
}

/* 00000F78-000010CC       .text checkArea__10daMbdoor_cFv */
BOOL daMbdoor_c::checkArea() {
    daPy_py_c* player = daPy_getPlayerActorClass();
    cXyz relPos1 = player->current.pos - home.pos;
    cXyz relPos2 = relPos1;
    relPos2.x = relPos1.z * cM_ssin(current.angle.y) - relPos1.x * cM_scos(current.angle.y);
    relPos2.z = relPos1.z * cM_scos(current.angle.y) + relPos1.x * cM_ssin(current.angle.y);
    
    if (relPos2.z > 160.0f) {
        return FALSE;
    }
    if (relPos2.x > 200.0f || relPos2.x < -200.0f) {
        return FALSE;
    }
    if (fopAcM_seenActorAngleY(player, this) > 0x2000) {
        return FALSE;
    }
    
    if (relPos2.x > 0.0f) {
        field_0x2ad = 1;
    } else {
        field_0x2ad = 0;
    }
    
    return TRUE;
}

/* 000010CC-00001198       .text checkUnlock__10daMbdoor_cFv */
BOOL daMbdoor_c::checkUnlock() {
    s32 swbit = getSwbit();
    switch (getType()) {
    case 0:
        return dComIfGs_isSwitch(swbit, fopAcM_GetRoomNo(this));
    case 1:
        if (!fopAcM_myRoomSearchEnemy(fopAcM_GetRoomNo(this))) {
            if (field_0x2bc > 0) {
                field_0x2bc--;
            } else {
                if (swbit != 0xFF) {
                    dComIfGs_onSwitch(swbit, fopAcM_GetRoomNo(this));
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

/* 00001198-000011BC       .text daMbdoor_actionWait__FP10daMbdoor_c */
BOOL daMbdoor_actionWait(daMbdoor_c* i_this) {
    i_this->calcMtx();
    return TRUE;
}

/* 000011BC-0000121C       .text daMbdoor_actionLockWait__FP10daMbdoor_c */
BOOL daMbdoor_actionLockWait(daMbdoor_c* i_this) {
    if (i_this->checkUnlock()) {
        i_this->setAction(2);
        fopAcM_orderOtherEvent2(i_this, "MBDOOR_STOP_OPEN", 1);
    }
    return TRUE;
}

/* 0000121C-000012AC       .text daMbdoor_actionLockOff__FP10daMbdoor_c */
BOOL daMbdoor_actionLockOff(daMbdoor_c* i_this) {
    if (i_this->eventInfo.checkCommandDemoAccrpt()) {
        i_this->mEvtStaffId = dComIfGp_evmng_getMyStaffId("MBDOOR");
        i_this->demoProc();
        i_this->setAction(3);
    } else {
        fopAcM_orderOtherEvent2(i_this, "MBDOOR_STOP_OPEN", 1);
    }
    return TRUE;
}

/* 000012AC-00001324       .text daMbdoor_actionLockDemo__FP10daMbdoor_c */
BOOL daMbdoor_actionLockDemo(daMbdoor_c* i_this) {
    if (dComIfGp_evmng_endCheck("MBDOOR_STOP_OPEN")) {
        dComIfGp_event_reset();
        i_this->setAction(4);
    } else {
        i_this->demoProc();
    }
    return TRUE;
}

/* 00001324-000013E4       .text daMbdoor_actionCloseWait__FP10daMbdoor_c */
BOOL daMbdoor_actionCloseWait(daMbdoor_c* i_this) {
    if (i_this->eventInfo.checkCommandDoor()) {
        i_this->mEvtStaffId = dComIfGp_evmng_getMyStaffId("MBDOOR");
        i_this->demoProc();
        i_this->setAction(5);
        dComIfG_Bgsp()->Release(i_this->mpBgW);
        i_this->field_0x2ac = false;
    } else {
        if (i_this->checkArea()) {
            i_this->eventInfo.setEventName("MBDOOR_OPEN");
            i_this->eventInfo.onCondition(dEvtCnd_CANDOOR_e);
        }
    }
    return TRUE;
}

/* 000013E4-00001408       .text daMbdoor_actionOpen__FP10daMbdoor_c */
BOOL daMbdoor_actionOpen(daMbdoor_c* i_this) {
    i_this->demoProc();
    return TRUE;
}

BOOL daMbdoor_c::draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &tevStr);
    
    g_env_light.setLightTevColorType(mpFuModel, &tevStr);
    mDoExt_modelUpdateDL(mpFuModel);
    
    g_env_light.setLightTevColorType(mpLModel, &tevStr);
    mDoExt_modelUpdateDL(mpLModel);
    
    g_env_light.setLightTevColorType(mpRModel, &tevStr);
    mDoExt_modelUpdateDL(mpRModel);
    
    g_env_light.setLightTevColorType(mpToModel, &tevStr);
    mDoExt_modelUpdateDL(mpToModel);
    
    return TRUE;
}

/* 00001408-000014BC       .text daMbdoor_Draw__FP10daMbdoor_c */
static BOOL daMbdoor_Draw(daMbdoor_c* i_this) {
    return i_this->draw();
}

BOOL daMbdoor_c::execute() {
    static ActionFunc* l_action[] = {
        &daMbdoor_actionWait,
        &daMbdoor_actionLockWait,
        &daMbdoor_actionLockOff,
        &daMbdoor_actionLockDemo,
        &daMbdoor_actionCloseWait,
        &daMbdoor_actionOpen,
    };
    
    dDemo_actor_c* demoActor = dComIfGp_demo_getActor(demoActorID);
    if (demoActor) {
        field_0x2ad = 0;
        if (demoActor->checkEnable(0x8)) {
            field_0x2b2 = demoActor->getRatate()->y;
            field_0x2b0 = demoActor->getRatate()->z;
        }
        calcMtx();
    } else {
        (l_action[mCurActionIdx])(this);
    }
    return TRUE;
}

/* 000014BC-00001558       .text daMbdoor_Execute__FP10daMbdoor_c */
static BOOL daMbdoor_Execute(daMbdoor_c* i_this) {
    return i_this->execute();
}

/* 00001558-00001560       .text daMbdoor_IsDelete__FP10daMbdoor_c */
static BOOL daMbdoor_IsDelete(daMbdoor_c* i_this) {
    return TRUE;
}

/* 00001560-000015D4       .text daMbdoor_Delete__FP10daMbdoor_c */
static BOOL daMbdoor_Delete(daMbdoor_c* i_this) {
    if (i_this->heap) {
        dComIfG_Bgsp()->Release(i_this->mpBgW);
    }
    dComIfG_resDelete(&i_this->mPhs, i_this->getArcName());
    i_this->~daMbdoor_c();
    return TRUE;
}

/* 000015D4-000015F4       .text daMbdoor_Create__FP10fopAc_ac_c */
static s32 daMbdoor_Create(fopAc_ac_c* i_this) {
    return ((daMbdoor_c*)i_this)->create();
}

static actor_method_class l_daMbdoor_Method = {
    (process_method_func)daMbdoor_Create,
    (process_method_func)daMbdoor_Delete,
    (process_method_func)daMbdoor_Execute,
    (process_method_func)daMbdoor_IsDelete,
    (process_method_func)daMbdoor_Draw,
};

actor_process_profile_definition g_profile_MBDOOR = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_MBDOOR,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daMbdoor_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0132,
    /* Actor SubMtd */ &l_daMbdoor_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_6_e,
};
