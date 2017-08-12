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

#include "stdafx.h"

using namespace std;

int main()
{
	Cwrapper wrapper;
	chrono::steady_clock clock;
	int turn = 2;
	auto start = clock.now();
	while (wrapper.Fullboard() == false)
	{
		if (turn == 1)
			turn = 2;
		else
			turn = 1;
		auto x = wrapper.Putcomputer(turn, 20000);
		wrapper.Put(get<1>(x), get<2>(x), turn);
		if (wrapper.Checkwin(get<1>(x), get<2>(x)))
			break;
		cout << turn << ": " << static_cast<char>(get<1>(x) + 'A') << " " << static_cast<char>('A' + get<2>(x)) << ": " << get<0>(x) << endl;
	}
	auto end = clock.now();
	cout << "Duration: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " s." << endl;
	return 0;
}

