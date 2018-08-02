#include "aruco_unity_plugin/std/vector_vector_point2f.hpp"
#include "aruco_unity_plugin/cv/exception.hpp"

extern "C" {
  // Constructors & Destructors

  std::vector<std::vector<cv::Point2f>>* au_std_vectorVectorPoint2f_new() {
    return new std::vector<std::vector<cv::Point2f>>();
  }

  void au_std_vectorVectorPoint2f_delete(std::vector<std::vector<cv::Point2f>>* vector) {
    delete vector;
  }

  // Member Functions

  std::vector<cv::Point2f>* au_std_vectorVectorPoint2f_at(std::vector<std::vector<cv::Point2f>>* vector, size_t pos, cv::Exception* exception) {
    std::vector<cv::Point2f>* element = NULL;
    try {
      element = &(vector->at(pos));
    } catch (const cv::Exception& e) {
      ARUCO_UNITY_COPY_EXCEPTION(exception, e);
      return element;
    }
    return element;
  }

  std::vector<cv::Point2f>* au_std_vectorVectorPoint2f_data(std::vector<std::vector<cv::Point2f>>* vector) {
    return vector->data();
  }
  void au_std_vectorVectorPoint2f_push_back(std::vector<std::vector<cv::Point2f>>* vector, std::vector<cv::Point2f>* value) {
    vector->push_back(std::vector<cv::Point2f>(*value));
  }

  size_t au_std_vectorVectorPoint2f_size(std::vector<std::vector<cv::Point2f>>* vector) {
    return vector->size();
  }
}