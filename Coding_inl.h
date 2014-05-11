////////////////////////////////////////////////////////////////////////////
// Coding_inl.h
// Copyright (C) 2013-2014 Katayama Hirofumi MZ.  All rights reserved.
////////////////////////////////////////////////////////////////////////////
// This file is part of CodeReverse.
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// CR_Operand

inline CR_Operand::CR_Operand()
{
    clear();
}

inline CR_Operand::CR_Operand(const CR_Operand& opr)
{
    Copy(opr);
}

inline /*virtual*/ CR_Operand::~CR_Operand()
{
}

inline void CR_Operand::operator=(const CR_Operand& opr)
{
    Copy(opr);
}

inline void CR_Operand::SetReg(const char *name)
{
    Text() = name;
    OperandType() = OT_REG;
    Size() = CrRegGetSize(name, 64);
}

inline void CR_Operand::SetFuncName(const char *name)
{
    Text() = name;
    OperandType() = OT_FUNCNAME;
}

inline void CR_Operand::SetLabel(const char *label)
{
    Text() = label;
    OperandType() = OT_IMM;
}

inline void CR_Operand::SetMemImm(CR_Addr64 addr)
{
    OperandType() = OT_MEMIMM;
    Value64() = addr;
}

inline void CR_Operand::SetMemExpr(const char *exp)
{
    OperandType() = OT_MEMEXPR;
    MemExpr() = exp;
}

////////////////////////////////////////////////////////////////////////////
// CR_Operand accessors

inline CR_String& CR_Operand::Text()
{
    return m_text;
}

inline CR_OperandType& CR_Operand::OperandType()
{
    return m_ot;
}

inline DWORD& CR_Operand::Size()
{
    return m_size;
}

inline CR_Addr32& CR_Operand::Value32()
{
    return m_value32;
}

inline CR_Addr64& CR_Operand::Value64()
{
    return m_value64;
}

inline CR_String& CR_Operand::MemExpr()
{
    return m_memexpr;
}

inline CR_TriBool& CR_Operand::IsInteger()
{
    return m_is_integer;
}

inline CR_TriBool& CR_Operand::IsPointer()
{
    return m_is_pointer;
}

inline CR_TriBool& CR_Operand::IsFunction()
{
    return m_is_function;
}

////////////////////////////////////////////////////////////////////////////
// CR_Operand const accessors

inline const CR_String& CR_Operand::Text() const
{
    return m_text;
}

inline const CR_OperandType& CR_Operand::OperandType() const
{
    return m_ot;
}

inline const DWORD& CR_Operand::Size() const
{
    return m_size;
}

inline const CR_Addr32& CR_Operand::Value32() const
{
    return m_value32;
}

inline const CR_Addr64& CR_Operand::Value64() const
{
    return m_value64;
}

inline const CR_String& CR_Operand::MemExpr() const
{
    return m_memexpr;
}

inline const CR_TriBool& CR_Operand::IsInteger() const
{
    return m_is_integer;
}

inline const CR_TriBool& CR_Operand::IsPointer() const
{
    return m_is_pointer;
}

