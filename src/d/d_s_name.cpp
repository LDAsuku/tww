//
// Generated by dtk
// Translation Unit: d_s_name.cpp
//

#include "d/d_s_name.h"
#include "d/d_com_inf_game.h"
#include "d/d_com_lib_game.h"
#include "d/d_file_select.h"
#include "d/d_procname.h"
#include "d/d_menu_cloth.h"
#include "f_op/f_op_draw_iter.h"
#include "f_op/f_op_overlap_mng.h"
#include "f_op/f_op_scene_mng.h"
#include "m_Do/m_Do_audio.h"
#include "m_Do/m_Do_Reset.h"
#include "JSystem/J2DGraph/J2DOrthoGraph.h"
#include "JSystem/J2DGraph/J2DScreen.h"
#include "JSystem/JKernel/JKRExpHeap.h"

static Vec lit_2100 = {1.0f, 1.0f, 1.0f};
static Vec lit_2080 = {1.0f, 1.0f, 1.0f};

class dFile_error_c {
public:
    void _move();
};

dSn_HIO_c g_snHIO;

/* 8022F86C-8022F8F0       .text __ct__9dSn_HIO_cFv */
dSn_HIO_c::dSn_HIO_c() {
    field_0x5 = 20;
    field_0x6 = 15;
    field_0x7 = 30;
    field_0x8 = 0;
    field_0x9 = 0;
    field_0xa = 0;
    field_0xb = 0;
    field_0xe = 7;
    field_0xc = -200;
    field_0xf = 2;
    field_0x10 = 0;
    field_0x11 = 0;
    field_0x12 = 0;
    field_0x13 = 0;
    field_0x14 = 0;
    field_0x15 = 0;
    field_0x16 = 0;
    field_0x17 = 0;
    field_0x18 = 0;
    field_0x19 = 0;
    field_0x1a = 0;
    field_0x1b = 0;
}

/* 8022F8F0-8022F95C       .text phase_1__FPc */
static s32 phase_1(char* resName) {
    mDoAud_bgmStart(JA_BGM_SELECT);
    return !dComIfG_setStageRes(resName, NULL) ? cPhs_ERROR_e : cPhs_NEXT_e;
}

/* 8022F95C-8022F9B4       .text phase_2__FPc */
static s32 phase_2(char* resName) {
    s32 rt = dComIfG_syncStageRes(resName);
    if (rt < 0)
        return cPhs_ERROR_e;
    else if (rt > 0)
        return cPhs_INIT_e;
    return cPhs_NEXT_e;
}

/* 8022F9B4-8022F9BC       .text phase_3__FPc */
static s32 phase_3(char*) {
    return cPhs_COMPLEATE_e;
}

/* 8022F9BC-8022F9FC       .text resLoad__FP30request_of_phase_process_classPc */
s32 resLoad(request_of_phase_process_class* phase, char* resName) {
    static cPhs__Handler l_method[] = {
        (cPhs__Handler)phase_1,
        (cPhs__Handler)phase_2,
        (cPhs__Handler)phase_3,
    };
    if (phase->id == 2) {
        return cPhs_COMPLEATE_e;
    }
    return dComLbG_PhaseHandler(phase, l_method, resName);
}

/* 8022F9FC-802301C8       .text create__10dScnName_cFv */
s32 dScnName_c::create() {
    /* Nonmatching */
    dComIfGp_offEnableNextStage();
    dComIfGp_setNextStage("Name", 0, 0);
    dComIfGp_setStartStage(dComIfGp_getNextStartStage());
    dComIfGp_offEnableNextStage();

    s32 rt = resLoad(&mPhs, "Stage");
    if (rt == cPhs_COMPLEATE_e) {
        heap = JKRCreateExpHeap(0x68000, mDoExt_getGameHeap(), false);
        JUT_ASSERT(0x1c8, heap != 0);
    }

    oldHeap = mDoExt_setCurrentHeap(heap);
    mArchive = new JKRMemArchive();
    mArchive->mountFixed(dComIfG_getStageRes("Stage", 0x17), JKRMEMBREAK_FLAG_UNKNOWN0);
    cloth_create();
    buttonIconCreate();
    dFs_c = new dFile_select_c();
}

