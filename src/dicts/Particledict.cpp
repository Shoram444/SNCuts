// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdIParticledict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Particle.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_Particle(void *p = 0);
   static void *newArray_Particle(Long_t size, void *p);
   static void delete_Particle(void *p);
   static void deleteArray_Particle(void *p);
   static void destruct_Particle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Particle*)
   {
      ::Particle *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Particle >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Particle", ::Particle::Class_Version(), "Particle.hh", 14,
                  typeid(::Particle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Particle::Dictionary, isa_proxy, 4,
                  sizeof(::Particle) );
      instance.SetNew(&new_Particle);
      instance.SetNewArray(&newArray_Particle);
      instance.SetDelete(&delete_Particle);
      instance.SetDeleteArray(&deleteArray_Particle);
      instance.SetDestructor(&destruct_Particle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Particle*)
   {
      return GenerateInitInstanceLocal((::Particle*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Particle*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Particle::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Particle::Class_Name()
{
   return "Particle";
}

//______________________________________________________________________________
const char *Particle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Particle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Particle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Particle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Particle::Streamer(TBuffer &R__b)
{
   // Stream an object of class Particle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Particle::Class(),this);
   } else {
      R__b.WriteClassBuffer(Particle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Particle(void *p) {
      return  p ? new(p) ::Particle : new ::Particle;
   }
   static void *newArray_Particle(Long_t nElements, void *p) {
      return p ? new(p) ::Particle[nElements] : new ::Particle[nElements];
   }
   // Wrapper around operator delete
   static void delete_Particle(void *p) {
      delete ((::Particle*)p);
   }
   static void deleteArray_Particle(void *p) {
      delete [] ((::Particle*)p);
   }
   static void destruct_Particle(void *p) {
      typedef ::Particle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Particle

namespace {
  void TriggerDictionaryInitialization_Particledict_Impl() {
    static const char* headers[] = {
"Particle.hh",
0
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/snsw/opt/root-6.16.00/include/root",
"/sps/nemo/scratch/mpetro/Projects/FalaiseModules/SNCuts/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Particledict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Particle.hh")))  Particle;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Particledict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Particle.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Particle", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Particledict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Particledict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Particledict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Particledict() {
  TriggerDictionaryInitialization_Particledict_Impl();
}
