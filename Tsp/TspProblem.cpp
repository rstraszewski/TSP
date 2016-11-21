#include "stdafx.h"
#include "TspProblem.h"


TspProblem::TspProblem(Graph * graph)
{
	_graph = graph;
}

vector<int> TspProblem::Solve()
{
	const double EulerConstant = std::exp(1.0);

	Path = CreateRandomPath();
	Cost = CalculatePathCost(Path);

	double t = 100;
	double tMin = 0.00001;
	double alpha = 0.99999;

	while(t > tMin)
	{
		auto newPath = CreateNeigbourSolution(Path);
		auto newCost = CalculatePathCost(newPath);

		auto delta = Cost - newCost;
		auto acc = pow(EulerConstant, delta / t);
		auto p = (double)rand() / (double)RAND_MAX;

		if (p < acc)
		{
			Cost = newCost;
			Path = newPath;
		}

		t = alpha * t;
	}

	//vector<int> v;
	/*v.push_back(1 - 1);
	v.push_back(2 - 1);
	v.push_back(242 - 1);
	v.push_back(243 - 1);
	v.push_back(244 - 1);
	v.push_back(241 - 1);
	v.push_back(240 - 1);
	v.push_back(239 - 1);
	v.push_back(238 - 1);
	v.push_back(237 - 1);
	v.push_back(236 - 1);
	v.push_back(235 - 1);
	v.push_back(234 - 1);
	v.push_back(233 - 1);
	v.push_back(232 - 1);
	v.push_back(231 - 1);
	v.push_back(246 - 1);
	v.push_back(245 - 1);
	v.push_back(247 - 1);
	v.push_back(250 - 1);
	v.push_back(251 - 1);
	v.push_back(230 - 1);
	v.push_back(229 - 1);
	v.push_back(228 - 1);
	v.push_back(227 - 1);
	v.push_back(226 - 1);
	v.push_back(225 - 1);
	v.push_back(224 - 1);
	v.push_back(223 - 1);
	v.push_back(222 - 1);
	v.push_back(221 - 1);
	v.push_back(220 - 1);
	v.push_back(219 - 1);
	v.push_back(218 - 1);
	v.push_back(217 - 1);
	v.push_back(216 - 1);
	v.push_back(215 - 1);
	v.push_back(214 - 1);
	v.push_back(213 - 1);
	v.push_back(212 - 1);
	v.push_back(211 - 1);
	v.push_back(210 - 1);
	v.push_back(207 - 1);
	v.push_back(206 - 1);
	v.push_back(205 - 1);
	v.push_back(204 - 1);
	v.push_back(203 - 1);
	v.push_back(202 - 1);
	v.push_back(201 - 1);
	v.push_back(198 - 1);
	v.push_back(197 - 1);
	v.push_back(196 - 1);
	v.push_back(195 - 1);
	v.push_back(194 - 1);
	v.push_back(193 - 1);
	v.push_back(192 - 1);
	v.push_back(191 - 1);
	v.push_back(190 - 1);
	v.push_back(189 - 1);
	v.push_back(188 - 1);
	v.push_back(187 - 1);
	v.push_back(186 - 1);
	v.push_back(185 - 1);
	v.push_back(184 - 1);
	v.push_back(183 - 1);
	v.push_back(182 - 1);
	v.push_back(181 - 1);
	v.push_back(176 - 1);
	v.push_back(180 - 1);
	v.push_back(179 - 1);
	v.push_back(150 - 1);
	v.push_back(178 - 1);
	v.push_back(177 - 1);
	v.push_back(151 - 1);
	v.push_back(152 - 1);
	v.push_back(156 - 1);
	v.push_back(153 - 1);
	v.push_back(155 - 1);
	v.push_back(154 - 1);
	v.push_back(129 - 1);
	v.push_back(130 - 1);
	v.push_back(131 - 1);
	v.push_back(20 - 1);
	v.push_back(21 - 1);
	v.push_back(128 - 1);
	v.push_back(127 - 1);
	v.push_back(126 - 1);
	v.push_back(125 - 1);
	v.push_back(124 - 1);
	v.push_back(123 - 1);
	v.push_back(122 - 1);
	v.push_back(121 - 1);
	v.push_back(120 - 1);
	v.push_back(119 - 1);
	v.push_back(157 - 1);
	v.push_back(158 - 1);
	v.push_back(159 - 1);
	v.push_back(160 - 1);
	v.push_back(175 - 1);
	v.push_back(161 - 1);
	v.push_back(162 - 1);
	v.push_back(163 - 1);
	v.push_back(164 - 1);
	v.push_back(165 - 1);
	v.push_back(166 - 1);
	v.push_back(167 - 1);
	v.push_back(168 - 1);
	v.push_back(169 - 1);
	v.push_back(170 - 1);
	v.push_back(172 - 1);
	v.push_back(171 - 1);
	v.push_back(173 - 1);
	v.push_back(174 - 1);
	v.push_back(107 - 1);
	v.push_back(106 - 1);
	v.push_back(105 - 1);
	v.push_back(104 - 1);
	v.push_back(103 - 1);
	v.push_back(102 - 1);
	v.push_back(101 - 1);
	v.push_back(100 - 1);
	v.push_back(99 - 1);
	v.push_back(98 - 1);
	v.push_back(97 - 1);
	v.push_back(96 - 1);
	v.push_back(95 - 1);
	v.push_back(94 - 1);
	v.push_back(93 - 1);
	v.push_back(92 - 1);
	v.push_back(91 - 1);
	v.push_back(90 - 1);
	v.push_back(89 - 1);
	v.push_back(109 - 1);
	v.push_back(108 - 1);
	v.push_back(110 - 1);
	v.push_back(111 - 1);
	v.push_back(112 - 1);
	v.push_back(88 - 1);
	v.push_back(87 - 1);
	v.push_back(113 - 1);
	v.push_back(114 - 1);
	v.push_back(115 - 1);
	v.push_back(117 - 1);
	v.push_back(116 - 1);
	v.push_back(86 - 1);
	v.push_back(85 - 1);
	v.push_back(84 - 1);
	v.push_back(83 - 1);
	v.push_back(82 - 1);
	v.push_back(81 - 1);
	v.push_back(80 - 1);
	v.push_bk(79 - 1);
	v.push_back(78 - 1);
	v.push_back(77 - 1);
	v.push_back(76 - 1);
	v.push_back(75 - 1);
	v.push_back(74 - 1);
	v.push_back(73 - 1);
	v.push_back(72 - 1);
	v.push_back(71 - 1);
	v.push_back(70 - 1);
	v.push_back(69 - 1);
	v.push_back(68 - 1);
	v.push_back(67 - 1);
	v.push_back(66 - 1);
	v.push_back(65 - 1);
	v.push_back(64 - 1);
	v.push_back(58 - 1);
	v.push_back(57 - 1);
	v.push_back(56 - 1);
	v.push_back(55 - 1);
	v.push_back(54 - 1);
	v.push_back(53 - 1);
	v.push_back(52 - 1);
	v.push_back(51 - 1);
	v.push_back(50 - 1);
	v.push_back(49 - 1);
	v.push_back(48 - 1);
	v.push_back(47 - 1);
	v.push_back(46 - 1);
	v.push_back(45 - 1);
	v.push_back(44 - 1);
	v.push_back(59 - 1);
	v.push_back(63 - 1);
	v.push_back(62 - 1);
	v.push_back(118 - 1);
	v.push_back(61 - 1);
	v.push_back(60 - 1);
	v.push_back(43 - 1);
	v.push_back(42 - 1);
	v.push_back(41 - 1);
	v.push_back(40 - 1);
	v.push_back(39 - 1);
	v.push_back(38 - 1);
	v.push_back(37 - 1);
	v.push_back(36 - 1);
	v.push_back(35 - 1);
	v.push_back(34 - 1);
	v.push_back(33 - 1);
	v.push_back(32 - 1);
	v.push_back(31 - 1);
	v.push_back(30 - 1);
	v.push_back(29 - 1);
	v.push_back(28 - 1);
	v.push_back(27 - 1);
	v.push_back(26 - 1);
	v.push_back(22 - 1);
	v.push_back(25 - 1);
	v.push_back(23 - 1);
	v.push_back(24 - 1);
	v.push_back(14 - 1);
	v.push_back(15 - 1);
	v.push_back(13 - 1);
	v.push_back(12 - 1);
	v.push_back(11 - 1);
	v.push_back(10 - 1);
	v.push_back(9 - 1);
	v.push_back(8 - 1);
	v.push_back(7 - 1);
	v.push_back(6 - 1);
	v.push_back(5 - 1);
	v.push_back(4 - 1);
	v.push_back(277 - 1);
	v.push_back(276 - 1);
	v.push_back(275 - 1);
	v.push_back(274 - 1);
	v.push_back(273 - 1);
	v.push_back(272 - 1);
	v.push_back(271 - 1);
	v.push_back(16 - 1);
	v.push_back(17 - 1);
	v.push_back(18 - 1);
	v.push_back(19 - 1);
	v.push_back(132 - 1);
	v.push_back(133 - 1);
	v.push_back(134 - 1);
	v.push_back(270 - 1);
	v.push_back(269 - 1);
	v.push_back(135 - 1);
	v.push_back(136 - 1);
	v.push_back(268 - 1);
	v.push_back(267 - 1);
	v.push_back(137 - 1);
	v.push_back(138 - 1);
	v.push_back(139 - 1);
	v.push_back(149 - 1);
	v.push_back(148 - 1);
	v.push_back(147 - 1);
	v.push_back(146 - 1);
	v.push_back(145 - 1);
	v.push_back(199 - 1);
	v.push_back(200 - 1);
	v.push_back(144 - 1);
	v.push_back(143 - 1);
	v.push_back(142 - 1);
	v.push_back(141 - 1);
	v.push_back(140 - 1);
	v.push_back(266 - 1);
	v.push_back(265 - 1);
	v.push_back(264 - 1);
	v.push_back(263 - 1);
	v.push_back(262 - 1);
	v.push_back(261 - 1);
	v.push_back(260 - 1);
	v.push_back(259 - 1);
	v.push_back(258 - 1);
	v.push_back(257 - 1);
	v.push_back(254 - 1);
	v.push_back(253 - 1);
	v.push_back(208 - 1);
	v.push_back(209 - 1);
	v.push_back(252 - 1);
	v.push_back(255 - 1);
	v.push_back(256 - 1);
	v.push_back(249 - 1);
	v.push_back(248 - 1);
	v.push_back(278 - 1);
	v.push_back(279 - 1);
	v.push_back(3 - 1);
	v.push_back(280 - 1);*/



	return Path;
}

