#include "hooks/GJShaderState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/GJValueTween.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGJShaderState::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAGJShaderState::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAGJShaderState& o_value) {
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_tweenActions;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_tweenTimes;
    UMAP_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_time;
        SEPARATOR_I
        i_stream >> o_value.m_prevTime;
        SEPARATOR_I
        i_stream >> o_value.m_startTime;
        SEPARATOR_I
        i_stream >> o_value.m_textureScaleX;
        SEPARATOR_I
        i_stream >> o_value.m_textureScaleY;
        SEPARATOR_I
        i_stream >> o_value.m_blurRefColor;
        SEPARATOR_I
        i_stream >> o_value.m_blurIntensity;
        SEPARATOR_I
        i_stream >> o_value.m_blurRefChannel;
        SEPARATOR_I
        i_stream >> o_value.m_blurOnlyEmpty;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveStartTime;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveTime;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveTimeOffset;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveThickness;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveStrength;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveWidth;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveFadeIn;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveFadeOut;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveInvert;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveInner;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveOuter;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveTargetID;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveTarget;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenterMoving;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveRelative;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveMaxSize;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenterDirty;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenter;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineStartTime;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineTime;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineTimeOffset;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineAxis;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineDirection;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineDual;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineInvert;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineStrength;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineWidth;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineFadeIn;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineFadeOut;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineThickness;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineTargetID;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineTarget;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenterMoving;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineRelative;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineMaxSize;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineScreenOffset2;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenterDirty;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenter;
        SEPARATOR_I
        i_stream >> o_value.m_glitchStrength;
        SEPARATOR_I
        i_stream >> o_value.m_glitchSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_glitchSliceHeight;
        SEPARATOR_I
        i_stream >> o_value.m_glitchMaxSliceXOff;
        SEPARATOR_I
        i_stream >> o_value.m_glitchMaxColXOff;
        SEPARATOR_I
        i_stream >> o_value.m_glitchMaxColYOff;
        SEPARATOR_I
        i_stream >> o_value.m_glitchRelative;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticTargetX;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticTargetY;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticRelative;
        SEPARATOR_I
        i_stream >> o_value.m_cGStartTime;
        SEPARATOR_I
        i_stream >> o_value.m_cGTime;
        SEPARATOR_I
        i_stream >> o_value.m_cGSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_cGRGBOffset;
        SEPARATOR_I
        i_stream >> o_value.m_cGStrength;
        SEPARATOR_I
        i_stream >> o_value.m_cGSegmentHeight;
        SEPARATOR_I
        i_stream >> o_value.m_cGLineThickness;
        SEPARATOR_I
        i_stream >> o_value.m_cGLineStrength;
        SEPARATOR_I
        i_stream >> o_value.m_cGEnable;
        SEPARATOR_I
        i_stream >> o_value.m_cGActive;
        SEPARATOR_I
        i_stream >> o_value.m_cGRelative;
        SEPARATOR_I
        i_stream >> o_value.m_cGRelativePos;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateTargetX;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateTargetY;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateSnapGrid;
        SEPARATOR_I
        i_stream >> o_value.m_pixelatePixelating;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateRelative;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateHardEdges;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleSize;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleFade;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleStrength;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTargetID;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTintChannel;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleRelative;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleAdditive;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTint;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleCenter;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurSize;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurFade;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurTarget;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurTargetID;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurCenter;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurTargetX;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurTargetY;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurSpeedX;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurSpeedY;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurFollowEaseX;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurFollowEaseY;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurTargetIDX;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurTargetIDY;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurDual;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurRelative;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeValue;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeRelative;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeTargetID;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeRadius;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeCenter;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetX;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetY;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetEnabledX;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetEnabledY;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetIDX;
        SEPARATOR_I
        i_stream >> o_value.m_pinchTargetIDY;
        SEPARATOR_I
        i_stream >> o_value.m_pinchCenter;
        SEPARATOR_I
        i_stream >> o_value.m_pinchScreenOffset;
        SEPARATOR_I
        i_stream >> o_value.m_pinchRelative;
        SEPARATOR_I
        i_stream >> o_value.m_pinchRadius;
        SEPARATOR_I
        i_stream >> o_value.m_pinchModifier;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleValue;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleUseLum;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleTintChannel;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleTint;
        SEPARATOR_I
        i_stream >> o_value.m_sepiaValue;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorEditRGB;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorR;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorG;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorB;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorClampRGB;
        SEPARATOR_I
        i_stream >> o_value.m_hueShiftDegrees;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCR;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCG;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCB;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBR;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBG;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBB;
        SEPARATOR_I
        i_stream >> o_value.m_splitTargetRows;
        SEPARATOR_I
        i_stream >> o_value.m_splitTargetCols;
        SEPARATOR_I
        i_stream >> o_value.m_splitActive;
        SEPARATOR_I
        i_stream >> o_value.m_minBlendingLayer;
        SEPARATOR_I
        i_stream >> o_value.m_maxBlendingLayer;
        SEPARATOR_I
        i_stream >> o_value.m_zLayerDirty;
        SEPARATOR_I
        i_stream >> o_value.m_noPlayerParticles;
        SEPARATOR_I
        i_stream >> o_value.m_usesShaders;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGJShaderState,m_tweenTimes) + sizeof(gd::unordered_map<int, double>), 584);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAGJShaderState& i_value) {
    UMAP_SEPARATOR_O
    o_stream << i_value.m_tweenActions;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_tweenTimes;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_time;
    SEPARATOR_O
    o_stream << i_value.m_prevTime;
    SEPARATOR_O
    o_stream << i_value.m_startTime;
    SEPARATOR_O
    o_stream << i_value.m_textureScaleX;
    SEPARATOR_O
    o_stream << i_value.m_textureScaleY;
    SEPARATOR_O
    o_stream << i_value.m_blurRefColor;
    SEPARATOR_O
    o_stream << i_value.m_blurIntensity;
    SEPARATOR_O
    o_stream << i_value.m_blurRefChannel;
    SEPARATOR_O
    o_stream << i_value.m_blurOnlyEmpty;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveStartTime;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveTime;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveTimeOffset;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveSpeed;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveThickness;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveStrength;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveWidth;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveFadeIn;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveFadeOut;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveInvert;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveInner;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveOuter;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveTargetID;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveTarget;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenterMoving;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveRelative;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveMaxSize;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenterDirty;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenter;
    SEPARATOR_O
    o_stream << i_value.m_shockLineStartTime;
    SEPARATOR_O
    o_stream << i_value.m_shockLineTime;
    SEPARATOR_O
    o_stream << i_value.m_shockLineTimeOffset;
    SEPARATOR_O
    o_stream << i_value.m_shockLineSpeed;
    SEPARATOR_O
    o_stream << i_value.m_shockLineAxis;
    SEPARATOR_O
    o_stream << i_value.m_shockLineDirection;
    SEPARATOR_O
    o_stream << i_value.m_shockLineDual;
    SEPARATOR_O
    o_stream << i_value.m_shockLineInvert;
    SEPARATOR_O
    o_stream << i_value.m_shockLineScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_shockLineStrength;
    SEPARATOR_O
    o_stream << i_value.m_shockLineWidth;
    SEPARATOR_O
    o_stream << i_value.m_shockLineFadeIn;
    SEPARATOR_O
    o_stream << i_value.m_shockLineFadeOut;
    SEPARATOR_O
    o_stream << i_value.m_shockLineThickness;
    SEPARATOR_O
    o_stream << i_value.m_shockLineTargetID;
    SEPARATOR_O
    o_stream << i_value.m_shockLineTarget;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenterMoving;
    SEPARATOR_O
    o_stream << i_value.m_shockLineRelative;
    SEPARATOR_O
    o_stream << i_value.m_shockLineMaxSize;
    SEPARATOR_O
    o_stream << i_value.m_shockLineScreenOffset2;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenterDirty;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenter;
    SEPARATOR_O
    o_stream << i_value.m_glitchStrength;
    SEPARATOR_O
    o_stream << i_value.m_glitchSpeed;
    SEPARATOR_O
    o_stream << i_value.m_glitchSliceHeight;
    SEPARATOR_O
    o_stream << i_value.m_glitchMaxSliceXOff;
    SEPARATOR_O
    o_stream << i_value.m_glitchMaxColXOff;
    SEPARATOR_O
    o_stream << i_value.m_glitchMaxColYOff;
    SEPARATOR_O
    o_stream << i_value.m_glitchRelative;
    SEPARATOR_O
    o_stream << i_value.m_chromaticTargetX;
    SEPARATOR_O
    o_stream << i_value.m_chromaticTargetY;
    SEPARATOR_O
    o_stream << i_value.m_chromaticRelative;
    SEPARATOR_O
    o_stream << i_value.m_cGStartTime;
    SEPARATOR_O
    o_stream << i_value.m_cGTime;
    SEPARATOR_O
    o_stream << i_value.m_cGSpeed;
    SEPARATOR_O
    o_stream << i_value.m_cGRGBOffset;
    SEPARATOR_O
    o_stream << i_value.m_cGStrength;
    SEPARATOR_O
    o_stream << i_value.m_cGSegmentHeight;
    SEPARATOR_O
    o_stream << i_value.m_cGLineThickness;
    SEPARATOR_O
    o_stream << i_value.m_cGLineStrength;
    SEPARATOR_O
    o_stream << i_value.m_cGEnable;
    SEPARATOR_O
    o_stream << i_value.m_cGActive;
    SEPARATOR_O
    o_stream << i_value.m_cGRelative;
    SEPARATOR_O
    o_stream << i_value.m_cGRelativePos;
    SEPARATOR_O
    o_stream << i_value.m_pixelateTargetX;
    SEPARATOR_O
    o_stream << i_value.m_pixelateTargetY;
    SEPARATOR_O
    o_stream << i_value.m_pixelateSnapGrid;
    SEPARATOR_O
    o_stream << i_value.m_pixelatePixelating;
    SEPARATOR_O
    o_stream << i_value.m_pixelateRelative;
    SEPARATOR_O
    o_stream << i_value.m_pixelateHardEdges;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleSize;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleFade;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleStrength;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTargetID;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTintChannel;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleRelative;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleAdditive;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTint;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleCenter;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurSize;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurFade;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurTarget;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurTargetID;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurCenter;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurTargetX;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurTargetY;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurSpeedX;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurSpeedY;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurFollowEaseX;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurFollowEaseY;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurTargetIDX;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurTargetIDY;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurDual;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurRelative;
    SEPARATOR_O
    o_stream << i_value.m_bulgeValue;
    SEPARATOR_O
    o_stream << i_value.m_bulgeRelative;
    SEPARATOR_O
    o_stream << i_value.m_bulgeTargetID;
    SEPARATOR_O
    o_stream << i_value.m_bulgeRadius;
    SEPARATOR_O
    o_stream << i_value.m_bulgeCenter;
    SEPARATOR_O
    o_stream << i_value.m_bulgeScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetX;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetY;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetEnabledX;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetEnabledY;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetIDX;
    SEPARATOR_O
    o_stream << i_value.m_pinchTargetIDY;
    SEPARATOR_O
    o_stream << i_value.m_pinchCenter;
    SEPARATOR_O
    o_stream << i_value.m_pinchScreenOffset;
    SEPARATOR_O
    o_stream << i_value.m_pinchRelative;
    SEPARATOR_O
    o_stream << i_value.m_pinchRadius;
    SEPARATOR_O
    o_stream << i_value.m_pinchModifier;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleValue;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleUseLum;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleTintChannel;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleTint;
    SEPARATOR_O
    o_stream << i_value.m_sepiaValue;
    SEPARATOR_O
    o_stream << i_value.m_invertColorEditRGB;
    SEPARATOR_O
    o_stream << i_value.m_invertColorR;
    SEPARATOR_O
    o_stream << i_value.m_invertColorG;
    SEPARATOR_O
    o_stream << i_value.m_invertColorB;
    SEPARATOR_O
    o_stream << i_value.m_invertColorClampRGB;
    SEPARATOR_O
    o_stream << i_value.m_hueShiftDegrees;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCR;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCG;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCB;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBR;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBG;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBB;
    SEPARATOR_O
    o_stream << i_value.m_splitTargetRows;
    SEPARATOR_O
    o_stream << i_value.m_splitTargetCols;
    SEPARATOR_O
    o_stream << i_value.m_splitActive;
    SEPARATOR_O
    o_stream << i_value.m_minBlendingLayer;
    SEPARATOR_O
    o_stream << i_value.m_maxBlendingLayer;
    SEPARATOR_O
    o_stream << i_value.m_zLayerDirty;
    SEPARATOR_O
    o_stream << i_value.m_noPlayerParticles;
    SEPARATOR_O
    o_stream << i_value.m_usesShaders;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGJShaderState::describe() {
    int l_size = m_tweenActions.size();
    log::info("[PAGJShaderState - describe] m_tweenActions.size(): {}", l_size);
    int i = 0;
    for (gd::pair<int,GJValueTween> l_pair : m_tweenActions) {
        log::info("[PAGJShaderState - describe] m_tweenActions element {} key: {}", i, l_pair.first);
        log::info("[PAGJShaderState - describe] m_tweenActions element {} value:", i);
        reinterpret_cast<PAGJValueTween*>(&l_pair.second)->describe();
        i++;
    }
    i = 0;
    l_size = m_tweenTimes.size();
    log::info("[PAGJShaderState - describe] m_tweenTimes.size(): {}", l_size);
    for (gd::pair<int,double> l_pair : m_tweenTimes) {
        log::info("[PAGJShaderState - describe] m_tweenTimes element {} key: {}", i, l_pair.first);
        log::info("[PAGJShaderState - describe] m_tweenTimes element {} value: [{}]", i, l_pair.second);
        i++;
    }
    log::info("[PAGJShaderState - describe] m_time: {}", m_time);
    log::info("[PAGJShaderState - describe] m_prevTime: {}", m_prevTime);
    log::info("[PAGJShaderState - describe] m_startTime: {}", m_startTime);
    log::info("[PAGJShaderState - describe] m_textureScaleX: {}", m_textureScaleX);
    log::info("[PAGJShaderState - describe] m_textureScaleY: {}", m_textureScaleY);
    log::info("[PAGJShaderState - describe] m_blurRefColor: {}", m_blurRefColor);
    log::info("[PAGJShaderState - describe] m_blurIntensity: {}", m_blurIntensity);
    log::info("[PAGJShaderState - describe] m_blurRefChannel: {}", m_blurRefChannel);
    log::info("[PAGJShaderState - describe] m_blurOnlyEmpty: {}", m_blurOnlyEmpty);
    log::info("[PAGJShaderState - describe] m_shockWaveStartTime: {}", m_shockWaveStartTime);
    log::info("[PAGJShaderState - describe] m_shockWaveTime: {}", m_shockWaveTime);
    log::info("[PAGJShaderState - describe] m_shockWaveTimeOffset: {}", m_shockWaveTimeOffset);
    log::info("[PAGJShaderState - describe] m_shockWaveSpeed: {}", m_shockWaveSpeed);
    log::info("[PAGJShaderState - describe] m_shockWaveThickness: {}", m_shockWaveThickness);
    log::info("[PAGJShaderState - describe] m_shockWaveStrength: {}", m_shockWaveStrength);
    log::info("[PAGJShaderState - describe] m_shockWaveWidth: {}", m_shockWaveWidth);
    log::info("[PAGJShaderState - describe] m_shockWaveFadeIn: {}", m_shockWaveFadeIn);
    log::info("[PAGJShaderState - describe] m_shockWaveFadeOut: {}", m_shockWaveFadeOut);
    log::info("[PAGJShaderState - describe] m_shockWaveInvert: {}", m_shockWaveInvert);
    log::info("[PAGJShaderState - describe] m_shockWaveInner: {}", m_shockWaveInner);
    log::info("[PAGJShaderState - describe] m_shockWaveOuter: {}", m_shockWaveOuter);
    log::info("[PAGJShaderState - describe] m_shockWaveTargetID: {}", m_shockWaveTargetID);
    log::info("[PAGJShaderState - describe] m_shockWaveTarget: {}", m_shockWaveTarget);
    log::info("[PAGJShaderState - describe] m_shockWaveCenterMoving: {}", m_shockWaveCenterMoving);
    log::info("[PAGJShaderState - describe] m_shockWaveRelative: {}", m_shockWaveRelative);
    log::info("[PAGJShaderState - describe] m_shockWaveMaxSize: {}", m_shockWaveMaxSize);
    log::info("[PAGJShaderState - describe] m_shockWaveScreenOffset: {}", m_shockWaveScreenOffset);
    log::info("[PAGJShaderState - describe] m_shockWaveCenterDirty: {}", m_shockWaveCenterDirty);
    log::info("[PAGJShaderState - describe] m_shockWaveCenter: {}", m_shockWaveCenter);
    log::info("[PAGJShaderState - describe] m_shockLineStartTime: {}", m_shockLineStartTime);
    log::info("[PAGJShaderState - describe] m_shockLineTime: {}", m_shockLineTime);
    log::info("[PAGJShaderState - describe] m_shockLineTimeOffset: {}", m_shockLineTimeOffset);
    log::info("[PAGJShaderState - describe] m_shockLineSpeed: {}", m_shockLineSpeed);
    log::info("[PAGJShaderState - describe] m_shockLineAxis: {}", m_shockLineAxis);
    log::info("[PAGJShaderState - describe] m_shockLineDirection: {}", m_shockLineDirection);
    log::info("[PAGJShaderState - describe] m_shockLineDual: {}", m_shockLineDual);
    log::info("[PAGJShaderState - describe] m_shockLineInvert: {}", m_shockLineInvert);
    log::info("[PAGJShaderState - describe] m_shockLineScreenOffset: {}", m_shockLineScreenOffset);
    log::info("[PAGJShaderState - describe] m_shockLineStrength: {}", m_shockLineStrength);
    log::info("[PAGJShaderState - describe] m_shockLineWidth: {}", m_shockLineWidth);
    log::info("[PAGJShaderState - describe] m_shockLineFadeIn: {}", m_shockLineFadeIn);
    log::info("[PAGJShaderState - describe] m_shockLineFadeOut: {}", m_shockLineFadeOut);
    log::info("[PAGJShaderState - describe] m_shockLineThickness: {}", m_shockLineThickness);
    log::info("[PAGJShaderState - describe] m_shockLineTargetID: {}", m_shockLineTargetID);
    log::info("[PAGJShaderState - describe] m_shockLineTarget: {}", m_shockLineTarget);
    log::info("[PAGJShaderState - describe] m_shockLineCenterMoving: {}", m_shockLineCenterMoving);
    log::info("[PAGJShaderState - describe] m_shockLineRelative: {}", m_shockLineRelative);
    log::info("[PAGJShaderState - describe] m_shockLineMaxSize: {}", m_shockLineMaxSize);
    log::info("[PAGJShaderState - describe] m_shockLineScreenOffset2: {}", m_shockLineScreenOffset2);
    log::info("[PAGJShaderState - describe] m_shockLineCenterDirty: {}", m_shockLineCenterDirty);
    log::info("[PAGJShaderState - describe] m_shockLineCenter: {}", m_shockLineCenter);
    log::info("[PAGJShaderState - describe] m_glitchStrength: {}", m_glitchStrength);
    log::info("[PAGJShaderState - describe] m_glitchSpeed: {}", m_glitchSpeed);
    log::info("[PAGJShaderState - describe] m_glitchSliceHeight: {}", m_glitchSliceHeight);
    log::info("[PAGJShaderState - describe] m_glitchMaxSliceXOff: {}", m_glitchMaxSliceXOff);
    log::info("[PAGJShaderState - describe] m_glitchMaxColXOff: {}", m_glitchMaxColXOff);
    log::info("[PAGJShaderState - describe] m_glitchMaxColYOff: {}", m_glitchMaxColYOff);
    log::info("[PAGJShaderState - describe] m_glitchRelative: {}", m_glitchRelative);
    log::info("[PAGJShaderState - describe] m_chromaticTargetX: {}", m_chromaticTargetX);
    log::info("[PAGJShaderState - describe] m_chromaticTargetY: {}", m_chromaticTargetY);
    log::info("[PAGJShaderState - describe] m_chromaticRelative: {}", m_chromaticRelative);
    log::info("[PAGJShaderState - describe] m_cGStartTime: {}", m_cGStartTime);
    log::info("[PAGJShaderState - describe] m_cGTime: {}", m_cGTime);
    log::info("[PAGJShaderState - describe] m_cGSpeed: {}", m_cGSpeed);
    log::info("[PAGJShaderState - describe] m_cGRGBOffset: {}", m_cGRGBOffset);
    log::info("[PAGJShaderState - describe] m_cGStrength: {}", m_cGStrength);
    log::info("[PAGJShaderState - describe] m_cGSegmentHeight: {}", m_cGSegmentHeight);
    log::info("[PAGJShaderState - describe] m_cGLineThickness: {}", m_cGLineThickness);
    log::info("[PAGJShaderState - describe] m_cGLineStrength: {}", m_cGLineStrength);
    log::info("[PAGJShaderState - describe] m_cGEnable: {}", m_cGEnable);
    log::info("[PAGJShaderState - describe] m_cGActive: {}", m_cGActive);
    log::info("[PAGJShaderState - describe] m_cGRelative: {}", m_cGRelative);
    log::info("[PAGJShaderState - describe] m_cGRelativePos: {}", m_cGRelativePos);
    log::info("[PAGJShaderState - describe] m_pixelateTargetX: {}", m_pixelateTargetX);
    log::info("[PAGJShaderState - describe] m_pixelateTargetY: {}", m_pixelateTargetY);
    log::info("[PAGJShaderState - describe] m_pixelateSnapGrid: {}", m_pixelateSnapGrid);
    log::info("[PAGJShaderState - describe] m_pixelatePixelating: {}", m_pixelatePixelating);
    log::info("[PAGJShaderState - describe] m_pixelateRelative: {}", m_pixelateRelative);
    log::info("[PAGJShaderState - describe] m_pixelateHardEdges: {}", m_pixelateHardEdges);
    log::info("[PAGJShaderState - describe] m_lensCircleSize: {}", m_lensCircleSize);
    log::info("[PAGJShaderState - describe] m_lensCircleFade: {}", m_lensCircleFade);
    log::info("[PAGJShaderState - describe] m_lensCircleStrength: {}", m_lensCircleStrength);
    log::info("[PAGJShaderState - describe] m_lensCircleTargetID: {}", m_lensCircleTargetID);
    log::info("[PAGJShaderState - describe] m_lensCircleTintChannel: {}", m_lensCircleTintChannel);
    log::info("[PAGJShaderState - describe] m_lensCircleRelative: {}", m_lensCircleRelative);
    log::info("[PAGJShaderState - describe] m_lensCircleAdditive: {}", m_lensCircleAdditive);
    log::info("[PAGJShaderState - describe] m_lensCircleTint: {}", m_lensCircleTint);
    log::info("[PAGJShaderState - describe] m_lensCircleCenter: {}", m_lensCircleCenter);
    log::info("[PAGJShaderState - describe] m_lensCircleScreenOffset: {}", m_lensCircleScreenOffset);
    log::info("[PAGJShaderState - describe] m_radialBlurSize: {}", m_radialBlurSize);
    log::info("[PAGJShaderState - describe] m_radialBlurFade: {}", m_radialBlurFade);
    log::info("[PAGJShaderState - describe] m_radialBlurTarget: {}", m_radialBlurTarget);
    log::info("[PAGJShaderState - describe] m_radialBlurTargetID: {}", m_radialBlurTargetID);
    log::info("[PAGJShaderState - describe] m_radialBlurCenter: {}", m_radialBlurCenter);
    log::info("[PAGJShaderState - describe] m_radialBlurScreenOffset: {}", m_radialBlurScreenOffset);
    log::info("[PAGJShaderState - describe] m_motionBlurTargetX: {}", m_motionBlurTargetX);
    log::info("[PAGJShaderState - describe] m_motionBlurTargetY: {}", m_motionBlurTargetY);
    log::info("[PAGJShaderState - describe] m_motionBlurSpeedX: {}", m_motionBlurSpeedX);
    log::info("[PAGJShaderState - describe] m_motionBlurSpeedY: {}", m_motionBlurSpeedY);
    log::info("[PAGJShaderState - describe] m_motionBlurFollowEaseX: {}", m_motionBlurFollowEaseX);
    log::info("[PAGJShaderState - describe] m_motionBlurFollowEaseY: {}", m_motionBlurFollowEaseY);
    log::info("[PAGJShaderState - describe] m_motionBlurTargetIDX: {}", m_motionBlurTargetIDX);
    log::info("[PAGJShaderState - describe] m_motionBlurTargetIDY: {}", m_motionBlurTargetIDY);
    log::info("[PAGJShaderState - describe] m_motionBlurDual: {}", m_motionBlurDual);
    log::info("[PAGJShaderState - describe] m_motionBlurRelative: {}", m_motionBlurRelative);
    log::info("[PAGJShaderState - describe] m_bulgeValue: {}", m_bulgeValue);
    log::info("[PAGJShaderState - describe] m_bulgeRelative: {}", m_bulgeRelative);
    log::info("[PAGJShaderState - describe] m_bulgeTargetID: {}", m_bulgeTargetID);
    log::info("[PAGJShaderState - describe] m_bulgeRadius: {}", m_bulgeRadius);
    log::info("[PAGJShaderState - describe] m_bulgeCenter: {}", m_bulgeCenter);
    log::info("[PAGJShaderState - describe] m_bulgeScreenOffset: {}", m_bulgeScreenOffset);
    log::info("[PAGJShaderState - describe] m_pinchTargetX: {}", m_pinchTargetX);
    log::info("[PAGJShaderState - describe] m_pinchTargetY: {}", m_pinchTargetY);
    log::info("[PAGJShaderState - describe] m_pinchTargetEnabledX: {}", m_pinchTargetEnabledX);
    log::info("[PAGJShaderState - describe] m_pinchTargetEnabledY: {}", m_pinchTargetEnabledY);
    log::info("[PAGJShaderState - describe] m_pinchTargetIDX: {}", m_pinchTargetIDX);
    log::info("[PAGJShaderState - describe] m_pinchTargetIDY: {}", m_pinchTargetIDY);
    log::info("[PAGJShaderState - describe] m_pinchCenter: {}", m_pinchCenter);
    log::info("[PAGJShaderState - describe] m_pinchScreenOffset: {}", m_pinchScreenOffset);
    log::info("[PAGJShaderState - describe] m_pinchRelative: {}", m_pinchRelative);
    log::info("[PAGJShaderState - describe] m_pinchRadius: {}", m_pinchRadius);
    log::info("[PAGJShaderState - describe] m_pinchModifier: {}", m_pinchModifier);
    log::info("[PAGJShaderState - describe] m_grayscaleValue: {}", m_grayscaleValue);
    log::info("[PAGJShaderState - describe] m_grayscaleUseLum: {}", m_grayscaleUseLum);
    log::info("[PAGJShaderState - describe] m_grayscaleTintChannel: {}", m_grayscaleTintChannel);
    log::info("[PAGJShaderState - describe] m_grayscaleTint: {}", m_grayscaleTint);
    log::info("[PAGJShaderState - describe] m_sepiaValue: {}", m_sepiaValue);
    log::info("[PAGJShaderState - describe] m_invertColorEditRGB: {}", m_invertColorEditRGB);
    log::info("[PAGJShaderState - describe] m_invertColorR: {}", m_invertColorR);
    log::info("[PAGJShaderState - describe] m_invertColorG: {}", m_invertColorG);
    log::info("[PAGJShaderState - describe] m_invertColorB: {}", m_invertColorB);
    log::info("[PAGJShaderState - describe] m_invertColorClampRGB: {}", m_invertColorClampRGB);
    log::info("[PAGJShaderState - describe] m_hueShiftDegrees: {}", m_hueShiftDegrees);
    log::info("[PAGJShaderState - describe] m_colorChangeCR: {}", m_colorChangeCR);
    log::info("[PAGJShaderState - describe] m_colorChangeCG: {}", m_colorChangeCG);
    log::info("[PAGJShaderState - describe] m_colorChangeCB: {}", m_colorChangeCB);
    log::info("[PAGJShaderState - describe] m_colorChangeBR: {}", m_colorChangeBR);
    log::info("[PAGJShaderState - describe] m_colorChangeBG: {}", m_colorChangeBG);
    log::info("[PAGJShaderState - describe] m_colorChangeBB: {}", m_colorChangeBB);
    log::info("[PAGJShaderState - describe] m_splitTargetRows: {}", m_splitTargetRows);
    log::info("[PAGJShaderState - describe] m_splitTargetCols: {}", m_splitTargetCols);
    log::info("[PAGJShaderState - describe] m_splitActive: {}", m_splitActive);
    log::info("[PAGJShaderState - describe] m_minBlendingLayer: {}", m_minBlendingLayer);
    log::info("[PAGJShaderState - describe] m_maxBlendingLayer: {}", m_maxBlendingLayer);
    log::info("[PAGJShaderState - describe] m_zLayerDirty: {}", m_zLayerDirty);
    log::info("[PAGJShaderState - describe] m_noPlayerParticles: {}", m_noPlayerParticles);
    log::info("[PAGJShaderState - describe] m_usesShaders: {}", m_usesShaders);
}
#endif