/* 802301C8-802301FC       .text cloth_create__10dScnName_cFv */
void dScnName_c::cloth_create() {
    cloth2D_create();
    field_0x55d = 0;
}

/* 802301FC-80230240       .text cloth_move__10dScnName_cFv */
void dScnName_c::cloth_move() {
    /* Nonmatching */
    if (field_0x55d && !g_snHIO.field_0xb)
        cloth.cloth_c->cloth_move();
}

/* 80230240-802302F8       .text cloth2D_create__10dScnName_cFv */
void dScnName_c::cloth2D_create() {
    /* Nonmatching */
    JKRArchive* clothRes = dComIfGp_getClothResArchive();
    cloth.cloth_c = new dMCloth_c();
    JUT_ASSERT(0x321, cloth.cloth_c != 0);
    cloth.cloth_c->setArchive(clothRes);
    cloth.cloth_c->setClothType(1); // ?
}

/* 802302F8-80230500       .text buttonIconCreate__10dScnName_cFv */
void dScnName_c::buttonIconCreate() {
    /* Nonmatching */
}

/* 80230500-802305E0       .text paneTransButtonIcon__10dScnName_cFsUcffUc */
void dScnName_c::paneTransButtonIcon(s16, u8, f32, f32, u8) {
    /* Nonmatching */
}

void (dScnName_c::*MainProc[])() = {
    &dScnName_c::MemCardCheckMain,
    &dScnName_c::NoteOpen,
    &dScnName_c::NoteOpenWait,
    &dScnName_c::FileSelectOpen,
    &dScnName_c::FileSelectMain,
    &dScnName_c::FileSelectClose,
    &dScnName_c::NameInOpen,
    &dScnName_c::NameInMain,
    &dScnName_c::NameInClose,
    &dScnName_c::changeGameScene,
    &dScnName_c::SaveOpen,
    &dScnName_c::SaveMain,
    &dScnName_c::SaveClose,
    &dScnName_c::ResetWait,
    &dScnName_c::ShopDemoDataLoad,
    &dScnName_c::ShopDemoDataSet,
};

void (dScnName_c::*MemCardCheckProc[])() = {
    &dScnName_c::MemCardStatCheck,
    &dScnName_c::MemCardLoadWait,
    &dScnName_c::MemCardErrMsgWaitKey,
    &dScnName_c::MemCardErrMsgWaitKey2,
    &dScnName_c::MemCardErrMsgWaitNoSaveSel,
    &dScnName_c::MemCardErrMsgWaitFormatSel,
    &dScnName_c::MemCardErrMsgWaitFormatSel2,
    &dScnName_c::MemCardFormat,
    &dScnName_c::MemCardFormatCheck,
    &dScnName_c::MemCardMakeGameFileSel,
    &dScnName_c::MemCardMakeGameFile,
    &dScnName_c::MemCardMakeGameFileCheck,
    &dScnName_c::MemCardGotoFileSelect,
    &dScnName_c::MemCardGotoIPLSelect,
    &dScnName_c::MemCardGotoIPL,
    &dScnName_c::MemCardCheckDbg,
    &dScnName_c::MemCardCheckDbgWait,
};

void (dScnName_c::*NameOpenProc[])() = {
    &dScnName_c::NameOpenMain,
    &dScnName_c::NameOpenWait,
};

void (dScnName_c::*FileSelOpenProc[])() = {
    &dScnName_c::FileSelOpenMain,
    &dScnName_c::FileselOpenWait,
};

void (dScnName_c::*DrawProc[])() = {
    &dScnName_c::FileErrorDraw,
    &dScnName_c::FileSelectDraw,
    &dScnName_c::NameInDraw,
    &dScnName_c::SaveDraw,
    &dScnName_c::NoneDraw,
};

