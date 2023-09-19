#include "solution.h"

int box_capacity(int length,int width,int height){
    int count_boxes_in_length_inch {(length*12)/16};
    int count_boxes_in_width_inch {(width*12)/16};
    int count_boxes_in_height_inch {(height*12)/16};
    return count_boxes_in_length_inch*count_boxes_in_width_inch*count_boxes_in_height_inch; 
}