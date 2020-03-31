//****************************************************************************************
//
//  Copyright (c) 2015-2020, Yoshifumi Nakamura <nakamura@riken.jp>
//  Copyright (c) 2015-2020, Yuta Mukai         <mukai.yuta@fujitsu.com>
//  Copyright (c) 2018-2020, Ken-Ichi Ishikawa  <ishikawa@theo.phys.sci.hirosima-u.ac.jp>
//  Copyright (c) 2019-2020, Issaku Kanamori    <kanamori-i@riken.jp>
//
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer. 
//
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer listed
//    in this license in the documentation and/or other materials
//    provided with the distribution.
//
//  * Neither the name of the copyright holders nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
//
//----------------------------------------------------------------------------------------
//  ACKNOWLEDGMENT
//
//  This software has been developed in a co-design working group for the lattice QCD
//  supported by MEXT's programs for the Development and Improvement for the Next
//  Generation Ultra High-Speed Computer System, under its Subsidies for Operating the
//  Specific Advanced Large Research Facilities, and Priority Issue 9 
//  (Elucidation of the Fundamental Laws and Evolution of the Universe) to be tackled by
//  using the Supercomputer Fugaku.
//
//****************************************************************************************
#ifndef QWS_INTRINSICS_DOUBLE
#define QWS_INTRINSICS_DOUBLE

//=0;
inline rvecd_t fzero_d(void) __attribute__((always_inline));
inline rvecd_t fzero_d(void){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = 0;}
  return tmp;
}
//=a;
inline rvecd_t fcopy_d(const rvecd_t &a) __attribute__((always_inline));
inline rvecd_t fcopy_d(const rvecd_t &a){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i];}
  return tmp;
}
//=-a;
inline rvecd_t mfcopy_d(const rvecd_t &a) __attribute__((always_inline));
inline rvecd_t mfcopy_d(const rvecd_t &a){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] =-a.v[i];}
  return tmp;
}

//a[v]=a;
inline rvecd_t fload1_d(const double &a) __attribute__((always_inline));
inline rvecd_t fload1_d(const double &a){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a;}
  return tmp;
}
// a+b;
inline rvecd_t fadd_d(const rvecd_t &a, const rvecd_t &b) __attribute__((always_inline));
inline rvecd_t fadd_d(const rvecd_t &a, const rvecd_t &b){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i]+b.v[i];}
  return tmp;
}
// a-b;
inline rvecd_t fsub_d(const rvecd_t &a, const rvecd_t &b) __attribute__((always_inline));
inline rvecd_t fsub_d(const rvecd_t &a, const rvecd_t &b){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i]-b.v[i];}
  return tmp;
}

// a*b;
inline rvecd_t fmul_d(const rvecd_t &a, const rvecd_t &b) __attribute__((always_inline));
inline rvecd_t fmul_d(const rvecd_t &a, const rvecd_t &b){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i]*b.v[i];}
  return tmp;
}

// a*b+c;
inline rvecd_t fmadd_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c) __attribute__((always_inline));
inline rvecd_t fmadd_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i]*b.v[i]+c.v[i];}
  return tmp;
}

//-a*b+c;
inline rvecd_t fnmadd_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c) __attribute__((always_inline));
inline rvecd_t fnmadd_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] =-a.v[i]*b.v[i]+c.v[i];}
  return tmp;
}

// a*b-c;
inline rvecd_t fmsub_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c) __attribute__((always_inline));
inline rvecd_t fmsub_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] = a.v[i]*b.v[i]-c.v[i];}
  return tmp;
}

//-a*b-c;
inline rvecd_t fnmsub_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c) __attribute__((always_inline));
inline rvecd_t fnmsub_d(const rvecd_t &a, const rvecd_t &b,const rvecd_t &c){
  int i;
  rvecd_t tmp;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp.v[i] =-a.v[i]*b.v[i]-c.v[i];}
  return tmp;
}

//=sum(a);
inline double fsum_d(const rvecd_t &a) __attribute__((always_inline));
inline double fsum_d(const rvecd_t &a){
  int i;
  double tmp=0;
#pragma loop nounroll
  for (i=0;i<VLEND;i++){tmp += a.v[i];}
  return tmp;
}
#endif
