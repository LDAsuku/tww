//
// Generated by dtk
// Translation Unit: d_a_obj_dmgroom.cpp
//

#include "d/actor/d_a_obj_dmgroom.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

/* 00000078-00000098       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_this) {
    return ((daObjDmgroom_c*)i_this)->CreateHeap();
}

/* 00000098-000001FC       .text CreateHeap__14daObjDmgroom_cFv */
BOOL daObjDmgroom_c::CreateHeap() {
    J3DModelData* modelData = (J3DModelData*)(dComIfG_getObjectRes("Dmgroom", 0x04));
    JUT_ASSERT(0x52, modelData != 0);
    mpModel = mDoExt_J3DModel__create(modelData, 0x00, 0x11020203);
    if (!mpModel)
        return FALSE;

    J3DAnmTevRegKey* brk = (J3DAnmTevRegKey*)(dComIfG_getObjectRes("Dmgroom", 0x07));
    JUT_ASSERT(0x5c, brk != 0);
    if (!mBrkAnm.init(modelData, brk, true, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false, 0))
        return FALSE;

    return TRUE;
}

/* 000001FC-0000026C       .text CreateInit__14daObjDmgroom_cFv */
void daObjDmgroom_c::CreateInit() {
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    fopAcM_setCullSizeBox(this, -600.0f, -0.0f, -600.0f, 600.0f, 900.0f, 600.0f);
    fopAcM_setCullSizeFar(this, 1.0f);
    set_mtx();
}

/* 0000026C-000002EC       .text set_mtx__14daObjDmgroom_cFv */
void daObjDmgroom_c::set_mtx() {
    mpModel->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(current.angle.y);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

s32 daObjDmgroom_c::_create() {
    fopAcM_SetupActor(this, daObjDmgroom_c);

    s32 ret = dComIfG_resLoad(&mPhs, "Dmgroom");

    if (ret == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, CheckCreateHeap, 0x1460) == 0) {
            ret = cPhs_ERROR_e;
        } else {
            CreateInit();
        }
    }

    return ret;
}

bool daObjDmgroom_c::_delete() {
    dComIfG_resDelete(&mPhs, "Dmgroom");
    return true;
}

bool daObjDmgroom_c::_execute() {
    if (demoActorID != 0) {
        dDemo_actor_c * demoAc = dComIfGp_demo_getActor(demoActorID);
        if (demoAc != NULL && demoAc->checkEnable(0x40))
            mBrkAnm.setFrame(demoAc->mAnimationFrame);
    }
    set_mtx();
    return true;
}

bool daObjDmgroom_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &tevStr);
    g_env_light.setLightTevColorType(mpModel, &tevStr);
    dComIfGd_setListBG();
    mBrkAnm.entry(mpModel->getModelData());
    mDoExt_modelUpdateDL(mpModel);
    mBrkAnm.remove(mpModel->getModelData());
    dComIfGd_setList();
    return true;
}

/* 000002EC-000003B4       .text daObjDmgroom_Create__FPv */
static s32 daObjDmgroom_Create(void* i_this) {
    return ((daObjDmgroom_c*)i_this)->_create();
}

/* 00000458-00000488       .text daObjDmgroom_Delete__FPv */
static BOOL daObjDmgroom_Delete(void* i_this) {
    return ((daObjDmgroom_c*)i_this)->_delete();
}

/* 00000488-00000558       .text daObjDmgroom_Draw__FPv */
static BOOL daObjDmgroom_Draw(void* i_this) {
    return ((daObjDmgroom_c*)i_this)->_draw();
}

/* 00000558-000005CC       .text daObjDmgroom_Execute__FPv */
static BOOL daObjDmgroom_Execute(void* i_this) {
    return ((daObjDmgroom_c*)i_this)->_execute();
}

/* 000005CC-000005D4       .text daObjDmgroom_IsDelete__FPv */
static BOOL daObjDmgroom_IsDelete(void* i_this) {
    return TRUE;
}

static actor_method_class daObj_DmgroomMethodTable = {
    (process_method_func)daObjDmgroom_Create,
    (process_method_func)daObjDmgroom_Delete,
    (process_method_func)daObjDmgroom_Execute,
    (process_method_func)daObjDmgroom_IsDelete,
    (process_method_func)daObjDmgroom_Draw,
};

actor_process_profile_definition g_profile_Obj_Dmgroom = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Dmgroom,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjDmgroom_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x001D,
    /* Actor SubMtd */ &daObj_DmgroomMethodTable,
    /* Status       */ fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