/* 802305E0-80230678       .text execute__10dScnName_cFv */
BOOL dScnName_c::execute() {
    /* Nonmatching */
    if (!fopOvlpM_IsPeek())
        dComIfG_resetToOpening(this);

    if (mDoRst::isReset())
        return TRUE;
    cloth_move();

    if (dFe_c != NULL)
        dFe_c->_move();
    (this->*(MainProc[mMainProc]))();
    buttonIconProc();
    return TRUE;
}

/* 80230678-80230714       .text setView__10dScnName_cFv */
void dScnName_c::setView() {
    /* Nonmatching */
}

/* 80230714-802307EC       .text draw__10dScnName_cFv */
BOOL dScnName_c::draw() {
    setView();
    for (create_tag_class* pTag = fopDwIt_Begin(); pTag != NULL; pTag = fopDwIt_Next(pTag))
        fpcM_Draw(pTag->mpTagData);
    if (field_0x55d && !g_snHIO.field_0xb) {
        dComIfGd_set2DOpa(&cloth);
    }
    (this->*(DrawProc[mDrawProc]))();
    dComIfGd_set2DOpa(&btnIcon);
    return TRUE;
}

/* 802307EC-80230A14       .text __dt__10dScnName_cFv */
dScnName_c::~dScnName_c() {
    /* Nonmatching */
}

/* 80230A14-80230AD0       .text MemCardCheckMain__10dScnName_cFv */
void dScnName_c::MemCardCheckMain() {
    /* Nonmatching */
}

/* 80230AD0-80230C78       .text MemCardStatCheck__10dScnName_cFv */
void dScnName_c::MemCardStatCheck() {
    /* Nonmatching */
}

/* 80230C78-80230D20       .text MemCardLoadWait__10dScnName_cFv */
void dScnName_c::MemCardLoadWait() {
    /* Nonmatching */
}

/* 80230D20-80230D74       .text MemCardErrMsgWaitKey__10dScnName_cFv */
void dScnName_c::MemCardErrMsgWaitKey() {
    /* Nonmatching */
}

/* 80230D74-80230DE8       .text MemCardErrMsgWaitKey2__10dScnName_cFv */
void dScnName_c::MemCardErrMsgWaitKey2() {
    /* Nonmatching */
}

/* 80230DE8-80230E50       .text MemCardGotoIPLSelect__10dScnName_cFv */
void dScnName_c::MemCardGotoIPLSelect() {
    /* Nonmatching */
}

/* 80230E50-80230E7C       .text MemCardGotoIPL__10dScnName_cFv */
void dScnName_c::MemCardGotoIPL() {
    /* Nonmatching */
}

/* 80230E7C-80230F4C       .text MemCardErrMsgWaitNoSaveSel__10dScnName_cFv */
void dScnName_c::MemCardErrMsgWaitNoSaveSel() {
    /* Nonmatching */
}

/* 80230F4C-80230FD0       .text MemCardErrMsgWaitFormatSel__10dScnName_cFv */
void dScnName_c::MemCardErrMsgWaitFormatSel() {
    /* Nonmatching */
}

/* 80230FD0-8023106C       .text MemCardErrMsgWaitFormatSel2__10dScnName_cFv */
void dScnName_c::MemCardErrMsgWaitFormatSel2() {
    /* Nonmatching */
}

/* 8023106C-802310C0       .text MemCardFormat__10dScnName_cFv */
void dScnName_c::MemCardFormat() {
    /* Nonmatching */
}

/* 802310C0-8023117C       .text MemCardFormatCheck__10dScnName_cFv */
void dScnName_c::MemCardFormatCheck() {
    /* Nonmatching */
}

/* 8023117C-80231284       .text MemCardMakeGameFileSel__10dScnName_cFv */
void dScnName_c::MemCardMakeGameFileSel() {
    /* Nonmatching */
}

/* 80231284-802312D8       .text MemCardMakeGameFile__10dScnName_cFv */
void dScnName_c::MemCardMakeGameFile() {
    /* Nonmatching */
}

