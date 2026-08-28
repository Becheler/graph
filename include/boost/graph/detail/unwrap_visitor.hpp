//
//=======================================================================
// Copyright 2026 Arnaud Becheler
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
//

// Unwrapping helpers for algorithms that accept a visitor which may be passed
// with std::ref so the caller keeps ownership of a stateful object.
#ifndef BOOST_GRAPH_DETAIL_UNWRAP_VISITOR_HPP
#define BOOST_GRAPH_DETAIL_UNWRAP_VISITOR_HPP

#include <functional>

namespace boost
{

namespace graph
{

namespace detail
{

// Resolve the underlying visitor type behind a possible std::ref wrapper.
template < class Visitor > struct unwrap_visitor { using type = Visitor; };
template < class Visitor > struct unwrap_visitor< std::reference_wrapper< Visitor > > { using type = Visitor; };

// Resolve a std::ref-wrapped visitor to the referenced object.
template < class Visitor > Visitor& deref_visitor(Visitor& vis) { return vis; }
template < class Visitor > Visitor& deref_visitor(std::reference_wrapper< Visitor > vis) { return vis.get(); }

} // namespace detail

} // namespace graph

} // namespace boost

#endif // BOOST_GRAPH_DETAIL_UNWRAP_VISITOR_HPP
