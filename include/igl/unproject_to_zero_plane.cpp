// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "unproject_to_zero_plane.h"
#ifndef IGL_NO_OPENGL

#include "OpenGL_convenience.h"

#include "project.h"
#include "unproject.h"

IGL_INLINE void igl::unproject_to_zero_plane(
  const double winX,
  const double winY,
  double* objX,
  double* objY,
  double* objZ)
{
  double winOrigin[3]; 
  igl::project(0,0,0,&winOrigin[0],&winOrigin[1],&winOrigin[2]);
  return igl::unproject(winX, winY, winOrigin[2], objX, objY, objZ);
}

template <typename Derivedwin, typename Derivedobj>
IGL_INLINE void igl::unproject_to_zero_plane(
  const Eigen::PlainObjectBase<Derivedwin> & win,
  Eigen::PlainObjectBase<Derivedobj> & obj)
{
  return unproject_to_zero_plane(win(0),win(1),
      &obj.data()[0],
      &obj.data()[1],
      &obj.data()[2]);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instanciation
template void igl::unproject_to_zero_plane<Eigen::Matrix<double, 3, 1, 0, 3, 1>, Eigen::Matrix<double, 3, 1, 0, 3, 1> >(Eigen::PlainObjectBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> >&);
template void igl::unproject_to_zero_plane<Eigen::Matrix<double, 2, 1, 0, 2, 1>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::PlainObjectBase<Eigen::Matrix<double, 2, 1, 0, 2, 1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> >&);
template void igl::unproject_to_zero_plane<Eigen::Matrix<double, 2, 1, 0, 2, 1>, Eigen::Matrix<double, 3, 1, 0, 3, 1> >(Eigen::PlainObjectBase<Eigen::Matrix<double, 2, 1, 0, 2, 1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> >&);
#endif

#endif
