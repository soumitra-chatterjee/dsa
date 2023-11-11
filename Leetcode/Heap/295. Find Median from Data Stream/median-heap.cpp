class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(min_heap.size() == 0 && max_heap.size() == 0) {
            max_heap.push(num);
        }
        else {
            int med = findMedian();
            if(num >= med) {
                min_heap.push(num);
            }
            else {
                max_heap.push(num);
            }

            int size_flag = checkSize();

            if(size_flag == 1) {
                int min_h_top = min_heap.top();
                max_heap.push(min_h_top);
                min_heap.pop();
            }
            else if(size_flag == 2) {
                int max_h_top = max_heap.top();
                min_heap.push(max_h_top);
                max_heap.pop();
            }
        }
    }
    
    double findMedian() {

        int max_h_size = max_heap.size();
        int min_h_size = min_heap.size();

        if(max_h_size == min_h_size) {
            return (double)(max_heap.top() + min_heap.top()) / 2;
        }
        else if(max_h_size > min_h_size) { 
            return max_heap.top();
        }
        else {
            return min_heap.top();
        }
    }
private:
    int checkSize() {
        /* 
            0 : valid size difference
            1 : min heap is larger than valid
            2 : max heap is larger than valid
        */

        int min_s = min_heap.size();
        int max_s = max_heap.size();
        if(abs(min_s - max_s) <= 1) {
            return 0;
        }
        else if (min_s > max_s) {
            return 1;
        }
        else return 2;
    }
};
