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
* boost::python bindings to ObjCryst::ScatteringComponentList.
*
* $Id$
*
*****************************************************************************/

#include "ObjCryst/ScatteringPower.h"

#include <boost/utility.hpp>
#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

#include "helpers.h"


using namespace boost::python;
using namespace ObjCryst;

namespace
{

    const ScatteringComponent& 
    getItem(const ScatteringComponentList &scl, const long i)
    {
        long idx = i;
        long n = scl.GetNbComponent();
        if(idx < 0) idx += n;
        if(idx < 0 || idx >= n)
        {
            PyErr_SetString(PyExc_IndexError, "index out of range");
            throw_error_already_set();
        }
        return scl(i);
    }

    bool contains(const ScatteringComponentList &scl,
            const ScatteringComponent &sc)
    {
        for(long i=0; i < scl.GetNbComponent(); ++i)
        {
            if( scl(i) == sc ) return true;
        }
        return false;
    }

}

BOOST_PYTHON_MODULE(_scatteringcomponentlist)
{

    class_<ScatteringComponentList>
        ("ScatteringComponentList", init<const long>())
        .def(init<const ScatteringComponentList &>())
        .def("Reset", &ScatteringComponentList::Reset)
        .def("GetNbComponent", &ScatteringComponentList::GetNbComponent)
        .def("Print", &ScatteringComponentList::Print)
        .def(self == self)
        .def(self += self)
        .def(self += ScatteringComponent())
        .def("__str__", &__str__<ScatteringComponentList>)
        // Container-type things
        .def("__len__", &ScatteringComponentList::GetNbComponent)
        .def("__getitem__", &getItem, return_internal_reference<>())
        .def("__contains__", &contains)
        ;
}
