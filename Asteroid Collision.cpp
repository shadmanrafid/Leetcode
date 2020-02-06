class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> coll_detector;
        vector<int> remaining_asteroids;
        int n,placed,first;
        for(n = asteroids.size()-1; n>=0; n-- )
        {
            placed = 0;
            while(placed != 1)
            {
                if(coll_detector.empty())
                {
                    coll_detector.push(asteroids[n]);
                    placed = 1;
                }
                
            else
            {
                first = coll_detector.top();
                if((asteroids[n]<0 &&first <0) || (asteroids[n]>0 && first >0) || (asteroids[n] < 0 && first > 0))
                {
                    coll_detector.push(asteroids[n]);
                    placed =1;
                }
                else
                {
                        if (abs(asteroids[n]) < abs(first))
                            placed = 1;
                        else if (abs(asteroids[n]) == abs(first))
                        {
                            coll_detector.pop();
                            placed = 1;
                        }
                        else
                        {
                            coll_detector.pop();
                            if(coll_detector.empty())
                            {
                                coll_detector.push(asteroids[n]);
                                placed =1;
                            }
                            else
                            {
                                first = coll_detector.top();
                            }
                        }

                }
                
            }
            }
            
        }
        while(!coll_detector.empty())
        {
            first = coll_detector.top();
            coll_detector.pop();
            remaining_asteroids.push_back(first);
        }
        return remaining_asteroids;
        
    }
};