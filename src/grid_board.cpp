#include "aruco_unity_plugin/grid_board.hpp"
#include "aruco_unity_plugin/cv/exception.hpp"
#include <opencv2/imgproc.hpp>

extern "C" {
  // Constructors & Destructors

  void au_GridBoard_delete(cv::Ptr<cv::aruco::GridBoard>* gridBoard) {
    delete gridBoard;
  }

  // Member Functions

  void au_GridBoard_draw(cv::Ptr<cv::aruco::GridBoard>* gridBoard, cv::Size* outSize, cv::Mat** img, int marginSize, int borderBits,
    cv::Exception* exception) {
    try {
      *img = new cv::Mat();
      gridBoard->get()->draw(*outSize, **img, marginSize, borderBits);
    } catch (const cv::Exception& e) {
      ARUCO_UNITY_COPY_EXCEPTION(exception, e);
      return;
    };
    cv::cvtColor(**img, **img, cv::COLOR_GRAY2RGB);
  }

  cv::Size* au_GridBoard_getGridSize(cv::Ptr<cv::aruco::GridBoard>* gridBoard) {
    return new cv::Size(gridBoard->get()->getGridSize());
  }

  float au_GridBoard_getMarkerLength(cv::Ptr<cv::aruco::GridBoard>* gridBoard) {
    return gridBoard->get()->getMarkerLength();
  }

  float au_GridBoard_getMarkerSeparation(cv::Ptr<cv::aruco::GridBoard>* gridBoard) {
    return gridBoard->get()->getMarkerSeparation();
  }

  // Static Member Functions
  cv::Ptr<cv::aruco::GridBoard>* au_GridBoard_create(int markersX, int markersY, float markerLength, float markerSeparation, 
    cv::Ptr<cv::aruco::Dictionary>* dictionary, int firstMarker, cv::Exception* exception) {
    cv::Ptr<cv::aruco::GridBoard> gridBoard;
    try {
      gridBoard = cv::aruco::GridBoard::create(markersX, markersY, markerLength, markerSeparation, *dictionary, firstMarker);
    } catch (const cv::Exception& e) {
      ARUCO_UNITY_COPY_EXCEPTION(exception, e);
      return NULL;
    };
    return new cv::Ptr<cv::aruco::GridBoard>(gridBoard);
  }
}