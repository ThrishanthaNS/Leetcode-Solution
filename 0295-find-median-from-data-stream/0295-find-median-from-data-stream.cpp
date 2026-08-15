class MedianFinder {
public:
priority_queue<int>leftheap;
priority_queue<int,vector<int>,greater<int>>rightheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftheap.push(num);
        if(!rightheap.empty() && leftheap.top()>rightheap.top()){
            int x=leftheap.top();
            int y=rightheap.top();
            leftheap.pop();
            rightheap.pop();
            leftheap.push(y);
            rightheap.push(x);
        }
        if(leftheap.size()==rightheap.size()+2){
            rightheap.push(leftheap.top());
            leftheap.pop();
        }
        
    }
    
    double findMedian() {
        if(leftheap.size()==rightheap.size()){
            return (leftheap.top()+rightheap.top())/2.0;
        }
        else{
            return leftheap.top(); 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */