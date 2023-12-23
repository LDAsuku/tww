//
// Generated by dtk
// Translation Unit: J3DAnmLoader.cpp
//

#include "JSystem/J3DGraphLoader/J3DAnmLoader.h"
#include "JSystem/J3DGraphAnimator/J3DAnimation.h"
#include "JSystem/JSupport/JSupport.h"
#include "dolphin/os/OS.h"

/* 802FEDA0-802FF6C8       .text load__20J3DAnmLoaderDataBaseFPCv */
J3DAnmBase* J3DAnmLoaderDataBase::load(const void* i_data) {
    if (!i_data) {
        return NULL;
    }
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)i_data;
    if (header->mMagic == 'J3D1') {
        switch (header->mType) {
        case 'bck1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmTransformKey();
            return loader.load(i_data);
        }
        case 'bpk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmColorKey();
            return loader.load(i_data);
        }
        case 'blk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmClusterKey();
            return loader.load(i_data);
        }
        case 'btk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmTextureSRTKey();
            return loader.load(i_data);
        }
        case 'brk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmTevRegKey();
            return loader.load(i_data);
        }
        case 'bxk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.mAnm = new J3DAnmVtxColorKey();
            return loader.load(i_data);
        }
        case 'bca1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmTransformFull();
            return loader.load(i_data);
        }
        case 'bpa1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmColorFull();
            return loader.load(i_data);
        }
        case 'btp1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmTexPattern();
            return loader.load(i_data);
        }
        case 'bva1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmVisibilityFull();
            return loader.load(i_data);
        }
        case 'bla1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmClusterFull();
            return loader.load(i_data);
        }
        case 'bxa1': {
            J3DAnmFullLoader_v15 loader;
            loader.mAnm = new J3DAnmVtxColorFull();
            return loader.load(i_data);
        }
        default:
            OSReport("J3DAnmLoader: this is not a J3D Binary.\n");
            return NULL;
        }
    }
    return NULL;
}

/* 802FF6C8-802FF9EC       .text setResource__20J3DAnmLoaderDataBaseFP10J3DAnmBasePCv */
void J3DAnmLoaderDataBase::setResource(J3DAnmBase* param_1, const void* param_2) {
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)param_2;
    if (!header) {
        return;
    }
    if (header->mMagic != 'J3D1') {
        return;
    }
    switch (header->mType) {
        case 'bck1': {
            J3DAnmKeyLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bpk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'blk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'btk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'brk1': {
            J3DAnmKeyLoader_v15 loader;
            if (param_1->getKind() == 5) {
                loader.setResource(param_1, param_2);
            }
            break;
        }
        case 'bxk1': {
            J3DAnmKeyLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bca1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bpa1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'btp1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bla1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bxa1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        case 'bva1': {
            J3DAnmFullLoader_v15 loader;
            loader.setResource(param_1, param_2);
            break;
        }
        default: {
            OSReport("J3DAnmLoader: this is not a J3D Binary.\n");
            break;
        }
    }
}

/* 802FF9EC-802FFA08       .text __ct__20J3DAnmFullLoader_v15Fv */
J3DAnmFullLoader_v15::J3DAnmFullLoader_v15() {}

/* 802FFA08-802FFA64       .text __dt__20J3DAnmFullLoader_v15Fv */
J3DAnmFullLoader_v15::~J3DAnmFullLoader_v15() {}

/* 802FFA64-802FFA80       .text __ct__19J3DAnmKeyLoader_v15Fv */
J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15() {}

/* 802FFA80-802FFADC       .text __dt__19J3DAnmKeyLoader_v15Fv */
J3DAnmKeyLoader_v15::~J3DAnmKeyLoader_v15() {}

