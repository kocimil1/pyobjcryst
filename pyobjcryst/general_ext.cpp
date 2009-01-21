/*****************************************************************************
*
* pyobjcryst        by DANSE Diffraction group
*                   Simon J. L. Billinge
*                   (c) 2009 Trustees of the Columbia University
*                   in the City of New York.  All rights reserved.
*
* File coded by:    Chris Farrow
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
******************************************************************************
*
* boost::python bindings to general structures and objects defined in
* ObjCryst/General.h
*
* $Id$
*
*****************************************************************************/

#include <boost/utility.hpp>
#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

#include <string>
#include <iostream>

#include "ObjCryst/General.h"

using namespace boost::python;
using namespace ObjCryst;

BOOST_PYTHON_MODULE(_general)
{
    enum_<RadiationType>("RadiationType")
        .value("RAD_NEUTRON", RAD_NEUTRON)
        .value("RAD_XRAY", RAD_XRAY)
        .value("RAD_ELECTRON", RAD_ELECTRON)
        ;
}
