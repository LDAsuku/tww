//
// Generated by dtk
// Translation Unit: d_a_obj_Vteng.cpp
//

#include "d/actor/d_a_obj_Vteng.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

namespace {
    static const char l_arcname[] = "Vteng";
};

/* 00000078-00000120       .text init_mtx__12daObjVteng_cFv */
void daObjVteng_c::init_mtx() {
    mpModel->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::XYZrotM(shape_angle);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    mDoMtx_stack_c::scaleM(scale);
    MTXCopy(mDoMtx_stack_c::get(), mtx);
}

/* 00000120-00000144       .text solidHeapCB__12daObjVteng_cFP10fopAc_ac_c */
BOOL daObjVteng_c::solidHeapCB(fopAc_ac_c* i_this) {
    return ((daObjVteng_c*)i_this)->create_heap();
}

/* 00000144-000002C4       .text create_heap__12daObjVteng_cFv */
bool daObjVteng_c::create_heap() {
    bool ret = true;

    J3DModelData* pModelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(l_arcname, 0x08));
    J3DAnmTransform * pAnm = (J3DAnmTransform *)dComIfG_getObjectRes(l_arcname, 0x05);

    if (!pModelData || !pAnm) {
        JUT_ASSERT(0xb7, 0);
        ret = false;
    } else {
        mpMorf = new mDoExt_McaMorf(pModelData, NULL, NULL, pAnm, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0x3B, -1, 0, NULL, 0x00, 0x11020203);
        if (!mpMorf) {
            ret = false;
        } else {
            J3DModel * model = mpMorf->getModel();
            mpModel = model;
            mpBgW = dBgW_NewSet((cBgD_t*)dComIfG_getObjectRes(l_arcname, 0x0B), cBgW::MOVE_BG_e, &mtx);
            if (!mpBgW)
                ret = false;
        }
    }

    return ret;
}

/* 000002C4-00000324       .text jokai_demo__12daObjVteng_cFv */
bool daObjVteng_c::jokai_demo() {
    bool ret = false;

    if (dDemo_setDemoData(this, 0x60, mpMorf, "Vteng", 0, NULL, 0, 0) == TRUE)
        ret = true;

    return ret;
}

/* 00000324-000003F4       .text _create__12daObjVteng_cFv */
s32 daObjVteng_c::_create() {
    fopAcM_SetupActor(this, daObjVteng_c);

    s32 ret = dComIfG_resLoad(&mPhs, l_arcname);

    if (ret == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, solidHeapCB, 0x72a0)) {
            fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
            init_mtx();
            if (dComIfG_Bgsp()->Regist(mpBgW, this)) {
                ret = cPhs_ERROR_e;
            }
        } else {
            ret = cPhs_ERROR_e;
        }
    }

    return ret;
}

/* 000003F4-00000488       .text _delete__12daObjVteng_cFv */
bool daObjVteng_c::_delete() {
    dComIfG_resDelete(&mPhs, l_arcname);

    if (heap != NULL && mpBgW != NULL) {
        if (mpBgW->ChkUsed()) {
            dComIfG_Bgsp()->Release(mpBgW);
        }

        mpBgW = NULL;
    }

    return true;
}

/* 00000488-00000510       .text _execute__12daObjVteng_cFv */
bool daObjVteng_c::_execute() {
    if (mpBgW != NULL && mpBgW->ChkUsed())
        mpBgW->Move();
    if (!jokai_demo())
        mpMorf->play(NULL, 0, 0);
    return true;
}

/* 00000510-00000578       .text _draw__12daObjVteng_cFv */
bool daObjVteng_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG3, &current.pos, &tevStr);
    g_env_light.setLightTevColorType(mpModel, &tevStr);
    mpMorf->updateDL();
    fopAcM_SetModel(this, mpModel);
    return true;
}

/* 00000578-00000598       .text daObjVteng_Create__FP10fopAc_ac_c */
static s32 daObjVteng_Create(fopAc_ac_c* i_this) {
    return ((daObjVteng_c*)i_this)->_create();
}

/* 00000598-000005BC       .text daObjVteng_Delete__FP12daObjVteng_c */
static BOOL daObjVteng_Delete(daObjVteng_c* i_this) {
    return i_this->_delete();
}

/* 000005BC-000005E0       .text daObjVteng_Execute__FP12daObjVteng_c */
static BOOL daObjVteng_Execute(daObjVteng_c* i_this) {
    return i_this->_execute();
}

/* 000005E0-00000604       .text daObjVteng_Draw__FP12daObjVteng_c */
static BOOL daObjVteng_Draw(daObjVteng_c* i_this) {
    return i_this->_draw();
}

/* 00000604-0000060C       .text daObjVteng_IsDelete__FP12daObjVteng_c */
static BOOL daObjVteng_IsDelete(daObjVteng_c* i_this) {
    return TRUE;
}

static actor_method_class l_daObjVteng_Method = {
    (process_method_func)daObjVteng_Create,
    (process_method_func)daObjVteng_Delete,
    (process_method_func)daObjVteng_Execute,
    (process_method_func)daObjVteng_IsDelete,
    (process_method_func)daObjVteng_Draw,
};

actor_process_profile_definition g_profile_Obj_Vteng = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Vteng,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjVteng_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x005A,
    /* Actor SubMtd */ &l_daObjVteng_Method,
    /* Status       */ fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
