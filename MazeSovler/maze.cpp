#include "maze.h"
unsigned int dx[4] = { -1, 1, 0, 0 };	//上下左右对应的x增量
unsigned int dy[4] = { 0, 0, -1, 1 };	//上下左右对应的y增量
int visit[MAXM][MAXN];
int dist[MAXM][MAXN];
int lastdir[MAXM][MAXN];
Pos father[MAXM][MAXN];
vector<string> maze;
queue<Pos>	q;
vector<vector<Pos>> path;

//从maze.txt文件当中读取数据
vector<string> Maze::initMaze(string fileName)
{
	//打开文件
	ifstream fin;
	fin.open(fileName);
	if (!fin)
	{
		cout << "open " << fileName << " failed!!!" << endl;
		return {};
	}
	//初始化visit数组
	memset(visit, 0, sizeof(visit));
	//处理空格
	vector<string> res;
	string line;
	cout << "\nWhether the maze uses spaces as path（y/n）？" << endl;
	char choice;
	cin >> choice;
	if (choice == 'n' || choice == 'N')
	{
		while (getline(fin, line))
		{
			//C++自带的消除字符串当中的空格(消除标点的参数为ispunct)，当然也可以自己写
			//line.erase(remove_if(line.begin(), line.end(), static_cast<int(*)(int)>(&isspace)), line.end());
			trimSpace(line);
			res.push_back(line);
		}
	} 
	else
	{
		while (getline(fin, line))
		{
			replaceSpace(line);
			res.push_back(line);
		}
	}
	return res;
}

//（在不以空格为路径但字符之间存在空格那种迷宫）过滤文件当中的空格
void Maze::trimSpace(string& s)
{
	if (s.empty())	return;
	int index = 0;
	while ((index = s.find(' ', index)) != string::npos)
	{
		s.erase(index, 1);
	}
}

//（在以空格为路径的那种迷宫当中）将文件当中的空格替换为H
void Maze::replaceSpace(string& s)
{
	string tag = " ";
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s.replace(i, tag.size(), "H");
		}
	}
	return ;
}

//深度优先算法
void Maze::BFS(Pos& start)
{
	Pos p;
	p.x = start.x;
	p.y = start.y;
	visit[start.x][start.y] = 1;		//设置已被访问
	father[start.x][start.y] = p;		//设置父节点为自己
	q.push(p);			//压入队列
	while (!q.empty())
	{
		Pos front = q.front();	//从队列头取出元素
		q.pop();
		Pos now;
		now.x = front.x, now.y = front.y;
		//遍历四个方向
		for (int i = 0; i < 4; i++)
		{
			Pos next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];

			if (next.x >= 0 && next.x < m_rows
				&& next.y >= 0 && next.y < m_cols
				&& !visit[next.x][next.y]
				&& maze[next.x][next.y] == m_pathstr
				)
			{
				Pos tmp;
				tmp.x = next.x;
				tmp.y = next.y;
				visit[next.x][next.y] = 1;
				father[next.x][next.y] = front;
				lastdir[next.x][next.y] = i;
				// 到入口最短距离为其父节点到入口最短距离+1
				dist[next.x][next.y] = dist[front.x][front.y] + 1;
				q.push(tmp);
			}
		}
	}
}

//输出路径的字符串
void Maze::printPathStr(Pos& end)
{
	cout << "The pathway is as follows:" << endl;
	stack<char> path;	//用来保存输出路径
	/*从出口往前遍历*/
	while (true)
	{
		int father_row = father[end.x][end.y].x;
		int father_col = father[end.x][end.y].y;
		if (father_row == end.x && father_col == end.y)
			break;
		else
		{
			path.push(m_direction[lastdir[end.x][end.y]]);
			end.x = father_row;
			end.y = father_col;
		}
	}
	while (!path.empty())	//输出路径
	{
		cout << path.top();
		path.pop();
	}
}

//输入迷宫相关意义的符号，及入口出口坐标
void Maze::inputMazeSymbols()
{
	cout << "Please enter the symbols as up, down, left and right." << endl;
	for (size_t i = 0; i < 4; i++)
		cin >> m_direction[i];
	cout << "Please enter the symbol of the pathway." << endl;
	cin >> m_pathstr;

	cout << "Please enter the entrance coordinates and exit coordinates: (such as entrance (1, 1), exit (6, 4), enter: 1 1 6 4):" << endl;
	cin >> m_start.x >> m_start.y >> m_end.x >> m_end.y;
}

//输出迷宫
void Maze::showMaze(vector<string>& maze)
{
	if (maze.empty())	return;
	cout << "The maze is as follows：" << endl;
	for (size_t i = 0; i < maze.size(); i++)
		cout << maze[i] << endl;
	m_rows = maze.size(), m_cols = maze[0].size();
	cout << "The number of columns in the maze is: " << m_rows << " and the number of rows is: " << m_cols << endl;
}

//输出结果
void Maze::showResult()
{
	maze = initMaze(MAZE_FILENAME);
	
	showMaze(maze);

	inputMazeSymbols();
	
	BFS(m_start);
	
	printPathStr(m_end);
	cout << endl;
	return ;
}