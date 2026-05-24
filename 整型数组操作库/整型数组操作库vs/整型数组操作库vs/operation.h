#pragma once
#include<vector>;
using namespace std;
void cin_arr(vector<int>& arr);
void sort_arr(vector<int>& arr);
void insert_element(vector<int>& arr, int index, int element);
void find_element(const vector<int>& arr, int element);
void delete_element(vector<int>& arr, int element);
void cout_arr(const vector<int>& arr);
void cout_sepcific_element(const vector<int>& arr, int index);
int sum_array(vector<int>& indices, const vector<int>& arr);

