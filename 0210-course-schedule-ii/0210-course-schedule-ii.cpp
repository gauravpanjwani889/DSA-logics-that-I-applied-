#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prev = prereq[1];
            adj[prev].push_back(course);
            inDegree[course]++;
        }
        
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        std::vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return (order.size() == numCourses) ? order : std::vector<int>();
    }
};
