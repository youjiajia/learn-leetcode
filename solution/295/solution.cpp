class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if(big_queue.empty()){
            big_queue.push(num);
            return;
        }
        if(big_queue.size()==small_queue.size()){
            if(num<big_queue.top()){big_queue.push(num);}
            else{small_queue.push(num);}
        }else if(big_queue.size()>small_queue.size()){
            if(num<big_queue.top()){
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
            else{small_queue.push(num);}
        }else{
            if(num>small_queue.top()){
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
            else{big_queue.push(num);}
        }

    }

    double findMedian() {
        if(big_queue.size()==small_queue.size()){return (big_queue.top() + small_queue.top())/2;}
        else if(big_queue.size()>small_queue.size()){return big_queue.top();}
        else{return small_queue.top();}
    }
private:
    std::priority_queue<double> big_queue;
    std::priority_queue<double, std::vector<double>, std::greater<double> > small_queue;
};