/* 802312D8-80231398       .text MemCardMakeGameFileCheck__10dScnName_cFv */
void dScnName_c::MemCardMakeGameFileCheck() {
    /* Nonmatching */
}

/* 80231398-802313AC       .text MemCardGotoFileSelect__10dScnName_cFv */
void dScnName_c::MemCardGotoFileSelect() {
    /* Nonmatching */
}

/* 802313AC-802313B0       .text MemCardCheckDbg__10dScnName_cFv */
void dScnName_c::MemCardCheckDbg() {}

/* 802313B0-80231428       .text MemCardCheckDbgWait__10dScnName_cFv */
void dScnName_c::MemCardCheckDbgWait() {
    /* Nonmatching */
}

/* 80231428-80231454       .text FileErrorDraw__10dScnName_cFv */
void dScnName_c::FileErrorDraw() {
    /* Nonmatching */
}

/* 80231454-802314E8       .text NoteOpen__10dScnName_cFv */
void dScnName_c::NoteOpen() {
    /* Nonmatching */
}

/* 802314E8-802315A8       .text NoteOpenWait__10dScnName_cFv */
void dScnName_c::NoteOpenWait() {
    /* Nonmatching */
}

/* 802315A8-802315E0       .text FileSelectOpen__10dScnName_cFv */
void dScnName_c::FileSelectOpen() {
    /* Nonmatching */
}

/* 802315E0-802319B4       .text buttonIconProc__10dScnName_cFv */
void dScnName_c::buttonIconProc() {
    /* Nonmatching */
}

/* 802319B4-80231A24       .text FileSelOpenMain__10dScnName_cFv */
void dScnName_c::FileSelOpenMain() {
    /* Nonmatching */
}

/* 80231A24-80231A28       .text FileselOpenWait__10dScnName_cFv */
void dScnName_c::FileselOpenWait() {}

/* 80231A28-80231A8C       .text FileSelectMain__10dScnName_cFv */
void dScnName_c::FileSelectMain() {
    /* Nonmatching */
}

/* 80231A8C-80231CB8       .text FileSelectMainNormal__10dScnName_cFv */
void dScnName_c::FileSelectMainNormal() {
    /* Nonmatching */
}

/* 80231CB8-80231D00       .text FileSelectMainExSave__10dScnName_cFv */
void dScnName_c::FileSelectMainExSave() {
    /* Nonmatching */
}

/* 80231D00-80231D28       .text ResetWait__10dScnName_cFv */
void dScnName_c::ResetWait() {
    if (field_0x558) {
        field_0x558--;
        return;
    }
    mDoRst::onReset();
}

/* 80231D28-80231E9C       .text FileSelectClose__10dScnName_cFv */
void dScnName_c::FileSelectClose() {
    /* Nonmatching */
}

/* 80231E9C-80231EC0       .text FileSelectDraw__10dScnName_cFv */
void dScnName_c::FileSelectDraw() {
    /* Nonmatching */
}

/* 80231EC0-80231EF8       .text NameInOpen__10dScnName_cFv */
void dScnName_c::NameInOpen() {
    /* Nonmatching */
}

/* 80231EF8-80231F44       .text NameOpenMain__10dScnName_cFv */
void dScnName_c::NameOpenMain() {
    /* Nonmatching */
}

/* 80231F44-80231F48       .text NameOpenWait__10dScnName_cFv */
void dScnName_c::NameOpenWait() {}

/* 80231F48-80231FF4       .text NameInMain__10dScnName_cFv */
void dScnName_c::NameInMain() {
    /* Nonmatching */
}

/* 80231FF4-80232050       .text NameInClose__10dScnName_cFv */
void dScnName_c::NameInClose() {
    /* Nonmatching */
}

/* 80232050-80232074       .text NameInDraw__10dScnName_cFv */
void dScnName_c::NameInDraw() {
    /* Nonmatching */
}

/* 80232074-802320C0       .text ShopDemoDataLoad__10dScnName_cFv */
void dScnName_c::ShopDemoDataLoad() {
    /* Nonmatching */
}

