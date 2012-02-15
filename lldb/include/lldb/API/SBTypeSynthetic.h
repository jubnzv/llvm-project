//===-- SBTypeSynthetic.h -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBTypeSynthetic_h_
#define LLDB_SBTypeSynthetic_h_

#include "lldb/API/SBDefines.h"

namespace lldb {
    
    class SBTypeSynthetic
    {
    public:
        
        SBTypeSynthetic();
        
        static SBTypeSynthetic
        CreateWithClassName (const char* data,
                             uint32_t options = 0); // see lldb::eTypeOption values
        
        static SBTypeSynthetic
        CreateWithScriptCode (const char* data,
                              uint32_t options = 0); // see lldb::eTypeOption values
        
        SBTypeSynthetic (const lldb::SBTypeSynthetic &rhs);
        
        ~SBTypeSynthetic ();
        
        bool
        IsValid() const;
        
        bool
        IsClassCode();

        bool
        IsClassName();
        
        const char*
        GetData ();
        
        void
        SetClassName (const char* data);
        
        void
        SetClassCode (const char* data);
                
        uint32_t
        GetOptions ();
        
        void
        SetOptions (uint32_t);
        
        bool
        GetDescription (lldb::SBStream &description, 
                        lldb::DescriptionLevel description_level);
        
        lldb::SBTypeSynthetic &
        operator = (const lldb::SBTypeSynthetic &rhs);

        bool
        IsEqualTo (lldb::SBTypeSynthetic &rhs);
        
        bool
        operator == (lldb::SBTypeSynthetic &rhs);
        
        bool
        operator != (lldb::SBTypeSynthetic &rhs);
        
    protected:
        friend class SBDebugger;
        friend class SBTypeCategory;
        
        lldb::TypeSyntheticImplSP
        GetSP ();
        
        void
        SetSP (const lldb::TypeSyntheticImplSP &typefilter_impl_sp);    
        
        lldb::TypeSyntheticImplSP m_opaque_sp;
        
        SBTypeSynthetic (const lldb::TypeSyntheticImplSP &);
        
        bool
        CopyOnWrite_Impl();
        
    };
    
    
} // namespace lldb

#endif // LLDB_SBTypeSynthetic_h_