/* 802FFADC-802FFC28       .text load__20J3DAnmFullLoader_v15FPCv */
J3DAnmBase* J3DAnmFullLoader_v15::load(const void* param_1) {
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)param_1;
    const J3DAnmDataBlockHeader* block = &header->mFirst;
    for (int i = 0; i < header->mCount; i++) {
        switch (block->mType) {
        case 'ANF1':
            readAnmTransform((J3DAnmTransformFullData*)block);
            break;
        case 'PAF1':
            readAnmColor((J3DAnmColorFullData*)block);
            break;
        case 'TPT1':
            readAnmTexPattern((J3DAnmTexPatternFullData*)block);
            break;
        case 'CLF1':
            readAnmCluster((J3DAnmClusterFullData*)block);
            break;
        case 'VAF1':
            readAnmVisibility((J3DAnmVisibilityFullData*)block);
            break;
        case 'VCF1':
            readAnmVtxColor((J3DAnmVtxColorFullData*)block);
            break;
        default:
            OSReport("Unknown data block\n");
            break;
        }
        block = block->getNext();
    }
    return mAnm;
}

/* 802FFC28-802FFDD4       .text setResource__20J3DAnmFullLoader_v15FP10J3DAnmBasePCv */
void J3DAnmFullLoader_v15::setResource(J3DAnmBase* param_1, const void* param_2) {
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)param_2;
    const J3DAnmDataBlockHeader* block = &header->mFirst;
    for (int i = 0; i < header->mCount; i++) {
        switch (block->mType) {
        case 'ANF1':
            if (param_1->getKind() == 0) {
                setAnmTransform((J3DAnmTransformFull*)param_1, (const J3DAnmTransformFullData*)block);
            }
            break;
        case 'PAF1':
            if (param_1->getKind() == 1) {
                setAnmColor((J3DAnmColorFull*)param_1, (const J3DAnmColorFullData*)block);
            }
            break;
        case 'TPT1':
            if (param_1->getKind() == 2) {
                setAnmTexPattern((J3DAnmTexPattern*)param_1, (const J3DAnmTexPatternFullData*)block);
            }
            break;
        case 'CLF1':
            if (param_1->getKind() == 3) {
                setAnmCluster((J3DAnmClusterFull*)param_1, (const J3DAnmClusterFullData*)block);
            }
            break;
        case 'VAF1':
            if (param_1->getKind() == 6) {
                setAnmVisibility((J3DAnmVisibilityFull*)param_1, (const J3DAnmVisibilityFullData*)block);
            }
            break;
        case 'VCF1':
            if (param_1->getKind() == 7) {
                setAnmVtxColor((J3DAnmVtxColorFull*)param_1, (const J3DAnmVtxColorFullData*)block);
            }
            break;
        default:
            OSReport("Unknown data block\n");
            break;
        }
        block = block->getNext();
    }
}

/* 802FFDD4-802FFDFC       .text readAnmTransform__20J3DAnmFullLoader_v15FPC23J3DAnmTransformFullData */
void J3DAnmFullLoader_v15::readAnmTransform(const J3DAnmTransformFullData* param_1) {
    setAnmTransform((J3DAnmTransformFull*)mAnm, param_1);
}

/* 802FFDFC-802FFE90       .text setAnmTransform__20J3DAnmFullLoader_v15FP19J3DAnmTransformFullPC23J3DAnmTransformFullData */
void J3DAnmFullLoader_v15::setAnmTransform(J3DAnmTransformFull* param_1, const J3DAnmTransformFullData* param_2) {
    param_1->field_0x22 = param_2->field_0xc;
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->field_0x24 = JSUConvertOffsetToPtr<J3DAnmTransformFullTable>(param_2, (void*)param_2->mTableOffset);
    param_1->field_0x10 = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mScaleValOffset);
    param_1->field_0x14 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mRotValOffset);
    param_1->field_0x18 = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mTransValOffset);
}

/* 802FFE90-802FFEB8       .text readAnmColor__20J3DAnmFullLoader_v15FPC19J3DAnmColorFullData */
void J3DAnmFullLoader_v15::readAnmColor(const J3DAnmColorFullData* param_1) {
    setAnmColor((J3DAnmColorFull*)mAnm, param_1);
}

/* 802FFEB8-802FFF84       .text setAnmColor__20J3DAnmFullLoader_v15FP15J3DAnmColorFullPC19J3DAnmColorFullData */
void J3DAnmFullLoader_v15::setAnmColor(J3DAnmColorFull* param_1, const J3DAnmColorFullData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mUpdateMaterialNum = param_2->mUpdateMaterialNum;
    param_1->mAnmTable = JSUConvertOffsetToPtr<J3DAnmColorFullTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mColorR = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mRValuesOffset);
    param_1->mColorG = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mGValuesOffset);
    param_1->mColorB = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mBValuesOffset);
    param_1->mColorA = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mAValuesOffset);
    param_1->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mUpdateMaterialIDOffset);
    param_1->mUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mNameTabOffset));
}

/* 802FFF84-802FFFAC       .text readAnmTexPattern__20J3DAnmFullLoader_v15FPC24J3DAnmTexPatternFullData */
void J3DAnmFullLoader_v15::readAnmTexPattern(const J3DAnmTexPatternFullData* param_1) {
    setAnmTexPattern((J3DAnmTexPattern*)mAnm, param_1);
}

/* 802FFFAC-80300050       .text setAnmTexPattern__20J3DAnmFullLoader_v15FP16J3DAnmTexPatternPC24J3DAnmTexPatternFullData */
void J3DAnmFullLoader_v15::setAnmTexPattern(J3DAnmTexPattern* param_1, const J3DAnmTexPatternFullData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mUpdateMaterialNum = param_2->field_0xc;
    param_1->field_0x18 = param_2->field_0xe;
    param_1->mAnmTable = JSUConvertOffsetToPtr<J3DAnmTexPatternFullTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mTextureIndex = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mValuesOffset);
    param_1->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mUpdateMaterialIDOffset);
    param_1->mUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mNameTabOffset));
}

/* 80300050-80300078       .text readAnmVisibility__20J3DAnmFullLoader_v15FPC24J3DAnmVisibilityFullData */
void J3DAnmFullLoader_v15::readAnmVisibility(const J3DAnmVisibilityFullData* param_1) {
    setAnmVisibility((J3DAnmVisibilityFull*)mAnm, param_1);
}

/* 80300078-803000F4       .text setAnmVisibility__20J3DAnmFullLoader_v15FP20J3DAnmVisibilityFullPC24J3DAnmVisibilityFullData */
void J3DAnmFullLoader_v15::setAnmVisibility(J3DAnmVisibilityFull* param_1, const J3DAnmVisibilityFullData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mUpdateMaterialNum = param_2->field_0xc;
    param_1->field_0x12 = param_2->field_0xe;
    param_1->mAnmTable = JSUConvertOffsetToPtr<J3DAnmVisibilityFullTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mVisibility = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mValuesOffset);
}

/* 803000F4-8030011C       .text readAnmCluster__20J3DAnmFullLoader_v15FPC21J3DAnmClusterFullData */
void J3DAnmFullLoader_v15::readAnmCluster(const J3DAnmClusterFullData* param_1) {
    setAnmCluster((J3DAnmClusterFull*)mAnm, param_1);
}

/* 8030011C-80300188       .text setAnmCluster__20J3DAnmFullLoader_v15FP17J3DAnmClusterFullPC21J3DAnmClusterFullData */
void J3DAnmFullLoader_v15::setAnmCluster(J3DAnmClusterFull* param_1, const J3DAnmClusterFullData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mAnmTable = JSUConvertOffsetToPtr<J3DAnmClusterFullTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mWeight = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mWeightOffset);
}

/* 80300188-803001B0       .text readAnmVtxColor__20J3DAnmFullLoader_v15FPC22J3DAnmVtxColorFullData */
void J3DAnmFullLoader_v15::readAnmVtxColor(const J3DAnmVtxColorFullData* param_1) {
    setAnmVtxColor((J3DAnmVtxColorFull*)mAnm, param_1);
}

/* 803001B0-80300318       .text setAnmVtxColor__20J3DAnmFullLoader_v15FP18J3DAnmVtxColorFullPC22J3DAnmVtxColorFullData */
void J3DAnmFullLoader_v15::setAnmVtxColor(J3DAnmVtxColorFull*, const J3DAnmVtxColorFullData*) {
    /* Nonmatching */
}

/* 80300318-80300464       .text load__19J3DAnmKeyLoader_v15FPCv */
J3DAnmBase* J3DAnmKeyLoader_v15::load(const void* param_1) {
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)param_1;
    const J3DAnmDataBlockHeader* block = &header->mFirst;
    for (int i = 0; i < header->mCount; i++) {
        switch (block->mType) {
        case 'ANK1':
            readAnmTransform((J3DAnmTransformKeyData*)block);
            break;
        case 'PAK1':
            readAnmColor((J3DAnmColorKeyData*)block);
            break;
        case 'CLK1':
            readAnmCluster((J3DAnmClusterKeyData*)block);
            break;
        case 'TTK1':
            readAnmTextureSRT((J3DAnmTextureSRTKeyData*)block);
            break;
        case 'TRK1':
            readAnmTevReg((J3DAnmTevRegKeyData*)block);
            break;
        case 'VCK1':
            readAnmVtxColor((J3DAnmVtxColorKeyData*)block);
            break;
        default:
            OSReport("Unknown data block\n");
            break;
        }
        block = block->getNext();
    }
    return mAnm;
}

/* 80300464-80300610       .text setResource__19J3DAnmKeyLoader_v15FP10J3DAnmBasePCv */
void J3DAnmKeyLoader_v15::setResource(J3DAnmBase* param_1, const void* param_2) {
    const J3DAnmDataHeader* header = (const J3DAnmDataHeader*)param_2;
    const J3DAnmDataBlockHeader* block = &header->mFirst;
    for (int i = 0; i < header->mCount; i++) {
        switch (block->mType) {
        case 'ANK1':
            if (param_1->getKind() == 0) {
                setAnmTransform((J3DAnmTransformKey*)param_1, (const J3DAnmTransformKeyData*)block);
            }
            break;
        case 'PAK1':
            if (param_1->getKind() == 1) {
                setAnmColor((J3DAnmColorKey*)param_1, (const J3DAnmColorKeyData*)block);
            }
            break;
        case 'CLK1':
            if (param_1->getKind() == 3) {
                setAnmCluster((J3DAnmClusterKey*)param_1, (const J3DAnmClusterKeyData*)block);
            }
            break;
        case 'TTK1':
            if (param_1->getKind() == 4) {
                setAnmTextureSRT((J3DAnmTextureSRTKey*)param_1, (const J3DAnmTextureSRTKeyData*)block);
            }
            break;
        case 'TRK1':
            if (param_1->getKind() == 5) {
                setAnmTevReg((J3DAnmTevRegKey*)param_1, (const J3DAnmTevRegKeyData*)block);
            }
            break;
        case 'VCK1':
            if (param_1->getKind() == 7) {
                setAnmVtxColor((J3DAnmVtxColorKey*)param_1, (const J3DAnmVtxColorKeyData*)block);
            }
            break;
        default:
            OSReport("Unknown data block\n");
            break;
        }
        block = block->getNext();
    }
}

/* 80300610-80300638       .text readAnmTransform__19J3DAnmKeyLoader_v15FPC22J3DAnmTransformKeyData */
void J3DAnmKeyLoader_v15::readAnmTransform(const J3DAnmTransformKeyData* param_1) {
    setAnmTransform((J3DAnmTransformKey*)mAnm, param_1);
}

/* 80300638-803006D4       .text setAnmTransform__19J3DAnmKeyLoader_v15FP18J3DAnmTransformKeyPC22J3DAnmTransformKeyData */
void J3DAnmKeyLoader_v15::setAnmTransform(J3DAnmTransformKey* param_1, const J3DAnmTransformKeyData* param_2) {
    param_1->field_0x22 = param_2->field_0xc;
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->field_0x24 = param_2->field_0x9;
    param_1->mFrame = 0.0f;
    param_1->field_0x28 = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(param_2, (void*)param_2->mTableOffset);
    param_1->field_0x10 = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->field_0x18);
    param_1->field_0x14 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->field_0x1c);
    param_1->field_0x18 = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->field_0x20);
}

/* 803006D4-803006FC       .text readAnmTextureSRT__19J3DAnmKeyLoader_v15FPC23J3DAnmTextureSRTKeyData */
void J3DAnmKeyLoader_v15::readAnmTextureSRT(const J3DAnmTextureSRTKeyData* param_1) {
    setAnmTextureSRT((J3DAnmTextureSRTKey*)mAnm, param_1);
}

