// Copyright (c) 2014, LAAS-CNRS
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-statistics.
// hpp-statistics is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-statistics is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-statistics. If not, see <http://www.gnu.org/licenses/>.

#ifndef HPP_STATISTICS_SUCCESSBIN_HXX
# define HPP_STATISTICS_SUCCESSBIN_HXX

# include "hpp/statistics/success-bin.hh"

# include <limits.h>

namespace hpp {
  namespace statistics {
    std::size_t SuccessBin::reasonID_last = 0;
    const SuccessBin::Reason SuccessBin::REASON_SUCCESS = SuccessBin::createReason ("Success");
    const SuccessBin::Reason SuccessBin::REASON_UNKNOWN = SuccessBin::createReason ("Unknown");
  } // namespace statistics
} // namespace hpp

#endif // HPP_STATISTICS_SUCCESSBIN_HXX
