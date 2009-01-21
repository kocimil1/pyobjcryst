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
* boost::python bindings to ObjCryst::ScatteringPowerAtom.
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

#include "ObjCryst/ScatteringPower.h"
#include "RefinableObj/RefinableObj.h"
#include "CrystVector/CrystVector.h"

using namespace boost::python;
using namespace ObjCryst;

BOOST_PYTHON_MODULE(_scatteringpoweratom)
{

    class_<ScatteringPowerAtom, bases<ScatteringPower> > ("ScatteringPowerAtom", 
        init<>())
        .def(init<const std::string&, const std::string&, optional<const float> >())
        .def(init<const ScatteringPowerAtom&>())
        .def("Init", &ScatteringPowerAtom::Init,
                (boost::python::arg("name"),
                boost::python::arg("symbol"),
                boost::python::arg("biso")=1.0
                ))
        .def("SetSymbol", &ScatteringPowerAtom::SetSymbol)
        .def("GetElementName", &ScatteringPowerAtom::GetElementName)
        .def("GetAtomicNumber", &ScatteringPowerAtom::GetAtomicNumber)
        ;
}
