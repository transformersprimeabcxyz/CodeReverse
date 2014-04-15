////////////////////////////////////////////////////////////////////////////
// Location.h
// Copyright (C) 2014 Katayama Hirofumi MZ.  All rights reserved.
////////////////////////////////////////////////////////////////////////////
// This file is part of CodeReverse.
////////////////////////////////////////////////////////////////////////////

#ifndef LOCATION_H_
#define LOCATION_H_

#include <string>       // std::string

//
// CR_Location
//
struct CR_Location
{
    std::string m_file;
    int m_line;

    CR_Location() : m_line(1) { }

    CR_Location(const CR_Location& loc)
    : m_file(loc.m_file), m_line(loc.m_line)
    {
    }

    CR_Location(const char *file, int line) : m_file(file), m_line(line) { }

    CR_Location(const std::string& file, int line) : m_file(file), m_line(line)
    {
    }

    void set(const char *file, int line)
    {
        m_file = file;
        m_line = line;
    }

    CR_Location& operator=(const CR_Location& loc)
    {
        m_file = loc.m_file;
        m_line = loc.m_line;
        return *this;
    }

    CR_Location& operator++()
    {
        m_line++;
        return *this;
    }

    CR_Location operator++(int)
    {
        CR_Location loc(*this);
        m_line++;
        return loc;
    }
};

#endif  // def LOCATION_H_