float TspProblem::CalculateDistance(int firstCityIndex, int secondCityIndex)
{
	float firstCityX = _graph->GraphX[firstCityIndex];
	float firstCityY = _graph->GraphY[firstCityIndex];

	float secondCityX = _graph->GraphX[secondCityIndex];
	float secondCityY = _graph->GraphY[secondCityIndex];

	float x = firstCityX - secondCityX;
	float y = firstCityY - secondCityY;

	float dist = pow(x, 2) + pow(y, 2);
	dist = round(sqrt(dist));
	//cout << firstCityX << " " << firstCityIndex<< " " << firstCityY << " " << firstCityIndex << " " << secondCityX << " " << secondCityIndex<< " " << secondCityY << " " << secondCityIndex << " \n";
	return dist;
}

float TspProblem::CalculatePathCost(vector<int> path)
{
	float cost = 0;

	for (int i = 1; i < _graph->Dimension; ++i)
	{
		auto firstCity = path[i - 1];
		auto secondCity = path[i];
		//cout <<"koszt"<< cost << endl;
		cost += CalculateDistance(firstCity, secondCity);
	}
	//cout << "przed:" << cost << endl;
	cost += CalculateDistance(path.back(), path.front());
	//cout << "po" << cost << endl;
	return cost;
}


vector<int> TspProblem::CreateRandomPath()
{
	vector<int> path;
	for (int i = 0; i < _graph->Dimension; ++i) path.push_back(i);

	random_shuffle(path.begin(), path.end());

	return path;
}

vector<int> TspProblem::CreateNeigbourSolution(vector<int> path)
{
	vector<int> neigbourPath(path);

	int first = -1; 
	int second = -1;

	while(first == second)
	{
		first = (rand() % (int)(_graph->Dimension));
		second = (rand() % (int)(_graph->Dimension));
	}

	iter_swap(neigbourPath.begin() + first, neigbourPath.begin() + second);

	return neigbourPath;
}

TspProblem::~TspProblem()
{
}
