/**
 * @file tofbf.h
 * @author LDRobot (marketing1@ldrobot.com)
 * @brief  LiDAR near-range filtering algorithm
 *         This code is only applicable to LDROBOT LiDAR LD06 products 
 * sold by Shenzhen LDROBOT Co., LTD
 * @version 0.1
 * @date 2021-10-28
 *
 * @copyright Copyright (c) 2021  SHENZHEN LDROBOT CO., LTD. All rights
 * reserved.
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License in the file LICENSE
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TOFBF_H_
#define __TOFBF_H_

#include <stdint.h>

#include <vector>

#include "lipkg.h"

class Tofbf {
 private:
  const int kConfidenceLow = 15;  // Low confidence threshold
  const int kConfidenceSingle = 220;  // Discrete points require higher confidence
  const int kScanFrequency = 4500;  // Default scan frequency, to change, read
                                    // according to radar protocol
  double curr_speed_;
  Tofbf() = delete;
  Tofbf(const Tofbf &) = delete;
  Tofbf &operator=(const Tofbf &) = delete;

 public:
  Tofbf(int speed);
  std::vector<PointData> NearFilter(const std::vector<PointData> &tmp) const;
  ~Tofbf();
};

#endif  //__TOFBF_H_

/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF
 * FILE ********/