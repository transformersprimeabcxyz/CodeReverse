////////////////////////////////////////////////////////////////////////////
// codereverse.h
// Copyright (C) 2013 Katayama Hirofumi MZ.  All rights reserved.
////////////////////////////////////////////////////////////////////////////
// This file is part of CodeReverse.
//
// CodeReverse is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CodeReverse is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CodeReverse.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////
// logo

extern LPCSTR cr_logo;

////////////////////////////////////////////////////////////////////////////

#include "include/cr.h"

////////////////////////////////////////////////////////////////////////////
// ADDR32, ADDR64 (virtual address)

typedef DWORD     ADDR32;
typedef ULONGLONG ADDR64;

////////////////////////////////////////////////////////////////////////////
// TBOOL - tri-state logical value

class TBOOL
{
public:
    TBOOL();
    TBOOL(BOOL b);
    TBOOL(const TBOOL& tb);
    virtual ~TBOOL();
    TBOOL& operator=(BOOL b);
    TBOOL& operator=(const TBOOL& tb);
    bool operator==(const TBOOL& tb) const;
    bool operator!=(const TBOOL& tb) const;
    VOID clear();

    BOOL CanBeTrue() const;
    BOOL CanBeFalse() const;
    BOOL IsUnknown() const;

    TBOOL& IsFalse(const TBOOL& tb);
    TBOOL& IsTrue(const TBOOL& tb);
    TBOOL& LogicalAnd(const TBOOL& tb1, const TBOOL& tb2);
    TBOOL& LogicalOr(const TBOOL& tb1, const TBOOL& tb2);
    TBOOL& LogicalNot(const TBOOL& tb1);
    TBOOL& Equal(const TBOOL& tb1, const TBOOL& tb2);
    TBOOL& NotEqual(const TBOOL& tb1, const TBOOL& tb2);

public:
    enum TBVALUE
    {
        TB_UNKNOWN, TB_FALSE, TB_TRUE
    };
    TBVALUE m_value;
};

////////////////////////////////////////////////////////////////////////////
// VECSET<ITEM_T>

template <typename ITEM_T>
class VECSET
{
public:
    VECSET();
    VECSET(const VECSET<ITEM_T>& vs);
    VECSET& operator=(const VECSET<ITEM_T>& vs);
    void Copy(const VECSET<ITEM_T>& vs);
    virtual ~VECSET();

    ITEM_T& operator[](SIZE_T index);
    const ITEM_T& operator[](SIZE_T index) const;
    SIZE_T size() const;
    bool empty() const;
    VOID clear();
    VOID insert(const ITEM_T& item);
    VOID insertIfNotFound(const ITEM_T& item);
    bool operator==(const VECSET<ITEM_T>& vs) const;
    bool operator!=(const VECSET<ITEM_T>& vs) const;
    SIZE_T count(const ITEM_T& item) const;
    BOOL Find(const ITEM_T& item) const;
    VOID sort();
    VOID uniq();
    VOID erase(const ITEM_T& item);
    VOID swap(VECSET<ITEM_T>& vs);
    VOID resize(SIZE_T size);

public:
    std::vector<ITEM_T> m_items;
};

////////////////////////////////////////////////////////////////////////////
// VECSET<ITEM_T> methods

template <typename ITEM_T>
VECSET<ITEM_T>::VECSET()
{
}

template <typename ITEM_T>
VECSET<ITEM_T>::VECSET(const VECSET<ITEM_T>& vs) : m_items(vs.m_items)
{
}

template <typename ITEM_T>
VECSET<ITEM_T>& VECSET<ITEM_T>::operator=(const VECSET<ITEM_T>& vs)
{
    m_items = vs.m_items;
    return *this;
}

template <typename ITEM_T>
void VECSET<ITEM_T>::Copy(const VECSET<ITEM_T>& vs)
{
    m_items = vs.m_items;
}

template <typename ITEM_T>
/*virtual*/ VECSET<ITEM_T>::~VECSET()
{
}

template <typename ITEM_T>
ITEM_T& VECSET<ITEM_T>::operator[](SIZE_T index)
{
    return m_items[index];
}

template <typename ITEM_T>
const ITEM_T& VECSET<ITEM_T>::operator[](SIZE_T index) const
{
    return m_items[index];
}

template <typename ITEM_T>
SIZE_T VECSET<ITEM_T>::size() const
{
    return m_items.size();
}