/* 803006FC-803008D8       .text setAnmTextureSRT__19J3DAnmKeyLoader_v15FP19J3DAnmTextureSRTKeyPC23J3DAnmTextureSRTKeyData */
void J3DAnmKeyLoader_v15::setAnmTextureSRT(J3DAnmTextureSRTKey* param_1, const J3DAnmTextureSRTKeyData* param_2) {
    param_1->mTrackNum = param_2->field_0xc;
    param_1->mFrameMax = param_2->field_0xa;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mDecShift = param_2->field_0x9;
    param_1->mFrame = 0.0f;
    param_1->mTrackNum = param_2->field_0xc;
    param_1->mScaleNum = param_2->field_0xe;
    param_1->mRotNum = param_2->field_0x10;
    param_1->mTransNum = param_2->field_0x12;
    param_1->mAnmTable = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mUpdateMatIDOffset);
    param_1->mUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mNameTab1Offset));
    param_1->mUpdateTexMtxID = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->mUpdateTexMtxIDOffset);
    param_1->mSRTCenter = JSUConvertOffsetToPtr<Vec>(param_2, (void*)param_2->unkOffset);
    param_1->mScaleData = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mScaleValOffset);
    param_1->mRotData = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mRotValOffset);
    param_1->mTransData = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mTransValOffset);
    if (param_2->mNameTab2Offset) {
        param_1->mPostUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mNameTab2Offset));
    }
    param_1->mPostTrackNum = param_2->field_0x34;
    param_1->field_0x4c = param_2->field_0x36;
    param_1->field_0x4e = param_2->field_0x38;
    param_1->field_0x50 = param_2->field_0x3a;
    param_1->field_0x64 = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(param_2, (void*)param_2->mInfoTable2Offset);
    param_1->mPostUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->field_0x40);
    param_1->mPostUpdateTexMtxID = JSUConvertOffsetToPtr<u8>(param_2, (void*)param_2->field_0x48);
    param_1->mPostSRTCenter = JSUConvertOffsetToPtr<Vec>(param_2, (void*)param_2->field_0x4c);
    param_1->field_0x54 = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->field_0x50);
    param_1->field_0x58 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->field_0x54);
    param_1->field_0x5c = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->field_0x58);
    switch (param_2->field_0x5c) {
    case 0:
    case 1:
        param_1->mTexMtxCalcType = param_2->field_0x5c;
        break;
    default:
        param_1->mTexMtxCalcType = 0;
        break;
    }
}

/* 803008D8-80300900       .text readAnmColor__19J3DAnmKeyLoader_v15FPC18J3DAnmColorKeyData */
void J3DAnmKeyLoader_v15::readAnmColor(const J3DAnmColorKeyData* param_1) {
    setAnmColor((J3DAnmColorKey*)mAnm, param_1);
}

/* 80300900-803009EC       .text setAnmColor__19J3DAnmKeyLoader_v15FP14J3DAnmColorKeyPC18J3DAnmColorKeyData */
void J3DAnmKeyLoader_v15::setAnmColor(J3DAnmColorKey* param_1, const J3DAnmColorKeyData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mUpdateMaterialNum = param_2->mUpdateMaterialNum;
    param_1->field_0x10 = param_2->field_0x10;
    param_1->field_0x12 = param_2->field_0x12;
    param_1->field_0x14 = param_2->field_0x14;
    param_1->field_0x16 = param_2->field_0x16;
    param_1->field_0x40 = JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(param_2, (void*)param_2->mTableOffset);
    param_1->field_0x30 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mRValOffset);
    param_1->field_0x34 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mGValOffset);
    param_1->field_0x38 = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mBValOffset);
    param_1->field_0x3c = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mAValOffset);
    param_1->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mUpdateMaterialIDOffset);
    param_1->mUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mNameTabOffset));
}

/* 803009EC-80300A14       .text readAnmCluster__19J3DAnmKeyLoader_v15FPC20J3DAnmClusterKeyData */
void J3DAnmKeyLoader_v15::readAnmCluster(const J3DAnmClusterKeyData* param_1) {
    setAnmCluster((J3DAnmClusterKey*)mAnm, param_1);
}

