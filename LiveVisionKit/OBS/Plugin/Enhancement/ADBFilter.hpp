//    *************************** LiveVisionKit ****************************
//    Copyright (C) 2022  Sebastian Di Marco (crowsinc.dev@gmail.com)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
// 	  **********************************************************************

#pragma once

#include "LiveVisionKit.hpp"
#include "OBS/Interop/VisionFilter.hpp"

namespace lvk
{

	class ADBFilter : public VisionFilter
	{
	public:

		static obs_properties_t* Properties();

		static void LoadDefaults(obs_data_t* settings);

		ADBFilter(obs_source_t* context);

		void configure(obs_data_t* settings);

		bool validate() const;

	private:

		virtual void filter(cv::UMat& frame) override;

		uint64_t draw_debug_frame(cv::UMat& frame);

		void draw_debug_hud(cv::UMat& frame, const uint64_t frame_time_ns);

	private:

		obs_source_t* m_Context = nullptr;

		bool m_TestMode = false;
		uint32_t m_DetectionLevels = 0;

		cv::UMat m_SmoothFrame{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_DetectionFrame{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_ReferenceFrame{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_BlockMask{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_KeepBlendMap{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_DeblockBlendMap{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_BlockGrid{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
		cv::UMat m_DeblockBuffer{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY}; 
		cv::UMat m_FloatBuffer{cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY};
	};

}