template <typename ITEM_T>
bool VECSET<ITEM_T>::empty() const
{
    return m_items.size() == 0;
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::clear()
{
    m_items.clear();
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::insert(const ITEM_T& item)
{
    m_items.push_back(item);
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::insertIfNotFound(const ITEM_T& item)
{
    if (!Find(item))
        insert(item);
}

template <typename ITEM_T>
bool VECSET<ITEM_T>::operator==(const VECSET<ITEM_T>& vs) const
{
    if (m_items.size() != vs.m_items.size())
        return false;

    for (SIZE_T i = 0; i < m_items.size(); i++)
    {
        if (m_items[i] != vs.m_items[i])
            return false;
    }
    return true;
}

template <typename ITEM_T>
bool VECSET<ITEM_T>::operator!=(const VECSET<ITEM_T>& vs) const
{
    return !(*this == vs);
}

template <typename ITEM_T>
SIZE_T VECSET<ITEM_T>::count(const ITEM_T& item) const
{
    SIZE_T count = 0;
    for (SIZE_T i = 0; i < m_items.size(); i++)
    {
        if (m_items[i] == item)
            count++;
    }
    return count;
}

template <typename ITEM_T>
BOOL VECSET<ITEM_T>::Find(const ITEM_T& item) const
{
    for (SIZE_T i = 0; i < m_items.size(); i++)
    {
        if (m_items[i] == item)
            return TRUE;
    }
    return FALSE;
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::sort()
{
    std::sort(m_items.begin(), m_items.end());
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::uniq()
{
    std::unique(m_items.begin(), m_items.end());
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::erase(const ITEM_T& item)
{
    SIZE_T i, j, count = m_items.size();
    for (i = j = 0; i < count; i++)
    {
        if (m_items[i] != item)
        {
            m_items[j++] = m_items[i];
        }
    }
    if (i != j)
        m_items.resize(j);
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::swap(VECSET<ITEM_T>& vs)
{
    m_items.swap(vs.m_items);
}

template <typename ITEM_T>
VOID VECSET<ITEM_T>::resize(SIZE_T size)
{
    m_items.resize(size);
}

namespace std
{
    template <typename ITEM_T>
    inline void swap(VECSET<ITEM_T>& vs1, VECSET<ITEM_T>& vs2)
    {
        vs1.swap(vs2);
    }
}

////////////////////////////////////////////////////////////////////////////
// ADDR32SET, ADDR64SET

typedef VECSET<ADDR32> ADDR32SET;
typedef VECSET<ADDR64> ADDR64SET;

////////////////////////////////////////////////////////////////////////////
// CONDCODE - condition code

enum CONDCODE
{
    C_A, C_AE, C_B, C_BE, C_C, C_E, C_G, C_GE, C_L, C_LE, C_NA, C_NAE,
    C_NB, C_NBE, C_NC, C_NE, C_NG, C_NGE, C_NL, C_NLE, C_NO, C_NP,
    C_NS, C_NZ, C_O, C_P, C_PE, C_PO, C_S, C_Z,
    C_NONE = -1
};

////////////////////////////////////////////////////////////////////////////
// x86 registers

enum X86_REGTYPE
{
    X86_CRREG = 0,
    X86_DRREG,
    X86_FPUREG,
    X86_MMXREG,
    X86_REG8,
    X86_REG8X,
    X86_REG16,
    X86_REG32,
    X86_REG64,
    X86_SEGREG,
    X86_XMMREG,
    X86_YMMREG,
    X86_COMPREG32,      // compound registry
    X86_COMPREG64,      // compound registry
    X86_COMPREG128,     // compound registry
    X86_FLAG,           // flag
    X86_REGNONE = -1
};

X86_REGTYPE cr_reg_get_type(LPCSTR name, INT bits);
DWORD       cr_reg_get_size(LPCSTR name, INT bits);
BOOL        cr_reg_in_reg(LPCSTR reg1, LPCSTR reg2);
BOOL        cr_reg_overlaps_reg(LPCSTR reg1, LPCSTR reg2);

////////////////////////////////////////////////////////////////////////////
// x86 flags

enum X86_FLAGTYPE
{
    X86_FLAG_NONE = 0,
    X86_FLAG_CF = (1 << 0),     // carry flag
    X86_FLAG_PF = (1 << 2),     // parity flag
    X86_FLAG_AF = (1 << 4),     // auxiliary flag
    X86_FLAG_ZF = (1 << 6),     // zero flag
    X86_FLAG_SF = (1 << 7),     // sign flag
    X86_FLAG_TF = (1 << 8),     // trap flag
    X86_FLAG_IF = (1 << 9),     // interrupt enable flag
    X86_FLAG_DF = (1 << 10),    // direction flag
    X86_FLAG_OF = (1 << 11),    // overflow flag
};

struct X86_FLAGS
{
    union
    {
        WORD flags;
        DWORD eflags;
        ULONGLONG rflags;
        struct
        {
            DWORD CF        : 1;    // carry flag
            DWORD ignore1   : 1;
            DWORD PF        : 1;    // parity flag
            DWORD ignore2   : 1;
            DWORD AF        : 1;    // auxiliary flag
            DWORD ignore3   : 1;
            DWORD ZF        : 1;    // zero flag
            DWORD SF        : 1;    // sign flag
            DWORD TF        : 1;    // trap flag
            DWORD IF        : 1;    // interrupt flag
            DWORD DF        : 1;    // direction flag
            DWORD OF        : 1;    // overflow flag
            DWORD ignore4   : 4;
            DWORD ignore5   : 16;
        } flag;
    };
};

X86_FLAGTYPE cr_flag_get_type(LPCSTR name, INT bits);
LPCSTR       cr_flag_get_name(X86_FLAGTYPE type, INT bits);

////////////////////////////////////////////////////////////////////////////
// ASMCODETYPE - assembly code type

enum ASMCODETYPE
{
    ACT_MISC,    // misc
    ACT_JMP,     // jump
    ACT_JCC,     // conditional jump
    ACT_CALL,    // call
    ACT_LOOP,    // loop
    ACT_RETURN,  // ret
    ACT_STACKOP, // stack operation
    ACT_UNKNOWN  // unknown
};

////////////////////////////////////////////////////////////////////////////
// OPERANDTYPE - type of operand

enum OPERANDTYPE
{
    OT_NONE,    // none
    OT_REG,     // registry
    OT_MEMREG,  // memory access by a register
    OT_MEMIMM,  // memory access by an immediate
    OT_MEMEXP,  // memory access by an expression
    OT_IMM,     // immediate
    OT_API      // API
};

////////////////////////////////////////////////////////////////////////////
// OPERAND - operand

class OPERAND
{
public:
    OPERAND();
    OPERAND(const OPERAND& opr);
    OPERAND& operator=(const OPERAND& opr);
    virtual ~OPERAND();
    VOID Copy(const OPERAND& opr);
    VOID clear();
    bool operator==(const OPERAND& opr) const;
    bool operator!=(const OPERAND& opr) const;

public:
    VOID SetReg(LPCSTR name);
    VOID SetAPI(LPCSTR api);
    VOID SetLabel(LPCSTR label);
    VOID SetMemImm(ADDR64 addr);
    VOID SetMemExp(LPCSTR exp_);
    VOID SetImm32(ADDR32 val, BOOL is_signed);
    VOID SetImm64(ADDR64 val, BOOL is_signed);

public:
    // accessors
    string&         Text();
    OPERANDTYPE&    OperandType();
    DWORD&          Size();
    ADDR32&         Value32();
    ADDR64&         Value64();
    string&         Exp();
    string&         DataType();
    TBOOL&          IsInteger();
    TBOOL&          IsPointer();
    TBOOL&          IsFunction();
    // const accessors
    const string&         Text() const;
    const OPERANDTYPE&    OperandType() const;
    const DWORD&          Size() const;
    const ADDR32&         Value32() const;
    const ADDR64&         Value64() const;
    const string&         Exp() const;
    const string&         DataType() const;
    const TBOOL&          IsInteger() const;
    const TBOOL&          IsPointer() const;
    const TBOOL&          IsFunction() const;

protected:
    struct OPERANDIMPL;
    OPERANDIMPL *m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// OPERANDSET

typedef VECSET<OPERAND> OPERANDSET;

////////////////////////////////////////////////////////////////////////////
// STACK

class STACK : public OPERANDSET
{
public:
    STACK();
    STACK(const STACK& s);
    STACK& operator=(const STACK& s);
    virtual ~STACK();
    VOID Copy(const STACK& s);
    VOID clear();
    bool operator==(const STACK& s) const;
    bool operator!=(const STACK& s) const;

public:
    VOID Push(const OPERAND& opr);
    VOID Pop(OPERAND& opr);

    DWORD GetSP();
    VOID SetSP(DWORD sp);
    VOID AddSP(SIZE_T size);
    VOID SubSP(SIZE_T size);
    VOID GetFromSP(SIZE_T index, OPERAND& opr);
    VOID SetFromSP(SIZE_T index, const OPERAND& opr);

    DWORD GetBP();
    VOID SetBP(DWORD bp);
    VOID AddBP(SIZE_T size);
    VOID SubBP(SIZE_T size);
    VOID GetFromBP(SIZE_T index, OPERAND& opr);
    VOID SetFromBP(SIZE_T index, const OPERAND& opr);

protected:
    SIZE_T m_minussp;
    SIZE_T m_minusbp;
};

////////////////////////////////////////////////////////////////////////////
// STACKSET

typedef VECSET<STACK> STACKSET;

////////////////////////////////////////////////////////////////////////////
// ASMCODE32 - assembly code of 64-bit mode

class ASMCODE32
{
public:
    ASMCODE32();
    ASMCODE32(const ASMCODE32& ac);
    ASMCODE32& operator=(const ASMCODE32& ac);
    virtual ~ASMCODE32();
    VOID Copy(const ASMCODE32& ac);
    VOID clear();

public:
    // accessors
    ADDR32SET&          Funcs();
    ADDR32&             Addr();
    string&             Name();
    OPERANDSET&         Operands();
    OPERAND*            Operand(SIZE_T index);
    vector<BYTE>&       Codes();
    ASMCODETYPE&        AsmCodeType();
    CONDCODE&           CondCode();
    // const accessors
    const ADDR32SET&          Funcs() const;
    const ADDR32&             Addr() const;
    const string&             Name() const;
    const OPERANDSET&         Operands() const;
    const OPERAND*            Operand(SIZE_T index) const;
    const vector<BYTE>&       Codes() const;
    const ASMCODETYPE&        AsmCodeType() const;
    const CONDCODE&           CondCode() const;

protected:
    struct ASMCODE32IMPL;
    ASMCODE32IMPL *m_pImpl;
};
typedef ASMCODE32 *LPASMCODE32;

////////////////////////////////////////////////////////////////////////////
// ASMCODE64 - assembly code of 64-bit mode

class ASMCODE64
{
public:
    ASMCODE64();
    ASMCODE64(const ASMCODE64& ac);
    ASMCODE64& operator=(const ASMCODE64& ac);
    virtual ~ASMCODE64();
    VOID Copy(const ASMCODE64& ac);
    VOID clear();

public:
    // accessors
    ADDR64SET&          Funcs();
    ADDR64&             Addr();
    string&             Name();
    OPERANDSET&         Operands();
    OPERAND*            Operand(SIZE_T index);
    vector<BYTE>&       Codes();
    ASMCODETYPE&        AsmCodeType();
    CONDCODE&           CondCode();
    // const accessors
    const ADDR64SET&          Funcs() const;
    const ADDR64&             Addr() const;
    const string&             Name() const;
    const OPERANDSET&         Operands() const;
    const OPERAND*            Operand(SIZE_T index) const;
    const vector<BYTE>&       Codes() const;
    const ASMCODETYPE&        AsmCodeType() const;
    const CONDCODE&           CondCode() const;

protected:
    struct ASMCODE64IMPL;
    ASMCODE64IMPL *m_pImpl;
};
typedef ASMCODE64 *LPASMCODE64;

////////////////////////////////////////////////////////////////////////////
// BLOCK32 - a node of control flow graph (CFG) for 32-bit mode

class BLOCK32
{
public:
    BLOCK32();
    BLOCK32(const BLOCK32& b);
    BLOCK32& operator=(const BLOCK32& b);
    VOID Copy(const BLOCK32& b);
    virtual ~BLOCK32();
    VOID clear();

public: // accessors
          ADDR32& Addr();
    const ADDR32& Addr() const;
          VECSET<ASMCODE32>& AsmCodes();
    const VECSET<ASMCODE32>& AsmCodes() const;
    BLOCK32*& NextBlock1();
    BLOCK32*& NextBlock2();
          ADDR32& NextAddr1();
    const ADDR32& NextAddr1() const;
          ADDR32& NextAddr2();
    const ADDR32& NextAddr2() const;

protected:
    struct BLOCK32IMPL;
    BLOCK32IMPL *m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// BLOCK64 - a node of control flow graph (CFG) for 64-bit mode

class BLOCK64
{
public:
    BLOCK64();
    BLOCK64(const BLOCK64& b);
    BLOCK64& operator=(const BLOCK64& b);
    VOID Copy(const BLOCK64& b);
    virtual ~BLOCK64();
    VOID clear();

public: // accessors
          ADDR64& Addr();
    const ADDR64& Addr() const;
          VECSET<ASMCODE64>& AsmCodes();
    const VECSET<ASMCODE64>& AsmCodes() const;
    BLOCK64*& NextBlock1();
    BLOCK64*& NextBlock2();
          ADDR64& NextAddr1();
    const ADDR64& NextAddr1() const;
          ADDR64& NextAddr2();
    const ADDR64& NextAddr2() const;

protected:
    struct BLOCK64IMPL;
    BLOCK64IMPL *m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// FUNCTYPE - function type

enum FUNCTYPE
{
    FT_UNKNOWN,             // unknown type

    FT_CDECL,               // __cdecl
    FT_CDECLVA,             // __cdecl (varargs)

    FT_STDCALL,             // __stdcall

    FT_FASTCALL,            // __fastcall
    FT_MSFASTCALL,          // Microsoft fastcall
    FT_BORFASTCALL,         // Borland fastcall
    FT_WCFASTCALL,          // Watcom fastcall

    FT_THISCALL,            // thiscall
    FT_GNUTHISCALL,         // GNU thiscall
    FT_MSTHISCALL,          // Microsoft thiscall

    FT_JUMPER,              // jumper function

    FT_64BIT,               // 64-bit function
    FT_64BITVA,             // 64-bit function (varargs)

    FT_INVALID              // invalid function
};

////////////////////////////////////////////////////////////////////////////
// FUNCTIONFLAGS - function flags

enum FUNCTIONFLAGS
{
    FF_NOTSTDCALL               = (1 << 0), // not __stdcall
    FF_DONTDECOMPBUTDISASM      = (1 << 1), // don't decompile but disasm
    FF_IGNORE                   = (1 << 2), // ignore
    FF_HASSTACKFRAME            = (1 << 3), // has stack frame
    FF_FUNCINFUNC               = (1 << 4), // function in function
};

////////////////////////////////////////////////////////////////////////////
// CODEFUNC32 - code function for 32-bit

class CODEFUNC32
{
public:
    CODEFUNC32();
    CODEFUNC32(const CODEFUNC32& cf);
    CODEFUNC32& operator=(const CODEFUNC32& cf);
    virtual ~CODEFUNC32();
    VOID Copy(const CODEFUNC32& cf);
    VOID clear();

public:
    // accessors
    ADDR32&                     Addr();
    string&                     Name();
    FUNCTYPE&                   FuncType();
    INT&                        SizeOfStackArgs();
    OPERANDSET&                 Args();
    DWORD&                      Flags();
    string&                     ReturnDataType();
    ADDR32SET&                  Jumpees();
    ADDR32SET&                  Jumpers();
    ADDR32SET&                  Callees();
    ADDR32SET&                  Callers();
    VECSET<BLOCK32>&            Blocks();
    BLOCK32*                    FindBlockOfAddr(ADDR32 addr);
    // const accessors
    const ADDR32&                       Addr() const;
    const string&                       Name() const;
    const FUNCTYPE&                     FuncType() const;
    const INT&                          SizeOfStackArgs() const;
    const OPERANDSET&                   Args() const;
    const DWORD&                        Flags() const;
    const string&                       ReturnDataType() const;
    const ADDR32SET&                    Jumpees() const;
    const ADDR32SET&                    Jumpers() const;
    const ADDR32SET&                    Callees() const;
    const ADDR32SET&                    Callers() const;
    const VECSET<BLOCK32>&              Blocks() const;
    const BLOCK32*                      FindBlockOfAddr(ADDR32 addr) const;

protected:
    struct CODEFUNC32IMPL;
    CODEFUNC32IMPL *m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// CODEFUNC64 - code function for 64-bit

class CODEFUNC64
{
public:
    CODEFUNC64();
    CODEFUNC64(const CODEFUNC64& cf);
    CODEFUNC64& operator=(const CODEFUNC64& cf);
    virtual ~CODEFUNC64();
    VOID Copy(const CODEFUNC64& cf);
    VOID clear();

public:
    // accessors
    ADDR64&                     Addr();
    string&                     Name();
    FUNCTYPE&                   FuncType();
    INT&                        SizeOfStackArgs();
    OPERANDSET&                 Args();
    DWORD&                      Flags();
    string&                     ReturnDataType();
    ADDR64SET&                  Jumpees();
    ADDR64SET&                  Jumpers();
    ADDR64SET&                  Callees();
    ADDR64SET&                  Callers();
    VECSET<BLOCK64>&            Blocks();
    BLOCK64*                    FindBlockOfAddr(ADDR64 addr);
    // const accessors
    const ADDR64&                       Addr() const;
    const string&                       Name() const;
    const FUNCTYPE&                     FuncType() const;
    const INT&                          SizeOfStackArgs() const;
    const OPERANDSET&                   Args() const;
    const DWORD&                        Flags() const;
    const string&                       ReturnDataType() const;
    const ADDR64SET&                    Jumpees() const;
    const ADDR64SET&                    Jumpers() const;
    const ADDR64SET&                    Callees() const;
    const ADDR64SET&                    Callers() const;
    const VECSET<BLOCK64>&              Blocks() const;
    const BLOCK64*                      FindBlockOfAddr(ADDR64 addr) const;

protected:
    struct CODEFUNC64IMPL;
    CODEFUNC64IMPL *m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// DECOMPSTATUS32 - decompilation status for 32-bit

class DECOMPSTATUS32
{
public:
    DECOMPSTATUS32();
    DECOMPSTATUS32(const DECOMPSTATUS32& status);
    DECOMPSTATUS32& operator=(const DECOMPSTATUS32& status);
    virtual ~DECOMPSTATUS32();
    VOID Copy(const DECOMPSTATUS32& status);
    VOID clear();

public:
    VOID MapAddrToAsmCode(ADDR32 addr, const ASMCODE32& ac);
    VOID MapAddrToCodeFunc(ADDR32 addr, const CODEFUNC32& cf);
    BOOL AnalyzeCFG();

public:
    // accessors
    map<ADDR32, ASMCODE32>&         MapAddrToAsmCode();
    ADDR32SET&                      Entrances();
    map<ADDR32, CODEFUNC32>&        MapAddrToCodeFunc();
    ASMCODE32 *                     MapAddrToAsmCode(ADDR32 addr);
    CODEFUNC32 *                    MapAddrToCodeFunc(ADDR32 addr);
    // const accessors
    const map<ADDR32, ASMCODE32>&   MapAddrToAsmCode() const;
    const ADDR32SET&                Entrances() const;
    const map<ADDR32, CODEFUNC32>&  MapAddrToCodeFunc() const;
    const ASMCODE32 *               MapAddrToAsmCode(ADDR32 addr) const;
    const CODEFUNC32 *              MapAddrToCodeFunc(ADDR32 addr) const;

protected:
    BOOL AnalyzeFuncCFGStage1(ADDR32 func, ADDR32 addr);
    BOOL AnalyzeFuncCFGStage2(ADDR32 func);

protected:
    struct DECOMPSTATUS32IMPL;
    DECOMPSTATUS32IMPL* m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
// DECOMPSTATUS64 - decompilation status for 64-bit

class DECOMPSTATUS64
{
public:
    DECOMPSTATUS64();
    DECOMPSTATUS64(const DECOMPSTATUS64& status);
    DECOMPSTATUS64& operator=(const DECOMPSTATUS64& status);
    virtual ~DECOMPSTATUS64();
    VOID Copy(const DECOMPSTATUS64& status);
    VOID clear();

public:
    VOID MapAddrToAsmCode(ADDR64 addr, const ASMCODE64& ac);
    VOID MapAddrToCodeFunc(ADDR64 addr, const CODEFUNC64& cf);
    BOOL AnalyzeCFG();

public:
    // accessors
    map<ADDR64, ASMCODE64>&         MapAddrToAsmCode();
    ADDR64SET&                      Entrances();
    map<ADDR64, CODEFUNC64>&        MapAddrToCodeFunc();
    ASMCODE64 *                     MapAddrToAsmCode(ADDR64 addr);
    CODEFUNC64 *                    MapAddrToCodeFunc(ADDR64 addr);
    // const accessors
    const map<ADDR64, ASMCODE64>&   MapAddrToAsmCode() const;
    const ADDR64SET&                Entrances() const;
    const map<ADDR64, CODEFUNC64>&  MapAddrToCodeFunc() const;
    const ASMCODE64 *               MapAddrToAsmCode(ADDR64 addr) const;
    const CODEFUNC64 *              MapAddrToCodeFunc(ADDR64 addr) const;

protected:
    BOOL AnalyzeFuncCFGStage1(ADDR64 func, ADDR64 addr);
    BOOL AnalyzeFuncCFGStage2(ADDR64 func);

protected:
    struct DECOMPSTATUS64IMPL;
    DECOMPSTATUS64IMPL* m_pImpl;
};

////////////////////////////////////////////////////////////////////////////
