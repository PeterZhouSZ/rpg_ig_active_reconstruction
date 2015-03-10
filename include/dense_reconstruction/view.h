/* Copyright (c) 2015, Stefan Isler, islerstefan@bluewin.ch
*
This file is part of dense_reconstruction, a ROS package for...well,

dense_reconstruction is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
dense_reconstruction is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License
along with dense_reconstruction. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <movements/core>
#include "dense_reconstruction/view_info.h"

namespace dense_reconstruction
{

/** represents one possible view in space with associated information */
class View
{
public:
  View();
  View( std::string _source_frame );
  
  /** grants access to the pose */
  movements::Pose& pose();
  
  /** whether this view is reachable by the robot
   */
  bool& reachable();
  
  /** how many times this view has already been visited */
  unsigned int& timesVisited();
  
  /** this view has been bad, or not
   */
  bool& bad();
  
  /** get the associated data */
  boost::shared_ptr<dense_reconstruction::ViewInfo> associatedData();
  
private:
  movements::Pose pose_; /// the pose...
  std::string source_frame_; /// pose is relative to this frame (as specified in tf), that is the transform that could be used to transform a poit in the pose frame into one in the source frame
  boost::shared_ptr<dense_reconstruction::ViewInfo> associated_data_; /// interface that gives possibility for a robot to store robot specific data that is associated with the pose, e.g. for the Youbot some IK calculations can be made beforehand but the robot needs to know which data implements a given view
  bool is_reachable_; /// whether the view is reachable or not
  bool is_bad_; /// marks a bad view for whatever reason (e.g. data reception failed here or the like)
  unsigned int visited_; /// how many times this view has been visited
};

} 
