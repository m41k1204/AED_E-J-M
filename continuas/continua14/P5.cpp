class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::multiset<std::string>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        std::vector<std::string> itinerary;
        dfs("JFK", graph, itinerary);
        std::reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const std::string& airport,
             std::unordered_map<std::string, std::multiset<std::string>>& graph,
             std::vector<std::string>& itinerary) {
        auto& destinations = graph[airport];
        while (!destinations.empty()) {
            auto next = destinations.begin();
            std::string nextAirport = *next;
            destinations.erase(next); 
            dfs(nextAirport, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};
