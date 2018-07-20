
#include <iostream>
#include <memory>
#include <thread>

#include <Core/Core.h>
#include <IO/IO.h>
#include <Visualization/Visualization.h>


// TUM intrinsic
// https://vision.in.tum.de/data/datasets/rgbd-dataset/file_formats

int main(int argc, char *argv[])
{
	using namespace three;

	SetVerbosityLevel(VerbosityLevel::VerboseAlways);


	

	auto image_ptr = CreateImageFromFile("../../dataset/TUM/rgbd_dataset_freiburg1_desk/depth/1305031453.940012.png");
	PinholeCameraIntrinsic camera;
	camera.SetIntrinsics(640, 480, 517.3, 516.5, 318.6, 255.3);
	auto pointcloud_ptr = CreatePointCloudFromDepthImage(*image_ptr,
			camera);
	DrawGeometries({pointcloud_ptr}, "PointCloud from Depth Image",
			1920, 1080);
	

	PrintInfo("End of the test.\n");

	return 1;
}
