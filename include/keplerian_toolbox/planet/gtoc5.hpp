/*****************************************************************************
 *   Copyright (C) 2004-2018 The pykep development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *                                                                           *
 *   https://gitter.im/esa/pykep                                             *
 *   https://github.com/esa/pykep                                            *
 *                                                                           *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

#ifndef KEP_TOOLBOX_PLANET_GTOC5_H
#define KEP_TOOLBOX_PLANET_GTOC5_H

#include <keplerian_toolbox/detail/visibility.hpp>
#include <keplerian_toolbox/serialization.hpp>
#include <keplerian_toolbox/planet/keplerian.hpp>

namespace kep_toolbox
{
namespace planet
{

/// A GTOC5 asteroid
/**
 * This class allows to instantiate asteroids
 * from the Global Trajectory Optimization Competition (GTOC) 5th edition
 *
 * @see http://www.esa.int/gsp/ACT/mad/op/GTOC/index.htm
 * @author Dario Izzo (dario.izzo _AT_ googlemail.com)
 * @author Francesco Biscani (bluescarni@gmail.com)
 */

class KEP_TOOLBOX_DLL_PUBLIC gtoc5 : public keplerian
{
public:
    gtoc5(int = 7076);
    planet_ptr clone() const override;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int)
    {
        ar &boost::serialization::base_object<keplerian>(*this);
    }
};
}
} /// End of namespace kep_toolbox

BOOST_CLASS_EXPORT_KEY(kep_toolbox::planet::gtoc5)

#endif // KEP_TOOLBOX_PLANET_GTOC5_H