/* 802320C0-8023213C       .text ShopDemoDataSet__10dScnName_cFv */
void dScnName_c::ShopDemoDataSet() {
    /* Nonmatching */
}

/* 8023213C-802321AC       .text SaveOpen__10dScnName_cFv */
void dScnName_c::SaveOpen() {
    /* Nonmatching */
}

/* 802321AC-8023222C       .text SaveMain__10dScnName_cFv */
void dScnName_c::SaveMain() {
    /* Nonmatching */
}

/* 8023222C-80232278       .text SaveClose__10dScnName_cFv */
void dScnName_c::SaveClose() {
    /* Nonmatching */
}

/* 80232278-8023229C       .text SaveDraw__10dScnName_cFv */
void dScnName_c::SaveDraw() {
    /* Nonmatching */
}

/* 8023229C-802322A0       .text NoneDraw__10dScnName_cFv */
void dScnName_c::NoneDraw() {
}

/* 802322A0-80232338       .text changeGameScene__10dScnName_cFv */
void dScnName_c::changeGameScene() {
    if (fopOvlpM_IsPeek())
        return;

    dComIfGs_gameStart();
    u32 procName = field_0x55f ? PROC_OPEN_SCENE : PROC_PLAY_SCENE;
    if (fopScnM_ChangeReq(this, procName, 0, 5)) {
        g_dComIfG_gameInfo.save.getDan().mStageNo = -1;
        dComIfGs_setRestartRoomParam(0);
        mDoAud_setSceneName(dComIfGp_getNextStageName(), dComIfGp_getNextStageRoomNo(), dComIfGp_getNextStageLayer());
    }
}

/* 80232338-80232358       .text dScnName_Draw__FP10dScnName_c */
s32 dScnName_Draw(dScnName_c* i_this) {
    return i_this->draw();
}

/* 80232358-80232378       .text dScnName_Execute__FP10dScnName_c */
s32 dScnName_Execute(dScnName_c* i_this) {
    return i_this->execute();
}

/* 80232378-80232380       .text dScnName_IsDelete__FP10dScnName_c */
s32 dScnName_IsDelete(dScnName_c*) {
    return 1;
}

/* 80232380-802323A8       .text dScnName_Delete__FP10dScnName_c */
s32 dScnName_Delete(dScnName_c* i_this) {
    i_this->~dScnName_c();
    return 1;
}

/* 802323A8-802323F8       .text dScnName_Create__FP11scene_class */
s32 dScnName_Create(scene_class* i_scn) {
    dScnName_c* i_this = new (i_scn) dScnName_c();
    return i_this->create();
}

/* 802323F8-8023245C       .text draw__13dDlst_BTICN_cFv */
void dDlst_BTICN_c::draw() {
    J2DOrthoGraph* graf = dComIfGp_getCurrentGrafPort();
    graf->setPort();
    scr->draw(0.0f, 0.0f, graf);
}

/* 8023245C-80232518       .text draw__19dDlst_FLSEL_CLOTH_cFv */
void dDlst_FLSEL_CLOTH_c::draw() {
    /* Nonmatching */
}

scene_method_class l_dScnName_Method = {
    (process_method_func)dScnName_Create,
    (process_method_func)dScnName_Delete,
    (process_method_func)dScnName_Execute,
    (process_method_func)dScnName_IsDelete,
    (process_method_func)dScnName_Draw,
};

scene_process_profile_definition g_profile_NAME_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_NAME_SCENE,
    &g_fpcNd_Method.base,
    sizeof(dScnName_c),
    0,
    0,
    &g_fopScn_Method.base,
    &l_dScnName_Method,
    NULL,
};

scene_process_profile_definition g_profile_NAMEEX_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_NAMEEX_SCENE,
    &g_fpcNd_Method.base,
    sizeof(dScnName_c),
    0,
    0,
    &g_fopScn_Method.base,
    &l_dScnName_Method,
    NULL,
};
