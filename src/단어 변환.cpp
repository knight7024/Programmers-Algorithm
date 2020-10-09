#include <string>
#include <vector>
#include <queue>

using namespace std;

bool node[51][51], visited[51];

bool isConvertible(string a, string b)
{
	int size = a.size();
	int diff = 0;
	for (int i = 0; i < size; i++)
		diff += a[i] != b[i];
	return diff == 1;
}

int solution(string begin, string target, vector<string> words)
{
	int targetIndex = -1;
	words.push_back(begin);
	for (int i = 0; i < words.size() - 1; i++)
	{
		if (words[i] == target)
			targetIndex = i;
		for (int j = i + 1; j < words.size(); j++)
			if (isConvertible(words[i], words[j]))
				node[i][j] = node[j][i] = true;
	}
	if (targetIndex == -1)
		return 0;
	vector<int> conv(words.size());
	queue<int> q;
	q.push(words.size() - 1);
	visited[words.size() - 1] = true;
	while (!q.empty())
	{
		int first = q.front();
		for (int i = 0; i < words.size(); i++)
		{
			if (node[first][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
				conv[i] = conv[first] + 1;
			}
		}
		q.pop();
	}
	return conv[targetIndex];
}
