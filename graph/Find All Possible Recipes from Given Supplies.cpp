#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> kahn(vector<vector<int>> &adj_list, vector<int> &indegree, vector<string> &idToStr, unordered_set<string> &recipeSet,vector<string> &supplies, map<string,int> &mpp) {

        queue<int> q;
        vector<string> res;

        for (string &sup : supplies) {
            if (mpp.count(sup)) {
                q.push(mpp[sup]);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            string currStr = idToStr[curr];

            if(recipeSet.count(currStr)) {
                res.push_back(currStr);
            }

            for(int it : adj_list[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return res;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int> mpp;
        int id = 0;

        for (string &rec : recipes) {
    //        if (!mpp.contains(rec)) mpp[rec] = id++;
        }

        for (auto &ing_list : ingredients) {
            for (string &ing : ing_list) {
    //            if (!mpp.contains(ing)) mpp[ing] = id++;
            }
        }

        for (string &sup : supplies) {
    //        if (!mpp.contains(sup)) mpp[sup] = id++;
        }

        int V = id;

        vector<vector<int>> adj_list(V);
        vector<int> indegree(V, 0);

        
        for(int i = 0; i < recipes.size(); i++) {
            int recipeId = mpp[recipes[i]];

            for(string &ing : ingredients[i]) {
                int ingId = mpp[ing];

                adj_list[ingId].push_back(recipeId);
                indegree[recipeId]++;
            }
        }

        vector<string> idToStr(V);
        for(auto &it : mpp) {
            idToStr[it.second] = it.first;
        }

        unordered_set<string> recipeSet(recipes.begin(), recipes.end());

        return kahn(adj_list, indegree, idToStr, recipeSet, supplies, mpp);
    }
};