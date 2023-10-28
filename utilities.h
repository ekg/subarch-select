#ifndef SUBARCH_SELECT_UTILS_H
#define SUBARCH_SELECT_UTILS_H

#include "cpuinfo_x86.h"
#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace cpu_features;

// For C++, add `using namespace cpu_features;`
static const X86Features features = GetX86Info().features;

static bool has_feature(const std::string f) {
    if (f == "x86-64-v2") return features.cx16 && features.popcnt && features.sse3 && features.sse4_1 && features.sse4_2 && features.ssse3;
    // ^^ missing is LAHF-SAHF
    if (f == "x86-64-v3") return features.avx && features.avx2 && features.bmi1 && features.bmi2 && features.f16c && features.movbe && features.cx16 && features.popcnt && features.sse3 && features.sse4_1 && features.sse4_2 && features.ssse3;
    // TODO: which is plain "FMA"?
    // missing is LZCNT & OSXSAVE
    if (f == "x86-64-v4") return features.avx512f && features.avx512bw && features.avx512cd && features.avx512dq && features.avx512vl && features.avx && features.avx2 && features.bmi1 && features.bmi2 && features.f16c && features.movbe && features.cx16 && features.popcnt && features.sse3 && features.sse4_1 && features.sse4_2 && features.ssse3;
    if (f == "fpu") return features.fpu;
    if (f == "tsc") return features.tsc;
    if (f == "cx8") return features.cx8;
    if (f == "clfsh") return features.clfsh;
    if (f == "mmx") return features.mmx;
    if (f == "aes") return features.aes;
    if (f == "erms") return features.erms;
    if (f == "f16c") return features.f16c;
    if (f == "fma4") return features.fma4;
    if (f == "fma3") return features.fma3;
    if (f == "vaes") return features.vaes;
    if (f == "vpclmulqdq") return features.vpclmulqdq;
    if (f == "bmi1") return features.bmi1;
    if (f == "hle") return features.hle;
    if (f == "bmi2") return features.bmi2;
    if (f == "rtm") return features.rtm;
    if (f == "rdseed") return features.rdseed;
    if (f == "clflushopt") return features.clflushopt;
    if (f == "clwb") return features.clwb;
    if (f == "sse") return features.sse;
    if (f == "sse2") return features.sse2;
    if (f == "sse3") return features.sse3;
    if (f == "ssse3") return features.ssse3;
    if (f == "sse4_1") return features.sse4_1;
    if (f == "sse4_2") return features.sse4_2;
    if (f == "sse4a") return features.sse4a;
    if (f == "avx") return features.avx;
    //if (f == "avx_vnni") return features.avx_vnni;
    if (f == "avx2") return features.avx2;
    if (f == "avx512f") return features.avx512f;
    if (f == "avx512cd") return features.avx512cd;
    if (f == "avx512er") return features.avx512er;
    if (f == "avx512pf") return features.avx512pf;
    if (f == "avx512bw") return features.avx512bw;
    if (f == "avx512dq") return features.avx512dq;
    if (f == "avx512vl") return features.avx512vl;
    if (f == "avx512ifma") return features.avx512ifma;
    if (f == "avx512vbmi") return features.avx512vbmi;
    if (f == "avx512vbmi2") return features.avx512vbmi2;
    if (f == "avx512vnni") return features.avx512vnni;
    if (f == "avx512bitalg") return features.avx512bitalg;
    if (f == "avx512vpopcntdq") return features.avx512vpopcntdq;
    if (f == "avx512_4vnniw") return features.avx512_4vnniw;
    if (f == "avx512_4vbmi2") return features.avx512_4vbmi2;
    if (f == "avx512_second_fma") return features.avx512_second_fma;
    if (f == "avx512_4fmaps") return features.avx512_4fmaps;
    if (f == "avx512_bf16") return features.avx512_bf16;
    if (f == "avx512_vp2intersect") return features.avx512_vp2intersect;
    //if (f == "avx512_fp16") return features.avx512_fp16;
    if (f == "amx_bf16") return features.amx_bf16;
    if (f == "amx_tile") return features.amx_tile;
    if (f == "amx_int8") return features.amx_int8;
    if (f == "pclmulqdq") return features.pclmulqdq;
    if (f == "smx") return features.smx;
    if (f == "sgx") return features.sgx;
    if (f == "cx16") return features.cx16;
    if (f == "sha") return features.sha;
    if (f == "popcnt") return features.popcnt;
    if (f == "movbe") return features.movbe;
    if (f == "rdrnd") return features.rdrnd;
    if (f == "dca") return features.dca;
    if (f == "ss") return features.ss;
    // not yet supported by debian libcpufeatures-dev
    //if (f == "adx") return features.adx;
    //if (f == "lzcnt") return features.lzcnt;
    //if (f == "gfni") return features.gfni;
    //if (f == "movdiri") return features.movdiri;
    //if (f == "movdir64b") return features.movdir64b;
    //if (f == "fs_rep_mov") return features.fs_rep_mov;
    //if (f == "fz_rep_movsb") return features.fz_rep_movsb;
    //if (f == "fs_rep_stosb") return features.fs_rep_stosb;
    //if (f == "fs_rep_cmpsb_scasb") return features.fs_rep_cmpsb_scasb;
    return false;
}

static bool is_matching_features(const std::string s) {
    std::istringstream iss(s);
    std::string feature;
    while(std::getline(iss, feature, ',')) {
        if (!has_feature(feature)) {
            return false;
        }
    }
    return true;
}

#endif