/* 80300A14-80300A80       .text setAnmCluster__19J3DAnmKeyLoader_v15FP16J3DAnmClusterKeyPC20J3DAnmClusterKeyData */
void J3DAnmKeyLoader_v15::setAnmCluster(J3DAnmClusterKey* param_1, const J3DAnmClusterKeyData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->field_0x14 = JSUConvertOffsetToPtr<J3DAnmClusterKeyTable>(param_2, (void*)param_2->mTableOffset);
    param_1->mWeight = JSUConvertOffsetToPtr<f32>(param_2, (void*)param_2->mWeightOffset);
}

/* 80300A80-80300AA8       .text readAnmTevReg__19J3DAnmKeyLoader_v15FPC19J3DAnmTevRegKeyData */
void J3DAnmKeyLoader_v15::readAnmTevReg(const J3DAnmTevRegKeyData* param_1) {
    setAnmTevReg((J3DAnmTevRegKey*)mAnm, param_1);
}

/* 80300AA8-80300C34       .text setAnmTevReg__19J3DAnmKeyLoader_v15FP15J3DAnmTevRegKeyPC19J3DAnmTevRegKeyData */
void J3DAnmKeyLoader_v15::setAnmTevReg(J3DAnmTevRegKey* param_1, const J3DAnmTevRegKeyData* param_2) {
    param_1->mFrameMax = param_2->mFrameMax;
    param_1->mAttribute = param_2->field_0x8;
    param_1->mFrame = 0.0f;
    param_1->mCRegUpdateMaterialNum = param_2->mCRegUpdateMaterialNum;
    param_1->mAnmCRegKeyTable = JSUConvertOffsetToPtr<J3DAnmCRegKeyTable>(param_2, (void*)param_2->mCRegTableOffset);
    param_1->mCRegUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mCRegUpdateMaterialIDOffset);
    param_1->mCRegUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mCRegNameTabOffset));
    param_1->mKRegUpdateMaterialNum = param_2->mKRegUpdateMaterialNum;
    param_1->mAnmKRegKeyTable = JSUConvertOffsetToPtr<J3DAnmKRegKeyTable>(param_2, (void*)param_2->mKRegTableOffset);
    param_1->mKRegUpdateMaterialID = JSUConvertOffsetToPtr<u16>(param_2, (void*)param_2->mKRegUpdateMaterialIDOffset);
    param_1->mKRegUpdateMaterialName.setResource(JSUConvertOffsetToPtr<ResNTAB>(param_2, (void*)param_2->mKRegNameTabOffset));
    param_1->mCRegDataCount[0] = param_2->field_0x10;
    param_1->mCRegDataCount[1] = param_2->field_0x12;
    param_1->mCRegDataCount[2] = param_2->field_0x14;
    param_1->mCRegDataCount[3] = param_2->field_0x16;
    param_1->mAnmCRegData[0] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mCRValuesOffset);
    param_1->mAnmCRegData[1] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mCGValuesOffset);
    param_1->mAnmCRegData[2] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mCBValuesOffset);
    param_1->mAnmCRegData[3] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mCAValuesOffset);
    param_1->mKRegDataCount[0] = param_2->field_0x18;
    param_1->mKRegDataCount[1] = param_2->field_0x1a;
    param_1->mKRegDataCount[2] = param_2->field_0x1c;
    param_1->mKRegDataCount[3] = param_2->field_0x1e;
    param_1->mAnmKRegData[0] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mKRValuesOffset);
    param_1->mAnmKRegData[1] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mKGValuesOffset);
    param_1->mAnmKRegData[2] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mKBValuesOffset);
    param_1->mAnmKRegData[3] = JSUConvertOffsetToPtr<s16>(param_2, (void*)param_2->mKAValuesOffset);
}

/* 80300C34-80300C5C       .text readAnmVtxColor__19J3DAnmKeyLoader_v15FPC21J3DAnmVtxColorKeyData */
void J3DAnmKeyLoader_v15::readAnmVtxColor(const J3DAnmVtxColorKeyData* param_1) {
    setAnmVtxColor((J3DAnmVtxColorKey*)mAnm, param_1);
}

/* 80300C5C-80300DC4       .text setAnmVtxColor__19J3DAnmKeyLoader_v15FP17J3DAnmVtxColorKeyPC21J3DAnmVtxColorKeyData */
void J3DAnmKeyLoader_v15::setAnmVtxColor(J3DAnmVtxColorKey*, const J3DAnmVtxColorKeyData*) {
    /* Nonmatching */
}
