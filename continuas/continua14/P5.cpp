class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport, unordered_map<string, multiset<string>>& graph, vector<string>& itinerary) {
        auto& destinations = graph[airport];
        while (!destinations.empty()) {
            auto next = destinations.begin();
            string nextAirport = *next;
            destinations.erase(next); 
            dfs(nextAirport, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};
