/*
Copyright 2017 Chijun Sima

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once
#include"stdafx.h"
#include"evaluation.h"
#include"chessboard.h"

#ifndef DllExport
#define DllExport   __declspec( dllexport )  
#endif // !DllExport

class searcher
{
public:
	DllExport std::tuple<int, int8_t, int8_t> alpha_beta_search(int8_t turn, chessboard board, int8_t depth, int timeout);
private:
	std::vector<std::tuple<int, int8_t, int8_t>> smart_genmove(const int8_t turn, chessboard& board, const int8_t current, evaluation& evaluator);
	std::tuple<int, int8_t, int8_t> max_value(int8_t turn, chessboard& board, int alpha, int beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation& evaluator, int score);
	std::tuple<int, int8_t, int8_t> min_value(int8_t turn, chessboard& board, int alpha, int beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation& evaluator, int score);
	std::tuple<int, int8_t, int8_t> max_value_first(int8_t turn, chessboard& board, int beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation& evaluator, int score);
	void min_value_first(int8_t turn, chessboard board, int beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation evaluator, int score);
	void min_value_second(int8_t turn, chessboard board, int beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation evaluator, int score);
	std::tuple<int, int8_t, int8_t> max_value_second(int8_t turn, chessboard board, int alpha, int& beta, int8_t depth, int8_t i, int8_t ii, int8_t ply, evaluation evaluator, int score);
	void write_val(const std::tuple<int, int8_t, int8_t>&);
	void getTrueVal(std::tuple<int, int8_t, int8_t>& temp);
	int getAlphaVal();
	int timeoutnum = 30000;
	std::chrono::time_point<std::chrono::steady_clock> start;
	int8_t search_depth;
	std::tuple<int, int8_t, int8_t> trueval;
	int alphaval;
	uint8_t maxnum;
};