inline const CR_TriBool& CR_Operand::IsFunction() const
{
    return m_is_function;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn32

inline CR_CodeInsn32::CR_CodeInsn32()
{
    clear();
}

inline CR_CodeInsn32::CR_CodeInsn32(const CR_CodeInsn32& ac)
{
    Copy(ac);
}

inline /*virtual*/ CR_CodeInsn32::~CR_CodeInsn32()
{
}

inline void CR_CodeInsn32::operator=(const CR_CodeInsn32& ac)
{
    Copy(ac);
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn32 accessors

inline CR_Addr32Set& CR_CodeInsn32::FuncAddrs()
{
    return m_funcaddrs;
}

inline CR_Addr32& CR_CodeInsn32::Addr()
{
    return m_addr;
}

inline CR_String& CR_CodeInsn32::Name()
{
    return m_name;
}

inline CR_OperandSet& CR_CodeInsn32::Operands()
{
    return m_operands;
}

inline CR_Operand* CR_CodeInsn32::Operand(std::size_t index)
{
    assert(index < m_operands.size());
    if (m_operands.size() > index)
        return &m_operands[index];
    else
        return NULL;
}

inline CR_Binary& CR_CodeInsn32::Codes()
{
    return m_codes;
}

inline CR_CodeInsnType& CR_CodeInsn32::CodeInsnType()
{
    return m_cit;
}

inline CR_CondCode& CR_CodeInsn32::CondCode()
{
    return m_ccode;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn32 const accessors

inline const CR_Addr32Set& CR_CodeInsn32::FuncAddrs() const
{
    return m_funcaddrs;
}

inline const CR_Addr32& CR_CodeInsn32::Addr() const
{
    return m_addr;
}

inline const CR_String& CR_CodeInsn32::Name() const
{
    return m_name;
}

inline const CR_OperandSet& CR_CodeInsn32::Operands() const
{
    return m_operands;
}

inline const CR_Operand* CR_CodeInsn32::Operand(std::size_t index) const
{
    assert(m_operands.size() > index);
    if (m_operands.size() > index)
        return &m_operands[index];
    else
        return NULL;
}

inline const CR_Binary& CR_CodeInsn32::Codes() const
{
    return m_codes;
}

inline const CR_CodeInsnType& CR_CodeInsn32::CodeInsnType() const
{
    return m_cit;
}

inline const CR_CondCode& CR_CodeInsn32::CondCode() const
{
    return m_ccode;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn64

inline CR_CodeInsn64::CR_CodeInsn64()
{
    clear();
}

inline CR_CodeInsn64::CR_CodeInsn64(const CR_CodeInsn64& ac)
{
    Copy(ac);
}

inline /*virtual*/ CR_CodeInsn64::~CR_CodeInsn64()
{
}

inline void CR_CodeInsn64::operator=(const CR_CodeInsn64& ac)
{
    Copy(ac);
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn64 accessors

inline CR_Addr64Set& CR_CodeInsn64::FuncAddrs()
{
    return m_funcaddrs;
}

inline CR_Addr64& CR_CodeInsn64::Addr()
{
    return m_addr;
}

inline CR_String& CR_CodeInsn64::Name()
{
    return m_name;
}

inline CR_OperandSet& CR_CodeInsn64::Operands()
{
    return m_operands;
}

inline CR_Operand* CR_CodeInsn64::Operand(std::size_t index)
{
    assert(index < m_operands.size());
    if (m_operands.size() > index)
        return &m_operands[index];
    else
        return NULL;
}

inline CR_Binary& CR_CodeInsn64::Codes()
{
    return m_codes;
}

inline CR_CodeInsnType& CR_CodeInsn64::CodeInsnType()
{
    return m_cit;
}

inline CR_CondCode& CR_CodeInsn64::CondCode()
{
    return m_ccode;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeInsn64 const accessors

inline const CR_Addr64Set& CR_CodeInsn64::FuncAddrs() const
{
    return m_funcaddrs;
}

inline const CR_Addr64& CR_CodeInsn64::Addr() const
{
    return m_addr;
}

inline const CR_String& CR_CodeInsn64::Name() const
{
    return m_name;
}

inline const CR_OperandSet& CR_CodeInsn64::Operands() const
{
    return m_operands;
}

inline const CR_Operand* CR_CodeInsn64::Operand(std::size_t index) const
{
    assert(m_operands.size() > index);
    if (m_operands.size() > index)
        return &m_operands[index];
    else
        return NULL;
}

inline const CR_Binary& CR_CodeInsn64::Codes() const
{
    return m_codes;
}

inline const CR_CodeInsnType& CR_CodeInsn64::CodeInsnType() const
{
    return m_cit;
}

inline const CR_CondCode& CR_CodeInsn64::CondCode() const
{
    return m_ccode;
}

////////////////////////////////////////////////////////////////////////////
// CR_LogByte

inline CR_LogByte::CR_LogByte()
{
}

inline /*virtual*/ CR_LogByte::~CR_LogByte()
{
}

inline CR_TypeSet& CR_LogByte::Types()
{
    return m_types;
}

inline const CR_TypeSet& CR_LogByte::Types() const
{
    return m_types;
}

inline CR_StringSet& CR_LogByte::Names()
{
    return m_names;
}

inline const CR_StringSet& CR_LogByte::Names() const
{
    return m_names;
}

inline CR_TriBool& CR_LogByte::IsConst()
{
    return m_is_const;
}

inline const CR_TriBool& CR_LogByte::IsConst() const
{
    return m_is_const;
}

inline CR_TriBool& CR_LogByte::IsInput()
{
    return m_is_input;
}

inline const CR_TriBool& CR_LogByte::IsInput() const
{
    return m_is_input;
}

inline CR_TriBool& CR_LogByte::IsOutput()
{
    return m_is_output;
}

inline const CR_TriBool& CR_LogByte::IsOutput() const
{
    return m_is_output;
}

inline CR_TriBool& CR_LogByte::IsInteger()
{
    return m_is_pointer;
}

inline const CR_TriBool& CR_LogByte::IsInteger() const
{
    return m_is_pointer;
}

inline CR_TriBool& CR_LogByte::IsFloating()
{
    return m_is_floating;
}

inline const CR_TriBool& CR_LogByte::IsFloating() const
{
    return m_is_floating;
}

inline CR_TriBool& CR_LogByte::IsPointer()
{
    return m_is_pointer;
}

inline const CR_TriBool& CR_LogByte::IsPointer() const
{
    return m_is_pointer;
}

inline CR_TriBool& CR_LogByte::IsFunction()
{
    return m_is_function;
}

inline const CR_TriBool& CR_LogByte::IsFunction() const
{
    return m_is_function;
}

inline CR_TriBool& CR_LogByte::IsContinuous()
{
    return m_is_continuous;
}

inline const CR_TriBool& CR_LogByte::IsContinuous() const
{
    return m_is_continuous;
}

////////////////////////////////////////////////////////////////////////////
// CR_LogBinary

inline CR_LogBinary::CR_LogBinary()
{
}

inline CR_LogBinary::CR_LogBinary(const CR_LogBinary& bin) :
    m_logbytes(bin.m_logbytes), m_databytes(bin.m_databytes)
{
}

inline void CR_LogBinary::operator=(const CR_LogBinary& bin)
{
    LogBytes() = bin.LogBytes();
    DataBytes() = bin.DataBytes();
}

inline /*virtual*/ CR_LogBinary::~CR_LogBinary()
{
}

inline bool CR_LogBinary::empty() const
{
    assert(LogBytes().size() == DataBytes().size());
    return LogBytes().empty();
}

inline std::size_t CR_LogBinary::size() const
{
    assert(LogBytes().size() == DataBytes().size());
    return LogBytes().size();
}

inline CR_DeqSet<CR_LogByte>& CR_LogBinary::LogBytes()
{
    return m_logbytes;
}

inline const CR_DeqSet<CR_LogByte>& CR_LogBinary::LogBytes() const
{
    return m_logbytes;
}

inline CR_DeqSet<CR_DataByte>& CR_LogBinary::DataBytes()
{
    return m_databytes;
}

inline const CR_DeqSet<CR_DataByte>& CR_LogBinary::DataBytes() const
{
    return m_databytes;
}

inline CR_DataByte *CR_LogBinary::Data()
{
    return const_cast<CR_DataByte *>(&DataBytes()[0]);
}

inline const CR_DataByte *CR_LogBinary::Data() const
{
    return const_cast<CR_DataByte *>(&DataBytes()[0]);
}

inline CR_LogByte& CR_LogBinary::LogByteAt(std::size_t index)
{
    return LogBytes()[index];
}

inline const CR_LogByte& CR_LogBinary::LogByteAt(std::size_t index) const
{
    return LogBytes()[index];
}

inline CR_DataByte& CR_LogBinary::DataByteAt(std::size_t index)
{
    return DataBytes()[index];
}

inline const CR_DataByte& CR_LogBinary::DataByteAt(std::size_t index) const
{
    return DataBytes()[index];
}

inline CR_TypeSet& CR_LogBinary::TypesAt(std::size_t index)
{
    return LogBytes()[index].Types();
}

inline const CR_TypeSet& CR_LogBinary::TypesAt(std::size_t index) const
{
    return LogBytes()[index].Types();
}

inline CR_StringSet& CR_LogBinary::NamesAt(std::size_t index)
{
    return LogBytes()[index].Names();
}

inline const CR_StringSet& CR_LogBinary::NamesAt(std::size_t index) const
{
    return LogBytes()[index].Names();
}

inline void CR_LogBinary::AddHead(const CR_LogBinary& cs)
{
    LogBytes().AddHead(cs.LogBytes());
    DataBytes().AddHead(cs.DataBytes());
}

inline void CR_LogBinary::AddTail(const CR_LogBinary& cs)
{
    LogBytes().AddTail(cs.LogBytes());
    DataBytes().AddTail(cs.DataBytes());
}

inline char& CR_LogBinary::CharAt(std::size_t index)
{
    assert(index + 1 <= size());
    return reinterpret_cast<char&>(DataByteAt(index));
}

inline const char& CR_LogBinary::CharAt(std::size_t index) const
{
    assert(index + 1 <= size());
    return reinterpret_cast<const char&>(DataByteAt(index));
}

inline short& CR_LogBinary::ShortAt(std::size_t index)
{
    assert(index + 2 <= size());
    return reinterpret_cast<short&>(DataByteAt(index));
}

inline const short& CR_LogBinary::ShortAt(std::size_t index) const
{
    assert(index + 2 <= size());
    return reinterpret_cast<const short&>(DataByteAt(index));
}

inline long& CR_LogBinary::LongAt(std::size_t index)
{
    assert(index + 4 <= size());
    return reinterpret_cast<long&>(DataByteAt(index));
}

inline const long& CR_LogBinary::LongAt(std::size_t index) const
{
    assert(index + 4 <= size());
    return reinterpret_cast<const long&>(DataByteAt(index));
}

inline long long& CR_LogBinary::LongLongAt(std::size_t index)
{
    assert(index + 8 <= size());
    return reinterpret_cast<long long&>(DataByteAt(index));
}

inline const long long& CR_LogBinary::LongLongAt(std::size_t index) const
{
    assert(index + 8 <= size());
    return reinterpret_cast<const long long&>(DataByteAt(index));
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc32 accessors

inline CR_Addr32& CR_CodeFunc32::Addr()
{
    return m_addr;
}

inline CR_String& CR_CodeFunc32::Name()
{
    return m_name;
}

inline CR_FuncType& CR_CodeFunc32::FuncType()
{
    return m_ft;
}

inline int& CR_CodeFunc32::SizeOfStackArgs()
{
    return m_SizeOfStackArgs;
}

inline DWORD& CR_CodeFunc32::Flags()
{
    return m_flags;
}

inline CR_Addr32Set& CR_CodeFunc32::Jumpees()
{
    return m_jumpees;
}

inline CR_Addr32Set& CR_CodeFunc32::Jumpers()
{
    return m_jumpers;
}

inline CR_Addr32Set& CR_CodeFunc32::Callees()
{
    return m_callees;
}

inline CR_Addr32Set& CR_CodeFunc32::Callers()
{
    return m_callees;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc32 const accessors

inline const CR_Addr32& CR_CodeFunc32::Addr() const
{
    return m_addr;
}

inline const CR_String& CR_CodeFunc32::Name() const
{
    return m_name;
}

inline const CR_FuncType& CR_CodeFunc32::FuncType() const
{
    return m_ft;
}

inline const int& CR_CodeFunc32::SizeOfStackArgs() const
{
    return m_SizeOfStackArgs;
}

inline const DWORD& CR_CodeFunc32::Flags() const
{
    return m_flags;
}

inline const CR_Addr32Set& CR_CodeFunc32::Jumpees() const
{
    return m_jumpees;
}

inline const CR_Addr32Set& CR_CodeFunc32::Jumpers() const
{
    return m_jumpers;
}

inline const CR_Addr32Set& CR_CodeFunc32::Callees() const
{
    return m_callees;
}

inline const CR_Addr32Set& CR_CodeFunc32::Callers() const
{
    return m_callees;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc64 accessors

inline CR_Addr64& CR_CodeFunc64::Addr()
{
    return m_addr;
}

inline CR_String& CR_CodeFunc64::Name()
{
    return m_name;
}

inline CR_FuncType& CR_CodeFunc64::FuncType()
{
    return m_ft;
}

inline int& CR_CodeFunc64::SizeOfStackArgs()
{
    return m_SizeOfStackArgs;
}

inline DWORD& CR_CodeFunc64::Flags()
{
    return m_flags;
}

inline CR_Addr64Set& CR_CodeFunc64::Jumpees()
{
    return m_jumpees;
}

inline CR_Addr64Set& CR_CodeFunc64::Jumpers()
{
    return m_jumpers;
}

inline CR_Addr64Set& CR_CodeFunc64::Callees()
{
    return m_callees;
}

inline CR_Addr64Set& CR_CodeFunc64::Callers()
{
    return m_callees;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc64 const accessors

inline const CR_Addr64& CR_CodeFunc64::Addr() const
{
    return m_addr;
}

inline const CR_String& CR_CodeFunc64::Name() const
{
    return m_name;
}

inline const CR_FuncType& CR_CodeFunc64::FuncType() const
{
    return m_ft;
}

inline const int& CR_CodeFunc64::SizeOfStackArgs() const
{
    return m_SizeOfStackArgs;
}

inline const DWORD& CR_CodeFunc64::Flags() const
{
    return m_flags;
}

inline const CR_Addr64Set& CR_CodeFunc64::Jumpees() const
{
    return m_jumpees;
}

inline const CR_Addr64Set& CR_CodeFunc64::Jumpers() const
{
    return m_jumpers;
}

inline const CR_Addr64Set& CR_CodeFunc64::Callees() const
{
    return m_callees;
}

inline const CR_Addr64Set& CR_CodeFunc64::Callers() const
{
    return m_callees;
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc32

inline CR_CodeFunc32::CR_CodeFunc32()
{
    clear();
}

inline CR_CodeFunc32::CR_CodeFunc32(const CR_CodeFunc32& cf)
{
    Copy(cf);
}

inline void CR_CodeFunc32::operator=(const CR_CodeFunc32& cf)
{
    Copy(cf);
}

inline /*virtual*/ CR_CodeFunc32::~CR_CodeFunc32()
{
}

////////////////////////////////////////////////////////////////////////////
// CR_CodeFunc64

inline CR_CodeFunc64::CR_CodeFunc64()
{
    clear();
}

inline CR_CodeFunc64::CR_CodeFunc64(const CR_CodeFunc64& cf)
{
    Copy(cf);
}

inline void CR_CodeFunc64::operator=(const CR_CodeFunc64& cf)
{
    Copy(cf);
}

inline /*virtual*/ CR_CodeFunc64::~CR_CodeFunc64()
{
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo32

inline CR_DisAsmInfo32::CR_DisAsmInfo32()
{
}

inline CR_DisAsmInfo32::CR_DisAsmInfo32(const CR_DisAsmInfo32& info)
{
    Copy(info);
}

inline void CR_DisAsmInfo32::operator=(const CR_DisAsmInfo32& info)
{
    Copy(info);
}

inline /*virtual*/ CR_DisAsmInfo32::~CR_DisAsmInfo32()
{
}

inline void CR_DisAsmInfo32::MapAddrToAsmCode(CR_Addr32 addr, CR_CodeInsn32 *ac)
{
    MapAddrToAsmCode()[addr] = CR_SharedCodeInsn32(ac);
}

inline void CR_DisAsmInfo32::MapAddrToCodeFunc(CR_Addr32 addr, CR_CodeFunc32* cf)
{
    MapAddrToCodeFunc()[addr] = CR_SharedCodeFunc32(cf);
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo32 accessors

inline CR_Map<CR_Addr32, CR_SharedCodeInsn32>&
CR_DisAsmInfo32::MapAddrToAsmCode()
{
    return m_mAddrToAsmCode;
}

inline CR_Addr32Set& CR_DisAsmInfo32::Entrances()
{
    return m_sEntrances;
}

inline CR_Map<CR_Addr32, CR_SharedCodeFunc32>&
CR_DisAsmInfo32::MapAddrToCodeFunc()
{
    return m_mAddrToCodeFunc;
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo32 const accessors

inline const CR_Map<CR_Addr32, CR_SharedCodeInsn32>&
CR_DisAsmInfo32::MapAddrToAsmCode() const
{
    return m_mAddrToAsmCode;
}

inline const CR_Addr32Set& CR_DisAsmInfo32::Entrances() const
{
    return m_sEntrances;
}

inline const CR_Map<CR_Addr32, CR_SharedCodeFunc32>&
CR_DisAsmInfo32::MapAddrToCodeFunc() const
{
    return m_mAddrToCodeFunc;
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo64

inline CR_DisAsmInfo64::CR_DisAsmInfo64()
{
}

inline CR_DisAsmInfo64::CR_DisAsmInfo64(const CR_DisAsmInfo64& info)
{
    Copy(info);
}

inline void CR_DisAsmInfo64::operator=(const CR_DisAsmInfo64& info)
{
    Copy(info);
}

inline /*virtual*/ CR_DisAsmInfo64::~CR_DisAsmInfo64()
{
}

inline void CR_DisAsmInfo64::MapAddrToAsmCode(CR_Addr64 addr, CR_CodeInsn64 *ac)
{
    m_mAddrToAsmCode[addr] = CR_SharedCodeInsn64(ac);
}

inline void CR_DisAsmInfo64::MapAddrToCodeFunc(CR_Addr64 addr, CR_CodeFunc64 *cf)
{
    m_mAddrToCodeFunc[addr] = CR_SharedCodeFunc64(cf);
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo64 accessors

inline CR_Map<CR_Addr64, CR_SharedCodeInsn64>&
CR_DisAsmInfo64::MapAddrToAsmCode()
{
    return m_mAddrToAsmCode;
}

inline CR_Addr64Set& CR_DisAsmInfo64::Entrances()
{
    return m_sEntrances;
}

inline CR_Map<CR_Addr64, CR_SharedCodeFunc64>&
CR_DisAsmInfo64::MapAddrToCodeFunc()
{
    return m_mAddrToCodeFunc;
}

////////////////////////////////////////////////////////////////////////////
// CR_DisAsmInfo64 const accessors

inline const CR_Map<CR_Addr64, CR_SharedCodeInsn64>&
CR_DisAsmInfo64::MapAddrToAsmCode() const
{
    return m_mAddrToAsmCode;
}

inline const CR_Addr64Set& CR_DisAsmInfo64::Entrances() const
{
    return m_sEntrances;
}

inline const CR_Map<CR_Addr64, CR_SharedCodeFunc64>&
CR_DisAsmInfo64::MapAddrToCodeFunc() const
{
    return m_mAddrToCodeFunc;
}

////////////////////////////////////////////////////////////////////////////
